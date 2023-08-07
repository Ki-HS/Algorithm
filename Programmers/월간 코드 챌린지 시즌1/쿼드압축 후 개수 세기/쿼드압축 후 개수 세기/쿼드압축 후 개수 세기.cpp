#include <string>
#include <vector>
#include <map>
using namespace std;
map<int, int> m;

void dfs(vector<vector<int>> arr, int sX, int sY, int eX, int eY) {
    if (eX - sX == 1) {
        m[arr[sX][sY]]++;
        return;
    }
    bool flag = false;
    for (int i = sX; i < eX; i++) {
        for (int j = sY; j < eY; j++) {
            if (arr[sX][sY] != arr[i][j]) {
                if (eX - sX == 2) {
                    m[arr[sX][sY]]++;
                    m[arr[sX + 1][sY]]++;
                    m[arr[sX][sY + 1]]++;
                    m[arr[sX + 1][sY + 1]]++;
                }
                else {
                    dfs(arr, sX, sY, (eX - sX) / 2 + sX, (eY - sY) / 2 + sY);
                    dfs(arr, sX, (eY - sY) / 2 + sY, (eX - sX) / 2 + sX, eY);
                    dfs(arr, (eX - sX) / 2 + sX, sY, eX, (eY - sY) / 2 + sY);
                    dfs(arr, (eX - sX) / 2 + sX, (eY - sY) / 2 + sY, eX, eY);
                }

                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    if (!flag) {
        m[arr[sX][sY]]++;
        return;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    dfs(arr, 0, 0, arr.size(), arr.size());

    answer.emplace_back(m[0]);
    answer.emplace_back(m[1]);

    return answer;
}