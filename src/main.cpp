#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
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
    N = board.size();
    vector<pair<int, char>> ans(N, {-1, '*'});
    probSolver(board, ans);
    cout << endl; 
    
    char saveTxt, savePng;
    string outputName;

    while (true) {
        cout << "Apakah anda ingin menyimpan solusi .txt? (Y/n): ";
        cin >> saveTxt;
        if (saveTxt == 'Y' || saveTxt == 'y') {
            filesystem::path inputPath(filename);
            outputName = "solTxt_" + inputPath.stem().string() + ".txt";
            saveBoardTxt(board, "test/" + outputName); 
            break;
        } else if (saveTxt == 'n' || saveTxt == 'N') {
            break;
        } else {
            cout << "Input tidak valid! Masukkan Y atau n." << endl;
        }
    }

    while (true) {
        cout << "Apakah anda ingin menyimpan solusi .png? (Y/n): ";
        cin >> savePng;
        if (savePng == 'Y' || savePng == 'y') {
            filesystem::path inputPath(filename);
            outputName = "solPng_" + inputPath.stem().string() + ".png";
            saveBoardPng(board, ans, "test/" + outputName);
            break;
        } else if (savePng == 'n' || savePng == 'N') {
            break;
        } else {
            cout << "Input tidak valid! Masukkan Y atau n." << endl;
        }
    }

    cout << "Program selesai!" << endl;
}