#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int N, M, a;

    cin >> N >> M;

    int index = 1;
    int pos = 0;

    while (N--)
    {
        cin >> a;
        
        if(a >= M){
            pos = index;
            break;
        }
        index++;
    }

    if (pos == 0) {
        cout << "-1";
    } else {
        cout << pos;
    }

    return 0;
}