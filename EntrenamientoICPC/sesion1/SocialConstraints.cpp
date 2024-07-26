#include <bits/stdc++.h>

using namespace std;

vector<int> arr, a(21), b(21), c(21);
int ans = 0;

int factorial(int n);
int constraints(int m);

int main(){

    int n, m;

    do {
        arr.clear();
        ans = 0;

        cin >> n >> m;

        for (int i = 0 ; i<n;++i) arr.push_back(i);

        if (m == 0 && n > 0) cout << factorial(n) <<endl;

        for (int i = 0; i < m ; ++i)
        {
            cin >> a[i] >> b[i] >> c[i];
        }

        if (m!=0) cout << constraints(m) << endl;

    } while (n != 0 || m !=0);
    
    return 0;
}

int factorial(int n){
    int mult=1;
    for (int i = n; i > 0; i--)
    {
        mult = mult *i;
    }
    return mult;
}

int constraints(int m){

    do 
    {
        int aPos, bPos;
        bool valid = false;

        for (int i = 0 ; i < m ; ++i){

            for ( int j = 0; j<arr.size(); ++j) {
                if(arr[j] == a[i] ) {
                    aPos = j;
                }
                if(arr[j] == b[i] ) {
                    bPos = j;
                }
            }
            
            if (c[i] > 0 && 
                abs(aPos - bPos) <= abs(c[i]) //Se calcula la diferencia entre las posiciones
            ){
                valid = true;
            } else if (c[i] < 0 && 
                abs(aPos - bPos) >= abs(c[i])
            ){
                valid = true;
            } else {
                valid = false; //Si alguno de los constraints falla, no se suma como una posibilidad
                break;
            }
        }
        if(valid){
                ans++;
        }

    } while (next_permutation(arr.begin(), arr.end()));
    
    return ans;
}