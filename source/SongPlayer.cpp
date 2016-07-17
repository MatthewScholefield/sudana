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

#include <fstream>
#include <chrono>
#include <thread>
#include <math.h>
#include <vector>
#include <iostream>
#include "SongPlayer.hpp"

SongPlayer::SongPlayer(SoundWorld &world) :
bass1(world, 3.f, 0.2f, 110.f),
bass2(world, 3.f, 0.2f, 55.f),
harm(world, 1.5f, 0.2f, 220.f),
lead(world, 2.f, 0.05f, 110.f) { }

class SongPlayer::SongLine
{
public:

	SongLine(const int BASS, const int HARM, const int LEAD) :
	BASS(BASS), HARM(HARM), LEAD(LEAD) { }
	
	const int BASS, HARM, LEAD;
};

void SongPlayer::delay(int ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

float SongPlayer::randPan()
{
	return (rand() % 200 - 100) / 170.f;
}

std::vector<SongPlayer::SongLine> SongPlayer::readLinesFromFile()
{
	std::ifstream file("song.dat");
	std::vector<SongLine> lines;
	int bass, harm, lead;
	
	while (file >> bass >> harm >> lead)
		lines.emplace_back(bass, harm, lead);
	
	return lines;
}

void SongPlayer::playSong()
{
	const int BEAT_MS = 250;
	
	const auto &LINES = readLinesFromFile();
	for (const SongLine &LINE : LINES)
	{
		if (LINE.BASS > 0)
		{
			bass1.playNote(LINE.BASS, randPan());
			bass2.playNote(LINE.BASS, randPan());
		}
		if (LINE.HARM > 0)
			harm.playNote(LINE.HARM, randPan());
		if (LINE.LEAD > 0)
			lead.playNote(LINE.LEAD, randPan());
		delay(BEAT_MS);
	}
	delay(2000);
}
