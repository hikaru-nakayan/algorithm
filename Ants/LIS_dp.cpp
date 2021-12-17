#include <iostream>
#include <algorithm>

using namespace std;
#define INF (1<<27)

int dp[1010];
int n;
int seq[1010101];

int solve()
{
    int ans = 0;
    fill(dp, dp + n, INF);
    for (int i = 0; i < n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            if (seq[i] > seq[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }
}

int main()
{
    input();
    cout << solve() << endl;

}
