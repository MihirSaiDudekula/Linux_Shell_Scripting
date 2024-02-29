#include<stdio.h>
#include<stdlib.h>
#define MAX 1024
void main(int argc,char *argv[])
{
	if(argc<3)
	{
		printf("usage: %s source destination",argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *source,*dest;
	char buffer[MAX];
	ssize_t bytesread;

	source=fopen(argv[1],"rb");
	dest=fopen(argv[2],"wb");

	while((bytesread=fread(buffer,1,MAX,source))>0)
	{
		fwrite(buffer,1,bytesread,dest);
	}

	fclose(source);
	fclose(dest);
}
