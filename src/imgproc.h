#ifndef IMGPROC_H
#define IMGPROC_H

#include <vector>
#include <string>
using namespace std;

struct Color {
    int r, g, b;
};

vector<string> processImage(string imagePath, int N);

#endif