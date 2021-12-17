#include <iostream>

using namespace std;

#define MAX 100005
#define NIL -1

struct Node {
    int parent;
    int left_ch;
    int right_sibling;
};

Node T[MAX];
int n, Dep[MAX];

void print(int u)
{
    int i, c;
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << Dep[u] << ", ";

    if (T[u].parent == NIL)
        cout << "root, ";
    else if (T[u].left_ch == NIL)
        cout << "leaf, ";
    else 
        cout << "internal node, ";
    
    cout << "[";
    for ( i = 0, c = T[u].left_ch; c != NIL; i ++, c = T[c].right_sibling)
    {
        if(i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;

}

void rec(int u, int p)
{
    Dep[u] = p;
    
    if (T[u].right_sibling != NIL)
        rec(T[u].right_sibling, p);
    if (T[u].left_ch != NIL)
        rec(T[u].left_ch, p + 1);
}

int main()
{
   cin >> n;
   for (int i = 0; i < n; i ++)
        T[i].parent = T[i].left_ch = T[i].right_sibling = NIL;
    
    for (int i = 0; i < n; i ++)
    {
        int ndnum, chcnt;
        cin >> ndnum >> chcnt;
        for (int j = 0; j < chcnt; j ++)
        {
            int c, l;
            cin >> c;
            if (j == 0)
                T[ndnum].left_ch = c;
            else
                T[l].right_sibling = c;
            l = c;
            T[c].parent = ndnum;
        }
    }

    int root;
    for (int i = 0; i < n; i ++)
    {
        if (T[i].parent == NIL)
            root = i;
    }

    rec(root, 0);

    for (int i = 0; i < n; i ++)
        print(i);
}

