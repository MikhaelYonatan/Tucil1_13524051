#include "fileproc.h"
#include "queen.h"

vector<string> loadBoardTxt(string filename) {
    vector<string> board;
    string line;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: File " << filename << " gagal dibuka!" << endl;
        exit(1);
    }

    while (getline(file, line)) {
        while (!line.empty() && isspace(line.back())) {
            line.pop_back();
        }

        if (!line.empty()) {
            board.push_back(line);
        }
    }

    file.close();

    if (board.empty()) {
        cerr << "Error: File kosong!" << endl;
        exit(1);
    }
    
    int row = board.size();
    int col = board[0].length();

    if (row != col) {
        cerr << "Error: Ukuran papan tidak persegi!" <<
                "(Baris: " << row << ", Kolom: " << col << ")" << endl;
        exit(1);
    }

    for (int i = 0 ; i < row ; i++) {
        if (board[i].length() != col) {
            cerr << "Ukuran papan tidak valid di baris-" << i + 1 << endl;
            exit(1);
        }
    }

    cout << "Berhasil membaca papan berukuran " << row << "x" << col << endl;
    return board;
}