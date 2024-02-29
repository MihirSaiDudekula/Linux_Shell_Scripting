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


#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    // Open the current directory
    dir = opendir(".");
    if (dir == NULL) { // Check if directory opening was successful
        perror("Error opening directory"); // Print error message if opening fails
        exit(EXIT_FAILURE); // Exit program with failure status
    }

    // Read and print all files in the directory
    while ((entry = readdir(dir)) != NULL) { // Loop through each directory entry
        if (entry->d_type == DT_REG) { // Check if entry is a regular file
            printf("%s\n", entry->d_name); // Print the name of the regular file
        }
    }

    // Close the directory
    closedir(dir);

    return 0; // Return 0 to indicate successful execution
}
