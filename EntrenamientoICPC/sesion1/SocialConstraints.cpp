#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int factorial(int n);
void constraints(int a, int b, int c);

int main(){

    int a, b, c;
    int n, m;

    do {
        arr.clear();

        cin >> n >> m;

        for (int i = 0 ; i<n;++i) arr.push_back(i);

        if (m == 0 && n > 0) cout << factorial(n) <<endl;

        while (m--)
        {
            cin >> a >> b >> c;
            constraints(a, b, c);
        }

    } while (n != 0 && m !=0);
    
    

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

void constraints(int a, int b, int c){

    do 
    {
        for (auto x:arr)
            cout << x << " ";
        cout << endl;
    } while (next_permutation(arr.begin(), arr.end()));
    

}