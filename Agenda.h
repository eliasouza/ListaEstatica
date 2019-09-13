#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#include "Pessoa.h" // Para os escopos, estruturas e demais bibliotecas já incluídas

// DEFINIÇÃO DA QUANTIDADE DE PESSOAS A SER ARMAZENADA NA AGENDA
#define MAXIMO 3

// DEFINIÇÃO DO CÓDIGO DE ERRO
#define ERRO -1

// DEFINIÇÃO DO CÓDIGO PARA LISTA VAZIA
#define VAZIA 0

// DEFINIÇÃO DO CÓDIGO PARA LISTA CHEIA
#define CHEIA 0

// DEFINIÇÃO DO CÓDIGO PARA SUCESSO
#define OK 1

// DEFINIÇÃO DA ESTRUTURA AGENDA
typedef struct AgendaTAD{
	Pessoa dado[MAXIMO]; // Estático
	int qtd;
} Agenda;

// ESCOPO DAS OPERAÇÕES DA AGENDA
Agenda *criarAgenda();
int armazenarPessoa( Agenda *lista, Pessoa *dado );
void liberarAgenda( Agenda *lista );
int tamanhoDaLista( Agenda *lista );
int listaCheia( Agenda *lista );
int listaVazia( Agenda *lista );
int removerPessoa( Agenda *lista );
void imprimirAgenda( Agenda *lista );

#endif // AGENDA_H_INCLUDED
