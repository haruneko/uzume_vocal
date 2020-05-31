// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#ifndef UZUME_VOCAL_SPECTROGRAM_REFERENCE_HPP
#define UZUME_VOCAL_SPECTROGRAM_REFERENCE_HPP

#include <string>
#include "SpectrumReference.hpp"

namespace uzume {
    namespace vocal {
        /**
         * SpectrogramReference represents a reference to some spectrogram,
         * This class contains not only the reference but also `cut out` and `stretch` of the spectrogram.
         */
        class SpectrogramReference {
        public:
            SpectrogramReference() = default;

            SpectrogramReference(std::string id, double msLength, double msStartPosition, double msEndPosition);

            SpectrogramReference(SpectrogramReference &&rhs) noexcept = default;

            SpectrogramReference &operator=(const SpectrogramReference &rhs) = default;

            /**
             * msSpectrogramPositionAt calculates corresponding position in a spectrogram.
             */
            double msSpectrogramPositionAt(double ms) const;

            std::string toString() const;

            std::string spectrogramId;
            double msLength{0.0};
            double msStartPosition{0.0};
            double msEndPosition{0.0};
        };

    }
}

#endif //UZUME_VOCAL_SPECTROGRAM_REFERENCE_HPP
