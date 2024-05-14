//2. Improve your shell program so that it should not be terminated due to SIGINT (ctrl+C).
#include<signal.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>


void sigint_handler(int sig)
{
   printf("SIGINT  caught:%d\n",sig);
}


int main()
{
   char cmd[400] ,*ptr, *args[34];
   int i,ret,err,s;
   signal(SIGINT,sigint_handler);
   while(1)
   {
     printf("cmd>  ");
	 gets(cmd);
//	 printf("cmd> ");

	 i=0;
	 ptr = strtok(cmd," ");
	 args[i]= ptr;
	 i++;
//	 printf("First token :%s\n",ptr);
	 do{
	     ptr = strtok(NULL," ");
		 args[i] = ptr;
		 i++;
		}while(ptr != NULL);

		if(strcmp(args[0],"exit") == 0)
		   break;
		else if(strcmp(args[0],"cd") == 0)
		   chdir(args[1]);
		else
		{
		  ret = fork();
		  if(ret == 0)
		  {
		    err = execvp(args[0] , args);
			if(err < 0)
			{
			  perror("bad command");
			  _exit(1);
			}
			else
			  wait(&s);
		  }
		}
	}
		printf("bye!\n");
		return 0;
}
			  
