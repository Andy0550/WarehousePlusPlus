//
//  main.cpp
//  WAREHOUSE
//
//  Created by Michael Dvořák on 06/09/2018.
//  Copyright © 2018 Michael Dvořák. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "class.h"

using namespace std;

//Function declarations

void printVec(vector<Item *>& List);

void readList(vector<Item *>& List);

void writeList(vector<Item *>& List);


//Main

int main(int argc, const char * argv[]) {
    vector<Item *> List;
    
    cout << "...Welcome to your WAREHOUSE app..." << endl;
    cout << "______________________________________" << endl <<  endl;
    
    readList(List);
    
    bool run = true;
    
    while (run == true) {
        cout << "Please, choose a required action:" << endl << endl;
        cout << "0) OPEN WAREHOUSE LIST" << endl;
        cout << "1) ADD ITEMS " << endl;
        cout << "2) REMOVE ITEMS " << endl;
        cout << "3) SEARCH " << endl;
        cout << "4) EXIT" << endl << endl;
        
        int i = 0;
        cin >> i;
        if (cin.fail()) {
            cout << "Input only numbers!!!" << endl;
            break;
        }
        
        switch (i) {
            case 0:
                printVec(List);
                break;
                
            case 1: {
                cout << "Choose type of item: " << endl;
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
                        cout << "Enter release year: ";
                        cin >> ReleaseYear;
                        cin.ignore();
                        cout << "Enter count of pages: ";
                        cin >> Pages;
                        cin.ignore();
                        cout << "Enter author: ";
                        getline(cin,Author);
                        cout << "Enter year of store: ";
                        cin >> StoreYear;
                        cin.ignore();
                        List.push_back (new Book (Item::Count, Name, Type, Info, ReleaseYear, Pages, Author, StoreYear));
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
                        List.push_back (new Movie (Item::Count, Name, Type, Info, ReleaseYear, Author, Genre, StoreYear));
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
                        List.push_back (new Movie (Item::Count, Name, Type, Info, ReleaseYear, Author, Genre, StoreYear));
                        break;
                    }
                    default:
                        break;
                }
                writeList(List);
                break;
            }
                
            case 2:
                printVec(List);
                cout << "Enter item's ID: " << endl;
                cin >> i;
                for (int c = 0; c < List.size(); c++) {
                    if((List[c] -> getID()) == i) {
                        List.erase(List.begin() + c);
                    }
                }
                printVec(List);
                writeList(List);
                break;
                
            case 3: {
                cout << "Enter item's ID/name: ";
                string i;
                cin >> i;
                for (int c = 0; c < List.size(); c++) {
                    if((List[c] -> getID()) == stoi(i) || List[c] -> getName() == i) {
                        List[c] -> get();
                    }
                }
                break;
            }
                
            case 4:
                cout << "Shutting down..." << endl << endl;
                run = false;
                break;
                
            default:
                cout << "Wrong choice!!! Please try again. " << endl << endl;
                break;
        }
    
    }
    
    return 0;
}




    //Function definitions


void printVec(vector<Item *>& List) {
    for (int c = 0; c < List.size(); c++) {
        List[c] -> get();
    }
}

void readList(vector<Item *>& List) {
    fstream File;
    File.open("/Users/Michael/Desktop/Seminárka/WAREHOUSE/WAREHOUSE/List.csv");
    if(File.is_open()) {
        string id,name,type,info,date,pages,author,genre,store,skipLine;
        getline(File,skipLine);
        while(File.good()) {
            getline(File,id,',');
            if(id == "") continue;
            getline(File,name,',');
            getline(File,type,',');
            getline(File,info,',');
            getline(File,date,',');
            getline(File,pages,',');
            getline(File,author,',');
            getline(File,genre,',');
            getline(File,store);
            
            try {
            
            if(type == "Book" || type == "Books") {
                List.push_back (new Book (Item::Count, name, type, info, stoi(date),stoi(pages), author, stoi(store)));
            }
            else if (type == "Movie" || type == "Movies") {
                List.push_back (new Movie (Item::Count, name, type, info, stoi(date), author, genre, stoi(store)));
            }
            else if (type == "LP" || type == "Vinyl") {
                List.push_back (new Vinyl (Item::Count, name, type, info, stoi(date), author, genre, stoi(store)));
            }
            } catch (invalid_argument) {
                continue;
            }
        }
        
        Item::Count = (List[List.size() - 1]->getID())+1;
        File.close();
    }
    else {
        cout << "Cannot connect to database!!!" << endl;
        exit(0);
        }
    }

void writeList(vector<Item *>& List) {
    fstream File;
    File.open("/Users/Michael/Desktop/Seminárka/WAREHOUSE/WAREHOUSE/List.csv",ios_base::out);
    if(File.is_open()) {
        File << "ID,Name,Type,Info,Release Year,Pages,Author,Genre,Store Date\n";
        for (int c = 0; c < List.size(); c++) {
                File << List[c] -> get2();
            }
        }
    }
