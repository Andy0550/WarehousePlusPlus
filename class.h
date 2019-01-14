//
//  class.h
//  WAREHOUSE
//
//  Created by Michael Dvořák on 04/05/2018.
//  Copyright © 2018 Michael Dvořák. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#ifndef class_h
#define class_h

static int Count = 0;

//Item

class Item {
 
protected:
    int ID;
    string Name;
    string Type;
    string Info;
    int StoreDate;
    
    
    
public:
    
    
    Item();
    
    Item(int, string, string, string, int);
    
    int getID() const;
    
    string getName() const;
    
    string getType() const;
    
    string getInfo() const;
    
    int getDate() const;
    
    virtual void get() const = 0;
    
    virtual string get2() const = 0;

};

//Book

class Book : public Item {
    
private:
    int Pages;
    string Author;
    
public:
    Book(int, string, string, string, int, string, int);
    
    string getAuthor() const;
    
    int getPages() const;
    
    void get() const;
    
    string get2() const;
};

//Movie
    
class Movie : public Item {
    
private:
    int ReleaseYear;
    string Director;
    string Genre;
    
public:
    Movie(int, string, string, string, int, string, string, int);
    
    int getReleaseYear() const;
    
    string getDirector() const;
    
    string getGenre() const;
    
    void get() const;
    
    string get2() const;
    
};

//Vinyl

class Vinyl : public Item {
    
private:
    int ReleaseYear;
    string Artist;
    string Genre;
    
public:
    Vinyl (int, string, string, string, int, string, string, int);

    string getArtist() const;
    
    string getGenre() const;
    
    int getReleaseYear() const;
    
    void get() const;
    
    string get2() const;

};





#endif /* class_h */
