#include<stdio.h>
int arr[500000];
int main()
{
    int n, i, q, bi, mid, st, ed;
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &q);
    
    for(i = 0; i < q; i++)
    {
        st = 0;
        ed = n-1;
        scanf("%d", &bi);
        while(st <= ed)
        {
            mid = (st + ed) /2;
            if(arr[mid] == bi)
            {
                printf("%d ", mid);
                break;
            }
            if(arr[mid] > bi)
                ed = mid - 1;
            else
                st = mid + 1;
        }
        if(st > ed)
            printf("-1 ");
    }
    
    return 0;
}