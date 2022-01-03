#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <cmath>

using namespace std;
#define N2 9
#define N 3

struct Puzzle
{
    int f[N2];  //パズルの配置
    int space;  //パズルの空白
    string path;

    bool operator < (const Puzzle &p) const
    {
        for (int i = 0; i < N2; i++)
        {
            if (f[i] == p.f[i])
                continue;
            return f[i] > p.f[i];
        }
        return false;
    }
};

static const int dx[4] = {-1, 0, 1, 0};
static const int dy[4] = {0, -1, 0, 1};
static const char dir[4] = {'u', 'l', 'd', 'r'};


bool isTarget(Puzzle p)
{
    for (int i = 0; i < N2; i ++)
    {
        if (p.f[i] != i + 1)
            return false;
    }
    return true;
}

string bfs(Puzzle s)
{
    queue<Puzzle> Q;
    map<Puzzle, bool> V;
    Puzzle u, v;
    s.path = "";
    Q.push(s);
    V[s] = true;

    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        if (isTarget(u))
            return u.path;
        int sx = u.space / N;
        int sy = u.space % N;
        for (int r = 0; r < 4; r++)
        {
            int tx = sx + dx[r];
            int ty = sy + dy[r];
            if (tx < 0 || tx >= N || ty < 0 || ty >= N)
                continue;
            v = u;
            swap(v.f[v.space], v.f[tx * N + ty]);
            v.space = tx * N + ty;
            if (!V[v])
            {
                V[v] = true;
                v.path += dir[r];
                Q.push(v);
            }
        }
    }

    return "unsolved";
}

Puzzle in;

void input()
{
    for (int i = 0; i < N2; i ++)
    {
        cin >> in.f[i];
        if (in.f[i] == 0)
        {
            in.f[i] = N2;
            in.space = i;
        }
    }
}

int main()
{
    input();
    string ans = bfs(in);
    cout << ans.size() << endl;
}