#include<stdio.h>
int main()
{
    int a, b, c, d, e, n, cnt = 0;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &n);

    if(n >= 16)
    {
        if(e < n / 16)
        {
            cnt += e;
            n -= e * 16;
        }
        else
        {
            cnt += n / 16;
            n %= 16;
        }
    }
    if(n >= 8)
    {
        if(d < n / 8)
        {
            cnt += d;
            n -= d * 8;
        }
        else
        {
            cnt += n / 8;
            n %= 8;
        }
    }
    if(n >= 4)
    {
        if(c < n / 4)
        {
            cnt += c;
            n -= c * 4;
        }
        else
        {
            cnt += n / 4;
            n %= 4;
        }
    }
    if(n >= 2)
    {
        if(b < n / 2)
        {
            cnt += b;
            n -= b * 2;
        }
        else
        {
            cnt += n / 2;
            n %= 2;
        }
    }
    if(n <= a)
        printf("%d", cnt + n);
    else
        printf("impossible");

    return 0;
}