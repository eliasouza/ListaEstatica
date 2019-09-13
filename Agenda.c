// DEFINIÇÃO DA BIBLIOTECA DEFINIDA PELO USUÁRIO
#include "Agenda.h" // Para os escopos, estruturas e demais bibliotecas já definidas

// IMPLEMENTAÇÃO DAS OPERAÇÕES

// Cria agenda
Agenda *criarAgenda(){
	// Alocação dinâmica de memória para armazenar T Pessoas
	Agenda *lista = ( Agenda* ) malloc( sizeof( Agenda ) );

	// Verifica se alocou memória
	if( lista != NULL ){
		lista->qtd = 0; // 0 indica que a lista está vazia.
	}

	else{
		printf( "Erro ao alocar memória para a lista Agenda." );
		exit( 1 ); // Aborta a execução do programa
	}

	return lista; // Caso dê tudo certo retorna o ponteiro para agenda
}

// Liberar memória alocada para Agenda
void liberarAgenda( Agenda *lista ){
    printf("\nLiberando agenda...\n");
    free( lista );
}

// Retorna o tamanho da lista
int tamanhoDaLista( Agenda *lista ){
    if( lista != NULL )
        return lista->qtd;
    else
        return ERRO;
}

// Retorna 1 se a lista está cheia, 0 se a lista não estiver cheia ou -1 se ocorrer erro
int listaCheia( Agenda *lista ){
    if( lista != NULL )
        return (lista->qtd == MAXIMO);
    else
        return ERRO;
}

// Retorna 1 se a lista está vazia, 0 se a lista não estiver vazia ou -1 se ocorrer erro
int listaVazia( Agenda *lista ){
    if( lista != NULL )
        return (lista->qtd == VAZIA);
    else
        return ERRO;
}

/* Insere uma pessoa no final da lista. Sempre no índice guardado pelo elemento ultimo/quantidade da lista
 * Retorna um código: 1 quando deu certo, 0 quando não deu certo.
*/
int armazenarPessoa( Agenda *lista, Pessoa *dado ){
    // Se a lista for nula
    if( lista == NULL )
        return ERRO; // Código de retorno -1 indica que não pode inserir na lista

    // Se a lista está cheia
    else if( listaCheia( lista ) )
        return CHEIA; // Código de retorno 0 indica que não pode inserir na lista, pois ela está cheia

    // Se passou pelas verificações acima, podemos inserir na lista:
    else{
        lista->dado[ lista->qtd ] = *dado; // Insere o conteúdo do dado pessoa na lista
        lista->qtd++; // Incrementa índice último
        return OK; // Código de retorno 1 indica sucesso na inserção
    }
}

// Remove uma pessoa no final da lista, caso não esteja vazia nem seja nula. Remove sempre na posição ultimo-1
int removerPessoa( Agenda *lista ){
    // Lista nula
    if( lista == NULL )
        return ERRO; // Código de retorno -1 indica que não pode inserir na lista

    // Lista vazia
    else if( listaVazia( lista ) )
        return VAZIA; // Código de retorno 0 indica que não pode inserir na lista, pois ela está vazia

    // Passou pelos testes acima podemos remover
    else{
        lista->qtd--; // Basta decrementar o atributo quantidade
        return OK;
    }
}

// Mostra todas as Pessoas na Agenda
void imprimirAgenda( Agenda *lista ){
	for( int i = 0; i < MAXIMO; i++ )
		exibirPessoa( lista->dado[i] );
}
