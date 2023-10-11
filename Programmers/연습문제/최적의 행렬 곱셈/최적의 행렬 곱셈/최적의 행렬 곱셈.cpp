#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> matrix) {
	int answer = 0;

	vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix.size() + 1, 0));

	for (int i = 1; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size()-i; j++) {
			dp[j][i+j] = 99999009;
			for (int k = j; k <= j + i; k++) {
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + (matrix[j][0] * matrix[k][1] * matrix[j + i][1]));
			}
		}
	}

	return dp[0][matrix.size() - 1];
}

int main() {
	cout << solution({ {5,3},{3,10},{10,6} });
}