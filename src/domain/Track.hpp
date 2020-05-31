// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#ifndef UZUME_VOCAL_TRACK_HPP
#define UZUME_VOCAL_TRACK_HPP

#include <vector>

#include "Expression.hpp"
#include "Piece.hpp"
#include "SpectrumReference.hpp"

namespace uzume {
    namespace vocal {
        class Track final {
        public:
            Track() = default;

            Track(Track &&rhs) noexcept = default;

            double msLength() const;

            std::vector<SpectrumReference> at(double ms) const;

            std::string toString() const;

            Expression gender;
            Expression breathy;

            Expression f0;

            void insert(Piece p);
        private:
            std::vector<Piece> pieces;
        };
    }
}

#endif //UZUME_VOCAL_TRACK_HPP
