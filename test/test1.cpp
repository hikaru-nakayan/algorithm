#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int H, W;
int sum;
int area;
static const int MAX_H = 101;
static const int MAX_W = 101;

char map[MAX_H][MAX_W];
int color[MAX_H][MAX_W];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};



void input()
{
    cin >> H >> W;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j ++)
            cin >> map[i][j];
    }
}

void init()
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j ++)
            color[i][j] = 0;
    }

}

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < H && 0 <= ny && ny < W && map[nx][ny] == '#')
        {
            sum += 1;
        }
    }
    color[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < H && 0 <= ny && ny < W && map[nx][ny] == '#' && color[nx][ny] != 1)
        {
            area ++;
            dfs(nx, ny);
        }
    }
}


int main()
{
    vector< pair<int, int> > P;
    input();
    init();
    int m = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (map[i][j] == '#' && color[i][j] != 1)
            {
                sum = 0;
                area = 1;
                dfs(i, j);
                m ++;
                P.push_back(make_pair(area * -1, sum * -1));
                
            }
        }
    }
    sort(P.begin(), P.end());
    for (int i = 0; i < m; i++)
    {
        cout << P[i].first * -1 << " " << (4 * P[i].first * -1) - P[i].second * -1 << endl;
    }
}
