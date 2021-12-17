#include <iostream>
#include <list>

using namespace std;

int main()
{
    int q, x;
    string com;

    list<int> v;
    cin >> q;
    for (int i = 0; i < q; i ++)
    {
        cin >> com;
        if (com[0] == 'i')
        {
            cin >> x;
            v.push_front(x);
        } else if (com[6] == 'L')
        {
            v.pop_back();
        } else if (com[6] == 'F')
        {
            v.pop_front();
        } else if (com[0] == 'd')
        {
            cin >> x;
            for (list<int>::iterator it = v.begin(); it != v.end(); it++)
            {
                if (*it == x)
                {
                    v.erase(it);
                    break;
                }
            }
        }
    }

    int i = 0;
    for (list<int>::iterator it = v.begin(); it != v.end(); it ++)
    {
        if (i++)    cout << " ";
        cout << *it;
    }
    cout << '\n';

}