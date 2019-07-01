#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Eg_list.h"

tList* inicio = NULL;

void Initializer() {
	inicio = NULL;
}

int Insert(tImovel data) {
	tList* pointer;

	pointer = (tList*) malloc(sizeof(tList));
	if (pointer == NULL) {
		puts(">>erro de alocação");
		return 0;
	}

	pointer->imovel = data;
	pointer->prox = NULL;

	if (inicio == NULL) {
		inicio = pointer;
		pointer->num = 1;
        puts(">>entrada registrada com sucesso");
	} else {
		pointer->prox = inicio;
		pointer->num = inicio->num + 1;
		inicio = pointer;
        puts(">>entrada registrada com sucesso");
	}
	return 1;
}

int RemoveUlt() {
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

tImovel getInfos(unsigned int choice){

	tImovel buffer;
    
    system("clear");
    
    puts("insira um título para o anúncio (simples): ");
    {
        char string[50];
        fgets(string, 50, stdin);
        RemoveEnter(string);
		strcpy(buffer.titulo, string);
	}
	puts("");
    puts("informe o nome da cidade: ");
    {
		char string[40];
		fgets(string, 50, stdin);
		RemoveEnter(string);
		strcpy(buffer.cidade, string);
	}
	puts("");
    puts("informe o nome do bairro");
    {
		char string[50];
		fgets(string, 50, stdin);
		RemoveEnter(string);
		strcpy(buffer.bairro, string);
	}
	puts("");
	puts("informe o nome da rua: ");
	{
		char string[50];
		fgets(string, 50, stdin);
		RemoveEnter(string);
		strcpy(buffer.rua, string);
	}
	puts("");
    puts("informe o CEP (sem pontuação): ");
    scanf("%lu%*c", &buffer.cep);
    
    puts("");
    puts("informe o número do imóvel: (SN = 0)");
    scanf("%u%*c", &buffer.num);
    
    puts("");
    puts("esse imóvel está sendo vendido ou alugado? ");
    puts("1- vendido");
    puts("2- alugado");
    {
        int temp = Escolha(2);
        buffer.venda= temp == 1? true : false;
    }
    
    puts("");
    puts("informe o valor do imóvel em reais (apenas números): ");
    scanf("%lf%*c", &buffer.valor);

	if(choice == 1){
		buffer.tipo= 1;
        puts("");
        puts("informe a quantidade de pavimentos do imóvel: ");
        scanf("%u%*c", &buffer.casa.pavimentos);

        puts("");
        puts("informe o número de quartos: ");
        scanf("%u%*c", &buffer.casa.quartos);
        
        puts("");
        puts("informe a área do terreno(apenas números): ");
        scanf("%lf%*c", &buffer.area);
        
        puts("");
        puts("informe a área construída(apenas números): ");
        scanf("%lf%*c", &buffer.casa.areaCons);
    
	}else if(choice == 2){
        buffer.tipo=2;
        puts("");
        puts("informe a área do imóvel: ");
        scanf("%lf%*c", &buffer.area);
        
        puts("");
        puts("informe a quantidade de quartos: ");
        scanf("%u%*c", &buffer.apartamento.quartos);
        
        puts("");
        puts("informe a posição do apartamento: ");
        {
            char string[50];
            fgets(string, 50, stdin);
            RemoveEnter(string);
            strcpy(buffer.apartamento.posicao, string);
        }
        puts("");
        puts("informe o andar do apartamento: ");
        scanf("%u%*c", &buffer.apartamento.andar);
        
        puts("");
        puts("informe o valor do condomínio: ");
        scanf("%lf%*c", &buffer.apartamento.condominio);
        
        puts("");
        puts("informe o numero de vagas da garagem");
        scanf("%u%*c", &buffer.apartamento.vagasGaragem);

	}else{
        buffer.tipo=3;
        puts("");
        puts("informe a área do terreno: ");
        scanf("%lf%*c", &buffer.area);
	}

	puts("");
    puts("");
	
	return buffer;
}

void PrintAll() {
	tList* pointer;

    system("clear");
    
	if (inicio == NULL) {
		puts("lista vazia");
        puts("");
		return;
	}

	pointer = inicio;
	while (pointer != NULL) {

		if (pointer->imovel.tipo == 1) {
			puts("*-------------------------------*");
			printf("%u. tipo do imóvel: casa\n", pointer->num);
            puts("");
			printf("título: %s\n", pointer->imovel.titulo);
			puts("");
			printf("cidade: %s\n", pointer->imovel.cidade);
			puts("");
			printf("bairro: %s\n", pointer->imovel.bairro);
			puts("");
			printf("rua: %s\n", pointer->imovel.rua);
			puts("");
			printf("CEP: %lu\n", pointer->imovel.cep);
			puts("");
			if(pointer->imovel.num == 0) puts("SN");
            else printf("número: %u\n", pointer->imovel.num);
			puts("");
			if (pointer->imovel.venda == true)
				printf("o imóvel está à VENDA\n");
			else
                printf("o imóvel está sendo ALUGADO\n");
			puts("");
			printf("valor: %.2lfR$\n", pointer->imovel.valor);
			puts("");
			printf("pavimentos: %u\n", pointer->imovel.casa.pavimentos);
			puts("");
			printf("quartos: %u\n", pointer->imovel.casa.quartos);
			puts("");
			printf("área do terreno: %.2lf metros quadrados\n", pointer->imovel.area);
            puts("");
			printf("área construída: %.2lf metros quadrados\n", pointer->imovel.casa.areaCons);
			puts("");
			puts("");

		} else if (pointer->imovel.tipo == 2) {
			puts("*-------------------------------*");
			printf("%u. tipo do imóvel: Apartamento\n", pointer->num);
            puts("");
			printf("título: %s\n", pointer->imovel.titulo);
			puts("");
			printf("cidade: %s\n", pointer->imovel.cidade);
			puts("");
			printf("bairro: %s\n", pointer->imovel.bairro);
			puts("");
			printf("rua: %s\n", pointer->imovel.rua);
			puts("");
			printf("CEP: %lu\n", pointer->imovel.cep);
			puts("");
			if(pointer->imovel.num == 0) puts("SN");
            else printf("número: %u\n", pointer->imovel.num);
			puts("");
			if (pointer->imovel.venda == true)
				printf("o imóvel está à VENDA\n");
			else
				printf("o imóvel está sendo ALUGADO\n");
			puts("");
			printf("valor: %.2lfR$\n", pointer->imovel.valor);
			puts("");
			printf("quantidade de quartos: %u\n", pointer->imovel.apartamento.quartos);
			puts("");
			printf("posição do apartamento: %s\n", pointer->imovel.apartamento.posicao);
			puts("");
			printf("andar do apartamento: %u\n", pointer->imovel.apartamento.andar);
			puts("");
			printf("valor do condomínio: %.2lf\n", pointer->imovel.apartamento.condominio);
			puts("");
			printf("quantidade de vagas na garagem: %u\n", pointer->imovel.apartamento.vagasGaragem);
			puts("");
			puts("");
		} else if (pointer->imovel.tipo == 3) {
			puts("*-------------------------------*");
			printf("%u. tipo do imóvel: terreno\n", pointer->num);
            puts("");
			printf("título: %s\n", pointer->imovel.titulo);
			puts("");
			printf("cidade: %s\n", pointer->imovel.cidade);
			puts("");
			printf("bairro: %s\n", pointer->imovel.bairro);
			puts("");
			printf("rua: %s\n", pointer->imovel.rua);
			puts("");
			printf("CEP: %lu\n", pointer->imovel.cep);
			puts("");
            if(pointer->imovel.num == 0) puts("SN");
            else printf("número: %u\n", pointer->imovel.num);
			puts("");
			if (pointer->imovel.venda == true)
				printf("o imóvel está à VENDA\n");
			else
				printf("o imóvel está sendo ALUGADO\n");
			puts("");
			printf("valor: %.2lfR$\n", pointer->imovel.valor);
			puts("");
			printf("a área do terreno é: %.2lf metros quadrados\n", pointer->imovel.area);
		}

		pointer = pointer->prox;
	}
	puts("");
	puts("---- fim da lista ---- \n");
}

void PrintSingle(tList* pointer){

    if(pointer == NULL) return;
    
	if (pointer->imovel.tipo == 1) {
		puts("*-------------------------------*");
		printf("%u. tipo do imóvel: casa\n", pointer->num);
        puts("");
		printf("título: %s\n", pointer->imovel.titulo);
		puts("");
		printf("cidade: %s\n", pointer->imovel.cidade);
		puts("");
		printf("bairro: %s\n", pointer->imovel.bairro);
		puts("");
		printf("rua: %s\n", pointer->imovel.rua);
		puts("");
		printf("CEP: %lu\n", pointer->imovel.cep);
		puts("");
        if(pointer->imovel.num == 0) puts("SN");
		else printf("número: %u\n", pointer->imovel.num);
		puts("");
		if (pointer->imovel.venda == true)
		printf("o imóvel está à VENDA\n");
		else
		printf("o imóvel está sendo ALUGADO\n");
		puts("");
		printf("valor: %.2lfR$\n", pointer->imovel.valor);
		puts("");
		printf("pavimentos: %u\n", pointer->imovel.casa.pavimentos);
		puts("");
		printf("quartos: %u\n", pointer->imovel.casa.quartos);
		puts("");
		printf("área do terreno: %.2lf metros quadrados\n", pointer->imovel.area);
        puts("");
		printf("área construída: %.2lf metros quadrados\n", pointer->imovel.casa.areaCons);
		puts("");
		puts("");

    } else if (pointer->imovel.tipo == 2) {
		puts("*-------------------------------*");
		printf("%u. tipo do imóvel: Apartamento\n", pointer->num);
        puts("");
		printf("título: %s\n", pointer->imovel.titulo);
		puts("");
		printf("cidade: %s\n", pointer->imovel.cidade);
		puts("");
		printf("bairro: %s\n", pointer->imovel.bairro);
		puts("");
		printf("rua: %s\n", pointer->imovel.rua);
		puts("");
		printf("CEP: %lu\n", pointer->imovel.cep);
		puts("");
        if(pointer->imovel.num == 0) puts("SN");
		else printf("número: %u\n", pointer->imovel.num);
		puts("");
        if (pointer->imovel.venda == true)
		printf("o imóvel está à VENDA\n");
		else
		printf("o imóvel está sendo ALUGADO\n");
		puts("");
		printf("valor: %.2lfR$\n", pointer->imovel.valor);
		puts("");
		printf("quantidade de quartos: %u\n", pointer->imovel.apartamento.quartos);
		puts("");
		printf("posição do apartamento: %s\n", pointer->imovel.apartamento.posicao);
		puts("");
		printf("andar do apartamento: %u\n", pointer->imovel.apartamento.andar);
		puts("");
		printf("valor do condomínio: %.2lf\n", pointer->imovel.apartamento.condominio);
		puts("");
		printf("quantidade de vagas na garagem: %u\n", pointer->imovel.apartamento.vagasGaragem);
		puts("");
		puts("");
    } else if (pointer->imovel.tipo == 3) {
		puts("*-------------------------------*");
		printf("%u. tipo do imóvel: terreno\n", pointer->num);
        puts("");
		printf("título: %s\n", pointer->imovel.titulo);
		puts("");
		printf("cidade: %s\n", pointer->imovel.cidade);
		puts("");
		printf("bairro: %s\n", pointer->imovel.bairro);
		puts("");
		printf("rua: %s\n", pointer->imovel.rua);
		puts("");
		printf("CEP: %lu\n", pointer->imovel.cep);
		puts("");
		if(pointer->imovel.num == 0) puts("SN");
		else printf("número: %u\n", pointer->imovel.num);
		puts("");
		if (pointer->imovel.venda == true)
			printf("o imóvel está à VENDA\n");
		else
			printf("o imóvel está sendo ALUGADO\n");
		puts("");
		printf("valor: %.2lfR$\n", pointer->imovel.valor);
		puts("");
		printf("a área do terreno é: %.2lf metros quadrados\n", pointer->imovel.area);
			}
			
    puts("");
}

void SearchForValue(char string[]) {   // in debugging process
       
	tList* pointer;
    int checker=0;
    char value[50];
    
	if (inicio == NULL){
        puts("nada foi encontrado com esse valor");
        return;
    }
    
	pointer = inicio;
    
	while (pointer != NULL) {
        sprintf(value, "%.2lf", pointer->imovel.valor);
		if (!strcmp(string, value)){
            printf("%u .\n", pointer->num);
			PrintSingle(pointer);
            pointer = pointer->prox;
            checker++;
        } else {
			pointer = pointer->prox;
        }
	}
    
	if(checker==0){
        puts("nada foi encontrado com esse valor");
    }
	return;
}

void SearchForTitle(char string[]) {
	tList* pointer;
    int checker=0;
    
	if (inicio == NULL)
		goto end;

	pointer = inicio;
	while (pointer != NULL) {
		if (!strcmp(pointer->imovel.titulo, string)){
            printf("%u. \n", pointer->num);
			PrintSingle(pointer);
            pointer = pointer->prox;
            checker++;
        } else
			pointer = pointer->prox;
	}
	
	end:
	if(checker== 0){
        puts("nada com esse título foi encontrado");
    }
	return;
}

void SearchForNeighbourhood(char string[]) {
	tList* pointer;
    int checker=0;
    
	if (inicio == NULL)
		goto end;

	pointer = inicio;
	while (pointer != NULL) {
		if (!strcmp(pointer->imovel.bairro, string)){
            printf("%u. \n", pointer->num);
			PrintSingle(pointer);
            pointer = pointer->prox;
            checker++;
        } else
			pointer = pointer->prox;
	}
        
    end:
	if(checker==0){
        puts("nada com esse bairro foi encontrado");
    }
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
            } else
                pointer = pointer->prox;
        }
        return;
    } else if(venda == false){
        while(pointer != NULL){
            if(pointer->imovel.venda==false){
                PrintSingle(pointer);
                pointer= pointer->prox;
            } else
                pointer = pointer->prox;
        }
        return;
    }
}

void EditEntry(unsigned int index){
    tList* pointer;
    bool found = false;
    
    if (inicio== NULL)
        return;
    
    pointer= inicio;
    
    while(pointer!=NULL){
        
        if(pointer->num == index){
            pointer->imovel = getInfos(pointer->imovel.tipo);
            found = true;
            break;
        } else{
            pointer= pointer->prox;
        }
    
    }
    
    if(!found) puts("nada foi encontrado");
    
    return;
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


int RemoveByIndex(unsigned int num){

    tList* pointer, *antes;

    if (inicio == NULL) return 0;

    pointer= inicio;
    antes= inicio;

    while (pointer != NULL ){
        
        if(pointer->num == num){
            
            
            if(pointer == inicio){
                inicio= inicio->prox;
                free(pointer);
                return 1;
            } else {
                antes->prox = pointer->prox;
                free(pointer);
                return 1;
            }
            
        } else{
            pointer= pointer->prox;
        }
    }
    
return 0;
}


void SaveFile(){
	FILE* fp;
    tList* pointer; 

        fp = fopen("imobiliariaSav.txt", "w");
    if(fp == NULL){
        printf("Erro ao salvar");
        return;
    }

    pointer= inicio;
  
    while(pointer!= NULL){
        fwrite(&pointer->imovel, sizeof(tImovel), 1, fp);
        pointer=pointer->prox;
    }
    
    if(!ferror(fp)) puts("dados salvos com sucesso!");
    else puts("erro ao salvar dados");
    
    fclose(fp);
}

void ReadFile(){
	FILE *fp;
    tImovel buffer;
    
	fp = fopen("imobiliariaSav.txt", "r");
    if(fp == NULL){
        return;
    }
    
	while( fread(&buffer, sizeof(tImovel), 1, fp) ){
        Insert(buffer);
    }
    
    if(!ferror(fp)) puts("dados lidos com sucesso!");
    else puts("erro ao ler dados");
        
  fclose(fp);
}

// --------------------------------------------------------------------------------------------------------------------------

int Escolha(int max){

	int escolha;

	while(1){
		scanf("%d%*c", &escolha);
		if(escolha<=max && escolha >0){
			break;
		}else{
			printf("DIGITE UMA OPCAO VALIDA\n");
		}
	}

	return escolha;
}

void RemoveEnter(char string[]){

	int i;

	for(i=0; string[i]!='\0'; i++){
		if(string[i] == '\n'){
			string[i] = '\0';
			break;
		}
	}
}

