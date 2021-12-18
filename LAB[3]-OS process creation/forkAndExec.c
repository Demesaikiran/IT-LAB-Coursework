#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<error.h>
#include<unistd.h>

int main()
{
    pid_t pid;
    pid = fork();
    
    if(pid == -1)
    {
        // Enters only when error occured
        printf("Fork not happend, ERROR OCCURED\n");
        exit(EXIT_FAILURE);
    }

    else if(pid == 0)
    {
        // pid equal to 0 implies child process is created.
        // getpid() returns process parent id
        // getppid() returns process parent - parent ID.

        char * argv_list[] = {"ls", "-lart", "/home", NULL};
        printf("Fork happend Successfully\n");
        printf("\nchild process, pid = %u\n",getpid());
        // Here It will return Parent of child Process means Parent process it self
        printf("\nparent of child process, pid = %u\n",getppid());


        // Exec replaces the original process image with newly created process image

        execv("ls", argv_list);
        exit(0);
    }

    else
    {
        // Pid of parent process gets a +ve number 
        printf("Exited successfully...\n");
        printf(" Parent of parent process - PID - %u\n", getppid());
        printf(" Parent process - PID = %u\n", getpid());
        exit(0);
    }

    return 0;

}