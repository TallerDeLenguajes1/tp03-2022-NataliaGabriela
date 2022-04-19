#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    setvbuf(stdout,NULL,_IONBF,0);
    int cantNombres;
    char *buff;
    char **nombres;
    
    buff = (char *) malloc(100*sizeof(char));
    printf("Ingrese el numero de nombres que quiere cargar");
    scanf("%d",&cantNombres);
    fflush(stdin);
    nombres = (char**) malloc(cantNombres*sizeof(char));
   
    
for (int i = 0; i < cantNombres; i++)
{   
    
    puts("Ingrese un nombre");
    gets(buff);
    
    *(nombres+i) = (char *) malloc((strlen(buff)+1)*sizeof(char));
    strcpy(*(nombres+i),buff);
    //free(buff);

}
for (int i = 0; i < cantNombres; i++)
{
    printf("%s\n",*(nombres+i));
    
    free(*(nombres+i));
}
free(buff);

scanf("%c");
return 0;
}