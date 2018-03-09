// Dijkstra Algorithm

#include <stdio.h>
#include <stdlib.h>

struct node{
    int destination;
    int weight;
    node *next;
};
node *vertex[51];
node *ptr, *temp;


int main() {
    
    unsigned int u = 0;
    unsigned int N, m, M, i, j, w, s;
    int d[51],parent[51],W[51]={0};
    int min;

    for (int i=0; i<=50; i++){
        vertex[i]=(node *)malloc(sizeof(node));
        vertex[i]=NULL;
    }
    
    
    scanf("%d %d",&N,&M);
    if (N>=1 && N<=50 && M>=1 && M<=200) {
        
        for (m=1; m<=M; m++) {
            
            scanf("%d %d %d", &i, &j, &w);
            if (i>N || i<1 || j>N || j<1 || i==j) break;
            ptr=(node *)malloc(sizeof(node));
            temp=(node *)malloc(sizeof(node));
            
            ptr->destination=j;
            ptr->weight=w;
            temp=vertex[i];
            ptr->next=temp;
            vertex[i]=ptr;
        }
        
        scanf("%d",&s);
        for (i=0; i<=50; i++) d[i]=2147483647;
        d[s]=0;
        
        if (s<=N && s>=1) {
            
            for (i=1; i<=N; i++) {
                
                min=2147483647;
                for (j=1; j<=N; j++) {
                    if (min>d[j] && d[j]!=-1) {
                        u=j;
                        min=d[j];
                    }
                }
                ptr=vertex[u];
                while (ptr!=NULL) {
                    if (d[ptr->destination]>d[u]+ptr->weight) {
                        d[ptr->destination]=d[u]+ptr->weight;
                        parent[ptr->destination]=u;
                    }
                    ptr=ptr->next;
                }
                W[u]=d[u];
                d[u]=-1;
            }
        }
        
        //output
        for (i=1; i<=N; i++) {
            printf("%d",W[i]);
            if (i!=N) printf(" ");
        }
        printf("\n");
        for (i=1; i<=N; i++) {
            printf("%d",parent[i]);
            if (i!=N) printf(" ");
        }
        printf("\n");

    }
    
    
    return 0;
}
