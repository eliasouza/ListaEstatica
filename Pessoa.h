#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <stdlib.h> // Para exit e malloc

// DEFINIÇÃO DAS ESTRUTURAS
typedef struct DataNascimento
{
	int dia;
	int mes;
	int ano;
} Data;

typedef struct PessoaTAD
{
	char nome[30];
	Data nascimento;
	float altura;
} Pessoa;


// PROTÓTIPOS DAS OPERAÇÕES
Pessoa* criarPessoa( char*, Data, float );
void alterarPessoa( Pessoa*, char*, Data, float );
void exibirPessoa( Pessoa );
void liberarPessoa( Pessoa* );

#endif // PESSOA_H_INCLUDED
