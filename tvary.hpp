//
//  tvary.hpp
//  Tvary
//
//  Created by Michael Dvořák on 16/01/2019.
//  Copyright © 2019 Michael Dvořák. All rights reserved.
//

#ifndef tvary_hpp
#define tvary_hpp

#include <stdio.h>

class Tvary {
    
protected:
    virtual double obsah()=0;
    virtual double obvod()=0;
};

class Tvary3D : public Tvary {
    
private:
    double v;
    
public:
    Tvary3D (double v);
    double objem(double v);
};


class Obdelnik : public Tvary {
    
private:
    double a, b;
    
public:
    Obdelnik (double a, double b);
    double obsah();
    double obvod();
};

class Kvadr : virtual Obdelnik, virtual Tvary3D {

public:
    Kvadr (double a, double b, double v);
};

class Kruh : public Tvary {
    
private:
    double r;
    
public:
    explicit Kruh (double r);
    double obsah();
    double obvod();
};

class Valec : virtual Kruh, virtual Tvary3D {

private:
    double v;
    
public:
    Valec (double r, double v);
};

class Trojuhelnik : public Tvary {
    
private:
    double a, b, c, s;
    
public:
    Trojuhelnik (double a, double b, double c);
    double obsah();
    double obvod();
};

class Hranol : virtual Trojuhelnik, virtual Tvary3D {
    
private:
    double v;
    
public:
    Hranol (double a, double b, double c, double v);
};






#endif /* tvary_hpp */
