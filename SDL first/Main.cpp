#include "Particle.h"
#include "Screen.h"
#include "Swarm.h"
#include <SDL.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
	std::srand(static_cast<unsigned int>(time(NULL)));
	particle::Screen screen;
	screen.init();

	particle::Swarm swarm;

	while (true) {
		// draw particles
		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0004)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0008)) * 128);

		const particle::Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < particle::Swarm::NPARTICLES; i++) {
			particle::Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * particle::Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * particle::Screen::SCREEN_WIDTH / 2 +
				particle::Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		// Draw the screen
		screen.update();

		// Check for messages/events

		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}