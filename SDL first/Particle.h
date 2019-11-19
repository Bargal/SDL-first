#pragma once

namespace particle {
	class Particle {
	public:
		double m_x;
		double m_y;

		void update(int interval);
		Particle();

		~Particle();

	private:
		double m_speed{};
		double m_direction{};

		void init();
	};
} // namespace particle
