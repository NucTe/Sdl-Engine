#include "Engine/GameLogic/GameWorld.h"

#include "Physics/2d/Physics.h"
#include "Physics/2d/Vector2d.h"

#include "Engine/Rendering/Renderer.h"


namespace NUCTE_NS {
	GameWorld::GameWorld(EntityManager& entityManager, Renderer& renderer) : entityManager(entityManager), m_Rend(renderer){
	}

	GameWorld::~GameWorld() {
	}

	const std::vector<Entity*>& GameWorld::GetEntities() const {
		return entityManager.GetEntities();
	}

	void GameWorld::Update(float dt) {
		//auto it = m_Rectangles.begin();
		//while (it != m_Rectangles.end()) {
		//	Rectangle& rect = *it;
		//
		//	rect.physicsObject->applyGravity(9.81f, dt);
		//	rect.position.x += rect.physicsObject->velocity.x * dt;
		//	rect.position.y += rect.physicsObject->velocity.y * dt;
		//
		//	float maxX = m_Rend->gViewWidth;
		//	float maxY = m_Rend->gViewHeight;
		//	if (rect.position.x < 0 || rect.position.y < 0 || rect.position.x > maxX || rect.position.y > maxY) {
		//		it = m_Rectangles.erase(it);
		//		continue;
		//	}
		//
		//	++it;
		//}
	}



	void GameWorld::Render() {
	}

	// Start Rect
	void GameWorld::AddRectangle(const glm::vec2& position, float width, float height, const glm::vec4& color, PhysicsObject& physicsObject) {
		Body body;
		body.position = Vector2d(position.x, position.y);
		body.velocity = Vector2d(0.0, 0.0);
		body.mass = 1.0;

		physicsObject.position = Vector2d(position.x, position.y);
		physicsObject.width = width;
		physicsObject.height = height;
		physicsObject.velocity = Vector2d(0.0, 0.0);
		physicsObject.bounciness = 0.5;
		physicsObject.isStatic = false;

		World world;
		world.addBody(body);
		world.addCollider(Collider(&physicsObject, &body));

		Rectangle rect;
		rect.id = RectId++;
		rect.position = position;
		rect.width = width;
		rect.height = height;
		rect.color = color;
		rect.physicsObject = &physicsObject;
		m_Rectangles.push_back(rect);
	}

	void GameWorld::RmRectangle(int id) {
		auto it = std::find_if(m_Rectangles.begin(), m_Rectangles.end(), [id](const Rectangle& rect) {
			return rect.id == id;
			});
		if (it != m_Rectangles.end()) {
			m_Rectangles.erase(it);
		}
	}


	const std::list<Rectangle>& GameWorld::GetRectangles() const {
		return m_Rectangles;
	}


	// End Rect
}
