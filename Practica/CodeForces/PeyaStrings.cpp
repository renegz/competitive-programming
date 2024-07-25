#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string word1, word2;

    cin >> word1 >> word2;

    int res;

    for (int i = 0; i < word1.length(); i++)
    {
        if (tolower(word1[i]) == tolower(word2[i]))
        {
            res = 0;
        } else if (tolower(word1[i]) > tolower(word2[i])){
            res = 1;
            break;
        } else {
            res = -1;
            break;
    }
    }
    
    cout << res;

    return 0;
}