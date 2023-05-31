#include<stdio.h>
int tree[1000000];
int main()
{
    int n, m, i, low = 0, high = 0, cut, have;
    int cnt = 0;
    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &tree[i]);
        if (tree[i] > high)
            high = tree[i];
    }

    while (have != m)
    {
        have = 0;
        cut = (high + low) / 2;

        if(high < low)
            break;

        for (i = 0; i < n; i++)
        {
            if(tree[i] > cut)
                have += tree[i] - cut;
            if (have > m) 
                break;            
        }        
        if(have == m)
            break;
            
        if (have < m)
            high = cut - 1;
        else
            low = cut + 1;
    }
    
    printf("%d", cut);

    return 0;
}