// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#include <algorithm>
#include "Track.hpp"

using namespace uzume::vocal;

double Track::msLength() const {
    double res = 0.0;
    for (const auto &piece : pieces) {
        res = std::max(res, piece.msEndPosition());
    }
    return res;
}

std::vector<SpectrumReference> Track::at(double ms) const {
    std::vector<SpectrumReference> res;
    auto i(std::find_if(pieces.begin(), pieces.end(), [ms](const Piece &p) { return p.contains(ms); }));
    for (; i != pieces.end(); i++) {
        res.emplace_back(i->at(ms));
    }
    return res;
}

void Track::insert(Piece p) {
    double ms = p.msPosition;
    auto i(std::find_if(pieces.begin(), pieces.end(), [ms](const Piece &e) { return e.msPosition <= ms; }));
    if (i == pieces.end()) {
        pieces.emplace_back(std::move(p));
    } else {
        pieces.emplace(i, std::move(p.reference), std::move(p.dynamics), p.msPosition);
    }
}
