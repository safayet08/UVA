#include<bits/stdc++.h>
long long coin[] = {1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
long long dp[22][10010], target;

long long coinchange(long long pos, long long amount)
{
    if(pos >= 21) return 0;
    if(amount < 0) return 0;
    if(dp[pos][amount] != -1) return dp[pos][amount];
    if (amount == 0) return 1;
    long long ret = 0; ret += coinchange(pos,amount-coin[pos]) + coinchange(pos+1,amount) ;
    return dp[pos][amount] = ret;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    while(scanf("%lld",&target) == 1)
        printf("%lld\n",coinchange(0,target));
}
