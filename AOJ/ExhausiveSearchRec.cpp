#include <iostream>
#include <vector>

using namespace std;

bool rec(int i, const vector<int>& a, int w)
{
    if (i == 0)
    {
        if (w == 0)
            return true;
        else
            return false;
    }

    if (rec(i - 1, a, w))
        return true;
        
    if (rec(i - 1, a, w - a[i - 1]))
        return true;


    return false;   
}