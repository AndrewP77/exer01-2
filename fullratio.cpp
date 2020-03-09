#include <iostream>
#ifndef CONTEST
#include "fullratio.hpp"
#endif
using namespace std;

rational::rational (int n, int d) {
  nom=n; den=d;
}

rational operator + (const rational &x, const rational &y) {
  int gcd=rational::gcd(x.nom*y.den+y.nom*x.den, x.den*y.den);
  return rational ((x.nom*y.den+y.nom*x.den)/gcd, (x.den*y.den)/gcd);
}

rational operator - (const rational &x, const rational &y) {
  int gcd=rational::gcd(x.nom*y.den-y.nom*x.den, x.den*y.den);
  return rational ((x.nom*y.den-y.nom*x.den)/gcd, (x.den*y.den)/gcd);
}

rational operator * (const rational &x, const rational &y) {
  int gcd=rational::gcd(x.nom*y.nom, x.den*y.den);
  return rational ((x.nom*y.nom)/gcd, (x.den*y.den)/gcd);
}

rational operator / (const rational &x, const rational &y) {
  int gcd=rational::gcd(x.nom*y.den, x.den*y.nom);
  return rational ((x.nom*y.den)/gcd, (x.den*y.nom)/gcd);
}

std::ostream & operator << (std::ostream &out, const rational &x) {
  out << x.nom << "/" << x.den;
  return out;
}

int rational::gcd(int x, int y){
  while (x > 0 && y > 0)
  if (x > y) x %= y; else y %= x;
  return x + y;
}