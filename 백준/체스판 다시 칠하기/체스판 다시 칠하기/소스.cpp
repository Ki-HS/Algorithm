#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie();
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	vector<vector<char>>board;
	vector<vector<char>>temp;

	for (int i = 0; i < a; i++) {
		vector<char> square;
		char w;
		for (int j = 0; j < b; j++) {
			cin >> w;
			square.push_back(w);
		}
		board.push_back(square);
	}
	temp = board;
	int q = a * b;
	int c = 0;

	for (int i = 0; i <= a - 8; i++) {
		for (int k = 0; k <= b - 8; k++) {
			board = temp;
			c = 0;
			if (board[i][k] == 'W') {
				for (int j = i; j < i + 8; j++) {
					if (j > i) {
						if (board[j - 1][k] == 'W' && board[j][k] == 'W') {
							board[j][k] = 'B';
							c++;
						}
						else if (board[j - 1][k] == 'B' && board[j][k] == 'B') {
							board[j][k] = 'W';
							c++;
						}
					}
					for (int l = k + 1; l < k + 8; l++) {
						if (board[j][l - 1] == 'W' && board[j][l] == 'W') {
							board[j][l] = 'B';
							c++;
						}
						else if (board[j][l - 1] == 'B' && board[j][l] == 'B') {
							board[j][l] = 'W';
							c++;
						}
					}
				}
				board = temp;
				if (q > c)q = c;
				c = 0;
				board[i][k] = 'B';
				c++;
				for (int j = i; j < i + 8; j++) {
					if (j > i) {
						if (board[j - 1][k] == 'W' && board[j][k] == 'W') {
							board[j][k] = 'B';
							c++;
						}
						else if (board[j - 1][k] == 'B' && board[j][k] == 'B') {
							board[j][k] = 'W';
							c++;
						}
					}
					for (int l = k + 1; l < k + 8; l++) {
						if (board[j][l - 1] == 'W' && board[j][l] == 'W') {
							board[j][l] = 'B';
							c++;
						}
						else if (board[j][l - 1] == 'B' && board[j][l] == 'B') {
							board[j][l] = 'W';
							c++;
						}
					}
				}
			}
			else {
				for (int j = i; j < i + 8; j++) {
					if (j > i) {
						if (board[j - 1][k] == 'W' && board[j][k] == 'W') {
							board[j][k] = 'B';
							c++;
						}
						else if (board[j - 1][k] == 'B' && board[j][k] == 'B') {
							board[j][k] = 'W';
							c++;
						}
					}
					for (int l = k + 1; l < k + 8; l++) {
						if (board[j][l - 1] == 'W' && board[j][l] == 'W') {
							board[j][l] = 'B';
							c++;
						}
						else if (board[j][l - 1] == 'B' && board[j][l] == 'B') {
							board[j][l] = 'W';
							c++;
						}
					}
				}
				if (q > c)q = c;
				c = 0;
				board = temp;
				board[i][k] = 'W';
				c++;
				for (int j = i; j < i + 8; j++) {
					if (j > i) {
						if (board[j - 1][k] == 'W' && board[j][k] == 'W') {
							board[j][k] = 'B';
							c++;
						}
						else if (board[j - 1][k] == 'B' && board[j][k] == 'B') {
							board[j][k] = 'W';
							c++;
						}
					}
					for (int l = k + 1; l < k + 8; l++) {
						if (board[j][l - 1] == 'W' && board[j][l] == 'W') {
							board[j][l] = 'B';
							c++;
						}
						else if (board[j][l - 1] == 'B' && board[j][l] == 'B') {
							board[j][l] = 'W';
							c++;
						}
					}
				}
			}
			if (q > c)q = c;
		}
	}
	cout << q;
}