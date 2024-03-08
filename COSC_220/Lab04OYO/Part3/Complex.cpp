#include <iostream>
#include <cstdlib>
#include "Complex.h"

using namespace std;

Complex::Complex(double r,double i)
{
  real = r;
  imag = i;
}

Complex::Complex(const Complex &obj)
{
  real = obj.real;
  imag = obj.imag;
}

Complex::~Complex()
{}

const double Complex::getReal()
{
  return real;
}


void Complex::setReal(double r)
{
  real=r;
}

double const Complex::getImag()
{
  return imag;
}

void Complex::setImag(double r)
{
  imag=r;
}

void Complex::set(double r ,double i)
{
  real=r;
  imag=i;
}

Complex Complex::operator+(const Complex &right)
{
  Complex temp(0,0);
  temp.setImag(imag+right.imag);
  temp.setReal(real+right.real);
  return temp;
}

Complex Complex::operator+(double right)
{
  Complex temp(0,0);
  temp.setImag(imag);
  temp.setReal(real+right);
  return temp;
}

  Complex operator + (double left,const Complex &right)
{
  Complex temp(0,0);
  temp.setImag(right.imag);
  temp.setReal(left+right.real);
  return temp;
}



Complex Complex::operator-(const Complex &right)
{
  Complex temp(0,0);
  temp.setImag(imag-right.imag);
  temp.setReal(real-right.real);
  return temp;
}

Complex Complex::operator-(double right)
{
  Complex temp(0,0);
  temp.setImag(imag);
  temp.setReal(real-right);
  return temp;
}

  Complex operator - (double left,const Complex &right)
{
  Complex temp(0,0);
  temp.setImag(right.imag);
  temp.setReal(left-right.real);
  return temp;
}


Complex Complex::operator*(const Complex &right)
{
  Complex temp(0,0);
  temp.setImag((imag*right.real)+(real*right.imag));
  temp.setReal((real*right.real)-(imag*right.imag));
  return temp;
}

Complex Complex::operator*(const double right)
{
  Complex temp(0,0);
  temp.setImag(imag*right);
  temp.setReal(real*right);
  return temp;
}


Complex operator * (double left,const Complex &right)
{
  Complex temp(0,0);
  temp.setImag(right.imag*left);
  temp.setReal(right.real*left);
  return temp;
}


Complex Complex::operator/(const double right)
{
  Complex temp(0,0);
  temp.setImag(imag/right);
  temp.setReal(real/right);
  return temp;
}


Complex Complex::operator/(const Complex &right)
{
  Complex temp(0,0);
  double deno = (right.real*right.real)+(right.imag*right.imag);
  temp.setImag((imag*right.imag)/deno);
  temp.setReal((imag*right.imag*-1)/deno);
  return temp;
}

Complex operator/(double left,const Complex &right)
{
  Complex temp(0,0);
  temp.setImag(left/right.imag);
  temp.setReal(left/right.real);
  return temp;
}

void Complex::operator+=(const Complex &right)
{
  set(real+right.real, imag+right.imag);
}

void Complex::operator-=(const Complex &right)
{
  set(real-right.real, imag-right.imag);
}

Complex Complex::operator^(int right)
{
  Complex temp(0,0);
  for(int i =1;i<right;i++)
    {
      temp.setImag((imag*real)+(real*imag));
      temp.setReal((real*real)-(imag*imag));
    }
  return temp;
}

bool Complex::operator == (const Complex &right)
{
  if(imag==right.imag&&real==right.real)
  {
    return true;
  }
  else{
    return false;
  }
}

bool Complex::operator != (const Complex &right)
{
  if(imag==right.imag&&real==right.real)
  {
    return false;
  }
  else{
    return true;
  }
}

const Complex Complex::operator=(const Complex &right)
{
  Complex temp(0,0);
  temp.set(right.real,right.imag);
  return temp;
}

double Complex::mod()
{
  return sqrt((real*real)+(imag*imag));
}

 ostream& operator << (ostream &out, const Complex &right)
{
  return out<<right.real<<" + "<<right.imag<<"i \n";
}


 istream& operator >> (istream &in, Complex &right)
{
  double temp1;
  double temp2;
  in>>right.real;
  in>>right.imag;
  //right.setReal(temp1);
  //right.setImag(temp2);
  return in;
}
