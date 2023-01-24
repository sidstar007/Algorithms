#include <stdio.h>

void subset(int val[],int nums[],int n,int i,int sum) {
    if (sum==0 && i<n) {
        for (int k=0;k<i;++k) {
            printf("%d ",val[k]);
        }
        return;
    }
    
    if (i>=n) {
        return;
    }

    val[i]=nums[i];
    subset(val,nums,n,i+1,sum-nums[i]);
    subset(val,nums,i+1,n,sum);
}

int main() {
    int nums[]={2,4,5,21,5};
    int val[1024];
    subset(val,nums,5,0,10);
return 0;
}