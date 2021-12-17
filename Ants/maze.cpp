#include <iostream>
#include <queue>
#include <utility>



using namespace std;



typedef pair<int, int> P;
#define INF (1<<27)     //10^8以上の十分大きな値に設定
int N, M;
char maze[105][105];
int sx, sy;     //スタートの座標
int gx, gy;     //ゴールの座標
int d[105][105];    //スタートから各座標までの最短距離
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};





void bfs()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j ++)
            d[i][j] = INF;
    
    d[sx][sy] = 0;
    queue<P> que;
    que.push(P(sx, sy));



    while (!que.empty())
    {
        P u = que.front();
        que.pop();


        if (u.first == gx && u.second == gy)
            break;

        for (int i = 0; i < 4; i ++)
        {
            int nx = u.first + dx[i];
            int ny = u.second + dy[i];
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && d[nx][ny] == INF && maze[nx][ny] != '#')
            {
                que.push(P(nx, ny));
                d[nx][ny] = d[u.first][u.second] + 1;
            }
        }


    }

}   




void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            if (maze[i][j] == 'G')
            {
                gx = i;
                gy = j;
            }
        }
            
    }
}






int main()
{
    input();
    bfs();
    cout << d[gx][gy] << endl;
}



