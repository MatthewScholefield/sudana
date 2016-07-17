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

#pragma once

#include <memory>
#include "../SoundSystem.hpp"
#include "../Sample.hpp"

class Note
{
public:
	using Ptr = std::unique_ptr<Note>;

	Note(const float FREQ, const float RELEASE_SEC, const float AMP, const float PAN);
	Sample calcSample();

protected:
	virtual float calcIntensity() = 0; // Returns float from -1.f to 1.f
	void decay();
	float getAmp();

	const float FREQ;

private:
	float amp;
	float PAN;
	const float AMP_DEC;
};
