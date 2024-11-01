#include <bits/stdc++.h>

using namespace std;

int main(){

    string S1, S2;

    cin >> S1 >> S2;

    int r = S1.size();
    int c = S2.size();

    int dp[r+1][c+1];

    for(int i=0 ; i <= c; i++){
        dp[0][i] = 0;
    }
    for(int i=0 ; i <= r; i++){
        dp[i][0]= 0;
    }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if( S1[i-1] == S2[j-1] ){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[r][c] << endl;
    

    return 0;
}   