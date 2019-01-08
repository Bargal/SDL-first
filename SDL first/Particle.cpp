#define _USE_MATH_DEFINES
#include "Particle.h"
#include <cstdlib>


namespace particle {
	Particle::Particle() : m_x(0), m_y(0) {
	
		init();
	}

	void Particle::init() {
		m_x = 0;
		m_y = 0;
		m_direction = (3 * M_PI * rand())  / RAND_MAX;
		m_speed = ((0.004 * rand()) / RAND_MAX) *40 ;

		m_speed *= m_speed;
	};

	void Particle::update(int interval) {
		
		m_direction += interval * 0.0000003;

		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		m_x += xspeed * interval;
		m_y += yspeed * interval;

		if (m_x < -1 || m_x >1 || m_y < -1 || m_y > 1) {
			init();
		}
	
	};




		Particle::~Particle() {}
} // namespace particle

