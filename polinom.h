#pragma once

#include "monom.h"

class polinom 
{

public:
    link* h;

    polinom ();  

    void add (int powx, int powy, int powz, double a);

    void add (const link& x);

    friend ostream& operator<<(ostream &out, const polinom &t);
    friend polinom operator+(const polinom &x,const polinom &y);
    friend polinom operator*(const polinom &x, const polinom &y);
	void operator=(const polinom &x);
};
