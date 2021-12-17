#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;
vector<int> L;


void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        L.push_back(a);
    }
}



int main()
{
    input();
    int ans = 0;
    sort(L.begin(), L.end());
    
    while (L.size() != 1)
    {
        int t = L[0] + L[1];
        L.erase(L.begin());
        L.erase(L.begin());
        if (!L.empty())
            L.insert(lower_bound(L.begin(), L.end(), t), t);
        else
        {
            ans += t;
            break;
        }
            ans += t;
    }
    cout << ans << endl;
}