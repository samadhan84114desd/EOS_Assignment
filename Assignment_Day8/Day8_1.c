#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
  int a,b,c;
  int s,s1,s2;
  a=fork();
  if(a==0)
  {
    int i;
	for(i=0;i<=10;++i)
    {
	   printf("Child1=%d\n",i);
	   sleep(2);
	}
	_exit(0);
  }
  b=fork();
  if(b==0)
  {
    int i;
	for(i=11;i<=20;++i)
	{
	   printf("Child2=%d\n",i);
	   sleep(2);
	}
	_exit (0);
  }
  c=fork();
  if(c==0)
  {
    int i;
	for(i=21;i<=30;++i)
	{
	  printf("child3=%d\n",i);
	  sleep(2);
	}
	_exit(0);
  }
  waitpid(a,&s,0);
  waitpid(b,&s1,0);
  waitpid(c,&s2,0);
  return 0;
}















