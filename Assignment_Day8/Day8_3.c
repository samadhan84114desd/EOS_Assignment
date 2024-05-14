//3. Find max number of child processes that can be created on Linux using C program? Hint: use fork() in inﬁnite loop (wisely).

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
   int i=1,s,j,ret;
   while(i)
   {
      ret=fork();
	  if(ret==0)
	  {
	     printf("child\n");
		 sleep(5);
		 _exit(0);
	  }
	  else if(ret==-1)
	  {
	    printf("Fork() failed\n");
		break;
	  }
	  else
	  {
	    i++;
		printf("child count:%d\n",i);
	  }
	  for(j=1;j<=i;j++)
	  {
	    wait(&s);
	  }
	}
	return 0;
}
