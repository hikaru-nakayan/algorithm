#include <iostream>
#include <string>
using namespace std;

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};


int M, N;
static const int MAX_N = 20;
static const int MAX_M = 20;

int tile[MAX_M][MAX_N];

int opt[MAX_M][MAX_N];
int flip[MAX_M][MAX_N];

void input()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> tile[i][j];
        }
    }
}


int get(int x, int y)
{
    int c = tile[x][y];

    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N)
        {
            c += flip[nx][ny];
        }
    }

    return c % 2;
}


int calc()
{
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (get(i - 1, j) != 0)
            {
                flip[i][j] = 1;
            }
        }
    }

    for (int j = 0; j < N; j ++)
    {
        if (get(M - 1, j) != 0)
        {
            return -1;
        }
    }

    int res = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            res += flip[i][j];
        }
    }

    return res;
}

void init()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            flip[i][j] = 0;
    }
}


void solve()
{
    int res = -1;

    for (int i = 0; i < (1 << N); i ++)
    {
        for (int j = 0; j < N; j++)
        {
            flip[0][j] = (i >> j) & 1;
        }
        int num = calc();
        if (num >= 0 && (res < 0 || res > num))
        {
            res = num;
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j ++)
                {
                    opt[i][j] = flip[i][j];
                }
            }
        }
    }

    if(res < 0)
    {
        cout << "IMPOSSIBLE" << endl;
    } else {

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << opt[i][j] << (j + 1 == N ? '\n' : ' ');
            }
        }

    }
}

int main()
{
    input();
    init();
    solve();
}