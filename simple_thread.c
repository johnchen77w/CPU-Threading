#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

// initializing variables
int x = 10;
int y = 20;
int z = 0;

/*
 * Function:  thread_calculate
 * --------------------
 * This is a thread function, which computes and prints the value of z using:
 *    z = x + y
 *
 *  z: integer pointer
 *
 *  returns: 0
 */
void *thread_calculate(void *z)
{
    *(int *)z = x+y;
    printf("From thread_calculate: x + y = z = %d\n\n", *(int *)z);
    return 0;
}

/*
 * Function:  main
 * --------------------
 * This the main function, which does the following:
 *      fork()
 *      calculating z value
 *      making new thread
 *
 *  returns: 0
 */
int main() {
    pid_t pid1;
    printf("\n- - - - - - - - - - - - S - T - A - R - T - - - - - - - - - - - - \n\n");
    pid1 = fork();

    // fork unsuccessful :(
    if (pid1 < 0)
    {
        // prints out error message
        perror("fork unsuccessful");
    	exit(1);
    }

    // child process :)
    if (pid1 == 0)
    {
        printf("    Child process (PID %d):\n\n", getpid());
        // calculating z =  x + y
        z = x + y;
        printf("    Performing x + y ...\n\n");
    }

    // parent process :)
    if (pid1 > 0)
    {
        printf("Parent process (PID %d): \n\n", getpid());
        // wait for child to complete
        wait(NULL);
        // prints out the result
        // the value of z will remain unchanged (0) since child only modified
        //  its own copy of z value
        printf("x + y = z = %d\n\n", z);
        // make new thread from parent
        pthread_t thread_1;
        printf("From parent: creating thread...\n\n");
        // calling thread function
        pthread_create(&thread_1, NULL, thread_calculate, (void *)&z);
        // suspend execution of the calling thread until the target thread terminates
        pthread_join(thread_1, NULL);
        // print after thread terminates
        printf("Thread terminated\n\n");
        printf("- - - - - - - - - - - - - - E - N - D - - - - - - - - - - - - - - \n\n");
    }

    return 0;
}
