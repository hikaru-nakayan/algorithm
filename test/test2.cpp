#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define INF (1<<27)
int N; //ワード数
static const int MAX_N = 1010;
vector< pair<string, int> > W;


void input()
{
    string s;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        W.push_back(make_pair(s, i + 1));
    }

}



int cnt = 0;
int d[MAX_N];

void init()
{
    for (int i = 0; i < N + 2; i++)
        d[i] = INF;
}


int bfs()
{
    queue< pair<string, int> > que;
    que.push(make_pair("si", 0));
    d[0] = 0;

    while(que.size())
    {
        pair<string, int> P = que.front();
        que.pop();

        if (P.first[1] == 'n')
        {
            return d[P.second];
        }

        
        for (int i = 0; i < N; i++)
        {
            if (P.first[1] == W[i].first[0] && d[i + 1] == INF)
            {
                d[i + 1] = d[P.second] + 1;
                que.push(make_pair(W[i].first, W[i].second));
            }
        }
    }

    return -1;
}

int main()
{
    input();
    init();
    for (int i = 0; i < N; i++)
        cout << W[i].first << " " << W[i].second << endl;
    
    cout << bfs() << endl;
}