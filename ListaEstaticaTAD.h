/*
*
* Computer Science Section
* Faculdades Doctum de Caratinga
* Caratinga, MG, Brazil
* Feb. 20, 2020
* author: Elias Goncalves
* email: falarcomelias@gmail.com
* Licensed under the Apache License, Version 2.0
*
*/

#ifndef _LISTATAD_H_ // Se não tiver definido a constante _LISTATAD_H_
#define _LISTATAD_H_ // Define _LISTATAD_H_ Isso garante que essa biblioteca seja incluída só uma vez no projeto

// Definindo o tamanho do vetor que vai compor a Lista
#define MAX 7


// Definição do código para lista nula
#define LISTA_NULA -1


// Definindo o tipo abstrato a ser armazenado na lista. A implementação desse tipo definido pelo usuário é feita em ListaTAD.c
typedef struct ProdutoTAD Produto;

// Implementação do TAD Produto
struct ProdutoTAD
{
    int codigo;
    char descricao[20];
    float preco;
};

// Definindo o tipo abstrato lista estática. A implementação é feita em ListaTAD.c
typedef struct ListaEstatica Lista;


// Definindo os protótipos das operações da lista
Lista *criar_lista();
void destruir_lista( Lista* );
int obter_tamanho_lista( Lista* );
int esta_cheia_lista( Lista* );
int esta_vazia_lista( Lista* );
int inserir_final_lista( Lista*, struct ProdutoTAD ); // Inserir sempre no ínice guardado no elemento ultimo/quantidade da lista
int inserir_inicio_lista( Lista*, struct ProdutoTAD ); // Inserir sempre na índice 0
int inserir_meio_lista( Lista*, struct ProdutoTAD ); // Inserir de forma ordenada
int buscar_lista_indice( Lista*, int, struct ProdutoTAD* ); // Consultar por índice
int remover_final_lista( Lista* );
int remover_inicio_lista( Lista* );
int remover_meio_lista( Lista*, int );


#endif // _LISTATAD_H_
