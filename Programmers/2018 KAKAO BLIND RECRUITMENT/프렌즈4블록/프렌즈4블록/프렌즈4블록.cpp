#include <iostream>
#include <string>
#include <vector>

using namespace std;
int answer = 0;

void deleteFunction(vector<string>& b, int x, int y) {
    b[x][y] = tolower(b[x][y]);
    answer++;

    if (x > 0 && y > 0) {
        if (b[x][y] == tolower(b[x][y - 1]) && b[x][y] == tolower(b[x - 1][y]) && b[x][y] == tolower(b[x - 1][y - 1])) {
            if (b[x][y] != b[x - 1][y])
                deleteFunction(b, x - 1, y);
            if (b[x][y] != b[x][y - 1])
                deleteFunction(b, x, y - 1);
            if (b[x][y] != b[x - 1][y - 1])
                deleteFunction(b, x - 1, y - 1);
        }
    }
    if (x < b.size() - 1 && y < b[0].size() - 1) {
        if (b[x][y] == tolower(b[x][y + 1]) && b[x][y] == tolower(b[x + 1][y]) && b[x][y] == tolower(b[x + 1][y + 1])) {
            if (b[x][y] != b[x + 1][y])
                deleteFunction(b, x + 1, y);
            if (b[x][y] != b[x][y + 1])
                deleteFunction(b, x, y + 1);
            if (b[x][y] != b[x + 1][y + 1])
                deleteFunction(b, x + 1, y + 1);
        }
    }
    if (x > 0 && y < b[0].size() - 1) {
        if (b[x][y] == tolower(b[x][y + 1]) && b[x][y] == tolower(b[x - 1][y]) && b[x][y] == tolower(b[x - 1][y + 1])) {
            if (b[x][y] != b[x - 1][y])
                deleteFunction(b, x - 1, y);
            if (b[x][y] != b[x][y + 1])
                deleteFunction(b, x, y + 1);
            if (b[x][y] != b[x - 1][y + 1])
                deleteFunction(b, x - 1, y + 1);
        }
    }
    if (x < b.size() - 1 && y>0) {
        if (b[x][y] == tolower(b[x][y - 1]) && b[x][y] == tolower(b[x + 1][y]) && b[x][y] == tolower(b[x + 1][y - 1])) {
            if (b[x][y] != b[x + 1][y])
                deleteFunction(b, x + 1, y);
            if (b[x][y] != b[x][y - 1])
                deleteFunction(b, x, y - 1);
            if (b[x][y] != b[x + 1][y - 1])
                deleteFunction(b, x + 1, y - 1);
        }
    }
}

int solution(int m, int n, vector<string> board) {
    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1]) {
                deleteFunction(board, i, j);
            }
        }
    }

    return answer;
}

int main() {
    cout << solution(4, 5, { "CCBDE", "AAADE", "AAABF", "CCBBF" });
}