#include "complex.h"
#include <cmath>

//===================================================== constructor, destructor
Complex::Complex(const float real, const float imag): x(real), iy(imag)
{
    //complex number c = x + y(i), where i = sqrt(-1)
} //end constructor

Complex::~Complex()
{
    //default destructor : class has no dynamic or ptr variables
} //end destructor

Complex::Complex(const Complex& other): x(other.x), iy(other.iy)
{
    //intentionally left blank
} //end copy constructor

Complex& Complex::operator =(const Complex& other)
{
    this->x = other.x;
    this->iy = other.iy;
    return *this;
} //end assignment operator =

//============================================================ member functions
//----------------------------------------------------------- mutable operators
//mutable operators change the value of the Complex that invokes the function

//(+=) addition of 2 Complex numbers: returns sum of this + other
void Complex::operator +=(Complex &other)
{
    //(a + bi) + (c + di) = (a + c) + (b + d)i
    x += other.x;
    iy += other.iy;
} //end operator +=

//(*=) multiplication of 2 Complex numbers: returns product of this * other
//  note: overloaded function; see Complex& operator *=(const float scalar)
void Complex::operator *=(Complex& other)
{
    //(a + bi)*(c + di) = ac + (ad + bc)i + (i*i)(bd) = (ac - bd) + (ad + bc)i
    float real = (x * other.x) - (iy * other.iy);
    float imag = (x * other.iy) + (iy * other.x);
    x = real;
    iy = imag;
} //end operator *=(const Complex&)

//(*=) scalar multiplication: returns product of this * scalar
//  note: overloaded function; see Complex& operator *=(const Complex& other)
void Complex::operator *=(const float scalar)
{
    //scalar multiplication: n(a + bi) = an + (bn)i
    x *= scalar;
    iy *= scalar;
} //end operator *=(const float)

//returns absolute value (or magnitude) of Complex = its distance from origin
float Complex::abs() const
{
    //absolute value of Complex = |(a + bi)| = sqrt(a*a + b*b)
    //i.e. abs() = hyponenuse of triangle w/sides of length a and b
    return (hypotf(x, iy));
} //end abs

float Complex::mag() const
{
    return (x*x + iy*iy);
}

//========================================================= immutable operators
//immutable operators return the result of the operator as a new Complex;
//the values of the variables on either side of the operator remain constant

//returns new Complex number that is the sum of c1 + c2
Complex& operator +(Complex& c1, Complex& c2)
{
    //(a + bi) + (c + di) = (a + c) + (b + d)i
    float real = c1.x + c2.x;
    float imag = c1.iy + c2.iy;
    return *(new Complex(real, imag));
} //end operator +

//returns new Complex number that is the product of c1 * c2
Complex& operator *(Complex& c1, Complex& c2)
{
    //(a + bi)*(c + di) = ac + (ad + bc)i + (i*i)(bd) = (ac - bd) + (ad + bc)i
    float real = (c1.x * c2.x) - (c1.iy * c2.iy);
    float imag = (c1.x * c2.iy) + (c1.iy * c2.x);
    return *(new Complex(real, imag));
} //end operator *

//returns new Complex number that is the product of c1 * scalar
Complex& operator *(Complex& c1, const float scalar)
{
    //scalar multiplication: n(a + bi) = an + (bn)i
    float real = c1.x * scalar;
    float imag = c1.iy * scalar;
    return *(new Complex(real, imag));
} //end operator *
