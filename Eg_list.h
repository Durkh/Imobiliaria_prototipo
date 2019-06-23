/*
 * Eg_list.h
 *
 *  Created on: 18 de jun de 2019
 *      Author: egidio
 */

#ifndef EG_LIST_H_
#define EG_LIST_H_

typedef struct{
	size_t pavimentos;
	size_t quartos;
	double areaCons;
}tCasa;

typedef struct{
	size_t quartos;
	char posicao[50];
	size_t andar;
	double condominio;
	size_t vagasGaragem;
}tApartamento;

typedef struct{
	char rua[40];
    char bairro[40];
	size_t num;
	size_t cep;
	char cidade[40];
	double valor;
	double area;
	bool venda;
	char titulo[50];
	size_t tipo;
	tCasa casa;
	tApartamento apartamento;
}tImovel;

typedef struct Temp{
	tImovel imovel;
	size_t num;
	struct Temp* prox;
}tList;

void Inicializer();
int Insert(tImovel data);
int RemoveInic();
void PrintAll();
void PrintSingle(tList* pointer);
void SearchForValue(double data);
void SearchForTitle(char string[]);
void SearchForNeighbourhood(char string[]);
void PrintStatus(bool venda);
int RemoveByTtile(char string[]);
int RemoveByIndex(size_t num);


#endif /* EG_LIST_H_ */
