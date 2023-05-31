#include<stdio.h>
#include<algorithm>
using namespace std;
struct temp
{
    int x, y;
}a[10000];
int chk(temp i, temp j)
{
    return i.y < j.y;
}

int main()
{
    int n, i, cnt = 0, max = -999;
    scanf("%d", &n);

    for ( i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    

    sort(a, a+n, chk);

    for ( i = 0; i < n; i++)
    {
        if (a[i].x > max)
        {
            max = a[i].y;
            cnt++;
        }
    }
    
    printf("%d", cnt);

    return 0;
}