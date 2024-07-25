#include <bits/stdc++.h>

using namespace std;

void ChessRec(int position);
bool validPos(int position, int i);

vector<int> solutions(9);
int row, col;

int main(){

    int n;

    cin >> n;

    while (n--)
    {
        cin >> row >> col;
        ChessRec(1);
    }

    return 0;

}

void ChessRec(int queen){
    for (int pos = 1; pos<=8 ; ++pos){
        if (validPos(queen, pos))
        {
            solutions[queen] = pos;
            if(queen == 8 && solutions[col] == row){
                for (auto x:solutions)
                {
                    cout << x << " ";
                }
                cout << endl;
                return;
            } else{
                ChessRec(queen+1);
            }
        }
    }
}

bool validPos(int queen, int pos){
    for(int ant = 1; ant <= queen - 1; ant++)
        //La primera condicion es para ver si ya se ha colocado alguna reina anterior en esa fila (pos)
        //La segunda para comprobar si esta en una diagonal
        if(solutions[ant] == pos || (abs(solutions[ant] - pos) == abs(ant - queen))) 
            return false;
    return true;
}