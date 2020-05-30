// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "TrackSpectrogram.hpp"

using namespace uzume::vocal;

double TrackSpectrogram::msLength() const {
    ???
}

unsigned int TrackSpectrogram::fftSize() const {
    ???
}

bool TrackSpectrogram::pickUpSpectrumAt(uzume::dsp::Spectrum *destination, double ms) const {

}

double TrackSpectrogram::f0At(double ms) const {
    return track->f0.at(ms);
}
