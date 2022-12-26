/*******************************Header files*******************************/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <string.h>
/*******************************Global variables**************************/


/*******************************Functions Definitions**************************/
int main()
{
    //Local variables declaration and initialization
    int fd = 0;
    int fd1 = 0;
    int read_bytes = 0;
    int wrote_bytes = 0;
    unsigned char buff[10000];

    //Opening stdio.h file
    fd = open("/home/usr/include/stdio.h",O_RDONLY);
    if(fd == -1)
    {
        perror("Error in opening file");
        exit(EXIT_FAILURE);
    }

    //Reading from stdio.h
    read_bytes = read(fd,buff,strlen(buff));
    if(read_bytes == -1)
    {
        perror("Error in reading file from p1");
        exit(EXIT_FAILURE);
    }
    if(read_bytes == 0)
    {
        perror("Empty file");
        exit(EXIT_FAILURE);
    }

    //Creating and Openig fifo
    fd1 = open("q1fifo",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR);
    if(fd1 == -1)
    {
        perror("Error in opening fifo from p1");
        exit(EXIT_FAILURE);
    }

    //Writing data into fifo
    wrote_bytes = write(fd1,buff,strlen(buff));
    if(wrote_bytes == -1)
    {
        perror("Error in writing from p1 to fifo");
        exit(EXIT_FAILURE);
    }
    if(wrote_bytes == 0)
    {
        perror("Nothing wrote into fifo");
        exit(EXIT_FAILURE);
    }

    //Closing stdio.h and fifo
    close(fd);
    close(fd1);

    return 0;
}