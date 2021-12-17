#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_V 100
#define INF (1<<27)
typedef long long ll;

int d[MAX_N + 1][MAX_N * MAX_V + 1];
int w[MAX_N];
int v[MAX_N];
int N;
ll W;

void input()
{
    cin >> N >> W;
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }
}

int main()
{
    input();
    fill(d[0], d[0] + MAX_N * MAX_V + 1, INF);
    d[0][0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= MAX_V * MAX_N; j++)
        {
            if (j >= v[i - 1])
                d[i][j] = min(d[i - 1][j], d[i - 1][j - v[i - 1]] + w[i - 1]);
            else
                d[i][j] = d[i - 1][j];
        }
    }

    int res = 0;
    for (int j = 0; j <= MAX_V * MAX_N; j++)
    {
        if (d[N][j] <= W)
        {
            res = j;
        } 
    }

    cout << res << endl;
}