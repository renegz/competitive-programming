#include <bits/stdc++.h>

#define vi vector<int>

using namespace std;

enum { UNVISITED = -1, VISITED = -2};

vector<vi> al;
vi dfs_num;

void dfs(int u){
    dfs_num[u] = VISITED;
    for(int i = 0; i < al[u].size(); i++){
        int v = al[u][i];
        if(dfs_num[v] == UNVISITED){
            dfs(v);
            cout << al[u][i] << " ";
        }
    }
}

int main() {
    int n, c;
    cin >> n;
    while (n--)
    {
        cin >> c;
        vi aux;
        while (c--)
        {
            int val;
            cin >> val;
            aux.push_back(val);
        }
        al.push_back(aux);
        dfs_num.push_back(UNVISITED);
    }

    dfs(0);

    return 0;
}