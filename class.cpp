//
//  class.cpp
//  WAREHOUSE
//
//  Created by Michael Dvořák on 06/05/2018.
//  Copyright © 2018 Michael Dvořák. All rights reserved.
//

#include <stdio.h>
#include "class.h"
#include <string>


Item::Item() {
    Name = "";
    Type = "";
    Info = "";
}

Item::Item(int ID, string Name, string Type, string Info, int StoreDate) {
    this->ID = ID;
    this->Name = Name;
    this->Type = Type;
    this->Info = Info;
    this->StoreDate = StoreDate;
}

int Item::getID() const {
    return ID;
}

string Item::getName() const {
    return Name;
}

string Item::getType() const {
    return Type;
}

string Item::getInfo() const {
    return Info;
}

int Item::getDate() const {
    return StoreDate;
}


//Book

Book::Book(int ID, string Name, string Type, string Info, int Pages, string Author, int StoreDate) : Item(ID, Name, Type, Info, StoreDate) {
    this->Pages = Pages;
    this->Author = Author;
    Count ++;
}

int Book::getPages() const {
    return Pages;
}

string Book::getAuthor() const {
    return Author;
}

void Book::get() const {
    cout << "ID: " << ID << ", " << "Name: " << Name << ", " << "Type: " << Type << ", " << "Info: " << Info << ", " << "Pages: " << Pages << ", " << "Author: " << Author << "," << "Store Date: " << StoreDate << endl << endl;
}

string Book::get2() const {
    string exit;
    exit = to_string(ID) + "," + Name + "," + Type + "," + Info + "," + to_string(Pages) + "," + Author + ",," + to_string(StoreDate) + '\n';
    return exit;
}


//Movie

Movie::Movie(int ID, string Name, string Type, string Info, int ReleaseYear, string Director, string Genre, int StoreDate) : Item(ID, Name, Type, Info, StoreDate) {
    
    this->ReleaseYear = ReleaseYear;
    this->Director = Director;
    this->Genre = Genre;
    Count ++;
}

int Movie::getReleaseYear() const {
    return ReleaseYear;
}

string Movie::getDirector() const {
    return Director;
}

string Movie::getGenre() const  {
    return Genre;
}

void Movie::get() const {
    cout << "ID: " << ID << "," << "Name: " << Name << ", " << "Type: " << Type << ", " << "Info: " << Info << ", " << "Release Year: " << ReleaseYear << ", " << "Director: " << Director << ", " << "Genre: " << Genre << ", " << "Store Date: " << StoreDate << endl << endl;
}

string Movie::get2() const {
    string exit;
    exit = to_string(ID) + "," + Name + "," + Type + "," + Info + "," + to_string(ReleaseYear) + "," + Director + "," + Genre + "," + to_string(StoreDate) + '\n';
    return exit;
}

//Vinyl

Vinyl::Vinyl(int ID, string Name, string Type, string Info, int ReleaseYear, string Artist, string Genre, int StoreDate) : Item(ID, Name, Type, Info, StoreDate) {
    
    this->Artist = Artist;
    this->Genre = Genre;
    this->ReleaseYear = ReleaseYear;
    Count ++;
}

string Vinyl::getArtist() const {
    return Artist;
}

string Vinyl::getGenre() const {
    return Genre;
}

int Vinyl::getReleaseYear() const {
    return ReleaseYear;
}

void Vinyl::get() const {
    cout << "ID: " << ID << ", " << "Name: " << Name << ", " << "Type: " << Type << ", " << "Info: " << Info << ", " << "Release Year: " << ReleaseYear << "Artist: " << Artist << ", " << "Genre: " << Genre << ", " << "Store Date: " << StoreDate << endl << endl;
}

string Vinyl::get2() const {
    string exit;
    exit = to_string(ID) + "," + Name + "," + Type + "," + Info + "," + to_string(ReleaseYear) + "," + Artist + "," + Genre + "," + to_string(StoreDate) + '\n';
    return exit;
}
