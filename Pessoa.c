// DEFINIÇÃO DA BIBLIOTECA DEFINIDA PELO USUÁRIO
#include "Pessoa.h" // Para os escopos, estruturas e demais bibliotecas definidas

// IMPLEMENTAÇÃO DAS OPERAÇÕES

// Criar e inicializa Pessoa
Pessoa* criarPessoa( char *nome, Data nasc, float altura )
{
	// Alocação dinâmica de memória
	Pessoa *p = ( Pessoa* ) malloc( sizeof( Pessoa ) );

	// Verifica se conseguiu alocar a memória necessária para criar Pessoa
	if ( p != NULL )
	{
		strcpy( p->nome, nome );
		p->nascimento.dia = nasc.dia;
		p->nascimento.mes = nasc.mes;
		p->nascimento.ano = nasc.ano;
		p->altura = altura;
	}

	else
	{
		printf( "Erro ao alocar memória!\n" );
		exit( 1 ); // Interrompe a execução do programa
	}

	// Retorna o ponteiro de Pessoa
	return p;
}

void alterarPessoa( Pessoa *p, char *nome, Data nasc, float altura )
{
		// Altera por referência
		strcpy( p->nome, nome );
		p->nascimento.dia = nasc.dia;
		p->nascimento.mes = nasc.mes;
		p->nascimento.ano = nasc.ano;
		p->altura = altura;
}

// Exibir pessoa
void exibirPessoa( Pessoa p ){
	printf("\n#########################\n");
	printf( "Nome: %s\n", p.nome );
	printf( "Nascimento: %d/%d/%d\n", p.nascimento.dia, p.nascimento.mes, p.nascimento.ano );
	printf( "Altura: %.2f", p.altura );
	printf("\n#########################\n");
}

// Liberar memória alocada para Pessoa
void liberarPessoa( Pessoa *p ){
	printf( "\nLiberando Pessoa...\n" );
	free( p );
}
