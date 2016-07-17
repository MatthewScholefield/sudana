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

#include "SoundWorld.hpp"
#include "Notes/SawNote.hpp"
#include "Notes/TriNote.hpp"
#include "Notes/SinNote.hpp"

#include <iostream>

SoundWorld::SoundWorld() : notes{}, id(0) { }

void SoundWorld::registerNote(Note* note)
{
	notes[id] = Note::Ptr(note);
	if (++id >= MAX_NOTES)
		id = 0;
}

Sample SoundWorld::calcSample()
{
	Sample sample;
	for (auto &i : notes)
	{
		if (!i)
			continue;
		sample += i->calcSample();
	}
	return sample;
}
