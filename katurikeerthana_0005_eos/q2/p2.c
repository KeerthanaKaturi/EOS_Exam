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
char *s2;

/*******************************Functions Definitions**************************/
int main()
{
    //Local variables declaration and initialization
    int fd1 = 0;
    
    //Opening shared memory
    fd1 = shm_open("/shmfile",O_RDWR,S_IRUSR|S_IWUSR);
    if(fd1 == -1)
    {
        perror("Error in opening sharedmemory from p1");
        exit(EXIT_FAILURE);
    }

    //*ftruncate() functions cause the regular file named by path or referenced by fd to be truncated to a size of pre‐cisely length bytes.*/

    ftruncate(fd1,sizeof(char));

    s2 = (char *)mmap(NULL,sizeof(char),PROT_READ|PROT_WRITE,MAP_SHARED,fd1,0);
    while(*s2 != '\0')
    {
        if(*s2 == 's')
        {
            count++;
        }
    }
    printf("\nNumber of 's' in stdio.h are %d",count);
    return 0;
}