#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vii vector<pair<int,int>>
#define qi queue<int>
#define vi vector<int>
#define f(i,a,b) for(int i = a; i<b;++i)
int main () {
    int n,m, t;
    cin >> t;
    f(ti, 0,t) {

        cin >> n >> m;
        int am[n][n] = {0};
        vi aug(n,INT_MIN);
        int kw[n];
        f(i,0,n){
            cin >> kw[i];
        }
        f(i,0,m){
            int u,v;
            cin >> u >> v;
            am[u][v]=1;
        }

        qi q;
        q.push(0);
        aug[0] = 0;

        int resIndex = 0, resValue = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            f(i,0,n){
                if (!am[u][i]) continue;
                int v = i;
                if(am[u][v] && aug[u]+kw[v] > aug[v]) {
                    aug[v] = aug[u]+kw[v];
                    // resIndex = (resValue<aug[v] ? v : resIndex);
                    // resValue = max(resValue,aug[v]);
                    q.push(v);
                }
            }
        }
        f(i,0,n){
            if (resValue < aug[i]) {
                resValue = aug[i];
                resIndex = i;
            }
        }
        cout << "Case " << ti+1 << ": " << resValue << ' ' << resIndex << '\n';
    }
    return 0;
}
