#pragma once
#include "Vector2.h"
#include "Render.h"

struct Particle
{
	int red;
	int green;
	int blue; 
	int alpha;

	Vector2 position{ 0, 0 };
	Vector2 velocity{ 0,0 };
	float m_lifespan;


	Particle() = default;

	Particle(Vector2 position, Vector2 velocity) :
		position{ position },
		velocity{ velocity },
		m_lifespan{ 0}
	{}

	Particle(Vector2 position, Vector2 velocity,float lifespan) :
		position{ position },
		velocity{ velocity },
		m_lifespan{ lifespan}
	{}
	Particle(Vector2 position, Vector2 velocity, float lifespan, int red, int green, int blue, int alpha) :
		position{ position },
		velocity{ velocity },
		m_lifespan{ lifespan },
		red{ red },
		green{ green },
		blue{ blue },
		alpha{ alpha }
	{}

	void Update(float dt);

	void Draw(Renderer& renderer);



};