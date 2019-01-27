//
//  tvary.cpp
//  Tvary
//
//  Created by Michael Dvořák on 16/01/2019.
//  Copyright © 2019 Michael Dvořák. All rights reserved.
//

#include "tvary.hpp"
#include <math.h>


//Tvary3D
    Tvary3D::Tvary3D(double v) : v(v){
    }
    double Tvary3D::objem(double v) {
        return obsah()*v;
    }


//Obdelnik

    Obdelnik::Obdelnik(double a, double b) : a(a), b(b) {
    }
    double Obdelnik::obsah() {
        return a*b;
    }
    double Obdelnik::obvod(){
        return (2*a) + (2*b);
    }


//Kvadr

    Kvadr::Kvadr(double a, double b, double v) : Obdelnik(a, b), Tvary3D(v){
    }

//Kruh

    Kruh::Kruh (double r) : r(r){
    }
    double Kruh::obsah() {
        return M_PI * pow(r, 2);
    }
    double Kruh::obvod(){
        return 2 * M_PI * r;
    }

//Valec

    Valec::Valec (double r, double v) : Kruh(r), Tvary3D(v){
    }

//Trojuhelnik::

    Trojuhelnik::Trojuhelnik (double a, double b, double c) : a(a), b(b), c(c){
        s = obvod()/2;
    }
    double Trojuhelnik::obsah() {
        return sqrt(s*(s - a)*(s - b)*(s - c));
    }
    double Trojuhelnik::obvod(){
        return a + b + c;
    }

//Hranol

    Hranol::Hranol (double a, double b, double c, double v) : Trojuhelnik(a, b, c), Tvary3D(v){
    }

