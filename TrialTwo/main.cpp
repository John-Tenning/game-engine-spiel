// Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "Common.h"
#include "Spiel.h"
#include "LTexture.h"
#include "CollidibleObject.h"
#include "Playable.h"
#include "AnimatedTexture.h"

using std::vector;

// Screen dimension constants
int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;
// The window we'll be rendering to
SDL_Window *gWindow = NULL;
// The window renderer
SDL_Renderer *gRenderer = NULL;
int timeFrame = 0;

// Scene textures
LTexture gDotTexture;
LTexture gTreeTexture;
LTexture gGroundTexture;
AnimatedTexture gPlayerLeftWalkTexture;
AnimatedTexture gPlayerRightWalkTexture;
AnimatedTexture gPlayerUpWalkTexture;
AnimatedTexture gPlayerDownWalkTexture;
AnimatedTexture gPlayerLeftIdleTexture;
AnimatedTexture gPlayerRightIdleTexture;
AnimatedTexture gPlayerUpIdleTexture;
AnimatedTexture gPlayerDownIdleTexture;

AnimatedTexture gFireTexture;
AnimatedTexture gBlueFireTexture;

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

	if (!gGroundTexture.loadFromFile("assets/hjm-wasteland.png"))
	{
		printf("Failed to load ground texture!\n");
		success = false;
	}

	if (!gPlayerRightWalkTexture.loadFromFile("assets/Fumiko.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerRightWalkTexture.setValues(15, 4, 24, 32, 48, 32);
	}

	if (!gPlayerUpWalkTexture.loadFromFile("assets/Fumiko.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerUpWalkTexture.setValues(15, 4, 24, 32, 48, 0);
	}

	if (!gPlayerDownWalkTexture.loadFromFile("assets/Fumiko.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerDownWalkTexture.setValues(15, 4, 24, 32, 48, 64);
	}

	if (!gPlayerLeftIdleTexture.loadFromFile("assets/Fumiko.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerLeftIdleTexture.setValues(15, 1, 24, 32, 0, 96);
	}

	if (!gPlayerRightIdleTexture.loadFromFile("assets/Fumiko.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerRightIdleTexture.setValues(15, 1, 24, 32, 0, 32);
	}

	if (!gPlayerUpIdleTexture.loadFromFile("assets/Fumiko.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerUpIdleTexture.setValues(15, 1, 24, 32, 0, 0);
	}

	if (!gPlayerDownIdleTexture.loadFromFile("assets/Fumiko.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerDownIdleTexture.setValues(15, 1, 24, 32, 0, 64);
	}

	if (success)
	{
		printf("Media loaded successfully!\n");
	}

	return success;
}

void unloadMedia()
{
	// gSpriteSheetTexture.free();
	gDotTexture.free();
	gTreeTexture.free();
	gGroundTexture.free();
	gPlayerLeftWalkTexture.free();
	gPlayerRightWalkTexture.free();
	gPlayerUpWalkTexture.free();
	gPlayerDownWalkTexture.free();
	gPlayerLeftIdleTexture.free();
	gPlayerRightIdleTexture.free();
	gPlayerUpIdleTexture.free();
	gPlayerDownIdleTexture.free();
}

int main(int argc, char *args[])
{
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
			Playable player(100, 100);
			player.bindTexture("LEFT_WALK", gPlayerLeftWalkTexture);
			player.bindTexture("RIGHT_WALK", gPlayerRightWalkTexture);
			player.bindTexture("UP_WALK", gPlayerUpWalkTexture);
			player.bindTexture("DOWN_WALK", gPlayerDownWalkTexture);
			player.bindTexture("LEFT_STALL", gPlayerLeftIdleTexture);
			player.bindTexture("RIGHT_STALL", gPlayerRightIdleTexture);
			player.bindTexture("UP_STALL", gPlayerUpIdleTexture);
			player.bindTexture("DOWN_STALL", gPlayerDownIdleTexture);

			vector<CollidibleObject> trees;

			for (int i = 0; 56 + i * 24 < SCREEN_HEIGHT; i++)
			{
				CollidibleObject tree(24, 24 + i * 24);
				trees.push_back(tree);
			}

			for (int i = 0; 56 + i * 24 < SCREEN_HEIGHT; i++)
			{
				CollidibleObject tree(SCREEN_WIDTH - 56,24 + i * 24);
				trees.push_back(tree);
			}

			for (int i = 0; 56 + i * 24 < SCREEN_WIDTH; i++)
			{
				CollidibleObject tree(24 + i * 24, 24);
				trees.push_back(tree);
			}

			for (int i = 0; 56 + i * 24 < SCREEN_WIDTH; i++)
			{
				CollidibleObject tree(24 + i * 24, SCREEN_HEIGHT - 56);
				trees.push_back(tree);
			}

			// for (int i = 0; i < 10; i++)
			// {
			// 	CollidibleObject tree(SCREEN_WIDTH - 24, 24 + i * 24);
			// 	trees.push_back(tree);
			// }

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
					player.handleEventARROWS(e);
				}

				// Move the dot and check collision
				player.move(trees);

				// Clear screen
				SPIEL_refreshScreen();

				// Render dot
				player.render();
				for (int i = 0; i < trees.size(); i++)
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
