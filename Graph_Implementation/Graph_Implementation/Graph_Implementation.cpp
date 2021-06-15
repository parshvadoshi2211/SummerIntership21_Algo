#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;

#pragma region Adj. list using list with check contain cycle or not
//Make Adj. list using LIST..
class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y) {
        l[x].push_back(y); // in directed graph this line we have to write only not 2nd
        l[y].push_back(x);
    }

    bool cycle_helper(int node, bool* vis , int parent) {
        vis[node] = true;

        for (auto nbr : l[node]) {
            if (!vis[nbr]) {
                bool its_cycle = cycle_helper( nbr , vis , node );
                if (its_cycle)
                    return true;
            }
            else if( nbr != parent ) {
                return true;
            }
        }
        return false;
    }

    void contain_Cycle() {
        bool* vis = new bool[V];
        for (int i = 0; i < V; i++) {
            vis[i] = false;
        }
        bool ans = cycle_helper(0 , vis , -1);
        cout << ans;
    }


    void AddjList() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << "->";
            for (int itr : l[i]) {
                cout << itr << ", ";
            }
            cout << "\n";
        }
    }
};
#pragma endregion

#pragma region Adj. list using MAP
//class Graph {
//    unordered_map<string, list<pair<string, int>>> mp;
//public:
//    void addEdge(string x, string y, int w) {
//        mp[x].push_back(make_pair(y, w));
//        mp[y].push_back(make_pair(x, w));
//    }
//
//    void AddjList() {
//        for (auto p : mp) {
//            string city = p.first;
//            list<pair<string, int>> itr = p.second;
//
//            cout << city << " ->";
//            for (auto it : itr) {
//                cout << " ( " << it.first << ",";
//                cout << it.second << " ) ";
//            }
//            cout << "\n";
//        }
//    }
//};
#pragma endregion

#pragma region BFS_DFS
//template<typename T>
//class Graph {
//    unordered_map<T, list<T>> mp;
//public:
//    void addEdge(T  x, T y) {
//        mp[x].push_back(y);
//        mp[y].push_back(x);
//    }
//
//    void BFS(T src) {
//        map <T, bool> vis;
//        queue<T> q;
//
//        q.push(src);
//        vis[src] = true;
//
//        while (!q.empty()) {
//            T node = q.front();
//            q.pop();
//            cout << node << "\n";
//
//            for (T itr : mp[node]) {
//                if (vis[itr] == false) {
//                    q.push(itr);
//                    vis[itr] = true;
//                }
//            }
//
//        }
//    }
//
//    void dfs_helper(T src, map<T, bool> vis) {
//        
//        cout << src << " ";
//        vis[src] = true; 
//
//        for (T nbr : mp[src]) {
//            if (vis[nbr] == false) {
//                dfs_helper(nbr, vis);
//            }
//        }
//        return;
//    }
//
//    void DFS(T src) {
//        map<T, bool> vis;
//        for (auto i1 : mp) {
//            T node = i1.first;
//            vis[node] = false;
//        }
//        dfs_helper(src, vis);
//    }
//};
#pragma endregion


int main()
{
    Graph g(4);
    g.addEdge(0 , 2);
    //g.addEdge(1 , 2);
    g.addEdge(0 , 1);
    g.addEdge(2 , 3);
    //g.AddjList();
    g.contain_Cycle();


    /*Graph g;
    g.addEdge("A", "B" , 20);
    g.addEdge("B", "D" , 10);
    g.addEdge("A", "C" , 30);
    g.addEdge("C", "D" , 50);
    g.addEdge("A", "D" , 40);
    g.AddjList();*/

    
   /* Graph1<int> g;
    g.addEdge(11, 10);
    g.addEdge(2, 14);
    g.addEdge(11, 14);
    g.addEdge(1, 2);
    g.addEdge(10, 1);*/

    //g.BFS(10);
    //g.DFS(10);
}


