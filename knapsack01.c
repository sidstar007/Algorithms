// 0/1 Knapsack with dynamic programming implementaion

#include <stdio.h>

int max(int a,int b) {
    return a>b?a:b;
}
int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d",&n);
    int p[n+1],w[n+1];
    p[0]=0;
    w[0]=0;

    for (int i=1;i<=n;++i) {
        printf("Enter profit and weight: ");
        scanf("%d %d",&p[i],&w[i]);
    }

    int m;
    printf("Enter max weight of sack: ");
    scanf("%d",&m);

    int dp[n+1][m+1];

    //Initializing first column value with zero
    for (int i=0;i<n+1;++i) {
        dp[i][0]=0;
    }
    //Initializing first row with value of zero
    for (int i=0;i<m+1;++i) {
        dp[0][i]=0;
    }
    //Tabulation
    for (int i=1;i<n+1;++i) {
        for (int j=1;j<m+1;++j) {
            if (j-w[i]>=0) {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    for (int i=0;i<n+1;++i) {
        for (int j=0;j<m+1;++j) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }

return 0;
}