#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	DIR *dp;
	struct dirent* dir;
	int fd,n;

	dp=opendir(".");
	if(dp)
	{
		while((dir=readdir(dp))!=NULL)
		{
			fd=open(dir->d_name,O_RDWR,0777);
			n=lseek(fd,0,SEEK_END);
			if(!n)
			{
				unlink(dir->d_name);
			
			}
		
		}
	
	}

}



