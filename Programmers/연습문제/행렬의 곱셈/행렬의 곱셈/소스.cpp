#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> ans(arr1.size(), vector<int>(arr2[0].size(), 0));

    for (int k = 0; k < arr2.size(); k++) {
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[0].size(); j++) {
                ans[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }



    return ans;
}