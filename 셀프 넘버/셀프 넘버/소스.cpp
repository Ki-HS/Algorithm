#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
	bool* num = new bool[10001];
	memset(num, false, 10001);
	int i = 0;
	int sum = 0;
	int temp;
	while (i < 10000)
	{
		temp = i+1;
		sum = i+1;
		while (temp)
		{
			sum += temp % 10;
			temp /= 10;
		}
		if (sum <= 10000)
			num[sum] = true;
		i++;
	}
	for (int a = 1; a < 10001; a++)
	{
		if (num[a])
			continue;
		cout << a << "\n";
	}
	delete[] num;
}