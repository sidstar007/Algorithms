#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int n;
int ways=0;
bool isValid(int arr[][n],int i,int j) {
    for (int k=0;k<i;++k) {
    if (arr[k][j]==1) {
        return false;
    }
    }

int x=i-1,y=j-1;
    while (x>=0 && y>=0) {
    if (arr[x][y]==1) {
        return false;
    }
    --x;
    --y;
    }

x=i-1;y=j+1;
    while (x>=0 && y<n) {
    if (arr[x][y]==1) {
        return false;
    }
    --x;
    ++y;
    }
    return true;
}

void nQueen(int arr[][n],int i) {
    if (i==n) {
    ways++;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
    }

for (int j=0;j<n;++j) {
    arr[i][j]=1;
    if (isValid(arr,i,j)) {
        nQueen(arr,i+1);
    }
    arr[i][j]=0;
    }
}
int main() {
int _n;
printf("Enter size of the board: ");
scanf("%d",&_n);
n=_n;
int arr[n][n];
for (int i=0;i<n;++i) {
for (int j=0;j<n;++j) {
arr[i][j]=0;
}
}
nQueen(arr,0);
printf("Total ways are %d\n",ways);
printf("Enter 0 to exit.");
int op;
scanf("%d",&op);
if (op==0) {
    exit(0);
}
return 0;
}