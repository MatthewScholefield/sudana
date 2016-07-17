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

#include <portaudio.h>

class SoundWorld;

class SoundSystem
{
public:
	SoundSystem();
	void initialize(SoundWorld &world);
	void terminate();

	static const int SAMPLE_RATE = 44100;

private:
	template<typename Func, typename ...Args>
	void wrapper(Func func, Args... args);
	static PaError openStream(PaStream **stream, SoundWorld *world);
	static int calcAudio(const void*, void*, unsigned long,
						const PaStreamCallbackTimeInfo*, PaStreamCallbackFlags, void*);

	PaStream *stream;
};

#include "SoundSystem.inl"
