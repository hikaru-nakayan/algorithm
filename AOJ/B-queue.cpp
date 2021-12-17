#include <iostream>
#include <string>
//queueを利用
#include <queue>

using namespace std;


int main()
{
    int n, q, t;
    string name;

    //プロセスのキュー
    queue< pair<string, int> > Q;

    cin >> n >> q;

    //全てのプロセスをキューに順番に追加する
    for (int i = 0; i < n; i ++)
    {
        cin >> name >> t;
        Q.push(make_pair(name, t));
    }

    pair<string, int> u;
    int elaps = 0, a;

    while(!Q.empty())
    {
        u = Q.front();  Q.pop();
        a = min(u.second, q);   
        u.second -= a;
        elaps += a;
        if (u.second > 0)
        {
            Q.push(u);  //処理が完了していなければキューに追加
        } else 
        {
            cout << u.first << " " << elaps << endl;
        }
    }
}