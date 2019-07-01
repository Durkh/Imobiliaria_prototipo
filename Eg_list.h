/*
 * Eg_list.h
 *
 *  Created on: 18 de jun de 2019
 *      Author: egidio
 */

#ifndef EG_LIST_H_
#define EG_LIST_H_

typedef int bool;
enum { false, true }; //definição para booleanos

typedef struct{
	unsigned int pavimentos;
	unsigned int quartos;
	double areaCons;
}tCasa; //struct dos dados da casa

typedef struct{
	unsigned int quartos;
	char posicao[50];
	unsigned int andar;
	double condominio;
	unsigned int vagasGaragem;
}tApartamento; // struct dos dados do apartamento

typedef struct{
	char rua[40];
    char bairro[40];
	unsigned int num;
	unsigned long int cep;
	char cidade[40];
	double valor;
	double area;
	bool venda;
	char titulo[50];
	unsigned int tipo;
	tCasa casa;
	tApartamento apartamento;
}tImovel; //struct dos dados comuns aos imóveis

typedef struct Temp{
	tImovel imovel;
	unsigned int num;
	struct Temp* prox;
}tList; //struct da lista

//funções relativas à lista
void Initializer(); //inicializa a lista
int Insert(tImovel data); //adiciona uma entrada à lista
int RemoveUlt(); //remove o último da lista
tImovel getInfos(unsigned int choice); //recebe e trata os dados
void PrintAll(); //imprime todos os itens da lista
void PrintSingle(tList* pointer); //imprime um único item da lista
void SearchForValue(char string[]); //procura baseado em um valor fornecido
void SearchForTitle(char string[]); //procura baseado em um título fornecido
void SearchForNeighbourhood(char string[]); //procura baseado em um bairro
void PrintStatus(bool venda); //imprime baseado no status (venda ou aluguel)
void EditEntry(unsigned int index); //edita uma entrada da lista
int RemoveByTitle(char string[]); //remove um item baseado no título
int RemoveByIndex(unsigned int num); //remove um item baseado num índice fornecido

void SaveFile(); //salva
void ReadFile(); //lê

//funções diversas
int Escolha(int max);
void RemoveEnter(char string[]);

#endif /* EG_LIST_H_ */
