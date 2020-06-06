// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "Piece.hpp"

using namespace uzume::vocal;

Piece::Piece(SpectrogramReference reference, Expression dynamics, double msPosition)
        : reference(std::move(reference)), dynamics(std::move(dynamics)), msPosition(msPosition) {
}

SpectrumReference Piece::at(double ms) const {
    return SpectrumReference(
            reference.spectrogramId,
            reference.msSpectrogramPositionAt(ms - msPosition),
            dynamics.at((ms - msPosition) / reference.msLength));
}

double Piece::msLength() const {
    return reference.msLength;
}

double Piece::msEndPosition() const {
    return msPosition + msLength();
}

bool Piece::contains(double ms) const {
    return msPosition <= ms && ms <= msEndPosition();
}

std::string Piece::toString() const {
    return "uzume::vocal::Piece(" +
           reference.toString() + "," +
           dynamics.toString() + "," +
           std::to_string(msPosition) + ")";
}
