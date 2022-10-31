// Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
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
LTexture gTree2Texture;
LTexture gGroundTexture;
AnimatedTexture gPlayerLeftWalkTexture;
AnimatedTexture gPlayerRightWalkTexture;
AnimatedTexture gPlayerUpWalkTexture;
AnimatedTexture gPlayerDownWalkTexture;
AnimatedTexture gPlayerLeftIdleTexture;
AnimatedTexture gPlayerRightIdleTexture;
AnimatedTexture gPlayerUpIdleTexture;
AnimatedTexture gPlayerDownIdleTexture;

AnimatedTexture gPlayerTwoLeftWalkTexture;
AnimatedTexture gPlayerTwoRightWalkTexture;
AnimatedTexture gPlayerTwoUpWalkTexture;
AnimatedTexture gPlayerTwoDownWalkTexture;
AnimatedTexture gPlayerTwoLeftIdleTexture;
AnimatedTexture gPlayerTwoRightIdleTexture;
AnimatedTexture gPlayerTwoUpIdleTexture;
AnimatedTexture gPlayerTwoDownIdleTexture;

AnimatedTexture gFireTexture;
AnimatedTexture gBlueFireTexture;

bool loadMedia()
{
	// Loading success flag
	bool success = true;

	// Load tree texture with keying
	if (!gTreeTexture.loadFromFile("assets/P3.png"))
	{
		printf("Failed to load tree texture!\n");
		success = false;
	}

	if (!gTree2Texture.loadFromFile("assets/P4.png"))
	{
		printf("Failed to load tree texture!\n");
		success = false;
	}

	if (!gGroundTexture.loadFromFile("assets/background.jpg"))
	{
		printf("Failed to load ground texture!\n");
		success = false;
	}

	if (!gPlayerLeftWalkTexture.loadFromFile("assets/Fumiko.png"))
	{
		printf("Failed to load player left walk texture!\n");
		success = false;
	}
	else
	{
		gPlayerLeftWalkTexture.setValues(15, 4, 24, 32, 48, 96);
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

	if (!gPlayerTwoLeftWalkTexture.loadFromFile("assets/FumikoEvil.png"))
	{
		printf("Failed to load player left walk texture!\n");
		success = false;
	}
	else
	{
		gPlayerTwoLeftWalkTexture.setValues(15, 4, 24, 32, 48, 96);
	}

	if (!gPlayerTwoRightWalkTexture.loadFromFile("assets/FumikoEvil.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerTwoRightWalkTexture.setValues(15, 4, 24, 32, 48, 32);
	}

	if (!gPlayerTwoUpWalkTexture.loadFromFile("assets/FumikoEvil.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerTwoUpWalkTexture.setValues(15, 4, 24, 32, 48, 0);
	}

	if (!gPlayerTwoDownWalkTexture.loadFromFile("assets/FumikoEvil.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerTwoDownWalkTexture.setValues(15, 4, 24, 32, 48, 64);
	}

	if (!gPlayerTwoLeftIdleTexture.loadFromFile("assets/FumikoEvil.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerTwoLeftIdleTexture.setValues(15, 1, 24, 32, 0, 96);
	}

	if (!gPlayerTwoRightIdleTexture.loadFromFile("assets/FumikoEvil.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerTwoRightIdleTexture.setValues(15, 1, 24, 32, 0, 32);
	}

	if (!gPlayerTwoUpIdleTexture.loadFromFile("assets/FumikoEvil.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerTwoUpIdleTexture.setValues(15, 1, 24, 32, 0, 0);
	}

	if (!gPlayerTwoDownIdleTexture.loadFromFile("assets/FumikoEvil.png"))
	{

		printf("Failed to load player texture!\n");
		success = false;
	}
	else
	{
		gPlayerTwoDownIdleTexture.setValues(15, 1, 24, 32, 0, 64);
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
	// gDotTexture.free();
	gTreeTexture.free();
	gTree2Texture.free();
	gGroundTexture.free();
	gPlayerLeftWalkTexture.free();
	gPlayerRightWalkTexture.free();
	gPlayerUpWalkTexture.free();
	gPlayerDownWalkTexture.free();
	gPlayerLeftIdleTexture.free();
	gPlayerRightIdleTexture.free();
	gPlayerUpIdleTexture.free();
	gPlayerDownIdleTexture.free();
	gPlayerTwoDownIdleTexture.free();
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

			Playable player(104, 232);
			player.bindTexture("LEFT_WALK", gPlayerLeftWalkTexture);
			player.bindTexture("RIGHT_WALK", gPlayerRightWalkTexture);
			player.bindTexture("UP_WALK", gPlayerUpWalkTexture);
			player.bindTexture("DOWN_WALK", gPlayerDownWalkTexture);
			player.bindTexture("LEFT_STALL", gPlayerLeftIdleTexture);
			player.bindTexture("RIGHT_STALL", gPlayerRightIdleTexture);
			player.bindTexture("UP_STALL", gPlayerUpIdleTexture);
			player.bindTexture("DOWN_STALL", gPlayerDownIdleTexture);

			Playable player2(488, 344);
			player2.bindTexture("LEFT_WALK", gPlayerTwoLeftWalkTexture);
			player2.bindTexture("RIGHT_WALK", gPlayerTwoRightWalkTexture);
			player2.bindTexture("UP_WALK", gPlayerTwoUpWalkTexture);
			player2.bindTexture("DOWN_WALK", gPlayerTwoDownWalkTexture);
			player2.bindTexture("LEFT_STALL", gPlayerTwoLeftIdleTexture);
			player2.bindTexture("RIGHT_STALL", gPlayerTwoRightIdleTexture);
			player2.bindTexture("UP_STALL", gPlayerTwoUpIdleTexture);
			player2.bindTexture("DOWN_STALL", gPlayerTwoDownIdleTexture);

			vector<CollidibleObject> trees;

			for (int i = 0; 56 + i * 24 < SCREEN_HEIGHT; i++)
			{
				CollidibleObject tree(24, 24 + i * 24);
				if (rand() % 2 == 0)
					tree.bind(gTreeTexture);
				else
					tree.bind(gTree2Texture);
				trees.push_back(tree);
			}

			for (int i = 0; 56 + i * 24 < SCREEN_HEIGHT; i++)
			{
				CollidibleObject tree(SCREEN_WIDTH - 56, 24 + i * 24);
				if (rand() % 2 == 0)
					tree.bind(gTreeTexture);
				else
					tree.bind(gTree2Texture);
				trees.push_back(tree);
			}

			for (int i = 0; 96 + i * 24 < SCREEN_WIDTH; i++)
			{
				CollidibleObject tree(24 + i * 24, 24);
				if (rand() % 2 == 0)
					tree.bind(gTreeTexture);
				else
					tree.bind(gTree2Texture);
				trees.push_back(tree);
			}

			for (int i = 0; 96 + i * 24 < SCREEN_WIDTH; i++)
			{
				CollidibleObject tree(24 + i * 24, SCREEN_HEIGHT - 56);
				if (rand() % 2 == 0)
					tree.bind(gTreeTexture);
				else
					tree.bind(gTree2Texture);
				trees.push_back(tree);
			}
			int stX = 164, stY = 48;
			for (int i = 1; i < 7; i++)
			{
				CollidibleObject tree(stX, stY);
				if (rand() % 2 == 0)
					tree.bind(gTreeTexture);
				else
					tree.bind(gTree2Texture);
				trees.push_back(tree);
				stY += 28;
			}
			int mdX = 292, mdY = 360;
			for (int i = 1; i < 7; i++)
			{
				CollidibleObject tree(mdX, mdY);
				if (rand() % 2 == 0)
					tree.bind(gTreeTexture);
				else
					tree.bind(gTree2Texture);
				trees.push_back(tree);
				mdY -= 28;
			}

			int slX = 48, slY = 176;
			for (int i = 1; i < 3; i++)
			{
				CollidibleObject tree(slX , slY);
				if (rand() % 2 == 0)
					tree.bind(gTreeTexture);
				else
					tree.bind(gTree2Texture);
				trees.push_back(tree);
				slX += 28;
			}

			slX = 48; slY = 288;
			for (int i = 1; i < 3; i++)
			{
				CollidibleObject tree(slX , slY);
				if (rand() % 2 == 0)
					tree.bind(gTreeTexture);
				else
					tree.bind(gTree2Texture);
				trees.push_back(tree);
				slX += 28;
			}
			int edX = 392 , edY = 48;
			for (int i = 1; i < 8; i++)
			{
				CollidibleObject tree(edX , edY);
				if (rand() % 2 == 0)
					tree.bind(gTreeTexture);
				else
					tree.bind(gTree2Texture);
				trees.push_back(tree);
				edY += 28;
			}
			slX = 472; slY = 278;
			for (int i = 1; i < 5; i++)
			{
				CollidibleObject tree(slX , slY);
				if (rand() % 2 == 0)
					tree.bind(gTreeTexture);
				else
					tree.bind(gTree2Texture);
				trees.push_back(tree);
				slX += 28;
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
					player.handleEventARROWS(e);
					player2.handleEventWASD(e);
				}

				// Move the dot and check collision
				player.move(trees);
				player2.move(trees);

				// Clear screen
				SPIEL_refreshScreen();

				gGroundTexture.render(0, 0);
				// Render dot
				player.render();
				player2.render();
				for (int i = 0; i < trees.size(); i++)
				{
					trees[i].render();
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
