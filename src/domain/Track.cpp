// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "Track.hpp"

using namespace uzume::vocal;

Track::Track(Track &&rhs) noexcept
        : pieces(std::move(rhs.pieces)),
          gender(std::move(rhs.gender)),
          breathy(std::move(rhs.breathy)),
          f0(std::move(rhs.f0)) {
}
