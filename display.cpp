#include <iostream>
#include <queue>
#include"b+tree.h"
//using namespace std;

void BPTree::display(Node* cursor) 
{

    /*
        Level Order Display
    */
    //BFS DISPLAY
    if (cursor == NULL) return;
    queue<Node*> q;
    q.push(cursor);

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++) 
        {
            Node* u = q.front(); q.pop();

            //printing keys in self
            for (int val : u->keys)
                cout << val << " ";

            cout << "|| ";//to seperate next adjacent nodes
            
            if (u->isLeaf != true) 
            {
                for (Node* v : u->ptr2TreeOrData.ptr2Tree) 
                {
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
}
