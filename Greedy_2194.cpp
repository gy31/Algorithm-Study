#include<stdio.h>
int c[10001], y[10001];
int main()
{
    int n, s, i, price;
    long long ans=0;
    scanf("%d %d", &n, &s);

    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &c[i], &y[i]);
    }

    price = c[1];

    for (i = 1; i <= n; i++)
    {
        price += s;
        if (price > c[i])
        {
            price = c[i];
        }
        ans += price * y[i];
    }

    printf("%lld", ans);

    return 0;
}