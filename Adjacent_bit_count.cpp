#include<bits/stdc++.h>
using namespace std;
int dp[1005][105][2];
int f(int num,int target,int i,int parent){
    if (i == 0) return (target == 0) ? 1 : 0;
    if(target<0) return 0;
    if(dp[target][i][parent]!=-1) return dp[target][i][parent];
    int res = 0;
    res+=f(num,target,i-1,0);
    if (parent ==0) res+= f(num,target,i-1,1);
    else res+=f(num,target-1,i-1,1);
    return dp[target][i][parent]=res; 
}
int main(){
int p;
cin>>p;
vector<vector<int>> abc(p,vector<int>(3));
for(int i=0;i<p;i++){
    cin>>abc[i][0]>>abc[i][1]>>abc[i][2];
}
for(int i=0;i<p;i++){
    memset(dp,-1,sizeof(dp));
    cout<<abc[i][0]<<" "<<f(abc[i][1],abc[i][2],abc[i][1]-1,0) + f(abc[i][1],abc[i][2],abc[i][1]-1,1)<<endl; 
}

}