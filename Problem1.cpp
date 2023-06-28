#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

double dfs(vector<double> &v, int k, int i){
    if(k==0)return (1.0);
    if(i<0)return 0;
    if(dp[i][k]!=-1)return dp[i][k];
    double ans = 0;
    ans += v[i]*dfs(v, k-1, i-1);
    ans += (1.0-v[i])*dfs(v, k, i-1);
    return dp[i][k] = ans;
}

int main() {
    int n;
    cin>>n;
    vector<double> v(n);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i<n; i++)cin>>v[i];
    cout<<dfs(v,n/2+1, v.size()-1);<<endl;
}
