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
        /**
         * Piece of a vocal track.
         */
        class Piece final {
        public:
            Piece() = default;

            Piece(Piece &&rhs) = default;

            Piece(SpectrogramReference reference, Expression dynamics, double msPosition);

            Piece &operator=(const Piece &rhs) = default;

            /**
             * at returns a spectrum at ms [milli seconds].
             */
            SpectrumReference at(double ms) const;

            /**
             * msLength returns a length in milli seconds.
             */
            double msLength() const;

            /**
             * msEndPosition is an end position of this piece.
             * This method simply returns (position + length).
             */
            double msEndPosition() const;

            bool contains(double ms) const;

            std::string toString() const;

            SpectrogramReference reference;
            Expression dynamics;
            double msPosition{ 0.0 };
        };
    }
}

#endif //UZUME_VOCAL_PIECE_HPP
