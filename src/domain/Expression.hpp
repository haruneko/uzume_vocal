// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.
#ifndef UZUME_VOCAL_EXPRESSION_HPP
#define UZUME_VOCAL_EXPRESSION_HPP

#include <vector>

namespace uzume {
    namespace vocal {
        struct ExpressionEvent final {
            double position;
            double value;
        };

        class Expression final {
        public:
            Expression();

            Expression(Expression &&rhs) noexcept;

            double at(double position) const;

            void insert(double position, double value);

            void deleteBetween(double begin, double end);

            std::vector<ExpressionEvent> events;
        };
    }
}

#endif //UZUME_VOCAL_EXPRESSION_HPP
