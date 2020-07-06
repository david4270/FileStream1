#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#ifndef datahandle_h
#define datahandle_h
//program
void modFile();
//file handling
void readFile(string fileName);
void writeFile(string fileName, vector <string> ls);
//features handling string vector
void insertInfo(vector<string> & ls);
void searchInfo(vector<string> &ls);
void deleteInfo(vector<string> &ls);
void editInfo(vector<string> &ls);
#endif