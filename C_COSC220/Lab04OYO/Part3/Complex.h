#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <math.h>

using namespace std;

class Complex {
  private:
    double real;  //  Real Part
    double imag;  //  Imaginary Part

  public:
    // Constructors and Destructor
    Complex(double a = 0, double b = 0);
    Complex(const Complex &obj);
    ~Complex();

    // Acessors and Mutators
    void setReal(double);
    const double getReal();
    void setImag(double);
    const double getImag();
    void set(double, double);

    // Overloaded operator functions
    Complex operator + (const Complex &);
    Complex operator + (double);
    friend Complex operator + (double, const Complex &);

    Complex operator - (const Complex &);
    Complex operator - (double);
    friend Complex operator - (double, const Complex &);

    Complex operator * (const Complex &);
    Complex operator * (double);
    friend Complex operator * (double, const Complex &);

    Complex operator / (const Complex &);
    Complex operator / (double);
    friend Complex operator / (double, const Complex &);

    void operator += (const Complex &);
    void operator -= (const Complex &);
    Complex operator ^ (int);

    bool operator == (const Complex &);
    bool operator != (const Complex &);

    const Complex operator=( const Complex &right);

    // Functions
    double mod();

    // Friend functions for streaming.
    friend ostream &operator << (ostream &,  const Complex &);
    friend istream &operator >> (istream &,  Complex &);
};

#endif
