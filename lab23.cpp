#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here
double ComplexNumber::abs(){
	return (sqrt(pow(real,2)+pow(imag,2)));
}
double ComplexNumber::angle(){
	return atan2 (imag,real) * 180 / M_PI;
}

ostream &operator<<(ostream &os,const ComplexNumber &c){
	if (c.real!=0&&c.imag>0)    return os << c.real << "+" << c.imag << "i"; 
	else if (c.real!=0&&c.imag<0)    return os << c.real << c.imag << "i"; 
	else if (c.real==0&&c.imag!=0)    return os << c.imag << "i"; 
	else if (c.real!=0&&c.imag==0)    return os << c.real; 
	else return os <<"0";

}


ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag),(real*c.imag)+(imag*c.real));
}

ComplexNumber operator*(double a,const ComplexNumber &c){
	return ComplexNumber(a*c.real,a*c.imag);
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber(((real*c.real)+(imag*c.imag))/(pow(c.real,2)+pow(c.imag,2)),((imag*c.real)-(real*c.imag))/(pow(c.real,2)+pow(c.imag,2)));
}
ComplexNumber operator/(double a,const ComplexNumber &c){
	return ComplexNumber((a*c.real)/(pow(c.real,2)+pow(c.imag,2)),(-(a*c.imag))/(pow(c.real,2)+pow(c.imag,2)));
}

bool::ComplexNumber::operator==(const ComplexNumber &c){
	if(real == c.real && imag == c.imag){
		return true;
	}
	else{
		return false;
	}
}

ComplexNumber operator+(double a,const ComplexNumber &c){
	return ComplexNumber(a+c.real,c.imag);
}

ComplexNumber operator-(double a,const ComplexNumber &c){
	return ComplexNumber(a-c.real,-c.imag);
}

ComplexNumber operator==(double a,const ComplexNumber &c){
	if(a==c.real && c.imag==0)	return true;
	else return false;
}
