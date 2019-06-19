#include <stdlib.h>
#include <stdio.h>
#include "Eg_list.h"

#define casa 1
#define apartamento 2
#define terreno 3



tList* inicio = NULL;

void Inicializer(){
	inicio = NULL;
}

int Insert(tImovel data){
	tList* pointer;

	pointer = (tList*) malloc(sizeof(tList));
	if(pointer == NULL){
		puts("erro de alocação");
		return 0;
	}

		pointer->imovel=data;
		pointer->prox=NULL;

	if(inicio == NULL){
		inicio=pointer;
		pointer->num=1;
	}else{
		pointer->prox=inicio;
		pointer->num= inicio->num+1;
		inicio= pointer;
	}
	return 1;
}

int RemoveInic(){
	tList* pointer;


	if(inicio == NULL) return 0;
	else{
		pointer= inicio;
		inicio= inicio->prox;
		free(pointer);
		return 1;
	}
}

void Print(){
	tList* pointer;

	if(inicio==NULL){
		puts("lista vazia");
		return;
	}

	pointer=inicio;
	while(pointer != NULL){
		printf("dado= %d\n", pointer->);
		pointer= pointer->prox;
	}
	puts("---- fim da lista ---- \n");
}

tList* SearchForData(int data){
	tList* pointer;

	if(inicio ==NULL) return NULL;

	pointer= inicio;
	while(pointer!= NULL)
	{
		if(pointer->data == data) return pointer;
		else pointer= pointer->prox;
	}
	return NULL;
}

tList* SearchForNumber(int num){
	tList* pointer;

	if(inicio ==NULL) return NULL;

	pointer= inicio;
	while(pointer!= NULL)
	{
		if(pointer->num == num) return pointer;
		else pointer= pointer->prox;
	}
	return NULL;
}

int RemoveDado(int data){
	tList* pointer,* antes;

	if(inicio==NULL) return 0;
	else{
		pointer=inicio;
		antes=inicio;
		while(pointer!=NULL){
			if(pointer->data == data){
				if(pointer == inicio){
					inicio= inicio->prox;
					free(pointer);
					return 1;
				}else{
					antes->prox = pointer->prox;
					free(pointer);
					return 1;
				}
			}
			else{
				antes= pointer;
				pointer= pointer->prox;
			}
		}
		return 0;
	}
}
