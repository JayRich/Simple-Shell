// Jason Richardson

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <time.h>



int main(void) {
    pid_t child;
    DIR * d;
    struct dirent * de;
    int i, c, inc, temp;
    char k, u, user;
    char s[256], cmd[256];
	char *names[1000];
    time_t t;

    while (1) {

	printf("\nOperations:\n");
	printf("q - quit\n");
	printf("d - list time and current directory\n");
	printf("l - list files and subdirectories\n");
	printf("e - edit\n");
	printf("r - run\n");
	printf("c - change directory\n");
	printf("s - sort directory\n");
	printf("\n");
	
	printf("Enter menu option: ");
	scanf(" %c", &u);

	switch (u) {
        case 'q': exit(0); // quit
	case 'd':  t = time( NULL );	// list time and current directory
      			printf( "\nTime: %s\n", ctime( &t ));

      			getcwd(s, 200);

      			printf( "\nCurrent Directory: %s \n", s);

			break;
	case 'l': 
			d = opendir( "." );	// store files into array and list with next and previous
      			c = 0;
			inc = 0;
			temp = 0;
      			while ((de = readdir(d))){
          		if ((de->d_type) & DT_DIR) 
             		printf( " ( %d Directory:  %s ) \n", c++, de->d_name);	  
      			}
      			closedir( d );
      			d = opendir( "." );
      			c = 0;   
                 
      			while((de = readdir(d))){                    
          			if (((de->d_type) & DT_REG)){                            
					 // store files into array by name
        				names[inc] = (char*) malloc (strlen(de->d_name)+1);
        				strncpy (names[inc],de->d_name, strlen(de->d_name) );
        				inc++;
					temp++;
   					
          			
				}
}
			int keepTrack;
			keepTrack = 0;
			for(inc = 0; inc < temp; inc++)		//next and previous
			{
				printf("File number %d: %s\n",inc, names[inc]);	
				
				if(inc%5 == 0)
				{
					printf("press n for next or p for previous: ");
					scanf(" %c", &user);
					printf("--------------------------------\n");
					if(user == 'p')
					{
						printf("-------------Previous-------------------\n");
						keepTrack = inc;
						do
						{
							printf("File number %d: %s\n", keepTrack, names[keepTrack]);
							keepTrack--;
						}while(keepTrack%5!=0);
					
						printf("--------------Next------------------\n");
					}
				
				
				
				}
				
					
			}


	      	closedir( d );
		break;
	
        case 'e': printf( "Edit a file: " );
                  scanf( " %s", s );
                  strcpy( cmd, "pico ");
                  strcat( cmd, s );
                  system( cmd );
                  break;
        case 'r': printf( "\nRun a program:" );
                  scanf( "%s", cmd );
                  system( cmd );
                  break;
        case 'c': printf( "\nChange directory:" );
                  scanf( "%s", cmd );
                  chdir( cmd );   
                  break; 
	case 's': system("ls -ltr");
		  break;
	}
    
	
       
    }

}

