#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
// Optional: use these functions to add debug or error prints to your application
#define DEBUG_LOG(msg,...)
//#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)


void* threadfunc(void* thread_param)
{
    thread_data* ThreadData = (thread_data *)thread_param; 
    // TODO: wait, obtain mutex, wait, release mutex as described by thread_data structure
    // hint: use a cast like the one below to obtain thread arguments from your parameter
    //struct thread_data* thread_func_args = (struct thread_data *) thread_param;
    usleep((ThreadData->wait_to_obtain_ms)*1000);
    pthread_mutex_lock((ThreadData->mutex));
    usleep((ThreadData->wait_to_release_ms)*1000);
    pthread_mutex_unlock((ThreadData->mutex));
    ThreadData->thread_complete_success = true;
    return (thread_data*)ThreadData;
}

bool start_thread_obtaining_mutex(pthread_t *thread, pthread_mutex_t *mutex,int wait_to_obtain_ms, int wait_to_release_ms)
{
    /**
     * TODO: allocate memory for thread_data, setup mutex and wait arguments, pass thread_data to created thread
     * using threadfunc() as entry point.
     *
     * return true if successful.
     *
     * See implementation details in threading.h file comment block
     */
    thread_data* ThreadData = (thread_data*)malloc(sizeof(thread_data));
    if (!ThreadData) {
        printf("allocate memory failed\n");
        return false;
    }
    ThreadData->mutex = mutex;
    ThreadData->wait_to_obtain_ms = wait_to_obtain_ms;
    ThreadData->wait_to_release_ms = wait_to_release_ms;
    

    int res = pthread_create(thread, NULL, threadfunc, ThreadData); 
    if (res != 0)
    {
        fprintf(stderr, "Error creating thread: %d\n", res);
        return false;
    }
    return true;
}

