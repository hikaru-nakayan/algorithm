#include <iostream>
#include <vector>

using namespace std;
#define MAX 100
int main()
{
    int n;
    cin >> n;
    int p[MAX + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> p[i + 1];
    }

    vector< vector<int> > M(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i ++)
        M[i][i] = 0;
    
    for(int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i ++)
        {
            int j = i + len - 1;
            M[i][j] = (1 << 21);
            for (int k = i; k <= j - 1; k ++)
            {
                M[i][j] = min(M[i][j], M[i][k] + M[k + 1][j] + p[i - 1]*p[k]*p[j]);
            }
        }
    }

    cout << M[1][n] << endl;
}