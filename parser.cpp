#include "monom.h"
#include "polinom.h"
#include "parserr.h"

polinom calculate::parser (string s) {
    int n = s.size();
    polinom res;
    double k = 0;
    int st = 1;
    int i = n - 1;

    link* t = new link();
    while (i >= 0) {
        while (i >= 0 && (s[i] < '0' || s[i] > '9')) i--;
        while (i >= 0 && s[i] >= '0' && s[i] <= '9') {
            k += st * (s[i] - '0');
            st *= 10;    
            i--;
            if (i >= 0 && ((s[i] == '.') || (s[i] == ','))) {
                k /= (double)st;
                st = 1;
                i--;
            }
        }
        st = 1;
        while (i >= 0 && s[i] != 'x' && s[i] != 'y' && s[i] != 'z' && s[i] != '+' && s[i] != '-') i--;
        if (i < 0) {
            t->a = k;
			if(t->a==0)
				{
					break;
				}
            res.add (*t);
            return res;
        }
        switch (s[i])
        {
            case 'x':
                t->powx = k;
                k = 0;    
                break;
            case 'y':
                t->powy = k;
                k = 0;
                break;
            case 'z':
                t->powz = k;
                k = 0;
                break;
            default:
                t->a = (s[i] == '+' ? k : -k);
                k = 0;
                res.add (*t);
				i--;
                t = new link();
                break;
        }
    }
    return res;
}