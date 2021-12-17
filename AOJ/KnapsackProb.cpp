#include <iostream>
#include <algorithm>
#include <vector>
#define NMAX 105
#define WMAX 10005
#define DIAGONAL 1
#define TOP 0


using namespace std;

struct Itme {
    int value;
    int weight;
};


int N, W;


Itme items[NMAX + 1];
int C[NMAX + 1][WMAX + 1], G[NMAX + 1][WMAX + 1];

void chmax(int& max, int p, int i, int w)
{
    if (max < p)
    {
        max = p;
        G[i][w] = DIAGONAL;
    }
}


void compute(int& maxValue, vector<int> &selectin)
{
    for (int w = 0; w <= W; w ++)
    {
        C[0][w] = 0;
        G[0][w] = DIAGONAL;
    }



    for (int i = 0; i <= N; i++)
        C[i][0] = 0;
    

    for (int i = 1; i <= N; i++)
    {
        for (int w = 1; w <= W; w ++)
        {
            C[i][w] = C[i - 1][w];
            G[i][w] = TOP;
            if (w >= items[i].weight)
            {
                chmax(C[i][w], C[i - 1][w - items[i].weight] + items[i].value, i, w);
            }
        }
    }



    maxValue = C[N][W];

    selectin.clear();
    for (int i = N, w = W; i > 0; i --)
    {
        if (G[i][w] == DIAGONAL)
        {
            selectin.push_back(i);
            w -= items[i].weight;
        }
    }


    reverse(selectin.begin(), selectin.end());

}



void input()
{
    cin >> N >> W;
    for (int i = 1; i <= N; i++)
    {
        cin >> items[i].value >> items[i].weight;
    }
}


int main()
{
    int maxValue;
    vector<int> selection;
    input();
    compute(maxValue, selection);

    cout << maxValue << endl;
}





