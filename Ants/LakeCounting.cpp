#include <iostream>

using namespace std;

char Gd[105][105];
int N, M;

void dfs(int x, int y)
{
    Gd[x][y] = '.';
    for (int dx = -1; dx <= 1; dx ++)
    {
        for (int dy = -1; dy <= 1; dy ++)
        {
            int nx = dx + x;
            int ny = dy + y;
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && Gd[nx][ny] == 'W')
            {
                dfs(nx, ny);
            }
        }
    }
}



int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i ++)
    {
        for (int j = 0; j < M; j ++)
            cin >> Gd[i][j];
    }
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Gd[i][j] == 'W')
            {
                dfs(i, j);
                cnt ++;
            }
        }
    }

    cout << cnt << endl;
}