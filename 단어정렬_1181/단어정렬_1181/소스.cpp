#include <iostream>
#include <stdlib.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#define null NULL
int main()
{
	int n;
	cin >> n;
	if (n < 1 || n>20000) {
		return 0;
	}
	char word[20000][50] = {};
	for (int i = 0; i < n; i++) {
		cin >> word[i];
		word[i][strlen(word[i])] = '\0';
		for (int j = 0; j < strlen(word[i]); j++) {
			if (!isalpha(word[i][j])) {
				i--;
				continue;
			}
		}
	}
	
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n; j++) {
			if (strcmp(word[j], word[j + 1]) > 0) {
				char *temp = word[j];
				strcpy_s(word[j], word[j + 1]);
				strcpy_s(word[j+1], temp);
			}
			else if (strcmp(word[j], word[j + 1]) == 0) {
				int k = j;
				while (word[k + 2]) {
					char* temp = word[k + 1];
					strcpy_s(word[k + 1], word[k + 2]);
					strcpy_s(word[k + 2], temp);
					k++;
				}
				strcpy_s(word[k + 1], null);
			}
		}
	}
	int c = 0;
	while (word[c]) {
		int q = 0;
		while (q != strlen(word[c])) {
			cout << word[c][q];
			q++;
		}
		cout << '\n';
		c++;
	}
	return 0;
}