#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;


class Complex {
private:
    double real;
    double imag;


public:
    Complex(double real, double imag) {
        this->real = real;
        this->imag = imag;
    }

    Complex() {
        real = 0;
        imag = 0;
    }

    double getReal() {
        return real;
    }

    double getImag() {
        return imag;
    }

    Complex operator+(Complex& other) {
        return Complex(real + other.getReal(), imag + other.getImag());
    }

    Complex operator-(Complex& other) {
        return Complex(real - other.getReal(), imag - other.getImag());
    }

    string toString() {
        return to_string(real) + " + " + to_string(imag) + "i";
    }

    friend ostream& operator<<(ostream& os, Complex& c) {
        os << c.toString();
        return os;
    }

    bool operator>(Complex& other) {
        if(real > other.getReal()) {
            return true;
        }
        if(real == other.getReal() && imag > other.getImag()) {
            return true;
        }
        return false;
    }

    bool operator<(Complex& other) {
        if(real < other.getReal()) {
            return true;
        } else if(real == other.getReal() && imag < other.getImag()) {
            return true;
        }
        return false;
    }





};
