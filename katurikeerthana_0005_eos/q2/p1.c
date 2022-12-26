/*******************************Header files*******************************/
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>          /* For O_* constants */
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
/*******************************Global variables**************************/
char *s1;

/*******************************Functions Definitions**************************/
int main()
{
    //Local variables declaration and initialization
    int fd = 0;
    int fd1 = 0;
    int read_bytes = 0;
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

    //Opening shared memory
    fd1 = shm_open("/shmfile",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
    if(fd1 == -1)
    {
        perror("Error in opening sharedmemory from p1");
        exit(EXIT_FAILURE);
    }

    //*ftruncate() functions cause the regular file named by path or referenced by fd to be truncated to a size of pre‐cisely length bytes.*/

    ftruncate(fd1,sizeof(char));

    s1 = (char *)mmap(NULL,sizeof(char),PROT_READ|PROT_WRITE,MAP_SHARED,fd1,0);
    s1 = buff;
    while(*s1 != '\0')
    {
        s1++;
    }

    return 0;
}