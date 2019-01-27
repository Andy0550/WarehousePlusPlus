//
//  main.cpp
//  tvary_semestralka
//
//  Created by Šárka Piskáčková on 18/12/2018.
//  Copyright © 2018 Šárka Piskáčková. All rights reserved.

#include <iostream>
#include <fstream>
#include <math.h>
#include "tvary.hpp"
using namespace std;


int main() {
    ifstream soubor;
    soubor.open("/Users/Michael/C++/Turoň/Tvary/Tvary/soubor.txt");
    if(soubor.is_open()){
        string tvar;
        double p1, p2, p3;
        getline(soubor, tvar);
        cout << tvar << endl;
        
        if(tvar == "obdelnik, obvod"){
            soubor >> p1;
            soubor >> p2;
            cout << "strana a: " << p1 << ", strana b: " << p2 << endl;
            Obdelnik o (p1,p2);
            cout << "Obvod: " << o.obvod() << endl;
        }
        
        if(tvar == "obdelnik, obsah"){
            soubor >> p1;
            soubor >> p2;
            cout << "strana a: " << p1 << ", strana b: " << p2 << endl;
            Obdelnik o (p1,p2);
            cout << "Obsah: " << o.obsah() << endl;
        }
        
        /* if(tvar == "kvadr, objem"){
         soubor >> p1;
         soubor >> p2;
         soubor >> p3;
         cout << "strana a: " << p1 << ", strana b: " << p2 << ", vyska v: " << p3 << endl;
         Kvadr k (p1, p2, p3);
         }*/
        
        if(tvar == "kruh, obvod"){
            soubor >> p1;
            cout << "polomer: " << p1 << endl;
            Kruh k (p1);
            cout << "Obvod: " << k.obvod() << endl;
        }
        
        if(tvar == "kruh, obsah"){
            soubor >> p1;
            cout << "polomer: " << p1 << endl;
            Kruh k (p1);
            cout << "Obsah: " << k.obsah() << endl;
        }
        
        /*if(tvar == "valec, objem"){
         }*/
        
        if(tvar == "trojuhelnik, obvod"){
            soubor >> p1;
            soubor >> p2;
            soubor >> p3;
            cout << "strana a: " << p1 << ", strana b: " << p2 << ", strana c: " << p3 << endl;
            Trojuhelnik t (p1, p2, p3);
            cout << "Obvod: " << t.obvod() << endl;
        }
        
        if(tvar == "trojuhelnik, obsah"){
            soubor >> p1;
            soubor >> p2;
            soubor >> p3;
            cout << "strana a: " << p1 << ", strana b: " << p2 << ", strana c: " << p3 << endl;
            Trojuhelnik t (p1, p2, p3);
            cout << "Obsah: " << t.obsah() << endl;
        }
        
        /*if(tvar == "hranol, objem"){
         }*/
        
    }
    
    else{
        cout << "Neotevrel se soubor" << endl;
    }
    
    soubor.close();
}




