#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int tSize, K, answer;

void swap(vector<int>& a, vector<int> &b) {
    vector<int> tmp = a;
    a = b;
    b = tmp;
}

void permutation(vector<vector<int>>d, int depth, int n, int r) {
    if (depth == r) {
        int temp = K;
        int tmp = 0;
        for (int i = 0; i < tSize; i++) {
            if (temp < d[i][0] || temp < d[i][1])break;
            temp -= d[i][1];
            tmp++;
        }

        answer = answer < tmp ? tmp : answer;
    }
    for (int i = depth; i < n; i++) {
        swap(d[depth], d[i]);
        permutation(d, depth + 1, n, r);
        swap(d[depth], d[i]);
    }

}

int solution(int k, vector<vector<int>> dungeons) {
    tSize = dungeons.size();
    K = k;
    permutation(dungeons, 0, tSize, tSize);
    return answer;
}

int main() {
    solution(40, { {40,10},{10,10} ,{10,10} ,{10,10} ,{10,10} });
}