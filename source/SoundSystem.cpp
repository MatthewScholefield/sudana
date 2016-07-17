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

#include "SoundSystem.hpp"
#include "Instrument.hpp"
#include <portaudio.h>

SoundSystem::SoundSystem() { }

void SoundSystem::initialize(SoundWorld &world)
{
	wrapper(Pa_Initialize);
	wrapper(openStream, &stream, &world);
	wrapper(Pa_StartStream, stream);
}

void SoundSystem::terminate()
{
	wrapper(Pa_StopStream, stream);
	wrapper(Pa_CloseStream, stream);
	wrapper(Pa_Terminate);
}

PaError SoundSystem::openStream(PaStream **stream, SoundWorld *world)
{
	const int NUM_CHAN_IN = 0;
	const int NUM_CHAN_OUT = 2;
	const PaSampleFormat SAMPLE_FORMAT = paFloat32;
	const int SAMPLE_RATE = SoundSystem::SAMPLE_RATE;
	const int FRAMES_PER_BUFFER = paFramesPerBufferUnspecified;
	PaStreamCallback * const STREAM_CALLBACK = calcAudio;
	void *const USER_DATA = world;

	return Pa_OpenDefaultStream(stream, NUM_CHAN_IN, NUM_CHAN_OUT, SAMPLE_FORMAT,
								SAMPLE_RATE, FRAMES_PER_BUFFER, STREAM_CALLBACK, USER_DATA);
}

int SoundSystem::calcAudio(const void *inputBuffer, void *outputBuffer,
						   unsigned long framesPerBuffer,
						   const PaStreamCallbackTimeInfo* timeInfo,
						   PaStreamCallbackFlags statusFlags,
						   void *userData)
{
	SoundWorld *world = (SoundWorld*) userData;
	float *outAudio = (float*) outputBuffer;

	for (int i = 0; i < framesPerBuffer; ++i)
	{
		const Sample &SAMPLE = world->calcSample();
		*outAudio++ = SAMPLE.left;
		*outAudio++ = SAMPLE.right;
	}
	return 0;
}
