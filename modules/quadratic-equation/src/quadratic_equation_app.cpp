// Copyright 2017 Kiseleva Olga

#include "include/quadratic_equation.h"
#include "include/quadratic_equation_app.h"

#include <string>

#include <sstream>

QuadraticEquationCalculator::QuadraticEquationCalculator() : message_("") {}

void QuadraticEquationCalculator::Help(const char* appname,
    const char* message) {
    message_ =
        std::string(message) +
        "This is a quadratic equation application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <coefficient a> <coefficient b> " +
        "<coefficient c> <operation>\n\n" +

        "Where the first,the second and  the third  arguments " +
        "aren't equals zero number \n" +
        "<operation> is one of 'num' which returns count of real solution," +
        "'sol' returns solution\n";
}

bool QuadraticEquationCalculator::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    }
    else if (argc != 5) {
        Help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

double parseCoefficient(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0] || value == 0) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "num") == 0) {
        op = 'n';
    }
    else if (strcmp(arg, "sol") == 0) {
        op = 's';
    }
    else {
        throw std::string("Wrong operation format!");
    }
    return op;

}


std::string QuadraticEquationCalculator::operator()
(int argc, const char** argv) {
    Arguments args;
    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.coeffA = parseCoefficient(argv[1]);
        args.coeffB = parseCoefficient(argv[2]);
        args.coeffC = parseCoefficient(argv[3]);
        args.operation = parseOperation(argv[4]);
    }
    catch (std::string& str) {
        return str;
    }

    QuadraticEquation quadratic_eq(args.coeffA, args.coeffB, args.coeffC);

    std::ostringstream stream;
    int countSolution = quadratic_eq.NumOfRealSolutions();

    switch (args.operation) {
    case 'n':
        stream << "Count of solutions = " << countSolution << " ";
        break;
    case 's':
        switch (countSolution)
        {
        case 0:
            stream << "x1  = " << quadratic_eq.GetComplexX1().getRe() <<
                "+" << quadratic_eq.GetComplexX1().getIm() << "i ";
            stream << "x2  = " << quadratic_eq.GetComplexX2().getRe() <<
                quadratic_eq.GetComplexX2().getIm() << "i ";
            break;
        case 1:
            stream << "x = " << quadratic_eq.GetRealX1();
            break;
        case 2:
            stream << "x1 = " << quadratic_eq.GetRealX1() << " ";
            stream << "x2 = " << quadratic_eq.GetRealX2();
            break;
        }
    }
    message_ = stream.str();
    return message_;
}

