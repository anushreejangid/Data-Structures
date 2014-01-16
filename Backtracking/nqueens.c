//This problems solves the nqueens problem and produces all the solution possible for 8*8 chessboard
#include<stdio.h>
#include<math.h>

int place(int k,int i,int a[])
{
 int j;
 for(j=1;j<k;j++)
   {
     if(a[j]==i || abs(a[j]-i)==abs(j-k))
	   return 0;
	   
	}
 return 1;	     
}

void nqueen(int k,int n,int a[])
 {
 
   static int sol=1;
   int i,m,o;
   int res[9][9]={0};
     /* printf("inside nqueen");*/
   for(i=1;i<=n;i++)
    { 
	  if(place(k,i,a))
	    {
		  a[k]=i;
		  if(k==n)
		    {
			for(m=1;m<=n;m++)
			  {	   
			  res[m][a[m]]=1; 	  	  	    
			  /*printf("a[%d]=%d, ",m,a[m]);*/
			  for(o=1;o<=n;o++)
			   /*if(a[m]==o)
			    printf("1 ");
				else
				printf("0 ");*/
				printf("%d ",res[m][o]);
			  printf("\n");	   
			   
			  }
			  printf("sol= %d \n",sol++);  
			}
			else
			 nqueen(k+1,n,a);
		}  
	}	  
 }	     

int main()
{
int a[9];
nqueen(1,8,a);
return 0;
}

