#include "Vector3.hh"
#include "gtest/gtest.h"

#include <iostream>

using namespace testing;

TEST(TestVector3F, Constructors) {
  Vector3F v;
    
  EXPECT_FLOAT_EQ(v[0], 0);
  EXPECT_FLOAT_EQ(v[1], 0);
  EXPECT_FLOAT_EQ(v[2], 0);
    
  Vector3F u(1, 2, 3);
    
  EXPECT_FLOAT_EQ(u[0], 1);
  EXPECT_FLOAT_EQ(u[1], 2);
  EXPECT_FLOAT_EQ(u[2], 3);
}

TEST(TestVector3F, CompoundAssignment) {
  Vector3F v(1, 1, 1), u(0.5, 0.5, 0.5);
   
  v -= u;
    
  EXPECT_FLOAT_EQ(v[0], 0.5);
  EXPECT_FLOAT_EQ(v[1], 0.5);
  EXPECT_FLOAT_EQ(v[2], 0.5);
    
  v += u;
    
  EXPECT_FLOAT_EQ(v[0], 1);
  EXPECT_FLOAT_EQ(v[1], 1);
  EXPECT_FLOAT_EQ(v[2], 1);
}

TEST(TestVector3F, Arithmetic) {
  Vector3F v(1, 1, 1), u(0.5, 0.5, 0.5);

  Vector3F sum = v + u;

  EXPECT_FLOAT_EQ(sum[0], 1.5);
  EXPECT_FLOAT_EQ(sum[1], 1.5);
  EXPECT_FLOAT_EQ(sum[2], 1.5);

  Vector3F diff = v - u;
     
  EXPECT_FLOAT_EQ(diff[0], 0.5);
  EXPECT_FLOAT_EQ(diff[1], 0.5);
  EXPECT_FLOAT_EQ(diff[2], 0.5);
}

TEST(TestVector3F, ScalarOperations) {
  Vector3F v(1, 2, 3);

  Vector3F u = v * 2.0f;

  EXPECT_FLOAT_EQ(u[0], 2);
  EXPECT_FLOAT_EQ(u[1], 4);
  EXPECT_FLOAT_EQ(u[2], 6);

  u = v / 2.0f;

  EXPECT_FLOAT_EQ(u[0], 0.5);
  EXPECT_FLOAT_EQ(u[1], 1);
  EXPECT_FLOAT_EQ(u[2], 1.5);
}

TEST(TestVector3F, UnaryMinus) {
  Vector3F v(1, -2, 3), u;
    
  u = -v;
    
  EXPECT_FLOAT_EQ(u[0], -1);
  EXPECT_FLOAT_EQ(u[1],  2);
  EXPECT_FLOAT_EQ(u[2], -3);
}

TEST(TestVector3F, MagnitudeAndNormal) {
  Vector3F v(0, 3, 4);

  EXPECT_FLOAT_EQ(v.get_magnitude(), 5);

  v.normalize();

  EXPECT_FLOAT_EQ(v.get_magnitude(), 1);
}

TEST(TestVector3F, DotAndCross) {
  Vector3F v(1, 2, 3), u(2, 3, 4);

  EXPECT_FLOAT_EQ(v * u, 20);

  Vector3F cross_v = cross(v, u);

  EXPECT_FLOAT_EQ(cross_v[0], -1);
  EXPECT_FLOAT_EQ(cross_v[1], 2);
  EXPECT_FLOAT_EQ(cross_v[2], -1);
}

int main(int argc, char **argv) {
  InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

  

  

  
