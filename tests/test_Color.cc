#include "Color.cc"
#include "gtest/gtest.h"

#include <iostream>

using namespace testing;

TEST(TestColor, Constructors) {
  Color c1;
    
  EXPECT_FLOAT_EQ(c1.get_red()  , 0);
  EXPECT_FLOAT_EQ(c1.get_green(), 0);
  EXPECT_FLOAT_EQ(c1.get_blue() , 0);
    
  Color c2 (0.2, 0.3, 0.5);
    
  EXPECT_FLOAT_EQ(c2.get_red()  , 0.2);
  EXPECT_FLOAT_EQ(c2.get_green(), 0.3);
  EXPECT_FLOAT_EQ(c2.get_blue() , 0.5);
}

TEST(TestColor, CompoundAssignment) {
  Color c1(0.3, 0.1, 0.7), c2;

  c1 -= c2;
    
  EXPECT_FLOAT_EQ(c1.get_red(), 0.3);
  EXPECT_FLOAT_EQ(c1.get_green(), 0.1);
  EXPECT_FLOAT_EQ(c1.get_blue(), 0.7);
  
  c2 = Color(0.1, 0.1, 0.1);

  c1 += c2;
    
  EXPECT_FLOAT_EQ(c1.get_red()  , 0.4);
  EXPECT_FLOAT_EQ(c1.get_green(), 0.2);
  EXPECT_FLOAT_EQ(c1.get_blue() , 0.8);
}

TEST(TestColor, Arithmetic) {
  Color c1(0.3, 0.1, 0.7), c2;
    
  Color c3 = c1 + c2;
    
  EXPECT_FLOAT_EQ(c3.get_red(), 0.3);
  EXPECT_FLOAT_EQ(c3.get_green(), 0.1);
  EXPECT_FLOAT_EQ(c3.get_blue(), 0.7);
}
TEST(TestColor, Scalar) {
  Color c1(0.2, 0.1, 0.7);

  Color c2 = 3.0f * c1;
  Color c3 = c2 / 3.0f;
    
  EXPECT_FLOAT_EQ(c2.get_red()  , 0.6);
  EXPECT_FLOAT_EQ(c2.get_green(), 0.3);
  EXPECT_FLOAT_EQ(c2.get_blue() , 2.1);
    
  EXPECT_FLOAT_EQ(c3.get_red()  , c1.get_red());
  EXPECT_FLOAT_EQ(c3.get_green(), c1.get_green());
  EXPECT_FLOAT_EQ(c3.get_blue() , c1.get_blue());
}


int main(int argc, char **argv) {
  InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
