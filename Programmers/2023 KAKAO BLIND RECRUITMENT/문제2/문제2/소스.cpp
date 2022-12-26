#include <string>
#include <vector>
#include <iostream>
using namespace std;

int maxEmo = 0, maxMoney = 0;
vector<vector<int>> u;
vector<int>emo;

void repeat(vector<int> v, vector<int> p, int d) {
	int all = 0, plus = 0;
	if (d == p.size()) {
		for (int i = 0; i < u.size(); i++) {
			int sum = 0;
			for (int j = 0; j < p.size(); j++) {
				if (u[i][0] <= p[j]) {
					sum += (100 - p[j]) * emo[j] / 100;
				}
			}
			if (sum >= u[i][1]) {
				sum = 0;
				plus++;
			}
			all += sum;
		}
		if (maxEmo < plus) {
			maxMoney = all;
			maxEmo = plus;
		}
		else if (maxEmo <= plus && maxMoney < all) {
			maxMoney = all;
			maxEmo = plus;
		}

		return;
	}
	for (int i = 0; i < v.size(); i++) {
		p[d] = v[i];
		repeat(v, p, d + 1);
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	vector<int> answer;
	vector<int> sale = { 40,30,20,10 };
	vector<int> people(emoticons.size());
	u = users;
	emo = emoticons;
	repeat(sale, people, 0);
	answer.push_back(maxEmo);
	answer.push_back(maxMoney);

	return answer;
}

int main() {
	vector<vector<int>> a = { {40,10000},{25,10000} };
	vector<int> b = { 7000,9000 };

	vector<vector<int>> c = { {40,2900},{23,10000},{11,5200},{5,5900},{40,3100},{27,9200},{32,6900} };
	vector<int> d = { 1300,1500,1600,4900 };
	solution(c,d);
}