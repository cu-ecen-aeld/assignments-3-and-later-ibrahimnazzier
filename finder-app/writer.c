#include <stdio.h>
#include <syslog.h>
#include <time.h>
#include <string.h>
#include <sys/syslog.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define success_wrt     0
#define fail_wrt        1

int main(int argc, char *argv[])
    {
    time_t now = time(NULL);
    char* str_now = ctime(&now);
    openlog("Writefile",LOG_ODELAY,LOG_USER);
    syslog(LOG_INFO, "%s, Start logging, \"./writefile\" is executing now.", str_now);


    if (argc != 3)
    {
        now = time(NULL);
        str_now = ctime(&now);
        syslog(LOG_ERR,"%s, Error: At least 3 arguments are required", str_now);
        fprintf(stdout, "argument is the problem");
        return fail_wrt;
    }        
    else
    {   
        int fd;
        ssize_t ret;
        int len = strlen(argv[2]);
        char* buf = argv[2];
        fd = open(argv[1], O_CREAT | O_RDWR, 0744);
        if (fd == -1)
        {
                fprintf(stdout, argv[1]);
                perror ("open");
                now = time(NULL);
                str_now = ctime(&now);
                syslog(LOG_ERR, "%s, Error: Cannot open file.", str_now);
                closelog();
                return fail_wrt;
         }
        else {
            while(len != 0 && (ret = write(fd, buf, len)) != 0)
            {
                if (ret == -1 )
                {   
                if (errno == EINTR)
                continue;
                perror ("write");
                now = time(NULL);
                str_now = ctime(&now);
                syslog(LOG_ERR, "%s, Error: Cannot open file.", str_now);
                closelog();
                return fail_wrt;
                }
                len -= ret;
                buf += ret;
            }
            now = time(NULL);
            str_now = ctime(&now);
            syslog(LOG_USER, "%s, File written successfully: (written text is) \"%s\" to \"%s\" ", str_now, argv[2], argv[1]);   
            closelog();
            return success_wrt;
        }
    }
}