#include <iostream>


using namespace std;

int N, R;
int X[1010];

void input()
{
    cin >> N >> R;
    for (int i = 0; i < N; i++)
        cin >> X[i];
}



int main()
{
    input();
    int i = 0;
    int ans = 0;
    while (i < N)
    {
        int s = X[i];
        while(i < N && X[i] <= s + R)
        {
            i ++;
        }

        int p = X[i - 1];

        while(i < N && X[i] <= p + R)
            i++;
        ans++;
    }

    cout << ans << endl;
}