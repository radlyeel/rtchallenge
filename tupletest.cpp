// Regression tester for Ray Tracing Challenge
#include "gtest/gtest.h"
#include "tuples.h"
#include <cmath>

TEST(TupleTest, addTest)
{
    EXPECT_EQ(tuple(3, -2, 5, 1) + tuple(-2, 3, 1, 0), tuple(1, 1, 6, 1));
}

TEST(TupleTest, subTest1)
{
    EXPECT_EQ(point(3, 2, 1) - point(5, 6, 7), vector(-2, -4, -6));
}

TEST(TupleTest, subTest2)
{
    EXPECT_EQ(point(3, 2, 1) - vector(5, 6, 7), point(-2, -4, -6));
}

TEST(TupleTest, subTest3) {
    EXPECT_EQ(vector(3, 2, 1) - vector(5, 6, 7), vector(-2, -4, -6));
}

TEST(TupleTest, negTest) {
    EXPECT_EQ( -vector(1, -2, 3), vector(-1, 2, -3));
    EXPECT_EQ( -point(1, -2, 3), point(-1, 2, -3));
}

TEST(TupleTest, mulTest) {
    EXPECT_EQ( 3.5 * vector(1, -2, 3), vector(3.5, -7.0, 10.5));
    EXPECT_EQ( vector(1, -2, 3) * 3.5, vector(3.5, -7.0, 10.5));
}

TEST(TupleTest, divTest) {
    vector v = vector(3.5, -7.0, 10.5) / 3.5; 
    EXPECT_EQ(v, vector(1, -2, 3));
}

 
TEST(TupleTest, magTest) {
    EXPECT_EQ(magnitude(vector(1, 0, 0)), 1);
    EXPECT_EQ(magnitude(vector(0, 1, 0)), 1);
    EXPECT_EQ(magnitude(vector(0, 0, 1)), 1);
    EXPECT_EQ(magnitude(vector(1, 2, 3)), sqrt(14));
    EXPECT_EQ(magnitude(vector(-1, -2, -3)), sqrt(14));
}
 
TEST(TupleTest, normTest) {
    EXPECT_EQ(normalize(vector(4, 0, 0)), vector(1, 0, 0));
    EXPECT_EQ(normalize(vector(0, 4, 0)), vector(0, 1, 0));
    EXPECT_EQ(normalize(vector(0, 0, 1)), vector(0, 0, 1));
    EXPECT_EQ(normalize(vector(1, 2, 3)), vector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14)));
}

