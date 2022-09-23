#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int c, vector<string> cities) {
    int answer = 0;
    if (c == 0)return cities.size() * 5;
    for (int i = 0; i < cities.size(); i++) {
        string data = cities[i];
        std::transform(data.begin(), data.end(), data.begin(), ::tolower);
        cities[i] = data;
    }
    vector<string> v(c, "");
    int idx = 0;

    for (auto i : cities) {
        auto iter = find(v.begin(), v.end(), i);
        if (iter == v.end()) {
            iter = find(v.begin(), v.end(), "");
            if (iter == v.end()) {
                v.push_back(i);
                v.erase(v.begin());
            }
            else {
                iter = find(v.begin(), v.end(), "");
                v[iter - v.begin()] = i;
            }

            answer += 5;
        }
        else { v.erase(iter); v.push_back(i); answer += 1; }
    }
    return answer;
}