#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> a1 = { 1,2,3,4,5 };
    vector<int> a2 = { 2,1,2,3,2,4,2,5 };
    vector<int> a3 = { 3,3,1,1,2,2,4,4,5,5 };

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == a1[i % 5])a++;
        if (answers[i] == a2[i % 8])b++;
        if (answers[i] == a3[i % 10])c++;
    }
    int max = a;
    if (max < b)max = b;
    if (max < c)max = c;
    if (max == a)answer.push_back(1);
    if (max == b)answer.push_back(2);
    if (max == c)answer.push_back(3);


    return answer;
}