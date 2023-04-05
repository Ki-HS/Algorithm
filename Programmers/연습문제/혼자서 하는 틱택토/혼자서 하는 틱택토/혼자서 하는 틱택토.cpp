#include <string>
#include <vector>

using namespace std;

bool check(vector<string> board) {

    bool status1, status2;
    status1 = status2 = false;
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') ||
            (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O'))
            status1 = true;
    }
    if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
        board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
        status1 = true;

    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') ||
            (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X'))
            status2 = true;
    }
    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
        board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
        status2 = true;
    int x, o;
    x = o = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X')x++;
            if (board[i][j] == 'O')o++;
        }
    }
    if (o - x >= 2 || x > o || (status1 && status2))return false;
    if (status1) {
        if (x == o)return false;
    }
    else if (status2)
        if (o > x)return false;

    return true;
}

int solution(vector<string> board) {
    int answer = (check(board)) ? 1 : 0;
    return answer;
}