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

#include <iostream>

#include "../SoundWorld.hpp"
#include "Note.hpp"

Note::Note(const float FREQ, const float RELEASE_SEC, const float AMP, const float PAN) :
FREQ(FREQ), amp(AMP), PAN(PAN), AMP_DEC(AMP / (SoundSystem::SAMPLE_RATE * RELEASE_SEC)){ }

Sample Note::calcSample()
{
	decay();
	float samp = amp * calcIntensity();
	return Sample::fromPan(samp, PAN);
}

void Note::decay()
{
	if (amp > 0)
		amp -= AMP_DEC;
}

float Note::getAmp()
{
	return amp;
}
