#include<unistd.h>
// bringing in a set of tools that help us interact with the operating system.
// unistd.h contains information about basic system calls and constants related to operating system functionalities.
#include<fcntl.h>
// fcntl.h contains functions and constants for file control operations, like opening and manipulating files.
#include<dirent.h>
// dirent.h provides functions and data structures for reading and manipulating directory entries.
#include<time.h>
// time.h contains functions and data structures for working with time, like getting the current time or formatting time values

int main(int argc, char* argv[])
{
//This line declares the main function, which is the entry point of the program. 
// It accepts command-line arguments argc (the number of arguments that are passed) and 
// argv (an array of strings, each is the individual argument).

// ./my_program hello world
// , argc would be 3 because we gave the program three pieces of information (./my_program, hello, world).
// And argv would be an array (a list) of strings that looks like this: ["./my_program", "hello", "world"]

        struct dirent *dir;   // This struct pointer points to information about one item (like a file or folder) inside a directory
        struct stat mystat;   // This struct stores details about a specific file, like its size, owner, permissions, etc.
        DIR *dp;              // This box holds all the items (like files and folders) inside a directory at once

        // while (dir = readdir(dp)) {} would read each line in the directory

        dp = opendir(".");
        //dp points to the current directory indicated by '.'

        if(dp)
        {
                while(dir=readdir(dp))
                {
                        stat(dir->d_name,&mystat);
                        // stat is a special function that returns the stats of a file provided by os
                        // it takes in 2 arguments, directory name and struct where to store the stats
                        // dir->d_name is the directory name
                        // &mystat is where the stats will be stored
                        printf("%ld\t", mystat.st_ino);
                        printf("%d\t", mystat.st_uid);
                        printf("%d\t", mystat.st_gid);
                        printf("%ld\t", mystat.st_blksize);
                        printf("%ld\t", mystat.st_blocks);
                        printf("%ld\t", mystat.st_size);
                        printf("%lu\t", mystat.st_nlink);
                        printf("%s\t%s\t%s\t", ctime(&mystat.st_atime), dir->d_name, "\t");

                        printf("\n File Permissions User\n");
                        printf((mystat.st_mode & S_IRUSR)? "r":"-");
                        // checking if the read permission is set for the owner of the file represented by the mystat structure. 
                        // If the result is non-zero, it means the read permission is set.
                        printf((mystat.st_mode & S_IWUSR)? "w":"-");
                        printf((mystat.st_mode & S_IXUSR)? "x":"-");
                        printf("\n");
                        printf("\nFile Permissions Group\n");
                        printf((mystat.st_mode & S_IRGRP)? "r":"-");
                        printf((mystat.st_mode & S_IWGRP)? "w":"-");
                        printf((mystat.st_mode & S_IXGRP)? "x":"-");
                        printf("\n");
                        printf("\nFile Permissions Other\n");
                        printf((mystat.st_mode & S_IROTH)? "r":"-");
                        printf((mystat.st_mode & S_IWOTH)? "w":"-");
                        printf((mystat.st_mode & S_IXOTH)? "x":"-");
                        printf("\n");


                }
        }
}
