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
        
        solution = false;
        for (int i = M ; i > 0 ; i--){ //Se recorre el arreglo de derecha a izq en la ultima fila y si encuentra un 1 cambia la bandera a true e imprime el resultado
            if (dp[C][i] > 0){
                solution = true;
                cout << i << endl;
                break;
            }
        }

        if (!solution){ //Si la bandera no cambia significa que no hay solucion
            cout << "no solution" << endl;
        }
    }
    
    return 0;
}

void Shopping(vector<vector<int>> &dp){
    for (int i = 1; i <= C; ++i){
        for (int j =1; j <= M; ++j){
            check(dp, i, j);
        }
    }
}

void check(vector<vector<int>> &dp, int i, int j){
    if (dp[i-1][j] > 0 && i > 1){ //si hay un valor arriba se recorre en los modelos y se colocan 1, en las columnas del valor de la suma
        for (int k = 1; k <= K[i]; k++)
        {   
            if (j + models[i][k] <= M){  //Solo se coloca el 1 si es una columna que no excede el budget M
                dp[i][j + models[i][k]] = 1;
            }
        }
    }
    if (i == 1){ //Debido a que la primera fila no tiene valores arriba solo se colocan todos los 1 posibles en su columna
        for (int k = 1; k <= K[i]; k++)
        {   
            if (j == models[i][k]) dp[i][j] = 1; 
        }
    }
    
}