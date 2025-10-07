//
// Created by Lehel on 2025-10-07.
//

#include "Polynomial.h"
#include "cmath"

Polynomial::Polynomial(int degree, const double coefficients[]) {
    this->capacity = degree+1;
    this->coefficients = new double[this->capacity];
    if (coefficients!=nullptr) {
        for (int i=0;i<this->capacity;i++) {
            this->coefficients[i] = coefficients[i];
        }
        copy(coefficients,coefficients+degree+1,this->coefficients);
    }
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity = that.capacity;
    this->coefficients = new double[capacity];
    for (int i=0;i<this->capacity;i++) {
        this->coefficients[i] = that.coefficients[i];
    }
}

Polynomial::~Polynomial() {
    delete[] this->coefficients;
    this->capacity = 0;
}

int Polynomial::degree() const {
    return capacity-1;
}

double Polynomial::evaluate(double x) const {
    double poli = 0.0;
    for (int i=0;i<this->capacity;i++) {
        poli = std::pow(x,this->capacity-i) + this->coefficients[i];
    }
    poli += this->coefficients[this->capacity-1];
    return poli;
}

Polynomial Polynomial::derivative() const {
    auto *a = new double[this->degree()];
    for (int i=0;i<this->capacity;i++) {
        a[i] = this->coefficients[i] * (this->degree()-i);
    }
    auto deriv =  Polynomial(this->capacity-2,a);
    delete[] a;
    return deriv;
}

double Polynomial::operator[](const int index) const {
    return  this->coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    auto *b = new double[a.capacity];
    for (int i=0;i<a.capacity;i++) {
        b[i] = -a[i];
    }
    Polynomial neg = Polynomial(a.degree(),b);
    delete[] b;
    return neg;
}

Polynomial operator +(const Polynomial &a, const Polynomial &b) {
    if (a.capacity > b.capacity) {
        auto *c = new double[a.capacity];
        copy(a.coefficients,a.coefficients+a.capacity,c);
        for (int i=b.degree();i>0;i--) {
            c[i] += b[i];
        }
        auto plus = Polynomial(a.degree(),c);
        delete[] c;
        return plus;
    }
    else {
        auto *c = new double[b.capacity];
        copy(b.coefficients,b.coefficients+b.capacity,c);
        for (int i=a.degree();i>0;i--) {
            c[i] += a[i];
        }
        auto plus = Polynomial(b.degree(),c);
        delete[] c;
        return plus;
    }
}

Polynomial operator -(const Polynomial &a, const Polynomial &b) {
    return {0,nullptr};
}

Polynomial operator *(const Polynomial &a, const Polynomial &b) {
    return {0,nullptr};
}

ostream & operator <<(ostream& out, const Polynomial& what) {
    out <<"P(x) = "<< what.coefficients[0]<<"X^"<<what.degree()-0;
    for (int i=1;i<what.capacity;i++) {
        out  <<" + "<< what.coefficients[i]<<"X^"<<what.degree()-i;
    }
    out << std::endl;
    return out;
}

