#include <iostream>

using namespace std;

int binarySearch(int* a, int n, int key)
{
    int left = 0, right = n;
    int midle;
    while (left < right)
    {
        midle = (left + right) / 2;
        if (a[midle] == key)
            return 1;
        
        if (a[midle] > key)
        {
            right = midle;
        } else if (a[midle] < key)
        {
            left = midle + 1;
        }
    }

    return 0;
}

int main()
{
    int q, key, sum = 0;
    int A[1000000], n;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> A[i];
    }

    cin >> q;
    for (int i = 0; i < q; i ++)
    {
        cin >> key;
        if (binarySearch(A, n, key))
            sum ++;
    }

    cout  << sum << endl;
}