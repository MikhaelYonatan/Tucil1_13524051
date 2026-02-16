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

void overlayImage(Mat& background, const Mat& foreground, Point location) {
    if (location.x + foreground.cols > background.cols || location.y + foreground.rows > background.rows) return;

    for (int y = 0; y < foreground.rows; y++) {
        for (int x = 0; x < foreground.cols; x++) {
            Vec4b fgPixel = foreground.at<Vec4b>(y, x);
            
            if (fgPixel[3] > 0) { 
                background.at<Vec3b>(location.y + y, location.x + x) = Vec3b(fgPixel[0], fgPixel[1], fgPixel[2]);
            }
        }
    }
}

void saveBoardPng(vector<string>& board, vector<pair<int, char>>& ans, string filename) {
    int N = board.size();
    int cellSize = 60;
    int imgSize = N * cellSize;

    Mat queenIcon = imread("src/queen.png", IMREAD_UNCHANGED); 

    if (queenIcon.empty()) {
        cerr << "Error: Icon ratu tidak ditemukan!" << endl;
    } else {
        resize(queenIcon, queenIcon, Size(cellSize * 0.8, cellSize * 0.8));
    }

    Mat resultImg(imgSize, imgSize, CV_8UC3, Scalar(255, 255, 255));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c = board[i][j];
            bool isQueen = false;

            if (c == '#') {
                isQueen = true;
                c = ans[i].second; 
            }

            int r = (c * 70) % 255; 
            int g = (c * 150) % 255;
            int b = (c * 200) % 255;
            Scalar bgColor(b, g, r);

            Point topLeft(j * cellSize, i * cellSize);
            Point bottomRight((j + 1) * cellSize, (i + 1) * cellSize);

            rectangle(resultImg, topLeft, bottomRight, bgColor, FILLED);

            rectangle(resultImg, topLeft, bottomRight, Scalar(0, 0, 0), 2);

            if (isQueen && !queenIcon.empty()) {
                int iconX = topLeft.x + (cellSize - queenIcon.cols) / 2;
                int iconY = topLeft.y + (cellSize - queenIcon.rows) / 2;
                
                overlayImage(resultImg, queenIcon, Point(iconX, iconY));
            }
        }
    }

    imwrite(filename, resultImg);
    cout << "Gambar solusi disimpan ke: " << filename << endl;
}