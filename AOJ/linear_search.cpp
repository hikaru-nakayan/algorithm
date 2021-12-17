#include <iostream>


using namespace std;

//要素数nの配列からkeyを線形探索し、見つけると1を返し、失敗すると０を返す
int search(int* a, int n, int key)
{
    a[n] = key;
    int i = 0;
    while (a[i] != key)
    {
        i ++;
    }

    return i != n;
}

int main()
{
    int n, A[10000 + 1], q, key, sum = 0;

    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> A[i];
    
    cin >> q;
    for (int i = 0; i < q; i ++)
    {
        cin >> key;
        if (search(A, n, key))
            sum ++;
    }

    cout << sum << endl;
}