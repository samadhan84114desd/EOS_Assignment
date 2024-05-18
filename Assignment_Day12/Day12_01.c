#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
   int fd,cnt;
   int num1,num2;
   fd=open("dfifo",O_RDONLY);
   if(fd<0)
   {
      perror("open() failed");
	  _exit(1);
   }
   printf("wating for data..\n");
   read(fd,&num1,sizeof(int));
   read(fd,&num2,sizeof(int));
   printf("num1=%d",num1);
   printf("num2=%d\n",num2);
   int fd1=open("dfifo",O_WRONLY);
   int sum=num1+num2;
   write(fd1,&sum,sizeof(int));
   close(fd);
   close(fd1);

   return 0;
 }
