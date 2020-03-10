#include <cstdlib>
#include <iostream>
#ifndef CONTEST
#include "fullratio.hpp"
#endif
using namespace std;

rational::rational (int n, int d) {
  nom=n; den=d;
}

rational operator + (const rational &x, const rational &y) {
  return rational ((x.nom*y.den+y.nom*x.den), (x.den*y.den));
}

rational operator - (const rational &x, const rational &y) {
  return rational ((x.nom*y.den-y.nom*x.den), (x.den*y.den));
}

rational operator * (const rational &x, const rational &y) {
  return rational ((x.nom*y.nom), (x.den*y.den));
}

rational operator / (const rational &x, const rational &y) {
  return rational ((x.nom*y.den), (x.den*y.nom));
}

std::ostream & operator << (std::ostream &out, const rational &x) {
  int a=abs(x.nom), b=abs(x.den), gcd=rational::gcd(a, b);
  if (x.nom<0 xor x.den<0) out << "-" << a/gcd << "/" << b/gcd;
  else out << a/gcd << "/" << b/gcd;
  return out;
}

int rational::gcd(int x, int y){
  while (x > 0 && y > 0)
  if (x > y) x %= y; else y %= x;
  return x + y;
}