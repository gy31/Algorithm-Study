#include<stdio.h>
#include<algorithm>
using namespace std;
struct temp
{
    int num, x, y;
}t[501];
int chk(temp i, temp j)
{
    return i.y < j.y;
}
int main()
{
    int i, j, n, cnt = 0;
    int ot[501];
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &t[i].num, &t[i].x, &t[i].y);
    }
    sort(t, t+n+1, chk);    

    for(i = 1; i <= n; i++)
    {
        for(j = i+1; j <= n; j++)
        {
            if (t[i].y <= t[j].x)
            {
                if (cnt == 0)
                {
                    ot[++cnt] = t[i].num;
                }
                ot[++cnt] = t[j].num;
                i = j-1;
                break;
            }
        }
    }

    printf("%d\n", cnt);
    for(i = 1; i <= cnt; i++)
    {
        printf("%d ", ot[i]);
    }

    return 0;
}