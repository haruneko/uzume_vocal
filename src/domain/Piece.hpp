// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#ifndef UZUME_VOCAL_PIECE_HPP
#define UZUME_VOCAL_PIECE_HPP

#include "Expression.hpp"
#include "SpectrogramReference.hpp"
#include "SpectrumReference.hpp"

namespace uzume {
    namespace vocal {
        class Piece final {
        public:
            Piece() = default;

            Piece(Piece &&other) noexcept;

            SpectrumReference at(double ms) const;

            SpectrogramReference reference;
            Expression dynamics;
            double msPosition{ 0.0 };
        };
    }
}

#endif //UZUME_VOCAL_PIECE_HPP
