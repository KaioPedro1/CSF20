#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define MAX_NAME 20
#define MAX_READ 40
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/////////////////////////////////////
//VARIAVEIS GLOBAIS PARA CONTAGEM
static int Tamanho=0, C=0,M=0;
////////////////////////////////////
//struct principal do n�
typedef struct node Dados;
struct node{
    int rg;
    char nome[MAX_NAME];
};

////////////////////////////////////
//FUN��O DE ALOCA��O
Dados *alocaDados(int size);

///////////////////////////////////
//FUN�OES DE APRESENTA��O E MENU
void apresentaOrdenado(int c, int m, clock_t tempo);
void apresentaDados(Dados*lista, int position, clock_t *time);
void printaLista(Dados *lista);
int menu(Dados *lista);
void menuOrdenacao(Dados *lista);

///////////////////////////////////
//FUN�OES DE INSER��O
void inserirNoFinal(Dados *lista, Dados *info);
void inserirPosicaoN(Dados*lista , Dados *info,int posicao);

///////////////////////////////////
//FUN��O DE REMO��O
void removerPosicaoN(Dados *lista, int posicao);

///////////////////////////////////
//FUN�OES QUE ENVOLVEM MANIPULA��O DE ARQUIVOS
void escreveArquivo(Dados*lista);
void leArquivo(Dados*lista, char *filename);

///////////////////////////////////
//FUNCOES DE BUSCA 
void buscaLinearRG(Dados*lista, int rg);
void binarySearch(Dados *lista, int rg);

///////////////////////////////////
//Algoritmos de ordenacao

void selectionSortDireto(Dados *lista);
void insertionSortDireto(Dados *lista);
void bubleSortDireto(Dados *lista);
void quickSortDireto(Dados *lista, int inicioVet, int fimVet);
void merge(Dados  *lista, int inicio, int meio,int fim);
void  mergeSortIndireto(Dados *listaOriginal, int inicioVet, int fimVet);
void mergeV2(Dados *left, int sizeL, Dados *right, int sizeR, Dados *list);
void mergeSortV2(Dados *lista);

#endif // HEADER_H_INCLUDED
