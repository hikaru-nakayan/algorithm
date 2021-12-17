#include <iostream>
#include <utility>
using namespace std;
#define MAX 101010



int main()
{
    int n;
    cin >> n;
    int S[MAX], T[MAX];
    pair<int, int> P[MAX];
    for (int i = 0; i < n; i++)
    {
        cin >> S[i] >> T[i];
    }


    for (int i = 0; i < n; i++)
    {
        P[i].first = T[i];
        P[i].second = S[i];
    }

    sort(P, P + n);

    int cnt = 0;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (t < P[i].second)
        {
            t = P[i].first;
            cnt ++;
        }
    }


    cout << cnt << endl;
}