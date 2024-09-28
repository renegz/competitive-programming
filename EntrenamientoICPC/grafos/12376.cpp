#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>


vi kw;
vector<vi> AL(100);
int counter = 0;
int position = 0;
void solve(int s);

int main (){
    int T;
    cin >> T;

    int n, m;
    for(int i = 1; i <= T; i++){
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            kw.push_back(val);
        }


        while (m--)
        {
            int index, conection;
            cin >> index >> conection;
            AL[index].push_back(conection);
        }

        solve(0);
        cout << "Case " << i << ": " << counter << " " << position << endl;
        counter = 0;
        position = 0;

        kw.clear();
    }
    
    
    
}

void solve(int s){
    int aux = 0;
    if(AL[s].size() == 0) {
        return;
    }
    for (int i = 0; i<AL[s].size(); i++){
        if(counter + kw[AL[s][i]] > aux) {
            aux = counter + kw[AL[s][i]];
            position = AL[s][i];
        }
    }
    counter = aux;
    AL[s].clear();
    solve(position);
}