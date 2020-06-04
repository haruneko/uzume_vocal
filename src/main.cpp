// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "dsp/SynthesizeImpulseResponseWithWORLD.hpp"
#include "dsp/SynthesizePhraseWithWORLD.hpp"
#include "dsp/Waveform.hpp"
#include "dsp/WaveformSpectrogram.hpp"

#include "domain/Track.hpp"
#include "gateways/SpectrogramNaiveRepository.hpp"
#include "usecases/TrackSpectrogram.hpp"

using namespace uzume::dsp;
using namespace uzume::vocal;

// This is an example to use this `vocal` package.
int main() {
    const char *inputPath1 = "G:\\Projects\\vaiueo2d.wav";
    const char *outputPath = "G:\\Projects\\synthesized.wav";
    Waveform *w1 = Waveform::read(inputPath1);
    auto *s1 = new WaveformSpectrogram(w1);

    SpectrogramNaiveRepository r;
    r.append("input1", s1);

    Track t;
    t.f0.insert(0.0, 120.0);
    t.f0.insert(800.0, 120.0);
    t.insert(Piece(SpectrogramReference("input1", 1500.0, 0.0, 900.0), Expression(), 0.0));

    TrackSpectrogram spectrogram(&t, &r, s1->fftSize());

    Waveform output(w1->samplingFrequency * 2, w1->samplingFrequency);
    for (unsigned int i = 0; i < output.length; i++) {
        output.data[i] = 0.0;
    }

    SynthesizeImpulseResponseWithWORLD irs(spectrogram.fftSize(), output.samplingFrequency);
    SynthesizePhraseWithWORLD synthesize(&irs);

    PhraseSignal s(output.data, /* indexMin = */ 0, /* indexMax = */ output.length, output.samplingFrequency);
    PhraseParameters p(&spectrogram, /* startPhase = */ 0.0, /* startFractionalTimeShift = */ 0.0);

    synthesize(&s, &p);

    output.save(outputPath);
}
