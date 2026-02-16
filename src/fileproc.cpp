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
        for (int j = 0; j < col; j++) {
            char c = board[i][j];

            if (c < 'A' || c > 'Z') {
                cerr << "Error: Karakter tidak valid ditemukan di baris " << i + 1 << ", kolom " << j + 1 << endl;
                cerr << "Papan hanya boleh berisi Huruf Kapital (A-Z) tanpa spasi." << endl;
                exit(1);
            }
        }
    }

    cout << "Berhasil membaca papan berukuran " << row << "x" << col << endl;
    return board;
}

void saveBoardTxt(vector<string>& board, string filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Tidak bisa membuat file " << filename << endl;
        return;
    }

    int N = board.size();
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            file << board[i][j];
        }
        if (i < N - 1) file << '\n';
    }

    file.close();
    cout << "Berhasil menyimpan solusi teks ke: " << filename << endl;
}