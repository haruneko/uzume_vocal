// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "gtest/gtest.h"

#include "domain/Expression.hpp"

class ExpressionTest : public ::testing::Test {
protected:
    virtual void setUp()  {
    }
};

TEST_F(ExpressionTest, InitialValue) {
    uzume::vocal::Expression sut;

    for (int i = -10; i <= 10; i++) {
        EXPECT_DOUBLE_EQ(sut.at((double)i), 1.0);
    }

    sut.insert(0.0, 10.0);
    for (int i = -10; i <= 10; i++) {
        EXPECT_DOUBLE_EQ(sut.at((double)i), 10.0);
    }
}

TEST_F(ExpressionTest, InsertAndDelete) {
    uzume::vocal::Expression sut;

    sut.insert(0.0, 0.0);
    sut.insert(1.0, 2.0);
    sut.insert(2.0, 3.0);
    sut.insert(3.0, 3.5);

    EXPECT_DOUBLE_EQ(sut.at(-0.5), 0.0);
    EXPECT_DOUBLE_EQ(sut.at(0.0), 0.0);
    EXPECT_DOUBLE_EQ(sut.at(0.5), 1.0);
    EXPECT_DOUBLE_EQ(sut.at(1.0), 2.0);
    EXPECT_DOUBLE_EQ(sut.at(1.5), 2.5);
    EXPECT_DOUBLE_EQ(sut.at(2.0), 3.0);
    EXPECT_DOUBLE_EQ(sut.at(2.5), 3.25);
    EXPECT_DOUBLE_EQ(sut.at(3.0), 3.5);
    EXPECT_DOUBLE_EQ(sut.at(3.5), 3.5);

    sut.deleteBetween(1.0, 2.0);

    EXPECT_DOUBLE_EQ(sut.at(-0.5), 0.0);
    EXPECT_DOUBLE_EQ(sut.at(0.0), 0.0);
    EXPECT_DOUBLE_EQ(sut.at(0.5), 3.5 * 0.5 / 3.0);
    EXPECT_DOUBLE_EQ(sut.at(1.0), 3.5 * 1.0 / 3.0);
    EXPECT_DOUBLE_EQ(sut.at(1.5), 3.5 * 1.5 / 3.0);
    EXPECT_DOUBLE_EQ(sut.at(2.0), 3.5 * 2.0 / 3.0);
    EXPECT_DOUBLE_EQ(sut.at(2.5), 3.5 * 2.5 / 3.0);
    EXPECT_DOUBLE_EQ(sut.at(3.0), 3.5 * 3.0 / 3.0);
    EXPECT_DOUBLE_EQ(sut.at(3.5), 3.5);
}
