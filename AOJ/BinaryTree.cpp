#include <iostream>
#define MAX 10000
#define NIL -1

using namespace std;

struct Node {
    int parent;
    int right_ch;
    int left_ch;
};

Node T[MAX];
int n, Dep[MAX], Height[MAX];

void setDepth(int u, int d)
{
    if (u == NIL)
        return;
    Dep[u] = d;
    setDepth(T[u].right_ch, d + 1);
    setDepth(T[u].left_ch, d + 1);
}

int setHeight(int u)
{
    if (u == NIL)
        return 0;
    int h1 = setHeight(T[u].right_ch) + 1;
    int h2 = setHeight(T[u].left_ch) + 1;

    return Height[u] = max(h1, h2);
}

int getSibling(int u)
{
    if (T[u].parent == NIL)
        return NIL;
    if ((T[T[u].parent].left_ch != u) && (T[T[u].parent].left_ch != NIL))
        return T[T[u].parent].left_ch;
    if ((T[T[u].parent].right_ch != u) && (T[T[u].parent].right_ch != NIL))
        return T[T[u].parent].right_ch;
    return NIL;
}


void print(int u)
{
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "sibling = " << getSibling(u) << ", ";
    int deg = 0;
    if (T[u].left_ch != NIL)
        deg ++;
    if (T[u].right_ch != NIL)
        deg ++;
    cout << "degree = " << deg << ", ";
    cout << "depth = " << Dep[u] << ", ";
    cout << "height = " << Height[u] - 1 << ", ";
    
    if (T[u].parent == NIL)
        cout << "root" << endl;
    else if (T[u].left_ch == NIL && T[u].right_ch == NIL)
        cout << "leaf" << endl;
    else
        cout << "internal node" << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        T[i].parent = NIL;
    
    int v, l, r;
    for (int i = 0; i < n; i ++)
    {
        cin >> v >> l >> r;
        T[v].left_ch = l;
        T[v].right_ch = r;
        if (l != NIL)
            T[l].parent = v;
        if (r != NIL)
            T[r].parent = v;
    }

    int root = 0;
    for (int i = 0; i < n; i ++)
    {
        if (T[i].parent == NIL)
            root = i;
    }
    setDepth(root, 0);
    setHeight(root);

    for (int i = 0; i < n; i ++)
        print(i);
}