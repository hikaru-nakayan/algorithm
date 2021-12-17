#include <iostream>

using namespace std;

#define MAX 100  //MAXは頂点の最大数

#define WHITE 0  //未訪問の頂点
#define GRAY 1   //訪問した頂点
#define BLACK 2  //訪問を完了した頂点

int tt = 0;
int n, M[MAX][MAX];   //行列Mは隣接行列
int color[MAX];      //各頂点の状態を保管

int d[MAX];     //各頂点を訪れた時間
int f[MAX];     //各頂点の訪問を完了した時間

//再帰関数による深さ優先探索
void dfs_visit(int u)
{
    color[u] = GRAY;
    d[u] = ++tt;
    for (int v = 0; v < n; v ++)
    {
        if (M[u][v] == 0)
            continue;
        if (color[v] == WHITE)
            dfs_visit(v);
    }
    color[u] = BLACK;
    f[u] = ++tt;
}

void dfs()
{
    //初期化
    for (int u = 0; u < n; u ++)
        color[u] = WHITE;
    
    for (int u = 0; u < n; u++)
    {   //未訪問のuを始点としてDFS
         if (color[u] == WHITE)
            dfs_visit(u);
    }

     // 計測時間を出力  
    for (int u = 0; u < n; u++)
    {
        cout << u + 1 << " " << d[u] << " " << f[u] << endl;
    }

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

    dfs();
}


