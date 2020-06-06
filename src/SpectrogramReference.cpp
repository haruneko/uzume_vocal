// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "SpectrogramReference.hpp"

using namespace uzume::vocal;

SpectrogramReference::SpectrogramReference(std::string id, double msLength, double msStartPosition,
                                           double msEndPosition)
        : spectrogramId(std::move(id)), msLength(msLength), msStartPosition(msStartPosition),
          msEndPosition(msEndPosition) {
}

double SpectrogramReference::msSpectrogramPositionAt(double ms) const {
    double relativePosition = ms / msLength;
    return msStartPosition + (msEndPosition - msStartPosition) * relativePosition;
}

std::string SpectrogramReference::toString() const {
    return "uzume::vocal::SpectrogramReference(" +
           spectrogramId + "," +
           std::to_string(msLength) + "," +
           std::to_string(msStartPosition) + "," +
           std::to_string(msEndPosition) + ")";
}
