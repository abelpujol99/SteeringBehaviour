#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "SDL_SimpleApp.h"
#include "SoloAgentScene.h"
#include "MultiAgentScene.h"


using namespace std;

int main(int argc, char ** argv)
{
	bool quit = false;
	SDL_Event event;

	SDL_SimpleApp *app = SDL_SimpleApp::Instance();

	Scene *curr_scene = new SoloAgentScene;
	app->setWindowTitle(curr_scene->getTitle());

	while (!quit)
	{
		// run app frame by frame
		event = app->run(curr_scene);

		/* Keyboard events */
		switch (event.type)
		{
		case SDL_KEYDOWN:
			if (event.key.keysym.scancode == SDL_SCANCODE_1)
			{
				if (curr_scene->getTitle() != "SDL Steering Behaviors :: Solo Agent Demo")
				{
					delete(curr_scene);
					curr_scene = new SoloAgentScene;
					app->setWindowTitle(curr_scene->getTitle());
				}
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_2)
			{
				if (curr_scene->getTitle() != "SDL Steering Behaviors :: Multi Agent Demo")
				{
					delete(curr_scene);
					curr_scene = new MultiAgentScene;
					app->setWindowTitle(curr_scene->getTitle());
				}
			}
			if ((event.key.keysym.scancode == SDL_SCANCODE_Q) || (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
			{
				quit = true;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_F)
			{
				app->setFullScreen();
			}
			break;
		case SDL_QUIT:
			quit = true;
			break;
		}

	}

	return 0;
}