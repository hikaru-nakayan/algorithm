#include <iostream>
#include <set>
#include <map>
using namespace std;

int P;
static const int MAX_P = 1010101;

int a[MAX_P];

void input()
{
    cin >> P;
    for (int i = 0; i < P; i++)
        cin >> a[i];
}

void solve()
{
    set<int> all;
    for (int i = 0; i < P; i++)
        all.insert(a[i]);
    int n = all.size();

    int s = 0, t = 0, num = 0;

    map<int, int> count;
    int res = P;
    while(1)
    {
        while(t < P && num < n)
        {
            if (count[a[t++]]++ == 0)
                num ++;
        }

        if(num < n)
            break;
        
        res = min(res, t - s);
        if (--count[a[s++]] == 0)
            num--;
    }

    cout << res << endl;
}

int main()
{
    input();
    solve();
}


