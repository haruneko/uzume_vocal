// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "dsp/Spectrogram.hpp"

#include "SpectrogramNaiveRepository.hpp"

using namespace uzume::vocal;

SpectrogramNaiveRepository::~SpectrogramNaiveRepository() noexcept {
    for(auto &p: spectrograms) {
        delete p.second;
    }
}

void SpectrogramNaiveRepository::append(const std::string &id, uzume::dsp::Spectrogram *spectrogram) {
    erase(id);
    spectrograms[id] = spectrogram;
}

void SpectrogramNaiveRepository::erase(const std::string &id) {
    auto i(spectrograms.find(id));
    if (i != spectrograms.end()) {
        delete i->second;
        spectrograms.erase(i);
    }
}

const uzume::dsp::Spectrogram *SpectrogramNaiveRepository::find(const std::string &id) const {
    auto i(spectrograms.find(id));
    if (i == spectrograms.end()) {
        return nullptr;
    } else {
        return i->second;
    }
}
