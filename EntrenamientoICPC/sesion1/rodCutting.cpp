#include <bits/stdc++.h>

using namespace std;

int rodCutting(vector<int> *prices, int n);
int rodCuttingTopDown(vector<int> *prices, int n, vector<int> *ans);
int rodCuttingBottomUp(vector<int> *prices, int n);

int main(){

    vector<int> prices;

    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(8);
    prices.push_back(9);
    prices.push_back(10);
    prices.push_back(17);
    prices.push_back(17);
    prices.push_back(20);
    prices.push_back(24);
    prices.push_back(30);

    vector<int> ans(prices.size()*2);

    cout << rodCutting(&prices, 10) <<endl ;
    cout << rodCuttingTopDown(&prices, 10, &ans) <<endl ;
    cout << rodCuttingBottomUp(&prices, 10);

    return 0;
}

int rodCutting(vector<int> *prices, int n){
    if(n == 0)
        return 0;

    int q = INT16_MIN;
    for (int i = 1; i <= n; i++)
    {
        q = max(q, ((*prices)[i-1] + rodCutting(prices, n-i)));
    }
    
    return q;
}

int rodCuttingTopDown(vector<int> *prices, int n, vector<int> *ans){
    if(ans->at(n) > 0)
        return ans->at(n);
    if(n == 0){
        return 0;
    } 
    int q = INT16_MIN;
    for (int i = 1; i <= n; i++)
    {
        q = max(q, (prices->at(i-1) + rodCuttingTopDown(prices, n-i, ans)));
    }
    ans->at(n) = q;
    
    return q;
}

int rodCuttingBottomUp(vector<int> *prices, int n){
    vector<int> r(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            r[i] = max((*prices)[i], (*prices)[j]+(*prices)[i-j]);
        }
    }
    return r[n-1];
}