//Input signal number and a process id from user. Send given signal to the given process using kill() syscall.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
   int pid,sig_no;
   printf("Enter pid:");
   scanf("%d",&pid);
   printf("Enter sig_no:");
   scanf("%d",&sig_no);

   int ret=kill(pid,sig_no);
   printf("kill return =%d\n",ret);
   return 0;
}
