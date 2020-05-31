// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "gtest/gtest.h"
#include "domain/SpectrogramReference.hpp"

class SpectrogramReferenceTest : public ::testing::Test {
protected:
    virtual void setUp() {
    }
};

TEST_F(SpectrogramReferenceTest, msSpectrogramPositionAt) {
    uzume::vocal::SpectrogramReference sut("id", 1000.0, 500.0, 1000.0);

    EXPECT_DOUBLE_EQ(sut.msSpectrogramPositionAt(0.0), 500.0);
    EXPECT_DOUBLE_EQ(sut.msSpectrogramPositionAt(250.0), 625.0);
    EXPECT_DOUBLE_EQ(sut.msSpectrogramPositionAt(500.0), 750.0);
    EXPECT_DOUBLE_EQ(sut.msSpectrogramPositionAt(750.0), 875.0);
    EXPECT_DOUBLE_EQ(sut.msSpectrogramPositionAt(1000.0), 1000.0);
}
