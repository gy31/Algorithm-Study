#include<stdio.h>
#include<stdlib.h>
int target[21];
int m, min=999;
void dfs(int op1, int op2, int i, int chk) {
    if (chk > min)
        return;
    
    if (i >= m)
    {
        if(chk < min)
            min = chk;
        return;
    }
    else
    {
        dfs(target[i], op2, i+1, chk+abs(target[i]-op1));
        dfs(op1, target[i], i+1, chk+abs(target[i]-op2));
    }
}
int main() 
{
    int a,n,op1,op2;
    scanf("%d%d%d", &n, &op1, &op2);
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a);
        target[i] = a;
    }

    dfs(op1, op2, 0, 0);

    printf("%d", min);

    return 0;
}