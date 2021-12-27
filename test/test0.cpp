#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    

    int s[1000];
    for (int i = 0; i < 10; i++)
        s[i] = i;
    int* idx = s + 1;
    cout << *idx << endl;

    int d[1000];
    for (int i = 0; i < 10; i++)
    {
        d[i] = (i + 4) % 3;
    }

     for (int i = 0; i < 10; i++)
    {
        cout << d[i] << " ";
    }

    cout << endl;


    sort(d, d + 10);

    for (int i = 0; i < 10; i++)
    {
        cout << d[i] << " ";
    }

    cout << endl;



}