#pragma once

#include <SDL.h>

namespace particle {
	class Screen {
	public:
		const static int SCREEN_WIDTH = 1920;
		const static int SCREEN_HEIGHT = 1080;

	private:
		SDL_Window * m_window;
		SDL_Renderer *m_renderer;
		SDL_Texture *m_texture;
		Uint32 *m_buffer1;
		Uint32 *m_buffer2;

	public:
		Screen();
		bool init();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		void update();
		bool processEvents();
		void close();
		void boxBlur();
	};
} // namespace particle
