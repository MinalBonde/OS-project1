//Project1 submitted by: Minal Bonde (msb190000@utdallas.edu) 2021487655 
#include <sys/signal.h>
#include<stdio.h>
int wait(int*);
int main ( int argc, char *argv[] ) /* accepts argument parameters count and the string values in character array pointer */
{       
	int freq[26]; /* this array stores the frequency for alphabetical characters */
	int i,j,pid,stat,n;
	FILE *file2= fopen("result.txt","w");
	n= atoi(argv[1]);
    if ( argc < 3 ) /* argc should be 2 or more for correct execution */
    {
		/* We print error message */
        printf( "You have not entered any filename to be read \n");
    }else if(n!= argc-3){
		printf( "Number of files mismatch \n");
	}	
    else
    { 
       for(i=2;i<argc-1;i++)
	   {   
		if((pid=fork())==0){		
			FILE *file = fopen( argv[i], "r" );
			fprintf(file2,"filename : %s \n",argv[i]);
			
		/* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else
        {
            int x;
            /* Read one character at a time from file, stopping at EOF, which
               indicates the end of the file.*/
               for(j=0; j<26; j++)
                {
                        freq[j] = 0;
                } 
           
            while  ( ( x = fgetc( file ) ) != EOF )
            {
              if(x>='a'&& x<='z'){
                      freq[x-'a']++;
              }else if(x>='A'&& x<='Z'){
                      freq[x-'A']++;
              }               
            }
                     
        }
		// below loop writes into result.txt file the frequency count of characters.
         for(i=0;i<26;i++)
		 {
		   fprintf(file2,"'%c' = %d \n",(i+97),freq[i]);
                   
         }        

        fclose( file );
		
       } 
	   // wait for i th child to terminate
	   wait(&stat);
	  }  
	  
      fclose(file2);
    
    }
	if(pid>0){
		// wait for child to terminate 
		wait(&stat);
		printf("Parent is done executing. \n");
	}
	return 0;
}


