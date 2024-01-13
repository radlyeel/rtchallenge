// Regression tester for Ray Tracing Challenge
#include "gtest/gtest.h"
#include "tuples.h"

class TupleTest : public testing::Test {
protected:
    void SetUp() override {
        p = { -4, 4, 3};
        v = { -4, 4, 3};
        v2 = { 2, 2, 1};
        sum = p + v;
        diff = v - v2 ;

    }

    point p;
    vector v, v2;
    point sum;
    vector diff;
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
    EXPECT_EQ(sum, point(-8, 8, 6));
    EXPECT_EQ(diff, vector(-6, 2, 2));

}
