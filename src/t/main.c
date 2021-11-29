#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
   char str[256];
   const char s[2] = " ";
   char *token;
   scanf("%[^\n]%*c",str);
    printf("%s\n",str);
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }
   
   return(0);
}
