#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/**
 
 * Main
 
 */

int main(int argc, char **argv)
{
  DIR *dir;
       struct dirent *direntry;
       char currentdir[1024];
       // Parse command line
       if (argc > 1)
	 {
	   sprintf(currentdir, "%s", argv[1]);
	 }
       else
	 {
	   sprintf(currentdir, "%s", ".");
	 }
       // Open directory
       if (strcmp(currentdir, "help") == 0)
	 {
	   printf("\n___________________________________\n\n NAME\n\tlsls -- list of directory \n USAGE\n        ./lsls directory\n\n EXAMPLES\n\n        ./lsls .\n\n        ./lsls ~/Documents\n\n____________________________________\n\n");
	 }
       else if ((dir = opendir(currentdir)) == NULL)
	 {
	   perror("opendir error");
	 }
       // Repeatedly read and print entries
       else if (strcmp(currentdir, "help") != 0)
	 {
	   while ((direntry = readdir(dir)) !=NULL)
	     {
	       struct stat buf; 
	       char type[1024]; 
	       stat (direntry->d_name, &buf); 
	       if (direntry->d_type == DT_DIR) 
		 {
		   sprintf(type, "%s", "<>DIR<>"); 
		 }
	       else
		 {
		   sprintf(type, "%lld", buf.st_size); 
		 }
	       printf(" %12s %s\n", type, direntry->d_name); 
	     }
	   // Close Directory
	   closedir(dir);
	 }
       return 0;
}
//gcc -Wall -Wextra lsls.c -o lsls
