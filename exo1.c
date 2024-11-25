#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void print_matrix(int **t,int n ,int m)
{
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<m;j++)
        printf(" %d ",t[i][j]);
        printf("\n");
    }

}

void free_matrix(int **t,int n)
{
    for(int i=0;i<n;i++)
        free(t[i]);
    free(t);

}


int ** create_random_matrix_indicent(int n, int m)
{
    int i,j;
    srand(time(0));
 int **a = malloc(n*sizeof(int *));
 for(i=0;i<n;i++)
    a[i]=malloc(sizeof(int)*m);

    for(i=0;i<n;i++)
     for(j=0;j<m;j++)
        a[i][j]=0;

    for(j=0;j<m;j++)
    {
        int random1 = rand() % m;
        int random2;
        do{
        random2= rand() % m;
        }while(random2==random1);
        a[random1][j]=1;
        a[random2][j]=-1;

    }
    return a;
    




}










int main()
{
    int n=3,m=3;
    int **t;
    t=create_random_matrix_indicent(n,m);
    print_matrix(t,n,m);
    free_matrix(t,n);










}