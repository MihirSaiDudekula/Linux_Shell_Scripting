#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
int main(int argc, char *argv[]) {
if (argc != 3) {
fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
exit(EXIT_FAILURE);
}
FILE *source_file, *destination_file;
char buffer[BUFFER_SIZE];
size_t bytesRead;
// Open the source file in binary read mode
source_file = fopen(argv[1], "rb");
if (source_file == NULL) {
perror("Error opening source file");
exit(EXIT_FAILURE);
}
// Open or create the destination file in binary write mode
destination_file = fopen(argv[2], "wb");
if (destination_file == NULL) {
perror("Error opening destination file");
fclose(source_file);
exit(EXIT_FAILURE);
}
