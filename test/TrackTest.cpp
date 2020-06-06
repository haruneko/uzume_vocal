// Copyright 2020 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include "gtest/gtest.h"
#include "Track.hpp"

using namespace uzume::vocal;

class TrackTest : public ::testing::Test {
protected:
    virtual void setUp() {
    }
};

TEST_F(TrackTest, InsertAndAt) {
    Track sut;
    for (int i = -10; i <= 10; i++) {
        EXPECT_TRUE(sut.at(i * 100.0).empty());
    }

    sut.insert(Piece(SpectrogramReference("id1", 1000.0, 500.0, 1000.0), Expression(), 0.0));
    sut.insert(Piece(SpectrogramReference("id2", 1000.0, 0.0, 500.0), Expression(), 500.0));
    sut.insert(Piece(SpectrogramReference("id3", 250.0, 0.0, 500.0), Expression(), 750.0));

    auto v1 = sut.at(250.0);
    EXPECT_EQ(v1.size(), 1);
    EXPECT_DOUBLE_EQ(v1[0].dynRatio, 1.0);
    EXPECT_DOUBLE_EQ(v1[0].msPosition, 625.0);
    EXPECT_EQ(v1[0].spectrogramId, "id1");

    auto v2 = sut.at(625.0);
    EXPECT_EQ(v2.size(), 2);
    EXPECT_DOUBLE_EQ(v2[0].dynRatio, 1.0);
    EXPECT_DOUBLE_EQ(v2[0].msPosition, 812.5);
    EXPECT_EQ(v2[0].spectrogramId, "id1");
    EXPECT_DOUBLE_EQ(v2[1].dynRatio, 1.0);
    EXPECT_DOUBLE_EQ(v2[1].msPosition, 62.5);
    EXPECT_EQ(v2[1].spectrogramId, "id2");

    auto v3 = sut.at(750.0);
    EXPECT_EQ(v3.size(), 3);
    EXPECT_DOUBLE_EQ(v3[0].dynRatio, 1.0);
    EXPECT_DOUBLE_EQ(v3[0].msPosition, 875);
    EXPECT_EQ(v3[0].spectrogramId, "id1");
    EXPECT_DOUBLE_EQ(v3[1].dynRatio, 1.0);
    EXPECT_DOUBLE_EQ(v3[1].msPosition, 125.0);
    EXPECT_EQ(v3[1].spectrogramId, "id2");
    EXPECT_DOUBLE_EQ(v3[2].dynRatio, 1.0);
    EXPECT_DOUBLE_EQ(v3[2].msPosition, 0.0);
    EXPECT_EQ(v3[2].spectrogramId, "id3");

    auto v4 = sut.at(1250.0);
    EXPECT_EQ(v4.size(), 1);
    EXPECT_DOUBLE_EQ(v4[0].dynRatio, 1.0);
    EXPECT_DOUBLE_EQ(v4[0].msPosition, 375.0);
    EXPECT_EQ(v4[0].spectrogramId, "id2");
}
