#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//Includes necessary header files: stdio.h, stdlib.h, unistd.h, fcntl.h. 
//These headers provide functions for input/output operations, file manipulation, 
//and accessing system-specific features.

// buffer is a temporary storage area used to hold data while it is being 
// transferred between two locations or processes
#define MAX_SIZE 100
// represents the maximum size of the buffer used to read characters from the file.
// here, "buffer" refers to an array named buffer declared as char buffer[MAX_SIZE];
//  This buffer is used to temporarily store characters read from the file before they are written back to the file. 

int main() {
char filename[] = "file.txt";
// containing the name of the file to be manipulated , which is "file.txt"
int fd, new_fd;
char buffer[MAX_SIZE];
ssize_t bytes_read;
//ssize_t is an inbuilt datatype in c store the number of bytes read from the file.
// bytes_read of type ssize_t to store the number of bytes read from the file.
int n;
printf("Enter the number of characters to read and append: ");
scanf("%d", &n);
// Open the file
fd = open(filename, O_RDWR);
//When you open a file with the O_RDWR flag, 
//it means that you are allowing both reading from and writing to the file. 
if (fd == -1) {
perror("Error opening file");
exit(EXIT_FAILURE);
}
// Move file pointer to the end
lseek(fd, 0, SEEK_END);
// Duplicate file descriptor
new_fd = dup(fd);
if (new_fd == -1) {
perror("Error duplicating file descriptor");
close(fd);
exit(EXIT_FAILURE);
}
// Move the file pointer back 'n' characters
lseek(fd, -n, SEEK_END);
// Read 'n' characters from the file
bytes_read = read(fd, buffer, n);
if (bytes_read == -1) {
perror("Error reading file");
close(fd);
close(new_fd);
exit(EXIT_FAILURE);
}
// Append the read characters back to the file
if (write(new_fd, buffer, bytes_read) != bytes_read) {
perror("Error writing to file");
close(fd);
close(new_fd);
exit(EXIT_FAILURE);
}
// Close file descriptors
close(fd);
close(new_fd);
printf("%d characters read and appended successfully.\n", ((int)bytes_read));
return 0;
}
