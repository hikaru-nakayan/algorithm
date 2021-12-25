/*
    二分探索の問題
    O(logn)でソート列から検索可能

*/




#include <iostream> 

using namespace std;

static const int MAX_n = 1010101;
typedef long long ll;

int n;
ll k;
ll a[MAX_n];

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void solve()
{
    int lb = -1, ub = n;

    while (ub - lb > 1)
    {  
        int mid = (ub + lb) / 2;

        if (a[mid] >= k)
        {
            ub = mid;
        } else {
            lb = mid;
        }
    }

    cout << ub << endl;
}

int main()
{
    input();
    solve();
}