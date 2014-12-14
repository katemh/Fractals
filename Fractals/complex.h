#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
    Complex(const float real, const float imag);    //constructor
    ~Complex();                                     //default destructor
    Complex(const Complex& other);                  //copy constructor
    Complex& operator =(const Complex& other);      //assignment (=) operator

    //------------------------------------------------------- mutable operators
    //these functions return the Complex (itself) added/multiplied w/other
    //i.e., these functions change the value of the Complex they are called on
    void operator += (Complex& other);      //add   (this + other); return
    void operator *=(Complex& other);       //mult. (this * other); return
    void operator *=(const float scalar);   //mult. (scalar*this); return
    float abs() const;                      //return absolute value
    float mag() const;                      //return magnitude^2

    //----------------------------------------------------- immutable opeartors
    //these functions return the result of addition/multiplication of one
    //Complex number w/another Complex number (or a scalar)
    friend Complex& operator +(Complex& c1, Complex& c2); //(+) add
    friend Complex& operator *(Complex& c1, Complex& c2); //(*) multiply
    friend Complex& operator *(Complex& c1, float scalar);//(*) scale



private:
    //Complex class represents a complex number. Complex numbers have a
    //real number component (x) and an imaginary number component (yi).
    float x, iy;
};

#endif // COMPLEX_H
