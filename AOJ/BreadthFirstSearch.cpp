#include <iostream>
#include <queue>

using namespace std;

#define MAX 100
#define INFTY (1<<21)

int n, M[MAX][MAX];
int d[MAX]; //距離で訪問状態を管理する

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    d[s] = 0;
    for (int i = 1; i < n; i ++)
        d[i] = INFTY;
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v ++)
        {
            if (M[u][v] == 0)
                continue;
            if (d[v] != INFTY)
                continue;
            q.push(v);
            d[v] = d[u] + 1;
        }
    }

    for (int i = 0; i < n; i ++)
        cout << i + 1 << " " << ( (d[i] == INFTY) ? (-1) : d[i]) << endl;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
            M[i][j] = 0;
    }

    for (int i = 0; i < n; i ++)
    {
        int u, k;
        cin >> u >> k;
        u --;
        for (int j = 0; j < k; j ++)
        {
            int v;
            cin >> v;
            v--;
            M[u][v] = 1; 
        }
            
    }

    bfs(0);
}