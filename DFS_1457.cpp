#include<stdio.h>
#include<algorithm>
using namespace std;
int map[100][100];
int area[100];
int m, n, k;
int cnt = 0;
int chkArea = 0;
bool locationChk(int x, int y){
    return (x >= 0 && x < m) && (y >= 0 && y < n); 
}
int nextArea[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dfs(int x, int y) {
    chkArea++;
    map[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + nextArea[i][0];
        int nexty = y + nextArea[i][1];

        if (map[nextx][nexty] == 0 && locationChk(nextx, nexty))
        {
            dfs(nextx, nexty);
        }        
    }
    return chkArea;
}
int main() {
    int i, j;
    int x1, y1, x2, y2;
    scanf("%d %d %d", &n, &m, &k);

    for(int ii = 0; ii < k; ii++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(i = x1; i < x2; i++) {
            for(j = y1; j < y2; j++) {
                map[i][j] = 1;
            }
        }
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if (map[i][j] == 0)
            {
                area[cnt] = dfs(i, j);
                cnt++;
            }
            chkArea = 0;
        }
    }

    printf("%d\n", cnt);
    sort(area, area+cnt);
    for(i = 0; i < cnt; i++) {
        printf("%d ", area[i]);
    }

    return 0;
}