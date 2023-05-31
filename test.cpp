#include<stdio.h>
int score[1000];
int main() {
    int n, sum = 0, cnt = 0;
    double avg;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &score[i]);
        sum += score[i];
    }
    
    avg = sum / n;

    for (int i = 0; i < n; i++)
    {
        if (score[i] > avg)
        {
            cnt++;
        }
    }
    
    printf("%.3f", (double)cnt/n*100);

    return 0;
}