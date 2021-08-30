#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_NAME 20 //DEFINES PRO VETORES DE CHAR
#define MAX_READ 40
#define ZERO 0
/////////////////////////////////////
int M, C;//VARIAVEIS GLOBAIS PARA CONTAGEM



////////////////////////////////////
//struct principal do n�
typedef struct node{
struct node *anterior;
int rg;
char nome[MAX_NAME];
struct node *proximo;
}Node;
//struct pra ter controle do ultimo tamb�m
typedef struct cabecalho{
   Node *primeiro;
   Node *ultimo;
   Node **vetorPtr;
   int tamanho;
   int estaOrdenado;
}Header;

////////////////////////////////////
//FUN��O DE ALOCA��O
Node *alocaNode();

///////////////////////////////////
//FUN�OES DE APRESENTA��O E MENU
void apresentaDados(int *rg, char*nome, int *position, clock_t *time);
void printaLista(Header *lista);
int menu(Header *lista);
void subMenuOrdenacao(Header *lista);

///////////////////////////////////
//FUN�OES DE INSER��O
void inserirNoFim(int rg, char *nome, Header *lista);
void inserirPosicaoN(int rg, char *nome, Header *lista, int posicao);

///////////////////////////////////
//FUN��O DE REMO��O
void removerPosicaoN(Header*lista, int posicao);

///////////////////////////////////
//FUN�OES QUE ENVOLVEM MANIPULA��O DE ARQUIVOS
void escreveArquivo(Header*lista);
void leArquivo(Header*lista,char*filename);

///////////////////////////////////
//FUCOES DE BUSCA
void procuraRG(Header*lista, int rg);
void binarySearch(Header *listaOriginal, int rg);

///////////////////////////////////
//Algoritmos de ordenacao
void selectionSortIndireto(Header *lista);
void insertionSortIndireto(Header *listaOriginal);
void bubleSortIndireto(Header *listaOriginal);
void shellSortIndireto(Header *listaOriginal);
void quickSortIndireto(Header *listaOriginal, int inicioVet, int fimVet);
void  mergeSortIndireto(Header *listaOriginal, int inicioVet, int fimVet);
void merge(Header  *listaOriginal, int inicio, int meio,int fim);

////////////////////////////////////
//Funcoes para vetor auxiliar
void copiaVtrParaLista(Header *listaOrdenadaIndireta);
Node **criaListaPtr(Header *listaOriginal);

#endif // HEADER_H_INCLUDED
