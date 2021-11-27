//
// Created by Trey Wade 20170403 on 2021-10-14. For CMPE 320 Assignment 2
//

#ifndef ASSIGNMENT2_FRACTION_18GDW_H
#define ASSIGNMENT2_FRACTION_18GDW_H

#endif //ASSIGNMENT2_FRACTION_18GDW_H

using namespace std;

//Custom Exception Class made for the fraction
class FractionException{
public:
    FractionException(const string &message);
    string& what();
private:
    string message;
};

class Fraction{
public:
    //default constructor for function with no input
    Fraction();
    //Fraction constructor for a constant
    Fraction(int num);
    //Fraction  constructor for a constant
    Fraction(int num, int den);
    //Accsessor Methods
    int numerator() const;
    int denominator() const;
    //GCD to simplify the fractions
    int GCD(int num, int den);
    //PRE Increment
    Fraction& operator++();
    //POST  Increment
    Fraction operator++(int);
    //Seteing Fractions equal to each other and suming them
    Fraction operator=(const Fraction& rhs);
    Fraction operator+=(const Fraction& rhs);
    //Boolean Expression Overloading
    bool operator==(const Fraction& rhs);
    bool operator!=(const Fraction& rhs);
    bool operator!=(const int constant);
    bool operator>(const Fraction& rhs);
    bool operator>=(const Fraction &rhs);
    bool operator<(const Fraction& rhs);
    bool operator<=(const Fraction& rhs);
    friend bool operator<(int integer, const Fraction& rhs);
    friend bool operator!=(int integer, const Fraction& rhs);
    //IO Stream Overloading
    friend ostream& operator<<(ostream& out, const Fraction& fraction);
    friend istream& operator>>(istream& in, Fraction& fraction);
    friend istream& operator>>(istream &in, int num);

    //OVerloading +,-,*,/ operators
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

//Negate a Fraction
    friend Fraction operator-(const Fraction& oneSide);

private:
    int num;
    int den;
};


