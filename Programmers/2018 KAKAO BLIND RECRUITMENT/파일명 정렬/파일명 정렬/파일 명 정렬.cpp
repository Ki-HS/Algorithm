//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//using namespace std;
//
//string lower(string s) {
//    string t = "";
//    for (char& c : s) {
//        t += tolower(c);
//    }
//
//    return t;
//}
//
//struct cmp {
//    bool operator()(vector<string> a, vector<string> b) {
//        int i = 0;
//        int aS = 0, aE = 0;
//        int bS = 0, bE = 0;
//        for (; i < a[0].size(); i++) {
//            if (aS==0&&a[0][i] >= '0' && a[0][i] <= '9')aS = i;
//            if (aS > 0 && (a[0][i] > '9' || a[0][i] < '0')) {
//                aE = i; break;
//            }
//        }
//        i = 0;
//        for (; i < b[0].size(); i++) {
//            if (bS==0&&b[0][i] >= '0' && b[0][i] <= '9')bS = i;
//            if (bS > 0 && (b[0][i] > '9' || b[0][i] < '0')) { bE = i; break; }
//        }
//
//        string aHead, aNum, aTail;
//        aHead = a[0].substr(0, aS);
//        aNum = a[0].substr(aS, aE-2);
//
//        aHead = lower(aHead);
//        //aTail = a.substr(aE, a.size());
//
//        string bHead, bNum, bTail;
//        bHead = b[0].substr(0, bS);
//        bNum = b[0].substr(bS, bE-2);
//        //bTail = b.substr(bE,b.size());
//        bHead = lower(bHead);
//
//        if (aHead == bHead) {
//            if (stoi(aNum) == stoi(bNum)) {
//                return a[1] > b[1];
//            }
//            return stoi(aNum) > stoi(bNum);
//        }
//        return aHead > bHead;
//    }
//};
//
//vector<string> solution(vector<string> files) {
//    vector<string> answer;
//
//    priority_queue<vector<string>, vector<vector<string>>, cmp> pq;
//    for (int i = 0; i < files.size(); i++) {
//        string s = files[i];
//        string idx = "";
//        idx += '0' + i;
//
//        pq.push({ s,idx });
//    }
//
//    while (!pq.empty()) {
//        answer.push_back(pq.top()[0]);
//        pq.pop();
//    }
//    return answer;
//}
//
//int main() {
//    solution({ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });
//}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct fileName {
    int index;
    string head;
    int number;
};

vector<fileName> v;

bool cmp(const fileName& f1, const fileName& f2) {
    if (f1.head == f2.head) {
        if (f1.number == f2.number) {
            return f1.index < f2.index;
        }
        else return f1.number < f2.number;
    }
    else return f1.head < f2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    for (int i = 0; i < files.size(); i++) {
        vector<int> idx;
        for (int j = 0; j < files[i].size(); j++) {
            if ('0' <= files[i][j] && files[i][j] <= '9') {
                idx.push_back(j);
            }
        }
        string head = "";
        for (int j = 0; j < idx[0]; j++) {
            head += tolower(files[i][j]);
        }
        string number = files[i].substr(idx[0], idx.size());

        fileName f;
        f.index = i;
        f.head = head;
        f.number = stoi(number);

        v.push_back(f);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(files[v[i].index]);
    }
    return answer;
}