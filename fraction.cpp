#ifndef FRACTION_CPP
#define FRACTION_CPP


#include <iostream>
#include <cmath>
#include "fraction.h"
using namespace std;

int min(int x,int y){
	x=abs(x);
	y=abs(y);
	int e;
	if(x<y)e=x;
	else e=y;
	return e;
}

int max(int x,int y){
	x=abs(x);
	y=abs(y);
	int e;
	if(x>y)e=x;
	else e=y;
	return e;
}
int lcm(int x,int y){
	int i=max(x,y);
	int r=min(x,y);
	if(r==0)return 1;
	int g;
	for(g=1;i%r!=0;g++){
		i=max(x,y);
		i=i*g;
	}
	return i;
}


        int fraction::gcd(const int &x, const int &y) const{
			int i=max(x,y);
			int r=min(x,y);
			int Y=1;
			if(r==0)return 1;
			while(Y!=0){
				Y=i%r;
				i=r;
				r=Y;
			}
			return i;
		};
            // If you don't need this method, just ignore it.
        void fraction::simp(){
        	int temp=gcd(_numerator,_denominator);
        	_numerator/=temp;
        	_denominator/=temp;
        	if(_denominator<0){
        		_denominator=-_denominator;
        		_numerator=-_numerator;
        	}
        };
            // To get the lowest terms.
        fraction::fraction(const int & a, const int & b){
        	_numerator=a;
        	_denominator=b;
        	simp();
        };
            // The numerator and the denominator
            // fraction(5) = 5/1 = 5 :)
        fraction::fraction(const fraction &p){
        	_numerator=p._numerator;
        	_denominator=p._denominator;
        	simp();
        };
            // copy constructor

        void fraction::operator=(const fraction &p){
        	_numerator=p._numerator;
        	_denominator=p._denominator;
        	simp();
        };

        // You must know the meaning of +-*/, don't you ?
        fraction fraction::operator+(const fraction &p) const{
			int tempd=_denominator*p._denominator;
			int tempn=(_numerator*p._denominator)+(p._numerator*_denominator);
			fraction a(tempn,tempd);
			if(tempd==0){
				fraction b(0,0);
				return b;
			}
			a.simp();
			return a;
			
		};
        fraction fraction::operator-(const fraction &p) const{
			int tempd=lcm(_denominator,p._denominator);
			int tempn=(_numerator*(tempd/_denominator))-(p._numerator*(tempd/p._denominator));
			fraction a(tempn,tempd);
			if(tempd==0){
				fraction b(0,0);
				return b;
			}
			a.simp();
			return a;
			
		};
        fraction fraction::operator*(const fraction &p) const{
			int tempd=_denominator*p._denominator;
			int tempn=_numerator*p._numerator;
			fraction a(tempn,tempd);
			if(tempd==0){
				fraction b(0,0);
				return b;
			}
			a.simp();
			return a;
		};
        fraction fraction::operator/(const fraction &p) const{
			int tempd=_denominator*p._numerator;
			int tempn=_numerator*p._denominator;
			fraction a(tempn,tempd);
			if(tempd==0){
				fraction b(0,0);
				return b;
			}
			a.simp();
			return a;
		};

        void fraction::operator+=(const fraction &p){
        	int tempd=_denominator*p._denominator;
			int tempn=(_numerator*p._denominator)+(p._numerator*_denominator);
			_numerator=tempn;
			_denominator=tempd;
			if(tempd==0){
				_numerator=0;
				_denominator=0;
				return;
			}
			simp();
        };
        void fraction::operator-=(const fraction &p){
        	int tempd=lcm(_denominator,p._denominator);
			int tempn=(_numerator*(tempd/_denominator))-(p._numerator*(tempd/p._denominator));
			_numerator=tempn;
			_denominator=tempd;
			if(tempd==0){
				_numerator=0;
				_denominator=0;
				return;
			}
			simp();
        };
        void fraction::operator*=(const fraction &p){
        	fraction a(p._numerator,_denominator);
        	a.simp() ;
        	fraction b(_numerator,p._denominator);
        	b.simp() ;
        	*this=a*b;
        };
        void fraction::operator/=(const fraction &p){
        	fraction a(p._denominator,_denominator);
        	a.simp() ;
        	fraction b(_numerator,p._numerator);
        	b.simp() ;
        	*this=a*b;
        };

        // Comparison operators
        bool fraction::operator==(const fraction &p) const{
			if((_denominator==p._denominator&&_numerator==p._numerator)||((_denominator==0)&&(0==p._denominator)))return 1;
			else return 0;
		};
        bool fraction::operator!=(const fraction &p) const{
			if((_denominator==p._denominator&&_numerator==p._numerator)||((_denominator==0)&&(0==p._denominator)))return 0;
			else return 1;
		};
        bool fraction::operator<(const fraction &p) const{
			double a=(double)_numerator/(double)_denominator;
			double b=(double)p._numerator/(double)p._denominator;
			if(a<b)return 1;
			else return 0;
		};
        bool fraction::operator>(const fraction &p) const{
			double a=(double)_numerator/(double)_denominator;
			double b=(double)p._numerator/(double)p._denominator;
			if(a>b)return 1;
			else return 0;
		};
        bool fraction::operator<=(const fraction &p) const{
			if(*this<p||*this==p)return 1;
			else return 0;
		};
        bool fraction::operator>=(const fraction &p) const{
			if(*this>p||*this==p)return 1;
			else return 0;
		};

        std::istream & operator>>(std::istream &in, fraction &p){
        	in >> p._numerator >> p._denominator;
         	return in;
        	
        };
            // Input Format: two integers with a space in it
            // "a b" is correct. Not "a/b"
        std::ostream & operator<<(std::ostream &out, const fraction &p){
        	if(p._denominator==0){
        		out<<"NaN";
        	}
        	else if(p._denominator==1){
        		out<<p._numerator;
        	}
        	else{
        		out<<p._numerator<<'/'<<p._denominator;
        	}
        	return out;
        };
            // Normally you should output "a/b" without any space and LF
            // Sometims you may output a single integer (Why? Guess XD)
            // If it is not a number (den = 0), output "NaN"

#endif
