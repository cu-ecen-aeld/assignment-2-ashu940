#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>  // For strerror


int main(int argc, char *argv[]) {
    // Expected number of arguments (program name + 2 arguments)
    int num = 3;

    // Initialize syslog with LOG_USER facility
    openlog("writer", LOG_PID, LOG_USER);

    // Check if the correct number of arguments is passed
    if (argc != num) {
        syslog(LOG_ERR, "Incorrect arguments. Usage: %s <writefile> <writestr>", argv[0]);
        printf("Incorrect arguments.\n");
        printf("Usage: %s <writefile> <writestr>\n", argv[0]);
        closelog();
        return 1;
    }

    // Get the arguments: file path and string to write
    char *writefile = argv[1];
    char *writestr = argv[2];

    // Open the file for writing
    FILE *fp = fopen(writefile, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Error: Could not create file '%s'. %s", writefile, strerror(errno));
        printf("Error: Could not create file '%s'.\n", writefile);
        closelog();
        return 1;
    }

    // Write the string to the file
    if (fprintf(fp, "%s\n", writestr) < 0) {
        syslog(LOG_ERR, "Error: Could not write to file '%s'. %s", writefile, strerror(errno));
        printf("Error: Could not write to file '%s'.\n", writefile);
        fclose(fp);
        closelog();
        return 1;
    }

    // Success: log to syslog and close the file
    syslog(LOG_DEBUG, "Writing '%s' to '%s'", writestr, writefile);
    printf("File '%s' created successfully.\n", writefile);
    fclose(fp);

    // Close the syslog connection
    closelog();

    return 0;
}

