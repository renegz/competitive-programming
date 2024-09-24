#include <bits/stdc++.h>
using namespace std;
/*

1
2
3
4
5
6
7
8
9
0

00
11
22
33
44

100

*/
int main () {
    string s;
    map<int, int> mp;
    cin >> s;
    for(auto c:s){
        int i = c - '0';
        mp[i]++;
    }


    int cont = 0;
    vector<int> q;
    bool zeroflag = false;
    while (true) {
        bool flag = false;
        ++cont;

        /*

        1 - 10

        55
        mp[5] = 1

        */
        for(int i = 0;i < 10;++i) {
            if(i != 0 &&mp[i] < cont) {
                for(int j =0;j<cont;++j)
                    q.push_back(i);
                flag = true;
                break;
            } else if (zeroflag) {
                for(int j = 0;j<=cont;++j) {
                    if (!j) q.push_back(1);
                    else q.push_back(0);
                }
                flag = true;
                break;
            } else if (i == 0 && mp[i] < cont)
                zeroflag = true;
        }
        if(flag) break;
    }

    for (auto e: q) {
        cout << e;
    }
    cout <<'\n';
    return 0;
}
