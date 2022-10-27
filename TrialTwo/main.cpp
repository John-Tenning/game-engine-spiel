// Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "common.h"
#include "Spiel.h"
#include "LTexture.h"
#include "CollidibleObject.h"
#include "Playable.h"

using std::vector;

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

	// Load tree texture with keying
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
	gTreeTexture.free();
}

int main(int argc, char *args[])
{
	// sayHello();
	// Start up SDL and create window
	if (!SPIEL_init())
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
			Playable dot(100, 100);

			vector<CollidibleObject> trees;

			int TREE_COUNT = 15;
			for (int i = 0; i < TREE_COUNT; i++)
			{
				CollidibleObject tree(20, 20 + i * 20);
				trees.push_back(tree);
			}

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
				dot.move(trees);

				// Clear screen
				SPIEL_clearScreen();

				// Render dot
				dot.render(gDotTexture);
				for (int i = 0; i < TREE_COUNT; i++)
				{
					trees[i].render(gTreeTexture);
				}

				// Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	// Free resources and media
	unloadMedia();
	// Free resources and close SDL
	SPIEL_close();

	return 0;
}
