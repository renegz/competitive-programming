#include <bits/stdc++.h>

using namespace std;

int main(){

    string operation;

    cin >> operation;

    multiset<char> tree;

    for (auto x: operation)
    {
        if(x != '+'){
            tree.insert(x);
        }
    }

    for (auto it = tree.begin(); it != tree.end(); it++)
    {
        if(it != tree.begin()){
            cout<<"+";
        }
        
        cout << *it;

    }
    
    

    return 0;
}