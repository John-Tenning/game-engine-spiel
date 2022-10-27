// Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "common.h"
#include "Basics.h"
#include "LTexture.h"
#include "Dot.h"
#include "CollidibleObject.h"

// Screen dimension constants
int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;
// The window we'll be rendering to
SDL_Window *gWindow = NULL;
// The window renderer
SDL_Renderer *gRenderer = NULL;

// Scene textures
LTexture gDotTexture;
LTexture gTreeTexture;

bool loadMedia()
{
	// Loading success flag
	bool success = true;

	// Load press texture
	if (!gDotTexture.loadFromFile("assets/dot.bmp"))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}

	if (!gTreeTexture.loadFromFile("assets/tree.png", 252, 2, 252))
	{
		printf("Failed to load tree texture!\n");
		success = false;
	}

	return success;
}

void unloadMedia()
{
	gDotTexture.free();
}

int main(int argc, char *args[])
{
	// sayHello();
	// Start up SDL and create window
	if (!init())
		printf("Failed to initialize!\n");

	else
	{
		// Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			// Main loop flag
			bool quit = false;

			// Event handler
			SDL_Event e;

			// The dot that will be moving around on the screen
			Dot dot;
			Dot dot2;

			CollidibleObject tree1(20, 20);
			CollidibleObject tree2(20, 52);

			// While application is running
			while (!quit)
			{
				// Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					// User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					// Handle input for the dot
					dot.handleEvent(e);
				}

				// Move the dot and check collision
				dot.move(2, tree1, tree2);

				// Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				// Render dot
				dot.render(gDotTexture);
				// dot2.render(gDotTexture);
				tree1.render(gTreeTexture);
				tree2.render(gTreeTexture);

				// Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	// Free resources and media
	unloadMedia();
	// Free resources and close SDL
	close();

	return 0;
}
