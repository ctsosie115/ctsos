#include "Particlie.h"

void Particle::Update(float dt)
{
	if (m_lifespan != 0) {
		m_lifespan -= dt;
	}
	position = position + (velocity * dt);
}

void Particle::Draw(Renderer& renderer)
{
	if (m_lifespan >= 0) {
		renderer.DrawRect(position.x, position.y, 4.0f, 4.0f);  
		
	}
}
