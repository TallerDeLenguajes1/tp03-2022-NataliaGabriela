#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
int main() {
    setvbuf(stdout,NULL,_IONBF,0);
    char *buff;
    char *nombres[N];

for (int i = 0; i < N; i++)
{   
    buff = (char *) malloc(100*sizeof(char));
    puts("Ingrese un nombre");
    gets(buff);
    
    *(nombres+i) = (char *) malloc((strlen(buff)+1)*sizeof(char));
    *(nombres+i) = strcpy(*(nombres+i),buff);
    free(buff);

}
for (int i = 0; i < N; i++)
{
    printf("%s\n",*(nombres+i));
    
    free(*(nombres+i));
}


scanf("%c");
return 0;
}
