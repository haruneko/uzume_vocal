// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#ifndef UZUME_VOCAL_SPECTROGRAM_REPOSITORY_HPP
#define UZUME_VOCAL_SPECTROGRAM_REPOSITORY_HPP

#include <string>

namespace uzume {
    namespace dsp {
        class Spectrogram;
    }
    namespace vocal {
        class SpectrtogramRepository {
        public:
            virtual ~SpectrtogramRepository() noexcept = default;

            virtual const uzume::dsp::Spectrogram *find(const std::string &id) const = 0;
        };
    }
}

#endif //UZUME_VOCAL_SPECTROGRAM_REPOSITORY_HPP
