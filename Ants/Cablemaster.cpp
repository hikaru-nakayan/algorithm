#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

#define INF (1<<27)
int N, K;
static const int MAX_N = 101010;
double L[MAX_N];

void input()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> L[i];
}

//C(x)：長さxのひもをK本切り出すことができる
bool C(double x)
{
    int num = 0;
    for (int i = 0; i < N; i++)
    {
        num += (int)(L[i] / x);
    }

    return num >= K;
}

void solve()
{
    double lb = 0, ub = INF;

    for (int i = 0; i < 100; i++)
    {
        double mid = (lb + ub) / 2;
        if (C(mid))
            lb = mid;
        else 
            ub = mid;
    }

    cout << setprecision(3) << floor(ub * 100) / 100 << endl;
}

int main()
{
    input();
    solve();
}