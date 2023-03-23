#include <string>
#include <vector>

using namespace std;

int find_u(vector<string> vs) {
    for (int i = 0; i < vs.size(); i++) {
        for (int j = 0; j < vs[i].size(); j++) {
            if (vs[i][j] == '#') {
                return i;
            }
        }
    }
    return 0;
}
int find_d(vector<string> vs) {
    for (int i = vs.size() - 1; i >= 0; i--) {
        for (int j = 0; j < vs[i].size(); j++) {
            if (vs[i][j] == '#') {
                return i;
            }
        }
    }
    return 0;
}
int find_l(vector<string> vs) {
    int size = vs[0].size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < vs.size(); j++) {
            if (vs[j][i] == '#') {
                return i;
            }
        }
    }
    return 0;
}
int find_r(vector<string> vs) {
    int size = vs[0].size();
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < vs.size(); j++) {
            if (vs[j][i] == '#') {
                return i;
            }
        }
    }
    return 0;
}

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int w, h;
    w = wallpaper.size() - 1;
    h = wallpaper[0].size() - 1;


    answer.push_back(find_u(wallpaper));
    answer.push_back(find_l(wallpaper));
    answer.push_back(find_d(wallpaper) + 1);
    answer.push_back(find_r(wallpaper) + 1);

    return answer;
}