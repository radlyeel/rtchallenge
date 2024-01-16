// Regression tester for Ray Tracing Challenge
#include "gtest/gtest.h"
#include "tuples.h"
#include "canvas.h"
#include <cmath>

TEST(TupleTest, operators) {
    EXPECT_EQ(tuple(3, -2, 5, 1) + tuple(-2, 3, 1, 0), tuple(1, 1, 6, 1));
    EXPECT_EQ(vector(3, -2, 5) + point(-2, 3, 1), point(1, 1, 6));
    EXPECT_EQ(vector(3, -2, 5) + vector(-2, 3, 1), vector(1, 1, 6));

    EXPECT_EQ(point(3, 2, 1) - point(5, 6, 7), vector(-2, -4, -6));

    EXPECT_EQ(point(3, 2, 1) - vector(5, 6, 7), point(-2, -4, -6));

    EXPECT_EQ(point(3, 2, 1) - vector(5, 6, 7), point(-2, -4, -6));

    EXPECT_EQ(vector(3, 2, 1) - vector(5, 6, 7), vector(-2, -4, -6));

    EXPECT_EQ(vector(0, 0, 0) - vector(1, -2, 3), vector(-1, 2, -3));

    EXPECT_EQ( -vector(1, -2, 3), vector(-1, 2, -3));
    EXPECT_EQ( -tuple(1, -2, 3, -4), tuple(-1, 2, -3, 4));

    EXPECT_EQ( 3.5 * tuple(1, -2, 3, -4), tuple(3.5, -7, 10.5, -14));
    EXPECT_EQ( tuple(1, -2, 3, -4) * 0.5, tuple(0.5, -1, 1.5, -2));

    EXPECT_EQ(tuple(1, -2, 3, -4) / 2, tuple(0.5, -1, 1.5, -2));
 
    EXPECT_EQ(magnitude(vector(1, 0, 0)), 1);
    EXPECT_EQ(magnitude(vector(0, 1, 0)), 1);
    EXPECT_EQ(magnitude(vector(0, 0, 1)), 1);
    EXPECT_EQ(magnitude(vector(1, 2, 3)), sqrt(14));
    EXPECT_EQ(magnitude(vector(-1, -2, -3)), sqrt(14));
 
    EXPECT_EQ(normalize(vector(4, 0, 0)), vector(1, 0, 0));
    EXPECT_EQ(normalize(vector(1, 2, 3)), vector(1/sqrt(14), 2/sqrt(14), 3/sqrt(14)));
    EXPECT_EQ(magnitude(normalize(vector(1,2,3))), 1);

    EXPECT_EQ(dot(vector(1, 2, 3), vector(2, 3, 4)), 20);

    EXPECT_EQ(cross(vector(1,2,3), vector(2,3,4)), vector(-1, 2, -1));
    EXPECT_EQ(cross(vector(2,3,4), vector(1,2,3)), vector(1, -2, 1));
}

TEST(CanvasTest, colorTest) {
    color red(-0.5, 0.4, 1.7);
    EXPECT_EQ(red.red, -0.5);
    EXPECT_EQ(red.green, 0.4);
    EXPECT_EQ(red.blue, 1.7);
    EXPECT_EQ(red.blue, 1.7);
    EXPECT_EQ(color(0.9, 0.6, 0.75) + color(0.7, 0.1, 0.25), color(1.6, 0.7, 1.0));
    EXPECT_EQ(color(0.9, 0.6, 0.75) - color(0.7, 0.1, 0.25), color(0.2, 0.5, 0.5));
    EXPECT_EQ(color(0.2, 0.3, 0.4) * 2, color(0.4, 0.6, 0.8));
    EXPECT_EQ(2 * color(0.2, 0.3, 0.4), color(0.4, 0.6, 0.8));
    EXPECT_EQ(color(1, 0.2, 0.4) * color(0.9, 1, 0.1), color(0.9, 0.2, 0.04));
    canvas c(10, 20);
    int off_color = 0;
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 20; j++) {
            off_color += c.pixel_at(i,j) != color(0,0,0);
        }
    }
    EXPECT_EQ(off_color, 0);
    c.pixel_at(1,1) = color(1,1,1);
    EXPECT_EQ(c.pixel_at(1,1), color(1,1,1));


}
