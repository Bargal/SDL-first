#pragma once
#include "Particle.h"

namespace particle {
	class Swarm {
	private:
		particle::Particle *m_pParticles;
		int lastTime;

	public:
		const static int NPARTICLES = 15000;

		particle::Particle * getParticles() { return m_pParticles; };
		void update(int elapsed);

		Swarm();
		~Swarm();
	};
} // namespace particle
