#include<stdio.h>
#include<algorithm>
using namespace std;
int weight[1000];
int n,sum=0;
int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }
    
    sort(weight, weight+n);

    for (int i = 0; i < n; i++)
    {
        if (weight[i] > sum+1)
            break;
        sum += weight[i];        
    }
    
    printf("%d",sum+1);

    return 0;
}