/*
2. The child process send two numbers to the parent process via pipe. The parent process calculate the sum and return via another pipe. The child process
print the result and exit. The parent process wait for completion of the child and then exit.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
   int ret,s,num1,num2,n1,n2,r;
   int arr1[2],arr2[2],res;

   ret=pipe(arr1);
   ret=pipe(arr2);
   ret=fork();
   if(ret==0)
   {
      close(arr1[0]);
	  close(arr2[1]);
	  printf("Enter num1:");
	  scanf("%d",&num1);
	  printf("Enter num2:");
	  scanf("%d",&num2);
	  write(arr1[1],&num1,sizeof(num1));
	  write(arr1[1],&num2,sizeof(num1));
      printf("child send data!!!\n");

	  read(arr2[0],&res,sizeof(int));
	  printf("Result:%d\n",res);
	  close(arr2[0]);
	  close(arr1[1]);
	}
    else
	{
	  close(arr1[1]);
	  close(arr2[0]);
	  read(arr1[0],&n1,sizeof(int));
	  read(arr1[0],&n2,sizeof(int));
	  printf("%d  %d\n",n1,n2);
	  r=n1+n2;
	  write(arr2[1],&r,sizeof(int));
	  close(arr2[1]);
	  close(arr1[0]);
	  waitpid(-1,&s,0);
	}
	return 0;
}
	 

