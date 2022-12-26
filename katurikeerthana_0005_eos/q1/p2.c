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
    int read_bytes = 0;
    int wrote_bytes = 0;
    int count =0;
    unsigned char buff[10000];

    //Openig fifo
    fd = open("q1fifo",O_RDONLY,S_IRUSR|S_IWUSR);
    if(fd == -1)
    {
        perror("Error in opening fifo from p1");
        exit(EXIT_FAILURE);
    }

    //Reading from fifo
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


    //Finding number of "s" in the file
    for(int i=0;i < read_bytes;i++)
    {
        if(buff[i] == 's')
        {
            count++; //increment count for every instance of "s"
        }
    }

    printf("\n\n\t\tThe total instances of letter/character 's' in stdio.h are %d",count);
    //Closing fifo
    close(fd);
   
    return 0;
}