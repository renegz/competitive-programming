#include <bits/stdc++.h>

using namespace std;

void OneForAll();
void checkMinOnes(int number);

vector<int> dp(100005);
int n;

int main(){


    cin >> n;

    OneForAll();

    cout << dp[n] << endl;

}

void OneForAll(){

    for (int i = 1; i <= n; ++i){
        if(i <= 5) {dp[i] = i;} //Los casos i <= 5 son casos base
        else {
            checkMinOnes(i);
        }
    }
}

void checkMinOnes(int number){
    int value = INT32_MAX;

    //Casos de multiplicacion
    for (int i = 2; i<=sqrt(floor(number)); ++i){
        
        if(number%i == 0){
            int mult = number/i;
            value = min(value, dp[mult] + dp[i]);
        }
    }


    //Casos de suma
    // value = min(value, dp[number-1] + dp[1]); // No todos se resuelven el anterior + 1

    for(int i = 1; i < number ; ++i){ //Se deben verificar todas las opciones posibles de suma
        value = min(value, dp[number-i] + dp[i]);
    }

    //Casos de concatenaciones
    
    string str = to_string(number); // transformo el numero en un string para manejar las concatenaciones.
    for (int i = 1; i< str.length(); ++i){
        string s1 = str.substr(0, i);
        string s2 = str.substr(i, str.length());

        if(s2[0] != '0') { // Para 1 C 01 , en el s2 no se deben tomar en cuenta los ceros a la izquierda, entonces no guardamos esos casos.
            value = min(value, dp[stoi(s1)] + dp[stoi(s2)]);
        }
    }


    dp[number] = value; //El valor se almacena en el arreglo en la posicion del numero
}


