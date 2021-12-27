#include <iostream>
#include <algorithm>

using namespace std;

#define INF (1<<27)

int n, k;
static const int MAX_N = 10101;

int w[MAX_N], v[MAX_N];

double y[MAX_N];

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
}

bool C(double x)
{
    for (int i = 0; i < n; i++)
        y[i] = v[i] - x * w[i];
    
    sort(y, y + n);

    double sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += y[n - i -1];
    }

    return sum >= 0;
    
}


void solve()
{
    double lb = 0, ub = INF;
    for (int i = 0; i < 100; i++)
    {
        double mid = (lb + ub) / 2;
        if(C(mid))
            lb = mid;
        else 
            ub = mid;
    }
    cout << lb << endl;
}

int main()
{
    input();
    solve();
}