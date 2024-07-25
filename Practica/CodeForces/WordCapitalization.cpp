#include <bits/stdc++.h>

using namespace std;

int main(){

    string word;

    cin >> word;

    

    for (int i = 0; i < word.length(); i++)
    {
        if (i==0 && (char)toupper(word[i]) != word[i])
        {
            cout << (char)toupper(word[i]);
        } else {
            cout << word[i];
        }
    }
    
    

    return 0;   
}