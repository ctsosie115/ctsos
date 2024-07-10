#include "Render.h"
#include "Vector2.h"
#include "Input.h"
#include "Particlie.h"
#include "Random.h"
#include "CTime.h"
#include "MathUTIS.h"
#include "Model.h"
#include "Transformation.h"

#include <SDL.h>
#include <fmod.hpp>
#include <iostream>
#include <vector>



int main(int argc, char* argv[])
{	
	//create systems
	Renderer render;
	render.Iitialize();
	render.CreateWindow("Game Engine", 800, 600);

	Input input;
	input.Initialize();
	Time time;

	std::vector<Particle> particles;

	//create audio system
	FMOD::System* audio; 
	FMOD::System_Create(&audio);


	void* extradriverdata = nullptr;
	audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

	FMOD::Sound* sound = nullptr;
	std::vector<FMOD::Sound*> sounds; 
	audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound); 

	audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound); 

	audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);

	//Offset
	float offset = 0;
	bool quit = false;

	//Model
	std::vector<Vector2> points_dragon;
	std::vector<Vector2> points;

	points_dragon.push_back(Vector2{ -3, 0 });
	points_dragon.push_back(Vector2{ -2, 1 });
	points_dragon.push_back(Vector2{ 0, 0 });
	points_dragon.push_back(Vector2{ -2, -1 });
	points_dragon.push_back(Vector2{ -3, 0 });
	points_dragon.push_back(Vector2{ -15, 0 });
	points_dragon.push_back(Vector2{ -18, -1 });
	points_dragon.push_back(Vector2{ -20, 0 });
	points_dragon.push_back(Vector2{ -18, 1 });
	points_dragon.push_back(Vector2{ -15, 0 });
	points_dragon.push_back(Vector2{ -6, 0 });

	points_dragon.push_back(Vector2{ -12, -1 });
	points_dragon.push_back(Vector2{ -15, -3 });
	points_dragon.push_back(Vector2{ -15, -6 });
	points_dragon.push_back(Vector2{ -14, -4 });
	points_dragon.push_back(Vector2{  -9, -1 });
	points_dragon.push_back(Vector2{  -6,  0 });

	points_dragon.push_back(Vector2{ -12, 1 });
	points_dragon.push_back(Vector2{ -15, 3 });
	points_dragon.push_back(Vector2{ -15, 6 });
	points_dragon.push_back(Vector2{ -14, 4 });
	points_dragon.push_back(Vector2{  -9, 1 });
	points_dragon.push_back(Vector2{  -6, 0 });

	points_dragon.push_back(Vector2{ -6, -2 });
	points_dragon.push_back(Vector2{ -9, -4 });
	points_dragon.push_back(Vector2{ -7, -5 });
	points_dragon.push_back(Vector2{ -4, -5 });
	points_dragon.push_back(Vector2{ -2, -4 });
	points_dragon.push_back(Vector2{  0, -7 });
	points_dragon.push_back(Vector2{ -4, -8 });
	points_dragon.push_back(Vector2{ -8, -8 });
	points_dragon.push_back(Vector2{ -10,-6 });
	points_dragon.push_back(Vector2{ -9, -4 });
	points_dragon.push_back(Vector2{ -10,-6 });
	points_dragon.push_back(Vector2{ -12,-10 });
	points_dragon.push_back(Vector2{ -4, -12 });
	points_dragon.push_back(Vector2{  0, -7 });
	points_dragon.push_back(Vector2{ -2, -4 });
	points_dragon.push_back(Vector2{ -4, -2 });
	points_dragon.push_back(Vector2{ -5,   0 });
	points_dragon.push_back(Vector2{ -6,  0 });

	points_dragon.push_back(Vector2{ -6, 2 });
	points_dragon.push_back(Vector2{ -9, 4 });
	points_dragon.push_back(Vector2{ -7, 5 });
	points_dragon.push_back(Vector2{ -4, 5 });
	points_dragon.push_back(Vector2{ -2, 4 });
	points_dragon.push_back(Vector2{ 0,  7 });
	points_dragon.push_back(Vector2{ -4, 8 });
	points_dragon.push_back(Vector2{ -8, 8 });
	points_dragon.push_back(Vector2{ -10,6 });
	points_dragon.push_back(Vector2{ -9, 4 });
	points_dragon.push_back(Vector2{ -10,6 });
	points_dragon.push_back(Vector2{ -12,10 });
	points_dragon.push_back(Vector2{ -4, 12 });
	points_dragon.push_back(Vector2{ 0,  7 });
	points_dragon.push_back(Vector2{ -2, 4 });
	points_dragon.push_back(Vector2{ -4, 2 });
	points_dragon.push_back(Vector2{ -5,   0 });


	Model model{ points_dragon, Color{1,0,0} }; 
	Transform transform{ {render.GetWidth() >> 1, render.GetHeight() >> 1}, 0, 5};

	//main loop
	while (!quit) 
	{
		time.Tick(); 

		//Input
		input.Update(); 

		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) 
		{
			quit = true;
		}

		float thrust = 0;

		if (input.GetPreviousKeyDown(SDL_SCANCODE_UP)) thrust = 300; 
		if (input.GetPreviousKeyDown(SDL_SCANCODE_DOWN)) thrust = -300; 
		if (input.GetPreviousKeyDown(SDL_SCANCODE_LEFT)) transform.rotation -= Math::DegtoRad(100) * time.GetDeltaTime();
		if (input.GetPreviousKeyDown(SDL_SCANCODE_RIGHT)) transform.rotation += Math::DegtoRad(100) * time.GetDeltaTime(); 

		if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPreviousKeyDown(SDL_SCANCODE_Q))
		{
			audio->playSound(sounds[0], 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPreviousKeyDown(SDL_SCANCODE_Q))
		{
			audio->playSound(sounds[2], 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPreviousKeyDown(SDL_SCANCODE_Q))
		{
			audio->playSound(sounds[1], 0, false, nullptr);
		}

		Vector2 velocity = Vector2{thrust, 0.0f}.Rotate(transform.rotation);
		transform.position += velocity * time.GetDeltaTime();
		transform.position.x = Math::Wrap(transform.position.x, (float)render.GetWidth());
		transform.position.y = Math::Wrap(transform.position.y, (float)render.GetHeight());
		//UPDATE

		Vector2 mousePostion = input.GetMousePosition(); 

		if (input.GetMouseButtonDown(0))
		{
			for (int i = 0; i < 6; i++)
			{
				//particles.push_back(Particle{ mousePostion, randomOnUnitCircle() * randomF(10,200), randomF(1,5)});
				particles.push_back(Particle{ mousePostion, randomOnUnitCircle() * randomF(10,200), randomF(1,5), random(0,255), random(0,255), random(0,255), random(0,255) });
			}
		}

		for (Particle& particle : particles)
		{
			particle.Update(time.GetDeltaTime());
			if (particle.position.x > 800) particle.position.x = 0;
			if (particle.position.x > 800) particle.position.x = 800;

		}
		audio->update();

		//Draw
		//Clear Screen
		render.SetColor(0,0,0,0);
		render.BeginFrame(); 
		
		render.SetColor(255, 255, 255, 0);
		float radius = 60;
		offset += (90 * time.GetDeltaTime());

		//draw cirle
		for (float angle = 0; angle < 360; angle += 360 / 30)
		{
			float x = Math::Cos(Math::DegtoRad(angle + offset)) * Math::Sin((offset + angle) * 0.025f) * radius;
			float y = Math::Sin(Math::DegtoRad(angle + offset)) * Math::Cos((offset + angle) * 0.2f) * radius;
			
			render.DrawRect(400 + x,300 + y, 4.0f, 4.0f);
		}

		//draw particles
		for (Particle particleses: particles)
		{
			render.SetColor(particleses.red, particleses.green, particleses.blue, particleses.alpha);
			particleses.Draw(render);
		}
		//draw model

		model.Draw(render, transform);

		render.EndFrame(); 

	}
	render.Shutdown();

	return 0;
}

//Engines
//Group things to with the data heriarchy, and how the classes are laid out
//Phyiscal Design - how we arranging your files and directories

//Engine has the sound and cannot see the game
//The Game has the infomation for the engine and see the engine

//Game Frameowrk
//Audio
//Graphics
//Inpput
//Collision/Prime

//The Game project is using the engine as it's referance to see

//DLL os dynamic link library - is done by run time
// EXE is a static library - is done by before run time
//  
// The point of the engine is to create multiple games from a single game.

//projects are contianers that organizes files for developers
// 
// From source code to Excutable code
// reprocess compile link excutable
// source code, preprocessor, translation unit, complier, object file, linker, exectiable file
// 
// SDL Library Simple Direct Media Layer
// 
// 
//