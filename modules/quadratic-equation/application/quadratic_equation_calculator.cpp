// Copyright 2017 Kiseleva Olga

#include "include/quadratic_eq_app.h"

#include <iostream>
// #include <map>
#include <string>

int main(int argc, const char** argv) {
    QuadrEquationCalc app;
    std::string output = app(argc, argv);
    std::cout << output.c_str() << std::endl;
    system("pause");
    return 0;
}
