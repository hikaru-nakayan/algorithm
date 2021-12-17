#include <iostream>

//stackを利用
#include <stack>

//atoiを利用
#include <cstdlib>
#include <string>

using namespace std;


int main()
{
    //stackを利用
    stack<int> S;
    int a, b;
    string s;

    while(cin >> s)
    {
        if (s[0] == '+')
        {
            a = S.top();    S.pop();
            b = S.top();    S.pop();
            S.push(a + b);
        }else if (s[0] == '-')
        {
            a = S.top();    S.pop();
            b = S.top();    S.pop();
            S.push(b - a);
        }else if (s[0] == '*')
        {
            a = S.top();    S.pop();
            b = S.top();    S.pop();
            S.push(a * b);
        } else 
        {
            S.push(atoi(s.c_str()));
        }
        
    }

    cout << S.top() << endl;
}