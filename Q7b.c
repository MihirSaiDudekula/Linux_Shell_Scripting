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
