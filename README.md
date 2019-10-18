# Simple-Thread-in-C
Parent program will have three variables: int x,y,z; which to be initialized as 10, 20, and 0, respectively.
Parent creating child: parent will create a child by fork() and the child will perform z = x+y.
Parent will wait for child to complete before parent proceeds. 
Upon completion of child, parent will print out the value of z.
Parent creating thread: After above is completed, parent process will now create a thread by pthread_create() which will do the exact same task done by child above (i.e., z = x+y). parent will wait for its thread to complete before parent proceeds. 
Upon completion of the thread, parent will print out the value of z.

# Notes
Since fork() allows child to obtain a copy of globle variables, modifying those variables in child will not effect the global variable
