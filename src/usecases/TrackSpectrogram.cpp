// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include <cmath>
#include "TrackSpectrogram.hpp"

using namespace uzume::vocal;

TrackSpectrogram::TrackSpectrogram(const Track *track, const SpectrtogramRepository *repository, unsigned int fftSize)
        : track(track), repository(repository), _fftSize(fftSize) {
}

double TrackSpectrogram::msLength() const {
    return track->msLength();
}

unsigned int TrackSpectrogram::fftSize() const {
    return _fftSize;
}

bool TrackSpectrogram::pickUpSpectrumAt(uzume::dsp::Spectrum *destination, double ms) const {
    uzume::dsp::Spectrum buffer(_fftSize);
    for (unsigned int i = 0; i < destination->fftSize; i++) {
        destination->aperiodicSpectrum[i] = 0;
    }
    for (unsigned int i = 0; i < destination->fftSize; i++) {
        destination->periodicSpectrum[i] = 0;
    }
    auto rs(track->at(ms));
    for (const auto &r: rs) {
        auto s = repository->find(r.spectrogramId);
        if (s == nullptr) continue;
        s->pickUpSpectrumAt(&buffer, r.msPosition);
        for (unsigned int i = 0; i < destination->fftSize; i++) {
            destination->aperiodicSpectrum[i] += fabs(buffer.aperiodicSpectrum[i]) * r.dynRatio;
        }
        for (unsigned int i = 0; i < destination->fftSize; i++) {
            destination->periodicSpectrum[i] += buffer.periodicSpectrum[i] * r.dynRatio;
        }
    }
    return true;
}

double TrackSpectrogram::f0At(double ms) const {
    return track->f0.at(ms);
}
