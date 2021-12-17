#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

long long w[MAX];
int load_counts(long long max_weight, int tnum)
{
    long long lw = 0;
    int i = 0, k = 1;

    while(k <= tnum)
    {
        if (lw + w[i] <= max_weight)
        {
            lw += w[i];
            i ++;
        } else 
        {
            lw = 0;
            k ++;
        }
    }

    return i;
    
}




int main()
{
    int load_num, track_num;
    cin >> load_num >> track_num;
    
    
    for (int i = 0; i < load_num; i ++)
    {
        cin >> w[i];
    }

    long long left = 0;
    long long right = 100000 * 10000;
    long long mid;

    while (right - left > 1)
    {
        mid = (right + left) / 2;
        int v = load_counts(mid, track_num);
        if (v >= load_num)
        {
            right = mid;
        } else 
        {
            left = mid;
        }
    }

    cout << right << endl;
}