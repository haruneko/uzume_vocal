// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#ifndef UZUME_VOCAL_SPECTROGRAM_REFERENCE_HPP
#define UZUME_VOCAL_SPECTROGRAM_REFERENCE_HPP

#include <string>

namespace uzume {
    namespace vocal {
        class SpectrogramReference {
        public:
            SpectrogramReference() = default;

            SpectrogramReference(std::string id, double msLength, double msStartPosition, double msEndPosition);

            SpectrogramReference(SpectrogramReference &&rhs) noexcept;

            double msSpectrogramPositionAt(double ms) const;

            std::string spectrogramId;
            double msLength{0.0};
            double msStartPosition{0.0};
            double msEndPosition{0.0};
        };

    }
}

#endif //UZUME_VOCAL_SPECTROGRAM_REFERENCE_HPP
