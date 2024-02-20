#include "Engine/GameLogic/GameWorld.h"
#include "SdlEngine/draw.h"
#include "SdlEngine/Renderer/OpenGLRenderer.h"


namespace NUCTE_NS {
	GameWorld::GameWorld(EntityManager& entityManager) : entityManager(entityManager) {
	}

	GameWorld::~GameWorld() {
	}

	const std::vector<Entity*>& GameWorld::GetEntities() const {
		return entityManager.GetEntities();
	}

	void GameWorld::Update() {
	}

	void GameWorld::Render(OpenGLRenderer* m_OGL) {
		m_OGL->Render(*this);
	}
}

