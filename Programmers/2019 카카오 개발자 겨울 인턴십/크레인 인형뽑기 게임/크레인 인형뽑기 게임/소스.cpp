#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> v;
    for (int i = 0; i < moves.size(); i++) {
        int j = 0;
        while (j < board.size()&&board[j][moves[i]-1]==0)
            j++;
        if (j == board.size())continue;
        if (v.size() && v[v.size() - 1] == board[j][moves[i] - 1]) {
            answer += 2;
            board[j][moves[i] - 1] = 0;
            v.pop_back();
            continue;
        }
        v.push_back(board[j][moves[i] - 1]);
        board[j][moves[i] - 1] = 0;
    }
    return answer;
}

int main() {
    vector<vector<int>>b = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    vector<int> m = { 1, 5, 3, 5, 1, 2, 1, 4 };
    cout << solution(b, m);
}