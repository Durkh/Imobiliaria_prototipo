#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Eg_list.h"

void Menu1();
void Menu2();
int Escolha(int max);
tImovel getInfos(size_t choice);

int main(){

	menu:
	system("clear");
	Menu1();

	switch (Escolha(4)){
		case 1:
			system("clear");
			puts("você deseja adicionar:\n"
					"1- Casa\n"
					"2- Apartamento\n"
					"3- Terreno\n");
			switch(Escolha(3)){
				case 1:
					Insert(getInfos(1), 1);
					break;
				case 2:
					Inser(getInfos(2), 2);
					break;
				case 3:
					Insert(getInfos(3), 3);
					break;
			}
			break;
		case 2:
			break;
		case 3:
			system("clear");
						Menu2();
						switch (Escolha(6)){
							case 1:
							case 2:
							case 3:
							case 4:
							case 5:
								break;
							case 6:
								goto menu;
						}
			break;
		case 4:
		{
			char input;
			while(1){
				system("clear");
				puts("você tem certeza que deseja sair?(s/n)");
				scanf("%c", &input);
				if(input == 's' || input == 'S') return 0;
				if(input == 'n' || input == 'N') goto menu;
			}
		}
			break;
	}

	return 0;
}


void Menu1(){

	puts("\t\tSISTEMA DE REGISTRO DE IMÓVEIS V1.0\n");
	puts("");
	puts("");
	puts("");
	puts("Selecione a opção desejada:");
	puts("1- Cadastrar novo imóvel");
	puts("2- Ver imóveis registrados");
	puts("3- Busca e visualização personalizada");
	puts("4- salvar e sair");


}

void Menu2(){

	puts("1- Busca de imóvel por título");
	puts("2- Busca de imóvel por bairro");
	puts("3- Busca de imóveis por valor");
	puts("4- Mostrar todos os imóveis disponíveis para venda");
	puts("5- Mostrar todos os imóveis disponíveis para aluguel");
	puts("6- voltar");
}

int Escolha(int max){

	int escolha;

	while(1){
		scanf("%d", &escolha);
		if(escolha<=max && escolha >0){
			break;
		}else{
			printf("DIGITE UMA OPCAO VALIDA\n");
		}
	}

	return escolha;
}

tImovel getInfos(size_t choice){

	tImovel buffer;
    
    puts("insira um título para o anúncio: ");
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
	puts("informe o nome da rua: ");
	{
		char string[50];
		fgets(string, 50, stdin);
		RemoveEnter(string);
		strcpy(buffer.rua, string);
	}
	puts("");
    puts("informe o CEP (sem pontuação): ");
    scanf("%zu", &buffer.cep);
    
    puts("");
    puts("informe o número do imóvel: (SN = 0)");
    scanf("%zu", &buffer.num);
    
    puts("");
    puts("esse imóvel está sendo vendido ou alugado? ");
    puts("1- vendido");
    puts("2- alugado");
    {
        int temp = Escolha(2);
        buffer.venda= temp == 1? true : false;
    }
    
    puts("");
    puts("informe o valor do imóvel: ");
    scanf("%lf", &buffer.valor);

	if(choice == 1){
		buffer.tipo= 1;
        puts("");
        puts("informe a quantidade de pavimentos do imóvel: ");
        scanf("%zu", &buffer.casa.pavimentos);
    
        puts("");
        puts("informe o número de quartos: ");
        scanf("%zu", &buffer.casa.quartos);
        
        puts("");
        puts("informe a área do terreno: ");
        scanf("%lf", &buffer.area);
        
        puts("informe a área construída: ");
        scanf("%lf", &buffer.casa.areaCons);
    
	}else if(choice == 2){
        buffer.tipo=2;
        puts("");
        puts("informe a área do imóvel: ");
        scanf("%lf", &buffer.area);
        
        puts("");
        puts("informe a quantidade de quartos: ");
        scanf("%zu", &buffer.Apartamento.quartos);
        
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
        scanf("%zu", &buffer.apartamento.andar);
        
        puts("");
        puts("informe o valor do condomínio: ");
        scanf("%lf", &buffer.apartamento.condominio);
        
        puts("")
        puts("informe o numero de vagas da garagem");
        scanf("%zu", &buffer.apartamento.vagasGaragem);

	}else{
        buffer.tipo=3;
        puts("");
        puts("informe a área do terreno: ");
        scanf("%lf", buffer.area);
	}

	return buffer;
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
