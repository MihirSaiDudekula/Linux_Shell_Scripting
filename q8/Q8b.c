#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main() {
DIR *dir;
struct dirent *entry;
// Open the current directory
dir = opendir(".");
if (dir == NULL) {
perror("Error opening directory");
exit(EXIT_FAILURE);
}
// Read and print all files in the directory
while ((entry = readdir(dir)) != NULL) {
if (entry->d_type == DT_REG) {
printf("%s\n", entry->d_name);
}
}
// Close the directory
closedir(dir);
return 0;
}
