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

#include "SoundWorld.hpp"

template<typename NoteType>
class Instrument
{
public:
	Instrument(SoundWorld &world, const float RELEASE_SEC,
			const float VOLUME, const float BASE_FREQ);
	void playNote(const int NOTE, float pan = 0.f);

private:
	float calcFreq(int note);

	SoundWorld &world;
	const float RELEASE_SEC, VOLUME, BASE_FREQ;
	static constexpr float MAJOR_RATIOS[] = {
		1.f, //  // [0] = Unison
		9 / 8.f, // [1] = Major 2nd
		5 / 4.f, // [2] = Major 3rd
		4 / 3.f, // [3] = Perfect 4th
		3 / 2.f, // [4] = Perfect 5th
		5 / 3.f, // [5] = Major 6th
		15 / 8.f // [6] = Major 7th
	};
};

#include "Instrument.inl"
