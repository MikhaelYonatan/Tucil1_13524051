#include "fileproc.h"
#include "queen.h"

int main() {
    string namaFile;
    cout << "Masukkan nama file: ";
    cin >> namaFile;
    vector<string> board = loadBoard(namaFile);
    probSolver(board);
}