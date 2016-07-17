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

template<typename NoteType>
Instrument<NoteType>::Instrument(SoundWorld &world, const float RELEASE_SEC,
								 const float VOLUME, const float BASE_FREQ) :
world(world), RELEASE_SEC(RELEASE_SEC), VOLUME(VOLUME), BASE_FREQ(BASE_FREQ) { }

template<typename NoteType>
void Instrument<NoteType>::playNote(const int NOTE, float pan)
{
	world.registerNote(new NoteType(calcFreq(NOTE), RELEASE_SEC, VOLUME, pan));
}

template<typename NoteType>
float Instrument<NoteType>::calcFreq(int note)
{
	--note; // 1 -> [0] -> Unison
	float freq = BASE_FREQ;
	while (note >= 7) // 0..6
	{
		note -= 7;
		freq *= 2.f;
	}
	while (note < 0)
	{
		note += 7;
		freq /= 2.f;
	}
	freq *= MAJOR_RATIOS[note];
	return freq;
}

template<typename NoteType>
constexpr float Instrument<NoteType>::MAJOR_RATIOS[];
