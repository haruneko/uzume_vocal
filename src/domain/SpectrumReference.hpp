// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#ifndef UZUME_VOCAL_SPECTRUM_REFERENCE_HPP
#define UZUME_VOCAL_SPECTRUM_REFERENCE_HPP

#include <string>

namespace uzume {
    namespace vocal {
        class SpectrumReference final {
        public:
            SpectrumReference() = default;

            SpectrumReference(std::string id, double msPosition, double dynRatio);

            SpectrumReference(SpectrumReference &&rhs) noexcept;

            std::string spectrogramId;
            double msPosition{ 0.0 };
            double dynRatio{ 0.0 };
        };
    }
}

#endif //UZUME_VOCAL_SPECTRUM_REFERENCE_HPP
