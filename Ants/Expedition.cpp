/* プライオリティキューを用いる問題(P73)

    プライオリティキューは二分木を用いて実装されるので、O(logn)で挿入、削除できる。

    考察
    燃料が０になったら、通過したガソリンスタンドの最大の燃料を取得すればよい

*/


#include <iostream>
#include <queue>

using namespace std;

static const int MAX_N = 10101;
int N, L, P;
int A[MAX_N], B[MAX_N];

void input()
{
    cin >> N >> L >> P;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }
}

void solve()
{
    int tank = P;
    A[N] = L;
    int d = 0;
    int pos = 0;
    int cnt = 0;
    priority_queue<int> que;

    for (int i = 0; i < N; i++)
    {
        d = A[i] - pos;
        while (tank - d < 0)
        {
            if (que.empty())
            {
                cout << -1 << endl;
                return;
            }
            tank += que.top();
            que.pop();
            cnt ++;
        }
        que.push(B[i]);
        tank -= d;
        pos = A[i];
    }

    cout << cnt << endl;
}



int main()
{
    input();
    solve();
}