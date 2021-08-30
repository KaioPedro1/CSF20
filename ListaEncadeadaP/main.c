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
    //teste(&lista);

}
void teste(Header *lista){
    leArquivo(lista, "NomeRG100M.txt");
   // printaLista(lista);
    lista->vetorPtr = criaListaPtr(lista);
    quickSortIndireto(lista, 0, lista->tamanho-1);
    copiaVtrParaLista(lista);
  //  printaLista(lista);
   // buscaLinearRG(lista , 48864291);
    //binarySearch(lista, 48864291); //455197
}




