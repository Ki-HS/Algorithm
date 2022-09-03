#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    int arr[100005];

    int n;
    int cnt = 1;
    int top = 0;
    printf("총 막대기의 개수 : ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("막대기의 길이 : ");
        scanf("%d", &arr[i]);
    }

    top = arr[n - 1];
    for (int i = n - 1; i >= 0; --i)
    {
        if (arr[i] > top)
        {
            cnt++;
            top = arr[i];
        }
    }

    printf("보이는 막대기의 개수는 : %d", cnt);
}