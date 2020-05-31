// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "SpectrumReference.hpp"

using namespace uzume::vocal;

SpectrumReference::SpectrumReference(std::string id, double msPosition, double dyn)
        : spectrogramId(std::move(id)), msPosition(msPosition), dynRatio(dyn) {
}

std::string SpectrumReference::toString() const {
    return "uzume::vocal::SpectrumReference(" +
           spectrogramId + "," +
           std::to_string(msPosition) + "," +
           std::to_string(dynRatio) + ")";
}
