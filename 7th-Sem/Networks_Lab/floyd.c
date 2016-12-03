#include<stdio.h>
struct network
{
   int dist[10], outgoing[10];
};

struct network nodes[10];

void init(int n)
{
  // dist from node to every other nodes is infinite initially
  // and dist is 0 to itself
   int i,j;
   for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
     if(i!=j)
     {
        nodes[i].dist[j]=999;
        nodes[i].outgoing[j]=j;
     }
    nodes[i].dist[i]=0;
    nodes[i].outgoing[i]=i;
   }
}

void update(int i, int j, int k)
{
   nodes[i].outgoing[j]=k;
   nodes[i].dist[j]=nodes[i].dist[k]+nodes[k].dist[j];
}

void floyd(int n)
{
 int i, j, k;
 for(k=0;k<n;k++)
     for(i=0;i<n;i++)
       for(j=0;j<n;j++)
         if(nodes[i].dist[j]>(nodes[i].dist[k]+nodes[k].dist[j]))
             update(i,j,k);
}

void main()
{
   int n, i, j;
   printf("enter the num of nodes\n");
   scanf("%d",&n);
   init(n);
   printf("enter the distances \n");
   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
     {
        if(i!=j)
        {
            printf("enter distance from %d to %d\n",i+1,j+1);
            scanf("%d",&nodes[i].dist[j]);
        }
     }
   floyd(n);
   printf("distance vector routing algorith\n");
   for(i=0;i<n;i++)
   {
        printf("%d nodes vector table\n",i+1);
        printf("\t DEST \t DIST \t HOP\n");
        for(j=0;j<n;j++)
          if(i!=j)
             printf("\t %d \t %d \t %d\n",j+1,nodes[i].dist[j],nodes[i].outgoing[j]+1);
   }
}
