#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

//첫 번째 방법 (큐 사용)
//int solution(vector<int> elements) {
//    int answer = 0;
//    map<int, int> m;
//    queue<int> q;
//
//    for (int e : elements) {
//        q.push(e);
//        m[e]++;
//    }
//
//    for (int i = 2; i <= elements.size(); i++) {
//        if (i == elements.size()) {
//            int tmp = 0;
//            for (int k = 0; k < i; k++) {
//                tmp += q.front();
//                q.push(q.front());
//                q.pop();
//            }
//            m[tmp]++;
//            break;
//        }
//        for (int j = 0; j < elements.size(); j++) {
//            int tmp = 0;
//            for (int k = 0; k < i; k++) {
//                tmp += q.front();
//                q.push(q.front());
//                q.pop();
//            }
//            m[tmp]++;
//        }
//
//    }
//
//    return m.size();
//}

int solution(vector<int> elements) {
	int answer = 0;
	vector<int> tmp = elements;
	map<int, int> m;
	for (int j = 0; j < elements.size(); j++) m[elements[j]]++;

	for (int i = 2; i <= elements.size(); i++) {
		for (int j = 0; j < elements.size(); j++) {
			elements[j] += tmp[(j + i-1) % elements.size()];
		}

		for (int j = 0; j < elements.size(); j++) m[elements[j]]++;
	}
	answer = m.size();
	return answer;
}

int main() {
	cout << solution({ 1,2,3,4 });
}