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

// Incluindo as principais bibliotecas a serem usadas no projeto
#include<locale.h> // Para configurações de idioma:
#include <stdio.h> // Para scanf, printf, fgets, gets
#include <string.h> // Para strcpy
#include <stdlib.h> // Para exit e malloc
#include "ListaEstaticaTAD.c"

int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	/*
	 * Para melhor utilização, add nesse programa um menu para 
	 * informar ao usuário as opções que o programa implementa. 
	 * Desenvolva casos de teste para cada função do programa.
	 */

	// Declarar a lista e o produto
	Lista *l;
	Produto p;

	// Criar a lista
	l = criar_lista();

	// Preencher o produto
	p.codigo = 1;
	strcpy(p.descricao, "Computador");
	p.preco = 4500.00;
	
	// Inserir o produto na lista
	if( inserir_inicio_lista(l, p) )
		printf("Inserido com sucesso.\n");
	else
		printf("Erro ao inserir.\n");


	return 0;
}
