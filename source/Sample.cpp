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

#include "Sample.hpp"

Sample::Sample() : left(0.f), right(0.f) { }

Sample::Sample(float samp) : left(samp), right(samp) { }

Sample::Sample(float left, float right) : left(left), right(right) { }

Sample Sample::fromPan(float samp, float pan)
{
	Sample sample(samp);
	if (pan > 0.f)
		sample.left *= 1.f - pan;
	else if (pan < 0.f)
		sample.right *= 1.f + pan;
	return sample;
}

Sample &Sample::operator+=(const Sample& rhs)
{
	left += rhs.left;
	right += rhs.right;
	return *this;
}
