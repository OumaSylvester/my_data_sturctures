#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<cstdio>
#include <vector>
using namespace std;

int main()
{
   /* int open(char *filename, int flags, mode_t mode)  returns new file descriptor if OK, -1 if error
   The flags argument indicates how the process intends to access the file

    O_RDONLY . Reading only
    O_WRONLY. Writing only
    O_RDWR. Reading and writing
   */
    int fd=0;
    fd = open("../MyFirstFile.txt", O_RDWR, 0);
    int size_ = lseek(fd, 0, SEEK_END);
    char buf[size_] = {};
    lseek(fd, 0, SEEK_SET);
    /*
    while (size_ > sizeof(buf))
    {
        read(fd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, sizeof(buf));
        lseek(fd, 128, SEEK_SET);
        char buf[] = {0};
        size_ = size_ - 127;
    }
    */
    read(fd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, sizeof(buf));
    close(fd);

    return 0;
}
