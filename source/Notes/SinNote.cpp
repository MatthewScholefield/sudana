/*
 * Copyright (C) 2016 Matthew D. Scholefield
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../SoundSystem.hpp"
#include "SinNote.hpp"

#include <cmath>

float SinNote::calcIntensity()
{
	angle += D_THETA;
	if (angle > 2.f * M_PI)
		angle -= 2.f * M_PI;
	return std::sin(angle);
}

float SinNote::calcDTheta(const float FREQ)
{
	return (2.f * M_PI * FREQ) / SoundSystem::SAMPLE_RATE;
}
