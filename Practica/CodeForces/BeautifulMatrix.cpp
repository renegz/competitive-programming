#include <bits/stdc++.h>

using namespace std;

int main(){

    int M[5][5];
    int cont = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> M[i][j];

            if (M[i][j] == 1) {         

                cont = abs(2-i)+abs(2-j);

                // int iAux=i;
                // int jAux=j;

                // while (iAux !=2 || jAux != 2) {
                //     if (iAux<2){
                //         iAux++;
                //         cont++;
                //     }
                //     if (iAux>2){
                //         iAux--;
                //         cont++;
                //     }
                //     if (jAux<2){
                //         jAux++;
                //         cont++;
                //     }

                //     if (jAux>2){
                //         jAux--;
                //         cont++;
                //     }

                // }
            }
        }
    }

    cout << cont;

    return 0;
}