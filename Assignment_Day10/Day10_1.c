/*The child process send two numbers to the parent process via message queue. The parent process calculate the sum and return via same message queue.
The child process print the result and exit. The parent process wait for completion of the child and then exit.*/

#include<stdio.h>
#include<sys/wait.h>
#include<sys/msg.h>
#include<unistd.h>

#define MQ_KEY  0x1234

typedef struct msg{
               long type;
			   int num1,num2;
			   int ress;
			   }msg_t;
	           
struct msg1{
               long type;
			   int result;
			   };
int main()
{
    int mqid,ret,s;
	mqid=msgget(MQ_KEY,IPC_CREAT | 0600);
	if(mqid<0)
	{
	   perror("msgget() failed");
	   _exit(1);
	}
	ret=fork();
	if(ret==0)
	{
	   msg_t m1;
	   m1.type=1;
	   struct msg1 m5;
	   printf("Enter a num1:");
	   scanf("%d",&m1.num1);
	   printf("Enter a num2:");
	   scanf("%d",&m1.num2);
	   ret=msgsnd(mqid,&m1,sizeof(int)*2,0);
	   printf("sender:message sent:%d\n",ret);
	   printf("Senter wating for msg....\n");
	   ret=msgrcv(mqid,&m5,sizeof(int),11,0);
	   printf("Result is %d\n",m5.result);
	   printf("Message reveived succsifully\n");

	 }
	 else
	 {
	   msg_t m2;
	   printf("receiver:waiting for the msg.....\n");
	   ret=msgrcv(mqid,&m2,sizeof(int)*2,1,0);
	   printf("%d %d\n",m2.num1,m2.num2);
	  // int res;
	   struct msg1 m4;
	   m4.result=m2.num1+m2.num2;
	   m4.type=11;
	 
	   ret=msgsnd(mqid,&m4,sizeof(int),0);
	   printf("Result send\n");
       

	   wait(&s);
	   msgctl(mqid, IPC_RMID, NULL);

	 }
	 return 0;
}


