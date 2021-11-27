//
// Created by Trey Wade 20170403 on 2021-10-14. For CMPE 320 Assignment 2
//

#include <iostream>
#include "fraction_18gdw.h"
using namespace std;

Fraction::Fraction() {
    //Default is to set numerator to 0 and denomenator to 1
    this -> num = 0;
    this -> den = 1;
    cout << (num + "/" + den) << endl;
}

Fraction::Fraction(int num) {
    //Set Fraction With only a numerator
    this -> num = num;
    this -> den = 1;
}

Fraction::Fraction(int num, int den){
    //Ensures no invalid fractions
    if (den == 0){
        throw FractionException("ERROR INVALID DENOMENATOR");
    } else if (den < 0){
        num = -num;
        den = -den;
    }
    int gcd = GCD(num, den);
    this -> num = num/gcd;
    this -> den = den/gcd;

}

int Fraction::numerator() const {
    //Get Numerator
    return this -> num;
}

int Fraction::denominator() const{
    //Get Denomenator
    return this -> den;
}

int Fraction::GCD(int num, int den) {
    //No Negative Numbers
    num = abs(num);
    den = abs(den);
    if (den != 0){
        if (num < den){
            return GCD(den, num);
        } else if (den <= num && (num % den) != 0){
            return GCD(den, num % den);
        }  else {
            return den;
        }
    } else {
        return num;
    }
}

FractionException::FractionException(const string &message) : message(message){}
string& FractionException::what() {return message;}

Fraction operator+(const Fraction& lhs, const Fraction& rhs){
    int tempN1 = lhs.numerator() * rhs.denominator();
    int tempN2 = rhs.numerator() * lhs.denominator();
    int den = lhs.denominator() * rhs.denominator();
    return Fraction(tempN1 + tempN2, den);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs){
    int tempN1 = lhs.numerator() * rhs.denominator();
    int tempN2 = rhs.numerator() * lhs.denominator();
    int den = lhs.denominator() * rhs.denominator();
    return Fraction(tempN1 - tempN2, den);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs){
    return Fraction(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs){
    return Fraction(lhs.numerator() * rhs.denominator(), lhs.denominator() * rhs.numerator());
}

Fraction operator-(const Fraction& oneSide){
    int tempN = oneSide.numerator();
    return Fraction(-tempN, oneSide.denominator());
}


Fraction& Fraction::operator++(){
    this->num = num + den;
    return *this;
}

Fraction Fraction::operator++(int){
    Fraction temp = *this;
    ++*this;
    return temp;
}

Fraction Fraction::operator=(const Fraction& rhs){
    //num = (num * (rhs.denominator())) + (rhs.numerator() * (den));
    this->num = rhs.numerator();
    this->den = rhs.denominator();
    return Fraction(num, den);
}

Fraction Fraction::operator+=(const Fraction& rhs){
    num = (num * rhs.denominator()) + rhs.numerator() * den;
    den = den * rhs.denominator();
    int gcd = GCD(num, den);
    this -> num = num/gcd;
    this -> den = den/gcd;
    return Fraction(num, den);
}

bool Fraction::operator==(const Fraction &rhs) {
    if (num * rhs.denominator() == rhs.numerator() * den){
        return true;
    } else {
        return false;
    }
}

bool Fraction::operator!=(const Fraction &rhs) {
    if (num * rhs.denominator() != rhs.numerator() * den){
        return true;
    } else {
        return false;
    }
}

bool Fraction::operator!=(const int constant) {
    float result = (float)num/(float)den;
    if (result != constant ){
        return true;
    } else {
        return false;
    }
}

bool Fraction::operator>(const Fraction &rhs) {
    if (num * rhs.denominator() > rhs.numerator() * den){
        return true;
    } else {
        return false;
    }
}

bool Fraction::operator>=(const Fraction &rhs) {
    if (num * rhs.denominator() >= rhs.numerator() * den){
        return true;
    } else {
        return false;
    }
}

bool Fraction::operator<(const Fraction &rhs) {
    if (num * rhs.denominator() < rhs.numerator() * den){
        return true;
    } else {
        return false;
    }
}

bool Fraction::operator<=(const Fraction &rhs) {
    if (num * rhs.denominator() <= rhs.numerator() * den){
        return true;
    } else {
        return false;
    }
}

bool operator<(int integer, const Fraction &rhs) {
    if (integer * rhs.denominator() < rhs.numerator()){
        return true;
    } else {
        return false;
    }
}

bool operator!=(int integer, const Fraction &rhs) {
    if (integer * rhs.denominator() != rhs.numerator()){
        return true;
    } else {
        return false;
    }
}

ostream& operator<<(ostream& out, const Fraction& frac) {
    out << frac.numerator() << "/" << frac.denominator();
    return out;
}

istream& operator>>(istream &in, int num) {
    string fractionEntered;
    cin >> fractionEntered;
    num = stoi(fractionEntered);
    return in;
}

istream& operator>>(istream &in, Fraction &fraction) {
    string fractionEntered;
    cin >> fractionEntered;
    //Look for the division of the numerator and denomenator
    if (fractionEntered.find('/') < fractionEntered.length()){
        //the / was found
        int num = stoi(fractionEntered.substr(0, fractionEntered.find('/')));
        int den = stoi(fractionEntered.substr(fractionEntered.find('/')+1,fractionEntered.length()));
        fraction = Fraction(num, den);
    } else {
        // only the numerator
        fraction = Fraction(stoi(fractionEntered));
    }
    return in;
}

