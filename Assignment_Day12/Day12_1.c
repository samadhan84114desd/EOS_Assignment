/*
The client process send two numbers to the server process via one ﬁfo. The server process calculate the sum and return via another ﬁfo. The client
process print the result.
*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

// p1 -- writer
int main() {
	int fd, cnt;
	int num1,num2;
	fd = open("dfifo", O_WRONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("Enter num1: ");
	scanf("%d", &num1);
    printf("Enter num2:");
    scanf("%d",&num2);

	 write(fd,&num1, sizeof(int));
	 write(fd,&num2,sizeof(int));
	//printf("written in fifo: %d bytes\n", cnt);

	int fd1=open("dfifo",O_RDONLY);
	int sum;
	read(fd1,&sum,sizeof(int));
	printf("Addition of two numbers is %d\n",sum);

	close(fd);
	close(fd1);
	return 0;
}

