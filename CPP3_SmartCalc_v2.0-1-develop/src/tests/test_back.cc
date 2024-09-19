#include <gtest/gtest.h>

#include "../controller/calc_controler.h"

TEST(back, test_case_1) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "(1+1)";
  call.setStr(&str);
  EXPECT_EQ(1, call.valid());
  EXPECT_EQ(2.0, call.result());
}

TEST(back, test_case_2) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "(2*(3+4))/5";
  call.setStr(&str);
  EXPECT_EQ(1, call.valid());
  EXPECT_EQ(2.8, call.result());
}

TEST(back, test_case_3) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "sqrt(9)";
  call.setStr(&str);
  EXPECT_EQ(1, call.valid());
  EXPECT_EQ(3.0, call.result());
}

TEST(back, test_case_4) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "0.1+0.2";
  call.setStr(&str);
  EXPECT_EQ(1, call.valid());
  EXPECT_NEAR(0.3, call.result(), 1e-6);
}

TEST(back, test_case_5) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "1+2-3+4*5/6^7";
  call.setStr(&str);
  EXPECT_EQ(1, call.valid());
  EXPECT_NEAR(0.0000714449, call.result(),
              1e-6);  
}

TEST(back, test_case_6) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "5.43498^3-323*2/(sin(3))*1";
  call.setStr(&str);
  EXPECT_EQ(1, call.valid());
  EXPECT_NEAR(-4417.12022212, call.result(),
              1e-7); 
}

TEST(back, test_case_7) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "34/38472+(2*(3^3)%3)-100+sin(121*3-3)+cos(3)+tan(3)+3^3";
  call.setStr(&str);
  EXPECT_EQ(1, call.valid());
  EXPECT_NEAR(-73.1727395566, call.result(),
              1e-7); 
}

TEST(back, test_case_8) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str =
      "sqrt(34/38472+(2*(3^3)%3)-100+sin(121*3-3)+cos(3)+tan(3)+3^3*234/"
      "3482*(345873/(23^(3/3%2))))";
  call.setStr(&str);
  EXPECT_EQ(1, call.valid());
  EXPECT_NEAR(164.881214814, call.result(),
              1e-7);  
}
TEST(back, test_case_9) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str =
      "sqrt(34/38472+(2*(3^3)%3)-100+sin(121*3-3)+cos(3)+tan(3)+3^3*234/"
      "3482*(345873/(23^(3/3%2))))*sqrt(34/"
      "38472+(2*(3^3)%3)-100+sin(121*3-3)+cos(3)+tan(3)+3^3*234/3482*(345873/"
      "(23^(3/3%2))))/sqrt(34/"
      "38472+(2*(3^3)%3)-100+sin(121*3-3)+cos(3)+tan(3)+3^3*234/3482*(345873/"
      "(23^(3/3%2))))";
  call.setStr(&str);
  EXPECT_EQ(1, call.valid());
  EXPECT_NEAR(164.881214814, call.result(),
              1e-7);  
}

TEST(back, test_case_10) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "(atan(atan(-1)))";
  call.setStr(&str);
  EXPECT_EQ(1, call.valid());
  EXPECT_NEAR(-0.665773750028, call.result(), 1e-7);
}

TEST(back, test_case_11) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "cos(acos(-1))";
  call.setStr(&str);
  EXPECT_EQ(1, call.valid());
  EXPECT_NEAR(-1, call.result(), 1e-7);
}
TEST(back, test_case_12) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "sin(asin(-1))";
  call.setStr(&str);
  EXPECT_EQ(1, call.valid());
  EXPECT_NEAR(-1, call.result(), 1e-7);
}
TEST(back, test_case_13) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "ln(log(ln(12)))";
  call.setStr(&str);
  EXPECT_EQ(1, call.valid());
  EXPECT_NEAR(-0.92808481372, call.result(), 1e-7);
}
TEST(back, test_case_14) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "()";
  call.setStr(&str);
  EXPECT_EQ(0, call.valid());
}

TEST(back, test_case_15) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "))";
  call.setStr(&str);
  EXPECT_EQ(0, call.valid());
}

TEST(back, test_case_16) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "---";
  call.setStr(&str);
  EXPECT_EQ(0, call.valid());
}

TEST(back, test_case_17) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "1e-10+1e+1+2e-4";
  call.setStr(&str);
  EXPECT_NEAR(10.0002, call.result(), 1e-7);
}

TEST(back, test_case_18) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "-1";
  call.setStr(&str);
  EXPECT_NEAR(-1, call.result(), 1e-7);
}

TEST(back, test_case_19) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = ".(";
  call.setStr(&str);
  EXPECT_EQ(0, call.valid());
}
TEST(back, test_case_20) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "e/";
  call.setStr(&str);
  EXPECT_EQ(0, call.valid());
}

TEST(back, test_case_21) {
  s21::BackEnd bck;
  s21::calcControler call(&bck);
  std::string str = "(/";
  call.setStr(&str);
  EXPECT_EQ(0, call.valid());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
};
