#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Eg_list.h"

void Menu1();
void Menu2();
void Menu3();

int main(){
    
    FILE* fp;

    system("clear");
    Initializer();
    
    ReadFile();
    
    while(1){

        menu:
        Menu1();

        switch (Escolha(7)){
            case 1:
                system("clear");
                puts("você deseja adicionar:\n"
                        "1- Casa\n"
                        "2- Apartamento\n"
                        "3- Terreno\n");
                switch(Escolha(3)){
                    case 1:
                        Insert(getInfos(1));
                        break;
                    case 2:
                        Insert(getInfos(2));
                        break;
                    case 3:
                        Insert(getInfos(3));
                        break;
                }
                break;
            case 2:
                PrintAll();
                break;
            case 3:
                system("clear");
                Menu2();
                switch (Escolha(6)){
                   case 1:
                   {
                        system("clear");
                        char string[50];
                        printf("digite o título a ser buscado: ");
                        fgets(string, 50, stdin);
                        RemoveEnter(string);
                        SearchForTitle(string);
                    } break;
                    case 2:
                    {
                        system("clear");
                        char string[50];
                        printf("digite o título a ser buscado: ");
                        fgets(string, 50, stdin);
                        RemoveEnter(string);
                        SearchForNeighbourhood(string);
                    }    
                        break;
                    case 3:
                    {
                        system("clear");
                        char string[50];
                        double var;
                        printf("digite o valor a ser procurado: "); 
                        scanf("%lf", &var);
                        puts("");
                        sprintf(string, "%.2lf", var);
                        RemoveEnter(string);
                        SearchForValue(string); 
                    } break;
                    case 4:
                        system("clear");
                        PrintStatus(true);
                    break;
                    case 5:
                        system("clear");
                        PrintStatus(false);
                    break;
                    case 6:
                        goto menu;
                    }
            break;
            
            case 4: 
            {
                system("clear"); 
                unsigned int input;
                puts("digite o número da entrada que você quer editar");
                scanf("%u%*c", &input);
                EditEntry(input);
                break;
            }
            
            case 5:
                system("clear");
                Menu3();
                switch(Escolha(3)){
                   
                    case 1:
                    {
                        system("clear");
                        char string[50];
                        PrintAll();
                        puts("");
                        puts("");
                        printf("digite o título a ser deletado: ");
                        fgets(string, 50, stdin);
                        RemoveEnter(string);
                        if( RemoveByTitle(string) ){
                             puts("entrada removida com sucesso!"); 
                        } else{
                             puts("não foi possível remover a entrada selecionada");
                        }
                        
                    } break;
                        
                    case 2:
                        {
                            unsigned int input;
                            system("clear");
                            PrintAll();
                            puts("");
                            puts("");
                            puts("escreva qual o número da entrada que você deseja remover: (nt: digitando 0, você volta ao menu)");
                            scanf("%u%*c", &input);
                            if(input == 0) break;
                            else {
                                if( RemoveByIndex(input) ){
                                    puts("entrada removida com sucesso!"); 
                                } else{
                                    puts("não foi possível remover a entrada selecionada");
                                }
                            }
                        }   break;
                    case 3:
                        goto menu;
                } break;
            case 6:
                SaveFile();
                system("clear");
                break;
            case 7:
            {
                char input;
                while(1){
                    system("clear");
                    puts("você tem certeza que deseja sair?(s/n)");
                    scanf("%c", &input);
                    if(input == 's' || input == 'S'){
                        SaveFile();
                        return 0;  
                    } else if(input == 'n' || input == 'N') break;
                }
            } break;
        }
	
    }

	return 0;
}

void Menu1(){

    puts("*--------------------------------------------------------------------------*");
    puts("");
	puts("\t\tSISTEMA DE REGISTRO DE IMÓVEIS V1.0\n");
	puts("");
	puts("");
	puts("");
	puts("Selecione a opção desejada:");
	puts("1- Cadastrar novo imóvel");
	puts("2- Ver imóveis registrados");
	puts("3- Busca e visualização personalizada");
    puts("4- Editar entrada");
    puts("5- Remover entrada");
    puts("6- Salvar");
	puts("7- Salvar e sair");
}

void Menu2(){

	puts("1- Busca de imóvel por título");
	puts("2- Busca de imóvel por bairro");
	puts("3- Busca de imóveis por valor(precisão de 1 real)");
	puts("4- Mostrar todos os imóveis disponíveis para venda");
	puts("5- Mostrar todos os imóveis disponíveis para aluguel");
	puts("6- Voltar");
}

void Menu3(){
    
    puts("1- Remover por título");
    puts("2- Remover por índice");
    puts("3- voltar");
}
