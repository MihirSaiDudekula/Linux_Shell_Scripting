#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
void listFiles(char *path) {
DIR *dir;
struct dirent *entry;
struct stat fileStat;
// Open the directory
if ((dir = opendir(path)) == NULL) {
perror("Error opening directory");
exit(EXIT_FAILURE);
}
// Print header
printf("%-10s %-8s %-8s %-8s %-12s %s\n", "Permissions", "Links", "Owner", "Group", "Size",
"Last Modified");
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
// Get owner and group names
struct passwd *owner = getpwuid(fileStat.st_uid);
struct group *group = getgrgid(fileStat.st_gid);
// Print file attributes
printf("%s %2lu %-8s %-8s %8ld %s %s\n",
(S_ISDIR(fileStat.st_mode)) ? "d" : "-",
fileStat.st_nlink,
owner->pw_name,
group->gr_name,
fileStat.st_size,
ctime(&fileStat.st_mtime),
entry->d_name);
}
closedir(dir);
}
int main(int argc, char *argv[]) {
// Check if the correct number of arguments is provided
if (argc != 2) {
fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
exit(EXIT_FAILURE);
}
// Call the function to list files
listFiles(argv[1]);
return 0;
}
    
