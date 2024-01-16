// Regression tester for Ray Tracing Challenge
#include "gtest/gtest.h"
#include "tuples.h"
#include <cmath>

TEST(TupleTest, addTest)
{
    EXPECT_EQ(tuple(3, -2, 5, 1) + tuple(-2, 3, 1, 0), tuple(1, 1, 6, 1));
    EXPECT_EQ(vector(3, -2, 5) + point(-2, 3, 1), point(1, 1, 6));
    EXPECT_EQ(vector(3, -2, 5) + vector(-2, 3, 1), vector(1, 1, 6));
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
    EXPECT_EQ(point(3, 2, 1) - vector(5, 6, 7), point(-2, -4, -6));
}

TEST(TupleTest, subTest4) {
    EXPECT_EQ(vector(3, 2, 1) - vector(5, 6, 7), vector(-2, -4, -6));
}

TEST(TupleTest, subTest5) {
    EXPECT_EQ(vector(0, 0, 0) - vector(1, -2, 3), vector(-1, 2, -3));
}

TEST(TupleTest, negTest) {
    EXPECT_EQ( -vector(1, -2, 3), vector(-1, 2, -3));
    EXPECT_EQ( -tuple(1, -2, 3, -4), tuple(-1, 2, -3, 4));
    // Shouldn't negating a point work? (reflecion)
    // EXPECT_EQ( -point(1, -2, 3), point(-1, 2, -3));
}

TEST(TupleTest, mulTest) {
    EXPECT_EQ( 3.5 * tuple(1, -2, 3, -4), tuple(3.5, -7, 10.5, -14));
    EXPECT_EQ( tuple(1, -2, 3, -4) * 0.5, tuple(0.5, -1, 1.5, -2));
}

TEST(TupleTest, divTest) {
    EXPECT_EQ(tuple(1, -2, 3, -4) / 2, tuple(0.5, -1, 1.5, -2));
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
    EXPECT_EQ(normalize(vector(1, 2, 3)), vector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14)));
    EXPECT_EQ(magnitude(normalize(vector(1,2,3))), 1);
}

TEST(TupleTest, dotTest) {
    EXPECT_EQ(dot(vector(1, 2, 3), vector(2, 3, 4)), 20);
}


TEST(TupleTest, crossTest) {
    EXPECT_EQ(cross(vector(1,2,3), vector(2,3,4)), vector(-1, 2, -1));
    EXPECT_EQ(cross(vector(2,3,4), vector(1,2,3)), vector(1, -2, 1));
}
