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
    // Preparation.
    // Create buffer, clear buffer and calculate gen and bre.
    uzume::dsp::Spectrum buffer(_fftSize);
    for (unsigned int i = 0; i < destination->fftSize; i++) {
        buffer.aperiodicSpectrum[i] = 0;
    }
    for (unsigned int i = 0; i < destination->fftSize; i++) {
        buffer.periodicSpectrum[i] = 0;
    }
    double gen = track->gender.at(ms);
    double bre = track->breathy.at(ms);

    // get Spectrum corresponding to spectrogram references.
    auto rs(track->at(ms));
    for (const auto &r: rs) {
        auto s = repository->find(r.spectrogramId);
        if (s == nullptr) continue;
        s->pickUpSpectrumAt(destination, r.msPosition);
        for (unsigned int i = 0; i < buffer.fftSize; i++) {
            buffer.aperiodicSpectrum[i] += fabs(destination->aperiodicSpectrum[i]) * r.dynRatio * bre;
        }
        for (unsigned int i = 0; i < destination->fftSize; i++) {
            buffer.periodicSpectrum[i] += destination->periodicSpectrum[i] * r.dynRatio;
        }
    }

    // stretch by gen;
    for(unsigned int i = 0; i < destination->fftSize; i++) {
        double floatIndex = i * gen;
        double interpolation = floatIndex - (int)floatIndex;
        unsigned int indexCeil = std::min((unsigned int)floatIndex, destination->fftSize - 1);
        unsigned int indexFloor = std::min((unsigned int)(indexCeil + 1), destination->fftSize - 1);;
        destination->periodicSpectrum[i] = buffer.periodicSpectrum[indexCeil] * (1 - interpolation) + buffer.periodicSpectrum[indexFloor];
        destination->aperiodicSpectrum[i] = buffer.aperiodicSpectrum[indexCeil] * (1 - interpolation) + buffer.aperiodicSpectrum[indexFloor];
    }
    return true;
}

double TrackSpectrogram::f0At(double ms) const {
    return track->f0.at(ms);
}
