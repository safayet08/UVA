#include<bits/stdc++.h>
using namespace std;
int coin[] = {1,5,10,25,50};
int dp[10][7489];
int target;

int coinchange(int pos, int amount)
{
    if(pos >= 5)
        return 0;
    if(amount < 0)
        return 0;
    if(dp[pos][amount] != -1)
        return dp[pos][amount];
    if (amount == 0)
        return 1;
    int ret = 0;
    ret += coinchange(pos,amount-coin[pos]) + coinchange(pos+1,amount) ;
    dp[pos][amount] = ret;
    return ret;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&target) == 1)
    {
        printf("%d\n",coinchange(0,target));
    }
    return 0;
}
