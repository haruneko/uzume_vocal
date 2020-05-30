// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "Piece.hpp"

using namespace uzume::vocal;

Piece::Piece(Piece &&other) noexcept
        : reference(std::move(other.reference)), dynamics(std::move(other.dynamics)), msPosition(other.msPosition) {
}

SpectrumReference Piece::at(double ms) const {
    return SpectrumReference(
            reference.spectrogramId,
            reference.msSpectrogramPositionAt(ms),
            dynamics.at((ms - msPosition) / reference.msLength));
}
