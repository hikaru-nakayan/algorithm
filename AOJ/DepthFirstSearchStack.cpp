#include <iostream>
#include <stack>

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

int nt[MAX];    //uのnextを更新する

//uに隣接するvを番号順に取得
int next(int u)
{
    for (int v = nt[u]; v < n; v++)
    {
        nt[u] = v + 1;
        if (M[u][v])
            return v;
    }
    return -1;
}

//スタックを用いた深さ優先探索
void dfs_visit(int r)
{
    stack<int> S;
    S.push(r);
    color[r] = GRAY;
    d[r] = ++tt;

    while (!S.empty())
    {
        int u = S.top();
        int v = next(u);
        if (v != -1)
        {
            if (color[v] == WHITE)
            {
                S.push(v);
                color[v] = GRAY;
                d[v] = ++tt;
            }
            
        } else 
        {
            S.pop();
            color[u] = BLACK;
            f[u] = ++tt;
        }
    }
}


void dfs()
{
    //初期化
    for (int i = 0; i < n; i ++)
    {
        color[i] = WHITE;
        nt[i] = 0;
    }
    
    //未訪問のuを始点としてDFS
    for (int u = 0; u < n; u ++)
    {
        if (color[u] == WHITE)
            dfs_visit(u);
    }

    for (int i = 0; i < n; i ++)
    {
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
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