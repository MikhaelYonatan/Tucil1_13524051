#include "imgproc.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
using namespace cv;
using namespace std;

double getColorDistance(const Color& c1, const Color& c2) {
    return sqrt(pow(c1.r - c2.r, 2) + pow(c1.g - c2.g, 2) + pow(c1.b - c2.b, 2));
}

vector<string> processImage(string imagePath, int N) {
    Mat img = imread(imagePath);
    if (img.empty()) {
        cerr << "Error: Gambar tidak ditemukan atau format salah!" << endl;
        return {};
    }

    int height = img.rows;
    int width = img.cols;
    int cellH = height / N;
    int cellW = width / N;

    vector<string> board(N, string(N, ' '));
    vector<pair<Color, char>> knownColors;
    char nextChar = 'A';
    const double THRESHOLD = 30.0; 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int centerX = (j * cellW) + (cellW / 2);
            int centerY = (i * cellH) + (cellH / 2);

            Vec3b pixel = img.at<Vec3b>(centerY, centerX);
            Color currColor = {pixel[2], pixel[1], pixel[0]};

            char assignedChar = '?';
            bool found = false;

            for (auto& kc : knownColors) {
                if (getColorDistance(currColor, kc.first) < THRESHOLD) {
                    assignedChar = kc.second;
                    found = true;
                    break;
                }
            }

            if (!found) {
                assignedChar = nextChar;
                knownColors.push_back({currColor, assignedChar});
                nextChar++;
            }
            board[i][j] = assignedChar;
        }
    }
    return board;
}