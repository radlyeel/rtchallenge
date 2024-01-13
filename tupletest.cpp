// Regression tester for Ray Tracing Challenge
#include "gtest/gtest.h"
#include "tuples.h"

class TupleTest : public testing::Test {
protected:
    void SetUp() override {
        p = { -4, 4, 3};
        v = { -4, 4, 3};
    }

    point p;
    vector v;
};

TEST_F(TupleTest, myTupleTest)
{
    EXPECT_EQ(p.w, 1);	
    EXPECT_EQ(v.w, 0);	
    EXPECT_EQ(p.x, -4);	
    EXPECT_EQ(v.x, -4);	
    EXPECT_EQ(p.y, 4);	
    EXPECT_EQ(v.y, 4);	
    EXPECT_EQ(p.z, 3);	
    EXPECT_EQ(v.z, 3);	
    EXPECT_NE(p, v);
}
