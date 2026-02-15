#include <iostream>
#include <vector>
#include <string>
#include "fileproc.h"
#include "imgproc.h"
#include "queen.h" 

using namespace std;

int main() {
    string filename;
    int N;

    cout << "Masukkan nama file (contoh: input.txt ATAU input.png ATAU input.jpg): ";
    cin >> filename;
    string filePath = "test/" + filename;

    ifstream cekFile(filePath);
    if (!cekFile.good()) {
        cerr << "ERROR: File tidak ditemukan di: " << filePath << endl;
        cerr << "Pastikan file sudah ditaruh di dalam folder 'test'!" << endl;
        return -1;
    }
    cekFile.close();

    vector<string> board;

    if (filename.find(".png") != string::npos || filename.find(".jpg") != string::npos) {
        cout << "Mendeteksi file gambar: " << filePath << endl;
        cout << "Masukkan ukuran grid N (misal 10): ";
        cin >> N;
        board = processImage(filePath, N); 
    } 
    else {
        cout << "Mendeteksi file teks: " << filePath << endl;
        board = loadBoardTxt(filePath); 
    }

    if (board.empty()) {
        cout << "Gagal memproses board atau board kosong!" << endl;
        return -1;
    }

    printBoard(board);
    probSolver(board); 
    return 0;
}