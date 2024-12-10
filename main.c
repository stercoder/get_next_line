#include "get_next_line.h"

int main()
{ 
    
    int fd = open("file1.txt", O_RDONLY); 

    char *line = get_next_line(fd);
     
        printf("Read line: %s\n", line);
        free(line);
 
    return 0;

}