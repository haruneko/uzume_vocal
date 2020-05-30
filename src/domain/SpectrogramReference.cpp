// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include "SpectrogramReference.hpp"

using namespace uzume::vocal;

SpectrogramReference::SpectrogramReference(SpectrogramReference &&rhs) noexcept
        : SpectrogramReference(rhs.spectrogramId, rhs.msLength, rhs.msStartPosition, rhs.msEndPosition) {
}

SpectrogramReference::SpectrogramReference(std::string id, double msLength, double msStartPosition,
                                           double msEndPosition)
        : spectrogramId(std::move(id)), msLength(msLength), msStartPosition(msStartPosition),
          msEndPosition(msEndPosition) {
}

double SpectrogramReference::msSpectrogramPositionAt(double ms) const {
    double relativePosition = ms / msLength;
    return msStartPosition + (msEndPosition - msStartPosition) * relativePosition;
}
