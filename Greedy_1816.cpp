#include<stdio.h>
#include<algorithm>
using namespace std;
int cow[200], k[200]; // cow : 소의 위치 저장, k : 빈 외양간 길이 저장
int chk(int i, int j)
{
    return i>j;
}
int main()
{
    int i, m, s, c, sum;
    scanf("%d %d %d", &m, &s, &c);

    for(i = 0; i < c; i++)
    {
        scanf("%d", &cow[i]);
    }

    sort(cow, cow+c); // 소 위치 오름차순 정렬
    sum = cow[c-1] - cow[0] + 1; // 소 위치 끝과 끝 = 유효 외양간 길이

    for(i = 0; i < c-1; i++)
    {
        k[i] = cow[i+1] - cow[i] - 1; // 빈 외양간 길이 구하기
    }
    sort(k, k+c-1, chk); // 빈 외양간 내림차순 정렬 -> 가장 긴 것 먼저

    for(i = 0; i < m-1; i++)
    {
        sum -= k[i]; // 외양간 총 길이 - 빈 외양간(가장 긴 순서로 판자 수 만큼)
    }

    printf("%d", sum);

    return 0;
}