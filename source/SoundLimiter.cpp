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

#include <cmath>

#include "SoundLimiter.hpp"
#include "Sample.hpp"

SoundLimiter::SoundLimiter() : decRatio(1.f) { }

void SoundLimiter::processSample(Sample& sample)
{
	decRatio = 1 + 0.999995 * (decRatio - 1);
	if (std::abs(sample.left * decRatio) > 1.f)
		decRatio = 1.f/std::abs(sample.left);
	if (std::abs(sample.right * decRatio) > 1.f)
		decRatio = 1.f/std::abs(sample.right);
	sample.left *= decRatio;
	sample.right *= decRatio;
}
