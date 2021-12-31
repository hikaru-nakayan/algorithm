#include <iostream>
#include <algorithm>

using namespace std;

static const int N = 8;
#define FREE -1
#define NOT_FREE 1

int row[N], col[N], dpos[2*N - 1], dneg[2*N - 1];

bool X[N][N];

void init()
{
    fill(row, row + N, FREE);
    fill(col, col + N, FREE);
    fill(dpos, dpos + 2*N - 1, FREE);
    fill(dneg, dneg + 2*N - 1, FREE);

}


void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (X[i][j])
            {
                if (row[i] != j)
                    return;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j ++)
        {
            cout << ((row[i] == j) ? "Q" : ".");
        }
        cout << endl;
    }
}

void recursive(int i)
{
    if (i == N)
    {
        printBoard();
        return;
    }

    for (int j = 0; j < N; j ++)
    {
        if (col[j] == NOT_FREE || 
            dpos[i + j] == NOT_FREE ||
            dneg[i - j + N - 1] == NOT_FREE)
            continue;
        
        row[i] = j;
        col[j] = dpos[i + j] = dneg[i - j + N - 1] = NOT_FREE;

        recursive(i + 1);

        row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = FREE;
    }
}

int main()
{
    init();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            X[i][j] = false;
    
    int k; cin >> k;
    for (int i = 0; i < k; i++)
    {
         int r, c; cin >> r >> c;
         X[r][c] = true;
    }

    recursive(0);
       

}


