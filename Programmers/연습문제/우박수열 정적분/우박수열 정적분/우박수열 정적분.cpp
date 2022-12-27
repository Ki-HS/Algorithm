#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;

    vector<int> v;
    while (k != 1) {
        v.push_back(k);
        if (k % 2) k = k * 3 + 1;
        else k /= 2;
    }
    v.push_back(1);

    vector<double> area;
    for (int i = 0; i < v.size() - 1; i++) {
        double d = v[i] + v[i + 1];
        d /= 2;
        area.push_back(d);
    }

    for (int i = 0; i < ranges.size(); i++) {
        int a = ranges[i][0];
        int b = area.size() + ranges[i][1];

        if (a == b) answer.push_back(0.0);
        else if (a > b)answer.push_back(-1.0);
        else {
            double sum = 0.0;
            for (int i = a; i < b; i++) {
                sum += area[i];
            }
            answer.push_back(sum);
        }
    }

    return answer;
}