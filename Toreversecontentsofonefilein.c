#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        return -1;
    }
    int new = mkdir("Assignment", 0744);
    // printf("new = %d\n", new);

    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0)
    {
        perror("r1");
        return -1;
    }

    char delim[2] = "/";
    char *file1 = strtok(argv[1], delim);
    while (file1 != NULL)
    {
        strcpy(argv[1], file1);
        file1 = strtok(NULL, delim);
    }

    char path2[1000] = "Assignment/";
    strcat(path2, argv[1]);

    int fd2 = open(path2, O_CREAT | O_WRONLY, 0644);
    if (fd2 < 0)
    {
        perror("r1");
        return -1;
    }

    long int sizefile = lseek(fd1, (off_t)0, SEEK_END);
    long int testsize = sizefile / 10000;
    long int chuck;
    if (testsize == 0)
    {
        chuck = 1;
    }
    else
    {
        chuck = testsize;
    }
    char a[chuck], b[chuck];
    float progress = 0;
    long int filesize = sizefile;
    // char a;
    float cal;
    sizefile = ((sizefile - 1) / chuck) * chuck;
    long int i = filesize - sizefile;
    lseek(fd1, sizefile, SEEK_SET);
    while (1)
    {
        read(fd1, a, i);
        long int end = i - 1;
        for (long int begin = 0; begin < i; begin++)
        {
            b[begin] = a[end];
            end--;
        }
        b[i] = '\0';
        write(fd2, b, i);
        if (lseek(fd1, 0, SEEK_CUR) - chuck - i < 0)
        {
            break;
        }
        lseek(fd1, -chuck - i, SEEK_CUR);
        progress += i;
        cal = (progress / filesize) * 100;
        char calcu[6], rml[1];
        rml[0] = '\r';
        sprintf(calcu, "%.2f", cal);
        calcu[5] = '\0';
        write(STDOUT_FILENO, calcu, 4);
        write(STDOUT_FILENO, rml, 1);
        i = chuck;
    }
    cal = 100.00;
    char calculate[6];
    sprintf(calculate, "%.2f", cal);
    calculate[5] = '\0';
    write(STDOUT_FILENO, calculate, 4);
    close(fd2);
    close(fd1);
    return 0;
}