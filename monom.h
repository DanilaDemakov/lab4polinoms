#include <iostream>
#pragma once
using namespace std;

struct link
{
	int powx;
	int powy;
	int powz;
	double a;
	link *next;
	link(int _powx=0, int _powy=0, int _powz=0, double _a=0)
	{
		powx=_powx;
		powy=_powy;
		powz=_powz;
		a=_a;
		next=NULL;
	}
	link(const link &t)
	{
		powx=t.powx;
		powy=t.powy;
		powz=t.powz;
		a=t.a;
		next=NULL;
	}
	friend bool operator <(const link &x, const link &y);
	friend bool operator >=(const link &x, const link &y);
	friend bool operator ==(const link &x, const link &y);
	friend link operator *(const link &x, const link &y);
	friend ostream& operator<<(ostream &out,const link &t);
	friend istream& operator>>(istream &in, link &t);
};