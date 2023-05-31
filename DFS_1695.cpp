#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
int cnt = 0, chk = 0;
int map[25][25];
int output[500];
int nextArea[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
bool locationChk(int x, int y){
    return (x >= 0 && x < n) && (y >= 0 && y < n); 
}
int dfs(int x, int y){
    chk++;
    map[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + nextArea[i][0];
        int nexty = y + nextArea[i][1];
        if (locationChk(nextx, nexty) && map[nextx][nexty] == 1)
        {
            dfs(nextx, nexty);
        }
    }
    return chk;
    
}
int main(){
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1)
            {
                output[cnt] = dfs(i,j);
                cnt++;
                chk = 0;
            }
        }
    } 

    printf("%d", cnt);
    sort(output, output + cnt);
    for (int i = 0; i < cnt; i++)
    {
        printf("\n%d", output[i]);
    }
    

    return 0;
}