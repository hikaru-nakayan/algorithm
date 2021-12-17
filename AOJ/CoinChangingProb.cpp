#include <iostream>

using namespace std;
#define MAX 50101
#define INFTY (1<<21)

void chmin(int& min, int p)
{
    if (min > p)
        min = p;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int C[20];
    for (int i = 0; i < m; i++)
        cin >> C[i];
    
    int dp[MAX];

    for(int i = 0; i <= n; i++)
    {
        dp[i] = INFTY;
    }

    dp[0] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = C[i]; j <= n; j++)
        {
            chmin(dp[j], dp[j - C[i]] + 1);
        }
    }

    cout << dp[n] << endl;
}