#include <iostream>
#include "monom.h"
using namespace std;


bool operator < (const link& x, const link& y) {
   if (x.powx < y.powx) return true;
   if (x.powx == y.powx) {
       if (x.powy < y.powy) return true;
       if (x.powy == y.powy) {
           if (x.powz < y.powz) return true;
       }
   }
   return false;
}

bool operator >= (const link& x, const link& y) {
   if (x.powx < y.powx) return false;
   if (x.powx == y.powx) {
       if (x.powy < y.powy) return false;
       if (x.powy == y.powy) {
           if (x.powz < y.powz) return false;
       }
   }
   return true; 
}

bool operator == (const link& x, const link& y) {
    if (x.powx == y.powx && x.powy == y.powy && x.powz == y.powz) return true;
    return false;
}

link operator*(const link& x, const link& y) {
    link res;
    res.powx = x.powx + y.powx;
    res.powy = x.powy + y.powy;
    res.powz = x.powz + y.powz;
    res.a = x.a * y.a;
	return res;
}

ostream& operator<<(ostream &out, const link &t) {
    out << "(" << t.a << " * ";
    out << "x^" << t.powx << " * y^" << t.powy << " * z^" << t.powz << ")";
	return out;
}
istream& operator>>(istream &in, link &t) {
    in >> t.a >> t.powx >> t.powy >> t.powz;
	return in;
}