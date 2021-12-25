#include <iostream>
#include <algorithm>
using namespace std;
#define INF (1<<27)
int N, M;

static const int MAX_N = 101010;

int x[MAX_N];

void input()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> x[i];

}

//任意の牛の間の間隔をd以上にすることができる。
bool C(int d)
{
    int pos = 1; //現在の牛舎番号 0で初期化しd以上離れながら牛を入れていく
    int last = 0; //最後に牛を入れた牛舎番号
    int ucnt = M - 1; //入れていない牛の数

    while (ucnt > 0)
    {

        while (x[pos] - x[last] < d && pos < N)
        {
            pos ++;
        }

        if (pos == N)
        {
            return false;
        }

        last = pos;
        ucnt --;
    }

    return true;
}


void solve()
{
    sort(x, x + N);

    int lb = 0, ub = INF;

    while (ub - lb > 1)
    {
        int mid = (lb + ub) / 2;
        if (C(mid))
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