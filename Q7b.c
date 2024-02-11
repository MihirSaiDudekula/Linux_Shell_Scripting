#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
void removeEmptyFiles(char *path) {
DIR *dir;
struct dirent *entry;
struct stat fileStat;
// Open the directory
if ((dir = opendir(path)) == NULL) {
perror("Error opening directory");
exit(EXIT_FAILURE);
}
// Read each entry in the directory
while ((entry = readdir(dir)) != NULL) {
// Construct the full path
char filePath[1024];
snprintf(filePath, sizeof(filePath), "%s/%s", path, entry->d_name);
// Get file status
if (stat(filePath, &fileStat) < 0) {
perror("Error getting file status");
exit(EXIT_FAILURE);
}
// Check if the file is empty and remove it
if (S_ISREG(fileStat.st_mode) && fileStat.st_size == 0) {
if (unlink(filePath) == 0) {
printf("Removed empty file: %s\n", entry->d_name);
} else {
perror("Error removing file");
}
}
}
// Close the directory
closedir(dir);
}
int main(int argc, char *argv[]) {
// Check if the correct number of arguments is provided
if (argc != 2) {
fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
exit(EXIT_FAILURE);
}
// Call the function to remove empty files
removeEmptyFiles(argv[1]);
return 0;
}

#include <stdio.h>
#include <unistd.h> #include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
        DIR *dp;
        stuct dirent *dir;
        int fd,n;

        dp=opendir(".");
        if(dp)
        {
                while((dir=readdir(dp))!=NULL)
                {
                        fd=open(dir->d_name,O_RDWR,0777);
                    // This line opens the file specified by dir->d_name for reading and writing (O_RDWR) with the file permissions 0777 (in                          octal notation, representing read, write, and execute permissions for user, group, and others). The file descriptor is                         assigned to fd.
                        n=lseek(fd,0,SEEK_END);
                  
                  // if "example.txt" is 28 bytes long (including the newline character), lseek will return 28, indicating that the file is 28                      bytes in size.After this line executes, the variable n will contain the size of the file "example.txt" in bytes.
                        if(!n)
                        {
                                unlink(dir->d_name);
                          //If the file size is zero (indicating an empty file), the unlink function is called to remove (delete) the file                                 specified by dir->d_name.

                        }

                }

        }

}.
