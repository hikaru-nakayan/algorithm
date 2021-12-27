//しゃくとり法によって求める。

#include <iostream>
#include <algorithm>

using namespace std;

int n, S;
static const int MAX_N = 101010;
int a[MAX_N];

void input()
{
    cin >> n >> S;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}


void solve()
{
    int res = n;
    int sum = 0;
    int s = 0, t = 0;
    while(1)
    {
        while(t < n && sum < S)
        {
            sum += a[t++];
        }

        if (sum < S)
            break;
        res = min(res, t - s);
        sum -= a[s++];

    }

    if (res > n)
        res = -1;
    cout << res << endl;
}


int main()
{
    input();
    solve();
}
