#include "Render.h"
#include "Vector2.h"
#include "Input.h"
#include "Particlie.h"
#include "Random.h"
#include "CTime.h"

#include <SDL.h>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	//create system
	Renderer render;
	render.Iitialize();
	render.CreateWindow("Game Engine", 800, 600);

	Input input;
	input.Initialize();

	Time time;



	std::vector<Particle> particles;

	//main loop
	bool quit = false;
	while (!quit) 
	{
		time.Tick();
		std::cout << time.GetTime() << std::endl;  

		//Input
		input.Update(); 

		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) 
		{
			quit = true;
		}

		//UPDATE

		Vector2 mousePostion = input.GetMousePosition(); 

		if (input.GetMouseButtonDown(0))
		{

			for (int i = 0; i < 6; i++)
			{
				particles.push_back(Particle{ mousePostion, { randomF(-100, 100), randomF(-100, 100) }, 10}); 
			}
		}

		for (Particle& particle : particles)
		{
			particle.Update(time.GetDeltaTime());
			if (particle.position.x > 800) particle.position.x = 0;
			if (particle.position.x > 800) particle.position.x = 800;

		}


		//Vector2 mousePostion = input.GetMousePosition();
		//std::cout << mousePostion.x << " " << mousePostion.y << std::endl;

		/*if (input.GetMouseButtonDown(0) && !input.GetPreviousMouseButtonDown(0))
		{
			std::cout << "mouse pressed\n";
		}*/


		//Draw
		//Clear Screen
		render.SetColor(0,0,0,0);
		render.BeginFrame();
		
		render.SetColor(255, 255, 255, 0);
		for (Particle particleses: particles)
		{
			
			particleses.Draw(render);

		}

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