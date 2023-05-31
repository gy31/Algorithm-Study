#include<stdio.h>
#include<algorithm>
using namespace std;
struct temp
{
    int a,b;
}location[1001];
int Xchk(temp i, temp j) {
    return i.a > j.a;
}
int Ychk(temp i, temp j) {
    return i.b < j.b;
}

int main() {
    int x, y, n, paper, cm, cover;
    int high, low;

    scanf("%d%d", &x, &y);
    scanf("%d", &paper);
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &location[i].a, &location[i].b);
    }
    
    sort(location,location+n,Xchk);
    high = 10000000;
    low = location[0].a;
    sort(location,location+n,Ychk);

    while (true)
    {
        if(high < low) break;
        cm = (high + low) / 2;
        cover = location[0].b;

        for(int i = 0; i < paper; i++)
        {
            cover += cm - 1;
            if(cover >= n-1)
                continue;
            if (location[cover].b > cover)
            {
                cover = location[cover].b;
            }
        }

        if(cover == location[n-1].b)
            break;
        if(cover > location[n-1].b)
            high = cm - 1;
        else
            low = cm + 1;
    }
    
    printf("%d", cm);

    return 0;
}