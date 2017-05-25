// Copyright 2017 Kiseleva Olga

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADREQUATIONCALC_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADREQUATIONCALC_H_


#include <map>
#include <string>
#include <vector>
#include "quadratic_equation.h"

class QuadrEquationCalc {
 public:
     QuadrEquationCalc();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double coeffA;
        double coeffB;
        double coeffC;
        char operation;
    } Arguments;
};

#endif  // MODULES_QUADRATIC_EQUATION_CALCULATOR_INCLUDE_QUADREQUATIONCALC_H_