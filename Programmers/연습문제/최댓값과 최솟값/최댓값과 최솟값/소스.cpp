#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string solution(string s) {
    vector<int> v;
    stringstream sstream(s);
    string tmp;
    while (sstream >> tmp)v.push_back(stoi(tmp));


    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());
    string t;
    t += to_string(min);
    t += ' ';
    t += to_string(max);
    return t;
}