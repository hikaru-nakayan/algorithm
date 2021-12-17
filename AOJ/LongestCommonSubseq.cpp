#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for (int k = 0; k < q; k ++)
    {
        string X, Y;
        cin >> X >> Y;
        int m = X.size();
        int n = Y.size();
        int maxl = 0;
        vector< vector<int> > dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i ++)
            dp[i][0] = 0;
        for (int i = 1; i <= n; i ++)
            dp[0][i] = 0;

        for (int i = 1; i <= m; i ++)
        {
            for (int j = 1; j <= n; j ++)
            {
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        cout << dp[m][n] << endl;
    }
}