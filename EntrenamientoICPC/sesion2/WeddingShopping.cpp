#include <bits/stdc++.h>

using namespace std;

int M, C;
vector<int> K(21);
vector<vector<int>> models(21, vector<int>(21));
bool solution;

void check(vector<vector<int>> &dp, int i, int j);
void Shopping(vector<vector<int>> &dp);


int main(){

    int N;

    cin >> N;

    while (N--)
    {
        cin >> M >> C;

        vector<vector<int>> dp(C+2, vector<int>(M+2));
        solution = true;

        for (int i = 1; i <= C; i++)
        {
            cin >> K[i];
            for (int j = 1; j <= K[i]; j++)
            {
                cin >> models[i][j];
            }
        }

        Shopping(dp);

        //Imprimir las matrices dp
        // for (int i = 0; i <= C; i++)
        // {
        //     for (int j = 0; j <= M; j++)
        //     {
        //         cout << dp[i][j] << " "; 
        //     }
        //         cout << endl;
        // }
        

        if (dp[C][M] <= M && solution == true){
            cout << dp[C][M] <<endl;
        } else {
            cout << "no solution" << endl;
        }
        
        //dp.clear();
    }
    
    return 0;
}

void Shopping(vector<vector<int>> &dp){
    for (int i = 1; i <= C; ++i){
        for (int j =1; j <= M; ++j){
            check(dp, i, j);
        }
        if (dp[i-1][M] == 0 && i >1) solution = false;
    }
}

void check(vector<vector<int>> &dp, int i, int j){
    int value = 0;
    for (int k = 1; k <= K[i]; k++)
    {   

        if (models[i][k] + dp[i-1][j] <= M && j >= models[i][k]){ 
            value = max(value, models[i][k] + dp[i-1][j]);  
            
        } else {
            value = max(value, dp[i][j-1]);
        }
    }
    dp[i][j] = value;
}