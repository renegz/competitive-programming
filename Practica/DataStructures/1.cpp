//  Sort the following array of N elements. Use built-in library if possible.
// 1. N tuples (integer age ", string last name # (descending order), string first name ").
// 2*. N fractions ( numerator
// denominator ) in " (ascending order).

#include <bits/stdc++.h>
using namespace std;

struct Tuple
{
    int age;
    string last_name;
    string first_name;
};

bool ageCmp(Tuple a, Tuple b){
    return a.age<b.age;
}

bool lastNameCmp(Tuple a, Tuple b){
    return a.last_name>b.last_name;
}

bool firstNameCmp(Tuple a, Tuple b){
    return a.first_name<b.first_name;
}

int main(){
    int n;
    cin >> n;

    vector<Tuple> Tuples(n);

    for(int i = 0; i < n ; ++i){
        cin >> Tuples[i].age >> Tuples[i].first_name >> Tuples[i].last_name;
    }

    cout << "===============================" << endl;

    sort(Tuples.begin(), Tuples.end(), ageCmp);

    for(auto x: Tuples){
        cout << x.age << endl;
    }

    cout << "===============================" << endl;

    sort(Tuples.begin(), Tuples.end(), lastNameCmp);

    for(auto x: Tuples){
        cout << x.last_name << endl;
    }

    cout << "===============================" << endl;

    sort(Tuples.begin(), Tuples.end(), firstNameCmp);

    for(auto x: Tuples){
        cout << x.first_name << endl;
    }

    return 0;
}