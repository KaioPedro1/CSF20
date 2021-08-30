#include "Header.h"
#include "Ordenacao.c"
#include "ListaEncadeada.c"    //GAMBIARRA PQ NAO SEI COMO LINKAR TUDO
void teste(Header *lista);

int main(){
    Header lista;
    lista.primeiro = NULL;
    lista.ultimo = NULL;
    lista.tamanho = 0;
    lista.estaOrdenado = 0;
    lista.vetorPtr = NULL;
    while(menu(&lista)!=-1){
        printf("\nAperte qualquer tecla para continuar...");
        getchar();
        getchar();
    }
}





