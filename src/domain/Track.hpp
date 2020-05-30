// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#ifndef UZUME_VOCAL_TRACK_HPP
#define UZUME_VOCAL_TRACK_HPP

#include <vector>

#include "Expression.hpp"
#include "Piece.hpp"

namespace uzume {
    namespace vocal {
        class Track final {
        public:
            Track() = default;
            Track(Track &&rhs) noexcept;

            std::vector<Piece> pieces;

            Expression gender;
            Expression breathy;

            Expression f0;
        };
    }
}

#endif //UZUME_VOCAL_TRACK_HPP
