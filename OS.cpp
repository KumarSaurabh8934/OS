//Ques. 11. Reena’s operating system uses an algorithm for deadlock avoidance to manage the allocation of resources say three namely A, B, and C to three processes P0, P1, and P2. Consider the following scenario as reference .user must enter the current state of system as given in this example : 
//Suppose P0 has 0,0,1 instances , P1 is having 3,2,0 instances and P2 occupies 2,1,1 instances of A,B,C resource respectively. 
//Also the maximum number of instances required for P0 is 8,4,3 and for p1 is 6,2,0 and finally for P2 there are 3,3,3 instances of resources A,B,C respectively. There are 3 instances of resource A, 2 instances of resource B and 2 instances of resource C available. Write a program to check whether Reena’s operating system is in a safe state or not in the following independent requests for additional resources in the 
//current state: 
//1. Request1: P0 requests 0 instances of A and 0 instances of B and 2 instances of C. 
//2. Request2: P1 requests for 2 instances of A, 0 instances of B and 0 instances of C. 

//All the request must be given by user as input.


#include<conio.h>
#include<stdio.h>
int main()
{
 int n;    //n number of process
 int r;      // number of resources
 int i,j,k,cnt,cntt;
 int avail[10],p[10];
 int need[10][10],alloc[10][10],max[10][10];

 printf("\n please enter the number of process here  :");
 scanf("%d",&n);
 printf("\n please enter the number of resources available here : ");
 scanf("%d",&r);
 printf("\n please enter the instance for resources here :\n");
 for(i=0;i<r;i++)
 {  printf("R%d ",i+1);
  scanf("%d",&avail[i]);
  }
 printf("\n please enter the allocation matrix here : \n");
 for(i=0;i<n;i++)
 {
 printf("p%d",i+1);          p[i]=0;
 for(j=0;j<r;j++)
 {
  scanf("%d",&alloc[i][j]);
 }
}
  printf("\n please enter the MAX matrix here :  \n");

 for(i=0;i<n;i++)
 {
 printf("p%d",i+1);
 for(j=0;j<r;j++)
 {
  scanf("%d",&max[i][j]);
 }
 }

 for(i=0;i<n;i++)
 {
 printf("\np%d\t",i+1) ;
 for(j=0;j<r;j++)
 {
  need[i][j]=max[i][j]-alloc[i][j];
  printf("\t%d",need[i][j]);
  }
 }
 k=0;     cntt=0;
 printf("\n\n");
 while(k<15)
 {
 for(i=0;i<n;i++)
 {  cnt=0;
 for(j=0;j<r;j++)
 {
  if(p[i]==1) break;
  if(need[i][j]<=avail[j])
  {
  cnt++;
  }
  if(cnt==r)
  {
  for(j=0;j<r;j++)
  {
  avail[j]+=alloc[i][j];
  }
  printf("p%d\t",i+1);  p[i]=1;     cntt++;
  }
 }
 } k++;
 }
 if(cntt<n-1)
 {
 printf("\n Occurence of dead lock ");
 }
      getch();
 }


