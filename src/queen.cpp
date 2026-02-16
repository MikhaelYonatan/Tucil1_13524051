#include "queen.h"

bool isValid(int x, int y, char color, int N, vector<pair<int, char>>& ans) {
    if (ans[x].first != -1) return false;
    for (int i = 0 ; i < N ; i++) {
        if (ans[i].first == -1) continue;
        int queenCol = ans[i].first;
        char queenColor = ans[i].second;
        if(queenCol == y) return false;
        if (queenColor == color) return false;
        if (abs(x - i) == 1 && abs(y - queenCol) == 1) {
            return false;
        }
    }
    return true;
}

void updateBoard(vector<string>& board, vector<pair<int, char>>& ans) {
    int x, y;
    for (int i = 0 ; i < ans.size() ; i++) {
        x = i;
        y = ans[i].first;
        if (y != - 1) {
            board[x][y] = '#';
        }
    }
}

void printBoard(vector<string>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void probSolver(vector<string>& board, vector<pair<int, char>>& ans) {
    int N = board.size();
    int rowIt = 0;
    int colIt = 0;
    int found = 0;
    bool solved = false;

    long long iteration = 0;
    auto start = chrono::high_resolution_clock::now();
    auto lastUpdate = start;
    const int UPDATE_INTERVAL_MS = 25;
    while (found < N && !solved) {
        iteration++;
        auto now = chrono::high_resolution_clock::now();
        double elapsed = chrono::duration_cast<chrono::milliseconds>(now - lastUpdate).count();

        if (elapsed >= UPDATE_INTERVAL_MS) {
            cout << "==== LIVE UPDATE ====" << endl;
            cout << "Iterasi ke: " << iteration << endl;
            cout << "Queens ditempatkan: " << found << "/" << N << endl;
            cout << "Sedang mengecek: (" << rowIt << ", " << colIt << ")" << endl;
            
            updateBoard(board, ans);
            printBoard(board);
            
            lastUpdate = now;
        }

        if (colIt < N && rowIt < N) {
            if (isValid(rowIt, colIt, board[rowIt][colIt], N, ans)) {
                found++;
                ans[rowIt] = {colIt, board[rowIt][colIt]};
            }

            if (found == N) {
                solved = true;
            }
        }
        
        if (colIt < N) {
            colIt++;
        }
        else {
            if (rowIt < N) {
                rowIt++;
                colIt = 0;
            }
            else {
                found--;
                int lastQueenRow = rowIt - 1;
                while (lastQueenRow >= 0 && ans[lastQueenRow].first == -1) {
                    lastQueenRow--;
                }
                if (found < 0 || lastQueenRow < 0) {
                    break;
                }
                else {
                    rowIt = lastQueenRow;
                    colIt = ans[rowIt].first;
                    board[rowIt][colIt] = ans[rowIt].second;
                    colIt++;
                    ans[rowIt] = {-1, '*'};
                }
            }
        }        
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    if (solved) {
        cout << "INI JAWABANNYA!" << endl;
        updateBoard(board, ans);
        printBoard(board);
    }
    else {
        cout << "PAPAN INI MUSTAHIL DISELESAIKAN, HIKS :(" << endl;
        exit(1);
    }
    cout << "Jumlah iterasi yang dilakukan: " << iteration << endl;
    cout << "Waktu Eksekusi: " << duration.count() << " ms" << endl;
}