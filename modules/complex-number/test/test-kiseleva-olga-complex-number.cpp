// Copyright 2017 Kiseleva Olga

#include <gtest/gtest.h>

#include <limits>

#include "include/complex_number.h"

TEST(Kiseleva_Olga_ComplexNumberTest, Can_Create_Not_Zero) {
    // Arrange
    double re = 1.5;
    double im = 9;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}
TEST(Kiseleva_Olga_ComplexNumberTest, Do_Throw_When_Division_By_Double_Min) {
    // Arrange
    double min = std::numeric_limits<double>::min();
    double re = 10.2;
    double im = -89.3;

    // Act
    ComplexNumber z1(min, min);
    ComplexNumber z2(re, im);

    // Assert
    EXPECT_ANY_THROW(z2 / z1);
}
TEST(Kiseleva_Olga_ComplexNumberTest,
    Number_Is_Equal_To_Itself_Different_By_Double_Min) {
    // Arrange
    double min = std::numeric_limits<double>::min();
    double re = -50.4;
    double im = 378.9;
    // Act
    ComplexNumber z1(min, min);
    ComplexNumber z2(re, im);
    ComplexNumber expected = z2 - z1;
    // Assert
    EXPECT_DOUBLE_EQ(re, expected.getRe());
    EXPECT_DOUBLE_EQ(im, expected.getIm());
}
TEST(Kiseleva_Olga_ComplexNumberTest,
    Number_Is_Zero_When_Multiplication_By_Double_Min) {
    // Arrange
    double min = std::numeric_limits<double>::min();
    double eps = std::numeric_limits<double>::epsilon();
    double re = 9874.65;
    double im = -1679.1;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(min, min);
    ComplexNumber expected = z1*z2;

    // Assert
    EXPECT_NEAR(expected.getIm(), 0.0, eps);
    EXPECT_NEAR(expected.getRe(), 0.0, eps);
}
TEST(Kiseleva_Olga_ComplexNumberTest, Number_Is_Zero_When_Division_From_Min) {
    // Arrange
    double min = std::numeric_limits<double>::min();
    double eps = std::numeric_limits<double>::epsilon();
    double re = -96432.1345;
    double im = 19876;

    // Act
    ComplexNumber z1(min, min);
    ComplexNumber z2(re, im);
    ComplexNumber expected = z1 / z2;

    // Assert
    EXPECT_NEAR(expected.getIm(), 0.0, eps);
    EXPECT_NEAR(expected.getRe(), 0.0, eps);
}
TEST(Kiseleva_Olga_ComplexNumberTest,
    Number_Is_Equal_To_Itself_Summary_By_Double_Min) {
    // Arrange
    double min = std::numeric_limits<double>::min();
    double re = 150.4;
    double im = -42301.32;
    // Act
    ComplexNumber z1(min, min);
    ComplexNumber z2(re, im);
    ComplexNumber expected = z2 + z1;
    // Assert
    EXPECT_DOUBLE_EQ(re, expected.getRe());
    EXPECT_DOUBLE_EQ(im, expected.getIm());
}

