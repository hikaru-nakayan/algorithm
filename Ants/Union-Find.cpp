#include <iostream>

using namespace std;

static const int MAX_N = 50101;
static const int MAX_K = 101010;

int parent[MAX_N];
int depth[MAX_N];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        depth[i] = 0;
    }
}


int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    
    if (depth[x] < depth[y])
    {
        parent[x] = y;
    } else {
        parent[y] = x;
        if (depth[x] == depth[y])
            depth[x] ++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];

void input()
{
    cin >> N >> K;
    for (int i = 0; i < K; i ++)
    {
        cin >> T[i] >> X[i] >> Y[i];
    }
}

void solve()
{
    init(N * 3);

    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        int t = T[i];
        int x = X[i] - 1, y = Y[i] - 1;

        if (x < 0 || N <= x || y < 0 || N <= y)
        {
            ans ++;
            continue;
        }

        if (t == 1)
        {
            if (same(x, y + N) || same(x, y + 2 * N))
            {
                ans ++;
            } else {
                unite(x, y);
                unite(x + N, y + N);
                unite(x + 2 * N, y + 2 * N);
            }
        } else {
            if (same(x, y) || same(x, y + 2 * N))
            {
                ans ++;
            } else {
                unite(x, y + N);
                unite(x + N, y + 2 * N);
                unite(x + 2 * N, y);
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    input();
    solve();

}