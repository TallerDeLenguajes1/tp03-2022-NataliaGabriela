#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100
const char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
typedef struct {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
} Producto;
typedef struct {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
} Cliente;
Cliente *cargarclientes(Cliente *p,int cant_clientes);
float costototal(Producto *c);
void mostrar(Cliente *p,int c);
int main(void){
setvbuf(stdout,NULL,_IONBF,0);
srand(time(NULL));
int cantClientes;
Cliente *puntClientes;

printf("Ingrese la cantidad de clientes del 1 al 5");
scanf("%d",&cantClientes);
fflush(stdin);
puntClientes=(Cliente*)malloc(cantClientes * sizeof(Cliente));
puntClientes=cargarclientes(puntClientes,cantClientes);
mostrar(puntClientes,cantClientes);
    scanf("%c");
    return 0;
}
Cliente *cargarclientes(Cliente *p, int cantClientes)
{
  int i,j,cant;
  char *nombre;
  int posicionProducto;
  nombre = (char *) malloc(100*sizeof(char));
  for ( i = 0; i < cantClientes; i++)
  {
      p[i].ClienteID=i;
      puts("Ingrese el nombre del cliente");
      gets(nombre);
      p[i].NombreCliente=(char*)malloc((strlen(nombre)+1) * sizeof(char));
      p[i].NombreCliente=strcpy( p[i].NombreCliente,nombre);
      p[i].CantidadProductosAPedir=rand()%5+1;
      p[i].Productos=(Producto *)malloc( p[i].CantidadProductosAPedir * sizeof(Producto));
      

      for ( j = 0; j <  p[i].CantidadProductosAPedir; j++)
        {
            (p[i].Productos+j)->ProductoID=j;
            (p[i].Productos+j)->Cantidad=rand()%10+1;
            posicionProducto= ( rand ()% 5 );
            
            (p[i].Productos+j)->TipoProducto=(char*) malloc((strlen(tiposProductos[posicionProducto])+1) * sizeof(char));
            strcpy((p[i].Productos+j)->TipoProducto,tiposProductos[posicionProducto]);
            (p[i].Productos+j)->PrecioUnitario=rand()%100+10;
            
        }
    
  }
  free(nombre);
   printf("---------------------------------------------------------------\n");
   return p;

}
float costototal(Producto *c)
{
    float total;
        total=c->Cantidad * c->PrecioUnitario;
         
return total;    
}
void mostrar(Cliente *p,int c)
{
    int h,k;
    float aux,total_pagar=0;
    for ( h = 0; h < c; h++)
    {
        printf("Cliente numero:%d \n",p[h].ClienteID);
        printf("Nombre del cliente: %s \n",p[h].NombreCliente);
        printf("Cantidad de productos a pedir:%d \n\n",p[h].CantidadProductosAPedir);
        
        for (k = 0; k < p[h].CantidadProductosAPedir ; k++)
        {
            printf("Producto numero: %d\n",(p[h].Productos+k)->ProductoID);
            printf("Cantidad del producto: %d \n", (p[h].Productos+k)->Cantidad);
            printf("Tipo de Producto: %s\n", (p[h].Productos+k)->TipoProducto);
            printf("Precio Unitario: %.2f\n",(p[h].Productos+k)->PrecioUnitario);
            aux=costototal((p[h].Productos+k));
            total_pagar=total_pagar+aux;
            printf("Costo total del producto: %.2f\n",aux);
            printf("---------------\n\n");
            free((p[h].Productos+k)->TipoProducto);
        }
        printf("Total a pagar del Cliente: %.2f\n",total_pagar);
        printf("---------------------------------------------------------------\n");
        total_pagar=0;
        free(p[h].Productos);
        free(p[h].NombreCliente);

    }
}