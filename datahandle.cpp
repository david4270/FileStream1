//http://www.cplusplus.com/doc/tutorial/files/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "datahandle.h"

using namespace std;

int main(){
   modFile();
    return 0;
}

void modFile(){
    char command;
    string fileName = "example.txt";
    bool programEnd = false;
    vector <string> dataSet;

    while(!programEnd){
        cout << endl;
        cout << "Commands: "<<endl; 
        cout << "R - read" <<endl;
        cout << "W - write"<<endl;
        cout << "I - insert info" <<endl;
        cout << "S - search info" <<endl;
        cout << "D - delete info" <<endl; 
        cout << "C - clear info" <<endl; 
        cout << "E - edit info" <<endl;
        cout << "X - exit program" <<endl;
        cout << "Enter: "; 
        cin >> command;
        if (command == 'R' || command == 'r'){
            cout << "Reading " << fileName << "..." <<endl;
            readFile(fileName);
        }
        else if (command == 'W' || command == 'w'){
            cout << "Writing " << fileName << "..." <<endl;
            writeFile(fileName,dataSet);
        }
        else if (command == 'I' || command == 'i'){
            cout << "Inserting info..." <<endl;
            insertInfo(dataSet);
            writeFile(fileName,dataSet);
        }
        else if (command == 'X' || command == 'x'){
            programEnd = true;
        }
        else if (command == 'S' || command == 's'){
            cout << "Searching info..." <<endl;
            searchInfo(dataSet);
        }
        else if (command == 'D' || command == 'd'){
            cout << "Deleting info..." <<endl;
            deleteInfo(dataSet);
            writeFile(fileName,dataSet);
        }
        else if (command == 'C' || command == 'c'){
            cout << "Clearing info..." <<endl;
            dataSet.clear();
            writeFile(fileName,dataSet);
        }
        else if (command == 'E' || command == 'e'){
            cout << "Editing info..." <<endl;
            editInfo(dataSet);
            writeFile(fileName,dataSet);
        }
        else{
            cout << "Error: Invalid operation!" <<endl;
        }
    }
    dataSet.clear();
    writeFile(fileName,dataSet);
    cout << "Exiting program..." <<endl;
}

void insertInfo(vector<string> & ls){
    string line;
    cout << "Type a string: ";
    cin >> line;
    ls.push_back(line);
}

void searchInfo(vector<string> &ls){
    string toSearch;
    bool isFound = false;
    cout << "What is the item to search?: ";
    cin >> toSearch;
    for(auto it = 0; it < ls.size(); ++it){
        if (ls[it].compare(toSearch) == 0){
            cout << toSearch << " is found at line " << it+1 << " of the document" <<endl;
            isFound = true;
        }
    }
    if (!isFound){
        cout << "There is no information which corresponds to " << toSearch << endl;
    }
}

void deleteInfo(vector<string> &ls){
    string toSearch;
    bool isFound = false;
    cout << "What is the item to delete?: ";
    cin >> toSearch;
    for(auto it = 0; it < ls.size(); ++it){
        if (ls[it].compare(toSearch) == 0){
            ls.erase(ls.begin()+it);
            isFound = true;
        }
        
    }
    if (!isFound){
        cout << "Error: the operation is failed to remove " << toSearch << endl;
    }
}

void editInfo(vector<string> &ls){
    string toSearch, toChange;
    bool isFound = false;
    cout << "What is/are the item(s) to change?: ";
    cin >> toSearch;
    cout << "What do you want to change that item into?: ";
    cin >> toChange;
    for(auto it = 0; it < ls.size(); ++it){
        if (ls[it].compare(toSearch) == 0){
            ls[it] = toChange;
            isFound = true;
            cout << "We have changed " << toSearch << " into " << toChange << " in line " << it+1 << endl;
        }
    }
    if (!isFound){
        cout << "There is no information which corresponds to " << toSearch << endl;
    }
}

void readFile(string fileName){
    string line;
    ifstream myFileR(fileName);
    if(myFileR.is_open()){
        while(getline(myFileR,line)){
            cout << line <<endl;
        }
        myFileR.close();
    }
    else cout << "Error: Unable to read "<< fileName <<"!" <<endl;
}

void writeFile(string fileName, vector <string> ls){
    ofstream myFile(fileName);
    if(myFile.is_open()){
        for(auto it=0; it<ls.size(); ++it){
            myFile << ls[it] <<endl;
            //cout << ls[it]<<endl;
        }
        myFile.close();
    }
    else cout << "Error: Unable to write "<< fileName<< "!" <<endl;
}