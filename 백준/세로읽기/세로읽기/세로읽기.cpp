#include <iostream>
#define null NULL
using namespace std;

int main() {
	char word1[16] = {};
	char word2[16] = {};
	char word3[16] = {};
	char word4[16] = {};
	char word5[16] = {};

	cin >> word1;
	cin >> word2;
	cin >> word3;
	cin >> word4;
	cin >> word5;

	for (int i = 0; i < 15; i++) {
		if (word1[i] != '\0') cout << word1[i];
		if (word2[i] != '\0') cout << word2[i];
		if (word3[i] != '\0') cout << word3[i];
		if (word4[i] != '\0') cout << word4[i];
		if (word5[i] != '\0') cout << word5[i];
	}
}