#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<pair<int, int>>
#define f(i,a,b) for (int i = a; i <b; ++i)
#define qi queue<int>

int main () {
    int L,R,C;

    while (scanf("%d %d %d\n", &L, &R, &C), L){
        bool visited[32][32][32] = {0};
        char grid[32][32][32], letter;
        
        int sl,sr,sc, nodes_left = 1, nodes_next = 0, res = 0;
        f(l,0,L){
            f(r,0,R){
                f(c,0,C){
                    cin >> letter;
                    grid[l][r][c] = letter;
                    if (letter=='S') {
                        sl=l;
                        sr = r;
                        sc = c;
                    }
                }
            }
        }
        
        // bfs
        
        int dr[] = {0,0,0,0,1,-1};
        int dc[] = {0,0,-1,1,0,0};
        int dl[] = {1,-1,0,0,0,0};
        
        qi ql, qr, qc;
        
        ql.push(sl); qr.push(sr); qc.push(sc);
        bool flag = false;
        while(!ql.empty()) {
            int r = qr.front(), c = qc.front(), l = ql.front();
            qr.pop();
            qc.pop();
            ql.pop();
            --nodes_left;
            visited[l][r][c] = true;
            // moverse
            if (grid[l][r][c] == 'E') {
                flag = true;
                break;
            }
            f(k,0,6){
                int rr = r + dr[k];
                int cc = c + dc[k];
                int ll = l + dl[k];
                
                if (rr < 0 || cc < 0 || ll < 0) continue;
                if (rr >= R || cc >= C || ll >= L) continue;
                if (grid[ll][rr][cc] == '#' || visited[ll][rr][cc]) continue;
                
                qr.push(rr);qc.push(cc);ql.push(ll);
                visited[ll][rr][cc] = true;
                ++nodes_next;  
            }
            if (nodes_left == 0) {
                ++res;
                nodes_left = nodes_next;
                nodes_next = 0;
            }
        }
        if (flag) {
            cout << "Escaped in " << res << " minute(s)" << ".\n";
        } else {
            cout << "Trapped!\n";
        }
    }
    return 0;
}