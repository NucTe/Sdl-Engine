#include "Engine/GameLogic/GameWorld.h"
#include "SdlEngine/Renderer/OpenGLRenderer.h"
#include "SdlEngine/draw.h"
#include "Physics/2d/Physics.h"
#include "Physics/2d/Vector2d.h"


namespace NUCTE_NS {
	GameWorld::GameWorld(EntityManager& entityManager) : entityManager(entityManager){
	}

	GameWorld::~GameWorld() {
	}

	const std::vector<Entity*>& GameWorld::GetEntities() const {
		return entityManager.GetEntities();
	}

	void GameWorld::Update(float dt) {
		for (Rectangle& rect : m_Rectangles) {
			rect.physicsObject->applyGravity(9.81f, dt);

			rect.position.x += rect.physicsObject->velocity.x * dt;
			rect.position.y += rect.physicsObject->velocity.y * dt;

			std::cout << "y:" << rect.position.y << " x:" << rect.position.x << std::endl;
		}
	}


	void GameWorld::Render() {
	}

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
		rect.position = position;
		rect.width = width;
		rect.height = height;
		rect.color = color;
		rect.physicsObject = &physicsObject;
		m_Rectangles.push_back(rect);
	}

	const std::vector<Rectangle>& GameWorld::GetRectangles() const {
		return m_Rectangles;
	}

	void GameWorld::test() {
		glm::vec4 aquaBlue = glm::vec4(0.0f, 1.0f, 1.0f, 1.0f);
		PhysicsObject physicsObject({ 2.0f, 2.0f }, 0.5, false, 20.0);
		AddRectangle(glm::vec2(50.0f, 50.0f), 25.0f, 25.0f, aquaBlue, physicsObject);
		
		glm::vec4 Blue = glm::vec4(0.0f, 1.0f, 1.0f, 1.0f);
		AddRectangle(glm::vec2(100.0f, 100.0f), 25.0f, 25.0f, Blue, physicsObject);

	}
}
