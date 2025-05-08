#include <bits/stdc++.h>

using namespace std;

void solve (string P, string S){

    for (int i = 0; i < P.size(); i = i + S.size())
    {
        string sub = P.substr(i, S.size());
        if(sub != S) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    return;
}

int main(){

    string S;
    int N;
    string P;

    cin >> S >> N;

    while (N--){
        cin >> P;

        solve(P, S);

    }

    return 0;
}