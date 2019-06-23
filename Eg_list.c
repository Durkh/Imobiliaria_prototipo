#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Eg_list.h"

/*#define casa 1
#define apartamento 2
#define terreno 3*/

tList* inicio = NULL;

void Inicializer() {
	inicio = NULL;
}

int Insert(tImovel data) {
	tList* pointer;

	pointer = (tList*) malloc(sizeof(tList));
	if (pointer == NULL) {
		puts("erro de alocação");
		return 0;
	}

	pointer->imovel = data;
	pointer->prox = NULL;

	if (inicio == NULL) {
		inicio = pointer;
		pointer->num = 1;
	} else {
		pointer->prox = inicio;
		pointer->num = inicio->num + 1;
		inicio = pointer;
	}
	return 1;
}

int RemoveInic() {
	tList* pointer;

	if (inicio == NULL)
		return 0;
	else {
		pointer = inicio;
		inicio = inicio->prox;
		free(pointer);
		return 1;
	}
}

void PrintAll() {
	tList* pointer;

	if (inicio == NULL) {
		puts("lista vazia");
		return;
	}

	pointer = inicio;
	while (pointer != NULL) {

		if (pointer->imovel.tipo == 1) {
			puts("*-------------------------------*");
			printf("%zu. tipo do imóvel: casa\n", pointer->num);
			printf("título: %s\n", pointer->imovel.titulo);
			puts("");
			printf("cidade: %s\n", pointer->imovel.cidade);
			puts("");
			printf("bairro: %s\n", pointer->imovel.bairro);
			puts("");
			printf("rua: %s\n", pointer->imovel.rua);
			puts("");
			printf("número: %zu\n", pointer->imovel.num);
			puts("");
			printf("CEP: %zu\n", pointer->imovel.cep);
			puts("");
			printf("número: %zu\n", pointer->imovel.num);
			puts("");
			if (pointer->imovel.venda == true)
				printf("o imóvel está à VENDA\n");
			else
                printf("o imóvel está sendo ALUGADO\n");
			puts("");
			printf("valor: %lfR$\n", pointer->imovel.valor);
			puts("");
			printf("pavimentos: %zu\n", pointer->imovel.casa.pavimentos);
			puts("");
			printf("quartos: %zu\n", pointer->imovel.casa.quartos);
			puts("");
			printf("área do terreno: %lf", pointer->imovel.area);
			printf("área construída: %lf", pointer->imovel.casa.areaCons);
			puts("");
			puts("");

		} else if (pointer->imovel.tipo == 2) {
			puts("*-------------------------------*");
			printf("%zu. tipo do imóvel: Apartamento\n", pointer->num);
			printf("título: %s\n", pointer->imovel.titulo);
			puts("");
			printf("cidade: %s\n", pointer->imovel.cidade);
			puts("");
			printf("bairro: %s\n", pointer->imovel.bairro);
			puts("");
			printf("rua: %s\n", pointer->imovel.rua);
			puts("");
			printf("número: %zu\n", pointer->imovel.num);
			puts("");
			printf("CEP: %zu\n", pointer->imovel.cep);
			puts("");
			printf("número: %zu\n", pointer->imovel.num);
			puts("");
			if (pointer->imovel.venda == true)
				printf("o imóvel está à VENDA\n");
			else
				printf("o imóvel está sendo ALUGADO\n");
			puts("");
			printf("valor: %lfR$\n", pointer->imovel.valor);
			puts("");
			printf("quantidade de quartos: %zu\n", pointer->imovel.apartamento.quartos);
			puts("");
			printf("posição do apartamento: %s\n", pointer->imovel.apartamento.posicao);
			puts("");
			printf("andar do apartamento: %zu\n", pointer->imovel.apartamento.andar);
			puts("");
			printf("valor do condomínio: %lf\n", pointer->imovel.apartamento.condominio);
			puts("");
			printf("quantidade de vagas na garagem: %zu\n", pointer->imovel.apartamento.vagasGaragem);
			puts("");
			puts("");
		} else if (pointer->imovel.tipo == 3) {
			puts("*-------------------------------*");
			printf("%zu. tipo do imóvel: terreno\n", pointer->num);
			printf("título: %s\n", pointer->imovel.titulo);
			puts("");
			printf("cidade: %s\n", pointer->imovel.cidade);
			puts("");
			printf("bairro: %s\n", pointer->imovel.bairro);
			puts("");
			printf("rua: %s\n", pointer->imovel.rua);
			puts("");
			printf("número: %zu\n", pointer->imovel.num);
			puts("");
			printf("CEP: %zu\n", pointer->imovel.cep);
			puts("");
			printf("número: %zu\n", pointer->imovel.num);
			puts("");
			if (pointer->imovel.venda == true)
				printf("o imóvel está à VENDA\n");
			else
				printf("o imóvel está sendo ALUGADO\n");
			puts("");
			printf("valor: %lfR$\n", pointer->imovel.valor);
			puts("");
			printf("a área do terreno é: %lf\n", pointer->imovel.area);
		}

		pointer = pointer->prox;
	}
	puts("---- fim da lista ---- \n");
}

void PrintSingle(tList* pointer){

    if(pointer == NULL) return;
    
	if (pointer->imovel.tipo == 1) {
		puts("*-------------------------------*");
		puts("tipo do imóvel: casa");
		printf("título: %s\n", pointer->imovel.titulo);
		puts("");
		printf("cidade: %s\n", pointer->imovel.cidade);
		puts("");
		printf("bairro: %s\n", pointer->imovel.bairro);
		puts("");
		printf("rua: %s\n", pointer->imovel.rua);
		puts("");
		printf("número: %zu\n", pointer->imovel.num);
		puts("");
		printf("CEP: %zu\n", pointer->imovel.cep);
		puts("");
		printf("número: %zu\n", pointer->imovel.num);
		puts("");
		if (pointer->imovel.venda == true)
		printf("o imóvel está à VENDA\n");
		else
		printf("o imóvel está sendo ALUGADO\n");
		puts("");
		printf("valor: %lfR$\n", pointer->imovel.valor);
		puts("");
		printf("pavimentos: %zu\n", pointer->imovel.casa.pavimentos);
		puts("");
		printf("quartos: %zu\n", pointer->imovel.casa.quartos);
		puts("");
		printf("área do terreno: %lf", pointer->imovel.area);
		printf("área construída: %lf", pointer->imovel.casa.areaCons);
		puts("");
		puts("");

    } else if (pointer->imovel.tipo == 2) {
		puts("*-------------------------------*");
		puts("tipo do imóvel: Apartamento");
		printf("título: %s\n", pointer->imovel.titulo);
		puts("");
		printf("cidade: %s\n", pointer->imovel.cidade);
		puts("");
		printf("bairro: %s\n", pointer->imovel.bairro);
		puts("");
		printf("rua: %s\n", pointer->imovel.rua);
		puts("");
		printf("número: %zu\n", pointer->imovel.num);
		puts("");
		printf("CEP: %zu\n", pointer->imovel.cep);
		puts("");
		printf("número: %zu\n", pointer->imovel.num);
		puts("");
        if (pointer->imovel.venda == true)
		printf("o imóvel está à VENDA\n");
		else
		printf("o imóvel está sendo ALUGADO\n");
		puts("");
		printf("valor: %lfR$\n", pointer->imovel.valor);
		puts("");
		printf("quantidade de quartos: %zu\n", pointer->imovel.apartamento.quartos);
		puts("");
		printf("posição do apartamento: %s\n", pointer->imovel.apartamento.posicao);
		puts("");
		printf("andar do apartamento: %zu\n", pointer->imovel.apartamento.andar);
		puts("");
		printf("valor do condomínio: %lf\n", pointer->imovel.apartamento.condominio);
		puts("");
		printf("quantidade de vagas na garagem: %zu\n", pointer->imovel.apartamento.vagasGaragem);
		puts("");
		puts("");
    } else if (pointer->imovel.tipo == 3) {
		puts("*-------------------------------*");
		puts("tipo do imóvel: terreno");
		printf("título: %s\n", pointer->imovel.titulo);
		puts("");
		printf("cidade: %s\n", pointer->imovel.cidade);
		puts("");
		printf("bairro: %s\n", pointer->imovel.bairro);
		puts("");
		printf("rua: %s\n", pointer->imovel.rua);
		puts("");
		printf("número: %zu\n", pointer->imovel.num);
		puts("");
		printf("CEP: %zu\n", pointer->imovel.cep);
		puts("");
		printf("número: %zu\n", pointer->imovel.num);
		puts("");
		if (pointer->imovel.venda == true)
			printf("o imóvel está à VENDA\n");
		else
			printf("o imóvel está sendo ALUGADO\n");
		puts("");
		printf("valor: %lfR$\n", pointer->imovel.valor);
		puts("");
		printf("a área do terreno é: %lf\n", pointer->imovel.area);
			}
}

void SearchForValue(double data) {
	tList* pointer;

	if (inicio == NULL)
		goto end;

	pointer = inicio;
	while (pointer != NULL) {
		if (pointer->imovel.valor > (data- 1.0) &&  pointer->imovel.valor < (data + 1.0) ){
            printf("%zu .\n", pointer->num);
			PrintSingle(pointer);
        } else
			pointer = pointer->prox;
	}
	
	end:
	puts("nada foi encontrado com esse valor");
	return;
}

void SearchForTitle(char string[]) {
	tList* pointer;

	if (inicio == NULL)
		goto end;

	pointer = inicio;
	while (pointer != NULL) {
		if (!strcmp(pointer->imovel.titulo, string)){
            printf("%zu. \n", pointer->num);
			PrintSingle(pointer);
        } else
			pointer = pointer->prox;
	}
	
	end:
	puts("nada com esse título foi encontrado");
	return;
}

void SearchForNeighbourhood(char string[]) {
	tList* pointer;

	if (inicio == NULL)
		goto end;

	pointer = inicio;
	while (pointer != NULL) {
		if (!strcmp(pointer->imovel.bairro, string)){
            printf("%zu. \n", pointer->num);
			PrintSingle(pointer);
        } else
			pointer = pointer->prox;
	}
	
	end:
	puts("nada com esse bairro foi encontrado");
	return;
}

void PrintStatus(bool venda){
    
    tList* pointer;
    
    if (inicio == NULL) {
		puts("lista vazia");
		return;
	}
	
	pointer = inicio;
    
    if(venda == true){
        while(pointer != NULL){
            if(pointer->imovel.venda == true){
                PrintSingle(pointer);   
                pointer=pointer->prox;
            }
        }
    } else if(venda == false){
        while(pointer != NULL){
            if(pointer->imovel.venda==false){
                PrintSingle(pointer);
                pointer= pointer->prox;
            }
        }
    }
}

int RemoveByTitle(char string[]) {
	tList* pointer, *antes;

	if (inicio == NULL)
		return 0;
	else {
		pointer = inicio;
		antes = inicio;
		while (pointer != NULL) {
			if (!strcmp(pointer->imovel.titulo, string)) {
				if (pointer == inicio) {
					inicio = inicio->prox;
					free(pointer);
					return 1;
				} else {
					antes->prox = pointer->prox;
					free(pointer);
					return 1;
				}
			} else {
				antes = pointer;
				pointer = pointer->prox;
			}
		}
		return 0;
	}
}

int RemoveByIndex(size_t num){

    tList* pointer, *antes;

    if (inicio == NULL) return 0;

    pointer= inicio;
    antes= inicio;

    for(int i=0; i<num; i++){
        antes= pointer;
        pointer= pointer->prox;
    }

    if(pointer == inicio){
        inicio= inicio->prox;
        free(pointer);
        return 1;
    } else {
        antes->prox = pointer->prox;
        free(pointer);
        return 1;
    }

    
return 0;
}
