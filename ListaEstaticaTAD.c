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

// Incluir biblioteca ListaTAD.h
#include "ListaEstaticaTAD.h"

// Implementação do TAD Lista
struct ListaEstatica
{
    int ultimo;
    struct ProdutoTAD dados[MAX];
};


// Implementação das operações da lista
// Criar Lista
Lista *criar_lista()
{
    // Alocação de memória
    Lista *L = ( Lista* ) malloc( sizeof( struct ListaEstatica ) );

    // Verifica se a lista foi criada
    if( L != NULL )
        L->ultimo = 0; // Indica que a lista está vazia

    return L; // Retorna a lista criada
}


// Destruir Lista
void destruir_lista( Lista *L )
{
    free( L );
    printf("\nA lista foi destruída!\n\n\n");
}


// Obter tamanho da lista
int obter_tamanho_lista( Lista *L )
{
    if( L != NULL )
        return L->ultimo;

    else
        return LISTA_NULA; // informa que houve problema
}


// Obtém status da lista: 1 cheia, 0 não cheia, -1 nula
int esta_cheia_lista( Lista *L )
{
    if( L == NULL )
        return LISTA_NULA; // informa que houve problema

    else
        return ( L->ultimo == MAX ); // 1 cheia, 0 não cheia
}


// Obtém status da lista: 1 vazia, 0 não vazia, -1 nula
int esta_vazia_lista( Lista *L )
{
    if( L == NULL )
        return LISTA_NULA; // informa que houve problema

    else
        return ( L->ultimo == 0 ); // 1 vazia, 0 não vazia
}


/* Inserir no final da lista. Sempre no índice guardado pelo elemento ultimo/quantidade da lista
 * Retorna um código: 1 quando deu certo, 0 quando não deu certo.
*/
int inserir_final_lista( Lista *L, Produto p )
{
    if( L == NULL ) // Se a lista for nula
        return LISTA_NULA; // Código de retorno -1 indica que não pode inserir na lista

    if( esta_cheia_lista( L ) ) // Se a lista está cheia
        return 0; // Código de retorno 0 indica que não pode inserir na lista

    // Se passou pelas verificações acima, podemos inserir na lista:
	L->dados[ L->ultimo ] = p; // Insere produto na lista
    L->ultimo++; // Incrementa índice último

    return 1; // Código de retorno que indica sucesso na inserção
}


/* Inserir no início da lista. Sempre no índice 0 da lista
 * Retorna um código: 1 quando deu certo, 0 quando não deu certo.
*/
int inserir_inicio_lista( Lista *L, Produto p )
{
    if( L == NULL ) // Se a lista for nula
        return LISTA_NULA; // Código de retorno -1 indica que não pode inserir na lista

    if( esta_cheia_lista( L ) ) // Se a lista está cheia
        return 0; // Código de retorno 0 indica que não pode inserir na lista

    /*
     * Se passou pelas verificações acima, podemos inserir na lista. Mas como queremos
     * inserir no início, precisamos mover os dados para uma posição à frente, de modo
     * a deixar o índice 0 pronto para podermos inserir o dado atual.
     * Inserir no início é inserir no índice 0.
    */

     // Laço que faz a troca de posição dos elementos da lista:
    int i; // Para controle do laço

    for( i = L->ultimo - 1; i > 0; i-- ) // i recebe o índice do último item da lista
        L->dados[ i + 1 ] = L -> dados[ i ]; // O item da lista "é movido para a direita"

    L->dados[ 0 ] = p; // O item produto é add ao início da lista
    L->ultimo++; // Incrementa índice último

    return 1; // Código de retorno que indica sucesso na inserção
}


/* Inserir no meio da lista. Sempre no índice i da lista, pois faz uma inserção ordenada (crescente).
 * Percorre a lista de 0 até ultimo/quantidade comparando algum elemento do item da lista com o que será inserido,
 * normalmente o código ou o valor. Quando o elemento do item na lista for menor que o elemento do item a ser inserido
 * sabemos qual é o valor de i, e é nesse índice que está em i que será feita a inserção do item atual, mas para isso é necessário deslocar
 * os itens a partir desse índice para uma posição à frente evitando sobreescrevê-los, da mesma forma da inserção no início.
 * Retorna um código: 1 quando deu certo, 0 quando não deu certo.
 * Para que essa inserção seja possível a lista deve estar ordenada.
*/
int inserir_meio_lista( Lista *L, Produto p )
{
    if( L == NULL ) // Se a lista for nula
        return LISTA_NULA; // Código de retorno -1 indica que não pode inserir na lista

    if( esta_cheia_lista( L ) ) // Se a lista está cheia
        return 0; // Código de retorno 0 indica que não pode inserir na lista

     // Se passou pelas verificações acima, podemos inserir na lista
    int i = 0, j = 0; // Para controle dos laços

    /* Percorrer a lista de 0 (início) até ultimo/quantidade para inserir em ordem crescente de preço.
     * Enquanto não chegar ao ultimo item da lista e enquanto o preçco do item da lista for menor que o
     * preço do item a ser inserido significa que ainda não achou o local onde será inserido o novo item.
     */
    while( i < L->ultimo && L->dados[ i ].preco < p.preco ){
        i++; // Conta e acumula o índice i
        //printf("\n\nI: %d\nUltimo: %d\nPreco L: %.2f\nPreco p: %.2f\nCod: %d", i, L->ultimo, L->dados[i].preco, p.preco, L->dados[i].codigo);
    }

    printf("Inserir no MEIO no índice %d. ", i);

    // Laço que faz a troca de posição dos elementos da lista a partir de i:
    for( j = L->ultimo - 1; j >= i; j-- ) // j recebe o índice do último item da lista
        L->dados[ j + 1 ] = L -> dados[ j ]; // O item da lista "é movido para a direita", a partir de i

    L->dados[ i ] = p; // O item produto é add ao índice i da lista
    L->ultimo++; // Incrementa índice último

    return 1; // Código de retorno que indica sucesso na inserção
}

/*
 * Faz consulta pelo índice informado.
 * Retorna um código: 1 quando deu certo, 0 quando não deu certo.
 * Se a consulta der certo o conteúdo do item buscado é retornado por referência.
*/
int buscar_lista_indice( Lista *L, int indice, struct ProdutoTAD *p) // Considerando para o usuário o primeiro índice = 1
{
    if( L == NULL || indice <= 0 || indice > L->ultimo ) // Em qualquer das situações retorna o código inválido
        return LISTA_NULA;

    // Coloca o conteúdo no ponteiro p
    *p = L->dados[ indice - 1 ]; // Considerando o primeiro índice = 0

    return 1;
}

// Remove o último elemento caso não esteja vazia nem seja nula. Remove sempre na posição ultimo-1
int remover_final_lista( Lista *L )
{
    if( L == NULL ) // Lista nula
        return LISTA_NULA;

    if( L->ultimo == 0 ) // Lista vazia
        return 0;

    // Passou pelos testes acima podemos remover
    L->ultimo--; // Basta decrementar o elemento ultimo/quantidade

    return 1;
}


// Remove o primeiro elemento, caso não esteja vazia, nem seja nula. Remove sempre na posição 0.
int remover_inicio_lista( Lista *L )
{
    if( L == NULL ) // Lista nula
        return LISTA_NULA;

    if( L->ultimo == 0 ) // Lista vazia
        return 0;

    int i = 0;

    // Percorre o vetor de dados de 0 até a última posição com item
    for( i = 0; i < L->ultimo - 1; i++ ) // O item da lista "é movido para a esquerda"
        L->dados[ i ] = L->dados[ i + 1 ];

    // Passou pelos testes acima podemos remover
    L->ultimo--; // Basta decrementar o elemento ultimo/quantidade

    return 1;
}


int remover_meio_lista( Lista *L, int codigo )
{
    if( L == NULL ) // Se a lista for nula
        return LISTA_NULA; // Código de retorno -1 indica que não pode inserir na lista

    if( L->ultimo == 0 ) // Se a lista está vazia
        return 0; // Código de retorno 0 indica que não pode inserir na lista

     // Se passou pelas verificações acima, podemos remover da lista
    int i = 0, j = 0; // Para controle dos laços


    while( i < L->ultimo && L->dados[ i ].codigo != codigo )
        i++;

    if( i == L->ultimo ) // Não encontrou produto com o código passado
        return 0;

    printf("Remover do MEIO no índice %d. ", i);

    // Laço que faz a troca de posição dos elementos da lista
    for( j = i; j < L->ultimo - 1; j++ )
        L->dados[ j ] = L -> dados[ j + 1 ]; // O item da lista "é movido para a esquerda", a partir de i

    L->ultimo--; // Decrementa índice último

    return 1; // Código de retorno que indica sucesso na inserção
}
