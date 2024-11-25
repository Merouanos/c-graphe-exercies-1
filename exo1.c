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
void make_matrix_zero(int **t,int n,int m)
{
    for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
        t[i][j]=0;
}

int ** create_random_matrix_indicent(int n, int m)
{
    int i,j;
    srand(time(0));
 int **a = malloc(n*sizeof(int *));
 for(i=0;i<n;i++)
    a[i]=malloc(sizeof(int)*m);

    ;

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

void check_index(int **t, int j,int n,int *start ,int *finish)
{
   int k=0;
   *finish =-1;
   *start=-1;
   while(k<n &&(*finish==-1 ||*start ==-1))
   {
    if(-1==t[k][j])
       *finish=k; 
       else if(1==t[k][j])
       *start =k;
        k++;

   }


}

int **generate_adjacent(int **t,int n,int m)
{   
    int **a=malloc(sizeof(int *)*n);
    int i,j,start,finish;
    for (i=0;i<n;i++)
    a[i]=malloc(sizeof(int)*n);
    make_matrix_zero(a,n,n);
    for(j=0;j<m;j++)
    {
        check_index(t,j,n,&start,&finish);
        a[start][finish]=1;
    }
    return a;



}






int main()
{
    int n=3,m=3;
    int **t,**a;
    t=create_random_matrix_indicent(n,m);
    print_matrix(t,n,m);
    printf("\n");
    a=generate_adjacent(t,n,m);
    print_matrix(a,n,m);
    free_matrix(t,n);
    free_matrix(a,n);










}