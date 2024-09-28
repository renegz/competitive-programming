#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

vi kw;

int main (){
    int T;
    cin >> T;

    int n, m;
    while(T--){
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            kw.push_back(val);
        }

        vector<vi> AL(n);

        while (m--)
        {
            int index, conection;
            cin >> index >> conection;
            AL[index].push_back(conection);
        }

    }
    
    
    
}