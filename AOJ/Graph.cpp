#include <iostream>
using namespace std;

#define MAX 100

int main()
{
    int M[MAX][MAX];
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            M[i][j] = 0;
    
    for(int i = 0; i < n; i ++)
    {
        int row, k;
        cin >> row >> k;
        row --;
        for (int j = 0; j < k; j ++)
        {
            int v;
            cin >> v;
            v --;
            M[row][v] = 1;
        }
    }

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j) cout << " ";
            cout << M[i][j];
        }
        cout << endl;
    }
}