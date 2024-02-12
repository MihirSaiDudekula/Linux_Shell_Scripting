#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>

int main(int argc,char* argv[])
{
	struct dirent *dir;
	//current file or folder
	struct stat mystat;
	//stats about each file
	DIR *dp;
	//all files and folders
	
	dp = opendir(".");

	if(dp)
	{
		while(dir=readdir(dp))
		{
			stat(dir->d_name,&mystat);
			// stat is a special function that returns the stats of a file provided by os
			// it takes in 2 arguments, directory name and struct where to store the stats
			// dir->d_name is the directory name
			// &mystat is where the stats will be stored
			printf("%ld\t %d\t %d\t %ld\t %ld\t %ld\t %lu\t %s\t %s\t",mystat.st_ino,mystat.st_uid,mystat.st_gid,mystat.st_blksize,mystat.st_blocks,mystat.st_size,mystat.st_nlink,ctime(&mystat.st_atime),dir->d_name);
			printf("\t");
			printf("\n File Permissions User\n");
			printf((mystat.st_mode & S_IRUSR)? "r":"-");
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

