#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

#define SIZE_WINDOW_W 800
#define SIZE_WINDOW_H 900

int main(void)
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_bool window_is_open = SDL_TRUE;

	SDL_Init(SDL_INIT_VIDEO);

	if(SDL_CreateWindowAndRenderer(SIZE_WINDOW_W, SIZE_WINDOW_H,0, &window, &renderer) != 0)
		fprintf(stderr, "Impossible de creer la fenetre et le rendu\n");
	

	while(window_is_open)
	{
		SDL_Event event;
		while((SDL_PollEvent(&event)))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					window_is_open = SDL_FALSE;
					break;	
				
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							window_is_open = SDL_FALSE;
							break;
						
						default:
							continue;
					}

					break;

				default:
					break;
			}
		}


		SDL_RenderClear(renderer);
		
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return EXIT_SUCCESS;
}
