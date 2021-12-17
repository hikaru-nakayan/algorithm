#include <iostream>

using namespace std;
#define MAX 100000
int A[MAX], n;

int partition(int p, int r)
{
    int x, i, j, t;
    x = A[r];
    i = p - 1;
    for (j = p; j < r; j ++)
    {
        if (A[j] <= x)
        {
            i ++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[r]);
    return i + 1;
}

void quickSort(int* A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(p , r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main()
{
    int i, q;
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> A[i];
    
    q = partition(0, n - 1);

    for (int i = 0; i < n; i ++)
    {
        if(i) cout << " ";
        if(i == q) cout << "[";
        cout << A[i];
        if(i == q) cout << "]";
    }

    cout << endl;

    quickSort(A, 0, n - 1);
    for (int i = 0; i < n; i ++)
    {
        if(i) cout << endl;
        cout << A[i];
    }
    cout << endl;

}