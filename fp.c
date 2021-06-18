#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char *argv[]){
	int i;
	if (argc > 1 && strcmp(argv[1], "CREATE") == 0){
		if (strcmp(argv[2], "DATABASE") == 0){
			DIR* dir = opendir(argv[3]);
			if (dir){
				printf("Database sudah terbuat\n");
				closedir(dir);
			} 
			else {
				mkdir(argv[3], 0777);
			}
			
		}
		else if (strcmp(argv[2], "TABLE") == 0){
			chdir(argv[argc-1]);
			FILE *file = fopen(argv[3], "a");
			for (i=4;i<=argc;i++){
				fprintf(file, "%s\t", argv[i]);
			}
			fclose(file);
		}
	}
	else if (argc > 1 && strcmp(argv[1], "INSERT")==0 && argc > 1){
		
	}
}
