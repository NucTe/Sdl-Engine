#include "Engine/GameLogic/GameWorld.h"
#include "SdlEngine/Renderer/OpenGLRenderer.h"
#include "SdlEngine/draw.h"



namespace NUCTE_NS {
	GameWorld::GameWorld(EntityManager& entityManager) : entityManager(entityManager){
	}

	GameWorld::~GameWorld() {
	}

	const std::vector<Entity*>& GameWorld::GetEntities() const {
		return entityManager.GetEntities();
	}

	void GameWorld::Update() {
	}

	void GameWorld::Render() {
	}

	void GameWorld::AddRectangle(const glm::vec2& position, float width, float height, const glm::vec4& color) {
		Rectangle rect;
		rect.position = position;
		rect.width = width;
		rect.height = height;
		rect.color = color;
		m_Rectangles.push_back(rect);
	}

	const std::vector<Rectangle>& GameWorld::GetRectangles() const {
		return m_Rectangles;
	}

	void GameWorld::test() {
		glm::vec4 aquaBlue = glm::vec4(0.0f, 1.0f, 1.0f, 1.0f);
		AddRectangle(glm::vec2(50.0f, 50.0f), 25.0f, 25.0f, aquaBlue);
		
		glm::vec4 Blue = glm::vec4(0.0f, 1.0f, 1.0f, 1.0f);
		AddRectangle(glm::vec2(100.0f, 100.0f), 25.0f, 25.0f, Blue);

	}
}
