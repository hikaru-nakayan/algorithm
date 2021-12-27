#include <iostream>

using namespace std;

int N;
static const int MAX_N = 5010;
char s[MAX_N];
int dir[MAX_N];
int f[MAX_N];

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
        if (s[i] == 'B')
            dir[i] = 1;
        else 
            dir[i] = 0;
    }
}


int calc(int K)
{
    fill(f, f + N, 0);
    int res = 0;
    int sum = 0;

    for (int i = 0; i + K <= N; i++)
    {
        if ((dir[i] + sum) % 2 != 0)
        {
            res ++;
            f[i] = 1;
        }
        sum += f[i];

        if (i - K + 1 >= 0)
        {
            sum -= f[i - K + 1];
        }
    }

    for (int i = N - K + 1; i < N; i++)
    {
        if ((dir[i] + sum) % 2 != 0)
        {
            return -1;
        }

        if (i - K + 1 >= 0)
        {
            sum -= f[i - K + 1];
        }
    }

    return res;
}


void solve()
{
    int K = 1, M = N;
    for (int k = 1; k <= N; k++)
    {
        int m = calc(k);
        if (m >= 0 && M > m)
        {
            M = m;
            K = k;
        }
    }

    cout << K << endl << M << endl;
}


int main()
{
    input();
    solve();
}