/*
From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) and it (C) in turn create new child (D). All these
processes should run concurrently for 5 seconds and cleaned up properly upon termination.*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
   int var1,var2,var3,var4,s1,s2,s3,s4;
   var1=fork();
   if(var1==0)
   {
      var2=fork();
	  if(var2==0)
	  {
	     var3=fork();
		 if(var3==0)
		 {
		   var4=fork();
		   if(var4==0)
		   {
		     printf("child D\n");
			 sleep(5);
			 _exit(0);
           }
		   printf("child C\n");
		   sleep(2);
		   waitpid(var4,&s4,0);
		   printf("child D exit %d\n",s4);
		  // sleep(2);
		   _exit(0);
		 }
		 printf("child B\n");
		 sleep(5);
		 waitpid(var3,&s3,0);
		 printf("child C exit %d\n",s3);
		 _exit(0);
	  }
	  printf("child A\n");
	  sleep(2);
	  waitpid(var2,&s2,0);
	  printf("child B exit %d\n",s2);
	  _exit(0);
	}
	printf("pearent\n");
	sleep(2);
	waitpid(var1,&s1,0);
	printf("child A exit %d\n",s1);
	printf("End__!!\n");
	return 0;
}

