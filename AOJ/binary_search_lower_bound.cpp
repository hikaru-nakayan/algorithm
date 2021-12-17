#include <iostream>
#include <algorithm>

using namespace std;

int A[1000000], n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> A[i];
    }

    int q, key, sum = 0;

    cin >> q;

    for (int i = 0; i < q; i ++)
    {
        cin >> key;
        if (*(lower_bound(A, A + n, key)) == key)
            sum++;
    }

    cout << sum << endl;
}