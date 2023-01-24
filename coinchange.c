#include <stdio.h>
#include <limits.h>
#include <time.h>

int min(int a,int b) {
    return a<b?a:b;
}

//Memoization
int TDcoinChange(int dp[],int coins[],int n,int amount) {
    if (amount==0) {
        return 0;
    }

    if (dp[amount]!=0) {
        return dp[amount];
    }
    int ans=INT_MAX;
    for (int i=0;i<n;++i) {
        if (coins[i]<=amount) {
            int val=TDcoinChange(dp,coins,n,amount-coins[i]);
            ans=min(ans,val+1);
        } 
    }
    return dp[amount]=ans;
}

//Tabulation
int BUcoinChange(int coins[],int n,int amount) {
    int dp[amount+1];
    
    dp[0]=0;

    for (int i=1;i<=amount;++i) {
        dp[i]=INT_MAX;
        for (int j=0;j<n;++j) {
            if (coins[j]<=i) {
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }

    if (dp[amount]==INT_MAX || dp[amount]==INT_MIN) {
        return -1;
    }
    else {
        return dp[amount];
    }
}

//Driver Code
int main() {
    printf("Enter number of coins: ");
    int n;
    scanf("%d",&n);
    int coins[n];
    for (int i=0;i<n;++i) {
        scanf("%d",&coins[i]);
    }
    printf("Enter amount: ");
    int amount;
    scanf("%d",&amount);
    clock_t t;
    t=clock();
    printf("%d",BUcoinChange(coins,n,amount));
    t=clock()-t;
    double time_taken = (double)(t)/CLOCKS_PER_SEC;
    printf("Time: %lf",time_taken);
return 0;
}
