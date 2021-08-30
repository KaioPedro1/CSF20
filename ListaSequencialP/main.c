#include "Header.h"
#include "Ordenacao.c"
#include "ListaSequencial.c"    //GAMBIARRA PQ NAO SEI COMO LINKAR TUDO
void teste(Dados *lista);
int main()
{
    Dados *lista;
    lista = alocaDados(15000000);
    while(menu(lista)!=-1){
        printf("\nAperte qualquer tecla para continuar...");
        getchar();
        getchar();
    }
    free(lista);
    return 0;
}

