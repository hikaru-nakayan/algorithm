#include <iostream>
#include <algorithm>

using namespace std;

int n, S;
static const int MAX_N = 101010;
int a[MAX_N];
int sum[MAX_N + 1];

void input()
{
    cin >> n >> S;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int solve()
{
    sum[0] = 0;
    for (int i = 0; i < n; i ++)
    {
        sum[i + 1] = sum[i] + a[i];
    }

    if (sum[n] < S)
        return -1;
    
    int res = n;

    for (int s = 0; sum[s] + S <= sum[n]; s ++)
    {
        int* t = lower_bound(sum + s, sum + n, sum[s] + S);
        int idx = distance(sum, t);
        res = min(res, idx - s);
    }

    return res;
}

int main()
{
    input();
    cout << solve() << endl;
}