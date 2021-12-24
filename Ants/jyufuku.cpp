/*

 n種類の品物があり、i番目の品物はa_i個あります。異なる種類の品物
どうしは区別できるが、同じ種類の品物どうしは区別できない。これらの
品物の中からm個選ぶ組み合わせの総数をもとめよ。
1 <= n <= 1000
1 <= m <= 1000
1 <= a_i <= 1000
n = 3
m = 3
a = {1, 2, 3}

出力

6(0+0+3, 0+1+2, 0+2+1, 1+0+2, 1+1+1, 1+2+0)

*/


#include <iostream>

using namespace std;

int n, m;
static const int MAX_N = 1010;
static const int MAX_M = 1010;

int a[MAX_N];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void solve()
{
    int dp[MAX_N][MAX_M]; //dp[i][j]: i番目まで使ってj個選ぶ総数

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {   
            if (j - 1 - a[i - 1] >= 0)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1 - a[i - 1]];
            } else {
                dp[i][j] =  dp[i][j - 1] + dp[i - 1][j];
            }
            
        }
    }

    cout << dp[n][m] << endl;

}



int main()
{
    input();
    solve();

}