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

        /**
         * Expression represents an envelope, such as DYN, GEN, BRE and so on.
         */
        class Expression final {
        public:
            Expression();

            Expression(std::vector<ExpressionEvent> events);

            Expression(Expression &&rhs) noexcept = default;

            Expression &operator=(const Expression &rhs) = default;

            /**
             * at returns a value at position.
             */
            double at(double position) const;

            /**
             * insert an value change event on a position
             */
            void insert(double position, double value);

            /**
             * deleteBetween deletes events between begin and end.
             */
            void deleteBetween(double begin, double end);
        private:
            std::vector<ExpressionEvent> events;
        };
    }
}

#endif //UZUME_VOCAL_EXPRESSION_HPP
