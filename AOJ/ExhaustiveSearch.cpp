#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i ++)
        cin >> A[i];
    
    cin >> q;
    vector<int> a(q);
    bool exist[200] = {};
    for (int i = 0; i < q; i ++)
    {
        
        cin >> a[i];
        for (int bit = 0; bit < (1 << n); bit++)
        {
            int sum = 0;
            for (int j = 0; j < n; j ++)
            {
                if (bit & (1 << j))
                    sum += A[j];
            }

            if (sum == a[i])
                exist[i] = true;
        }

        if (exist[i])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

}