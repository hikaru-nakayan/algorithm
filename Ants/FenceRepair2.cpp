/* 
    プライオリティキューを用いる問題

    考察
    「板を最も小さいものと次に小さいものを合成する」という操作を
    1本の板になるまで繰り返したとき、 最小のコストになる。
    O(nlogn)で全体を解ける。
*/



#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int N;
//小さいものから取り出すように設定
priority_queue<int, vector<int>, greater<int> > L;


void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        L.push(a);
    }
}

void solve()
{
    ll ans = 0;

    while (L.size() > 1)
    {
        int l1, l2;

        l1 = L.top();
        L.pop();
        l2 = L.top();
        L.pop();

        ans += l1 + l2;
        L.push(l1 + l2);
    }

    cout << ans << endl;
    
}

int main()
{
    input();
    solve();
}




