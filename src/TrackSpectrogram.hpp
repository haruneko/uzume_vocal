// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#ifndef UZUME_VOCAL_TRACK_SPECTROGRAM_HPP
#define UZUME_VOCAL_TRACK_SPECTROGRAM_HPP

#include "Track.hpp"
#include "dsp/Spectrogram.hpp"
#include "SpectrogramRepository.hpp"

namespace uzume {
    namespace vocal {
        class TrackSpectrogram final : public uzume::dsp::Spectrogram {
        public:
            TrackSpectrogram() = delete;

            TrackSpectrogram(const Track *track, const SpectrtogramRepository *repository, unsigned int fftSize);

            bool pickUpSpectrumAt(uzume::dsp::Spectrum *destination, double ms) const override;

            double f0At(double ms) const override;

            double msLength() const override;

            unsigned int fftSize() const override;
        private:
            const Track *track;
            const SpectrtogramRepository *repository;
            unsigned int _fftSize;
        };
    }
}


#endif //UZUME_VOCAL_TRACK_SPECTROGRAM_HPP
