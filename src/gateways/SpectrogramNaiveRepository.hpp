// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#ifndef UZUME_VOCAL_SPECTROGRAM_NAIVE_REPOSITORY_HPP
#define UZUME_VOCAL_SPECTROGRAM_NAIVE_REPOSITORY_HPP
#include <unordered_map>

#include "SpectrogramRepository.hpp"

namespace uzume {
    namespace dsp {
        class Spectrogram;
    }
    namespace vocal {
        class SpectrogramNaiveRepository final : public SpectrtogramRepository {
        public:
            ~SpectrogramNaiveRepository() noexcept override;

            const uzume::dsp::Spectrogram *find(const std::string &id) const override;

            void append(const std::string &id, uzume::dsp::Spectrogram *spectrogram);

            void erase(const std::string &id);
        private:
            std::unordered_map<std::string, uzume::dsp::Spectrogram*> spectrograms;
        };
    }
}


#endif //UZUME_VOCAL_SPECTROGRAM_NAIVE_REPOSITORY_HPP
