#ifndef FILEPROC_H
#define FILEPROC_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> loadBoardTxt(string filename);

void saveBoardTxt(vector<string>& board, string filename);

#endif