#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
//iotaを利用
#include <numeric>

using namespace std;


int main()
{
    int n;
    vector<int> w(n), s(n);
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> w[i];
    

    list<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    for (int i = 0; i < n; i ++)
        s.push_back(w[i]);
    
    sort(s.begin(), s.end());

    for (list<int>::iterator it = idx.begin(); idx.size() != 0; it ++)
    {
        
    }
}