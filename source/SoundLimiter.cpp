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

#include "SoundLimiter.hpp"
#include "Sample.hpp"

SoundLimiter::SoundLimiter() : decAmount(0.f) { }

void SoundLimiter::processSample(Sample& sample)
{
	decAmount = 0.965f * decAmount;
	if (sample.left - decAmount > 1.f)
		decAmount = sample.left - 1.f;
	if (sample.right - decAmount > 1.f)
		decAmount = sample.right - 1.f;
	sample.left -= decAmount;
	sample.right -= decAmount;
}
