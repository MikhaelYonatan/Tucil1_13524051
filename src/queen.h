#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

bool isValid(int x, int y, char color, int N, vector<pair<int, char>>& ans);

void updateBoard(vector<string>& board, vector<pair<int, char>>& ans);

void printBoard(vector<string>& board);

void probSolver(vector<string>& board);