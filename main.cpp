//
//  main.cpp
//  WAREHOUSE
//
//  Created by Michael Dvořák on 01/05/2018.
//  Copyright © 2018 Michael Dvořák. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "class.h"

using namespace std;

//Function declarations

void readList(vector<Item *>& List);

void writeList(vector<Item *>& List);


//Main

int main(int argc, const char * argv[]) {
    vector<Item *> List;
    //List.push_back (new Book (1, "Pinocchio", "Knihy","Dětská knížka o hračce co neumí lhát." , 180, "Carlo Collodi", 2018));
    //List.push_back (new Movie (2, "Forrest Gump", "Filmy","Americký Jára Cimrman." , 1994, "Robert Zemeckis", "Comedy", 2016));
    //List.push_back (new Vinyl (3, "The Dark Side of the Moon", "LP", "Top LPíčko.", 1973, "Pink Floyd", "Rock", 2015));
    
    cout << "...Welcome to your WAREHOUSE app..." << endl;
    cout << "______________________________________" << endl <<  endl;
    
    readList(List);
    
    writeList(List);
    
    bool run = true;
    
    while (run == true) {
        
        cout << "Please, choose a required action:" << endl << endl;
        cout << "0) OPEN WAREHOUSE LIST" << endl;
        cout << "1) ADD GOODS " << endl;
        cout << "2) REMOVE GOODS " << endl;
        cout << "3) SEARCH " << endl;
        cout << "4) EXIT" << endl << endl;
        
        int i = 0;
        cin >> i;
        
        switch (i) {
            case 0:
                for (int c = 0; c < List.size(); c++) {
                    List[c] -> get();
                }
                break;
                
            case 1: {
                cout << "Choose type of good: " << endl;
                cout << "1) Book" << endl;
                cout << "2) Movie" << endl;
                cout << "3) Vinyl" << endl;
                int x = 0;
                cin >> x;
                
                string Name,Type,Info,Author,Genre;
                int Pages,ReleaseYear,StoreYear;
                
                switch (x) {
                    case 1: {
                        cin.ignore();
                        cout << "Enter name: ";
                        getline(cin,Name);
                        cout << "Enter type: ";
                        getline(cin,Type);
                        cout << "Enter info: ";
                        getline(cin,Info);
                        cout << "Enter count of pages: ";
                        cin >> Pages;
                        cin.ignore();
                        cout << "Enter author: ";
                        getline(cin,Author);
                        cout << "Enter year of store: ";
                        cin >> StoreYear;
                        cin.ignore();
                        List.push_back (new Book (Count, Name, Type, Info, Pages, Author, StoreYear));
                        break;
                    }
                    case 2: {
                        cin.ignore();
                        cout << "Enter name: ";
                        getline(cin,Name);
                        cout << "Enter type: ";
                        getline(cin,Type);
                        cout << "Enter info: ";
                        getline(cin,Info);
                        cout << "Enter release year: ";
                        cin >> ReleaseYear;
                        cin.ignore();
                        cout << "Enter director: ";
                        getline(cin,Author);
                        cout << "Enter genre: ";
                        getline(cin,Genre);
                        cout << "Enter year of store: ";
                        cin >> StoreYear;
                        cin.ignore();
                        List.push_back (new Movie (Count, Name, Type, Info, ReleaseYear, Author, Genre, StoreYear));
                        break;
                    }
                    case 3: {
                        cin.ignore();
                        cout << "Enter name: ";
                        getline(cin,Name);
                        cout << "Enter type: ";
                        getline(cin,Type);
                        cout << "Enter info: ";
                        getline(cin,Info);
                        cout << "Enter release year: ";
                        cin >> ReleaseYear;
                        cin.ignore();
                        cout << "Enter artist: ";
                        getline(cin,Author);
                        cout << "Enter genre: ";
                        getline(cin,Genre);
                        cout << "Enter year of store: ";
                        cin >> StoreYear;
                        cin.ignore();
                        List.push_back (new Movie (Count, Name, Type, Info, ReleaseYear, Author, Genre, StoreYear));
                        break;
                    }
                    default:
                        break;
                }
                
                break;
            }
                
            case 2:
                cout << "Enter goods info" << endl;
                // REMOVE();
                break;
                
            case 3:
                cout << "Enter goods ID/name" << endl;
                // SEARCH();
                break;
                
            case 4:
                cout << "Shutting down..." << endl << endl;
                run = false;
                break;
                
            default:
                cout << "Wrong choice! Please try again " << endl << endl;
                break;
        }
    
    }
    
    return 0;
}




    //Function definitions

void readList(vector<Item *>& List) {
    fstream File;
    File.open("/Users/Michael/Desktop/Seminárka/WAREHOUSE/WAREHOUSE/List.csv");
    if(File.is_open()) {
        string id,name,type,info,date,author,genre,store,skipLine;
        getline(File,skipLine);
        while(File.good()) {
            getline(File,id,',');
            getline(File,name,',');
            getline(File,type,',');
            getline(File,info,',');
            getline(File,date,',');
            getline(File,author,',');
            getline(File,genre,',');
            getline(File,store);
            
            if(type == "Knihy" || type == "Books") {
                List.push_back (new Book (stoi(id), name, type, info, stoi(date), author, stoi(store)));
            }
            else if (type == "Movie" || type == "Filmy") {
                List.push_back (new Movie (stoi(id), name, type, info, stoi(date), author, genre, stoi(store)));
            }
            else if (type == "LP" || type == "Vinyl") {
                List.push_back (new Vinyl (stoi(id), name, type, info, stoi(date), author, genre, stoi(store)));
            }
        }
        File.close();
    }
    else {
        cout << "Cannot connect to database!!!" << endl;
        exit(0);
        }
    }

void writeList(vector<Item *>& List) {
    fstream File;
    File.open("/Users/Michael/Desktop/Seminárka/WAREHOUSE/WAREHOUSE/Out.csv");
    if(File.is_open()) {
        File << "ID,Name,Type,Info,Release Year,Author,Genre,Store Date\n";
        for (int c = 0; c < List.size(); c++) {
                File << List[c] -> get2();
            }
        }
    }
