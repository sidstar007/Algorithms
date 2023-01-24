#include <stdio.h>

int start=0;
int cycle[5]={-1,-1,-1,-1,-1};
int visited[5]={0,0,0,0,0};

void findCycle(int mat[][5],int v,int count) {
    if (count==5 && mat[v][start]==1) {
        for (int i=0;i<5;++i) {
            printf("%d ",cycle[i]);
        }
        printf("\n");
    }

    for (int i=1;i<5;++i) {
        if (mat[v][i]==1 && visited[i]==0) {
            visited[i]=1;
            cycle[count]=i;
            findCycle(mat,i,count+1);
            visited[i]=0;
            cycle[count]=-1;
        }
    }
}

int main() {
    int mat[5][5]={{0,1,1,0,1},
                 {1,0,1,1,1},
                 {1,1,0,1,0},
                 {0,1,1,0,1},
                 {1,1,0,1,0}};

    visited[0]=1;
    cycle[0]=0;

    findCycle(mat,0,1);
return 0;
}