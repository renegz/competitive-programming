#include <bits/stdc++.h>

using namespace std;

int main(){

    string userName;
    unordered_set<char> table;

    cin >> userName;

    int distincts = 0;

    for (int i = 0; i < userName.length(); i++)
    {
        if (table.find(userName[i]) == table.end()){
            table.insert(userName[i]);
            distincts++;
        }
    }

    if (distincts % 2 == 0)
        cout << "CHAT WITH HER!";
    else 
        cout << "IGNORE HIM!";

    return 0;
}