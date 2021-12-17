#include <iostream>
#define MAX 10000
#define NIL -1
using namespace std;

struct Node {
    int parent;
    int left;
    int right;
};

struct Node T[MAX];
int n;

void preParse(int u)
{
    if (u == NIL)
        return;
    cout << u << " ";
    preParse(T[u].left);
    preParse(T[u].right);
}

void inParse(int u)
{
    if (u == NIL)
        return;
    inParse(T[u].left);
    cout << u << " ";
    inParse(T[u].right);
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
        T[v].left = l;
        T[v].right = r;
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

    cout << "Preorder" << endl;
    preParse(root);
    cout << endl;
    cout << "Inorder" << endl;
    inParse(root);
    cout << endl;

}