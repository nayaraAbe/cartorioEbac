#include <stdio.h> //biblíoteca de comunicação com o usuário
#include <stdlib.h> //biblíoteca de alocação de espaço em memória
#include <locale.h> //biblíoteca de alocação de texto por região
#include <string.h> //biblíoteca responsável por cuidar das strings

//Registro de Usuário

int registro()
{
	//Criação dos vetores(strings) para REGISTRAR os dados do usuário
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Registro CPF:
	printf ("Digite o CPF a ser cadastrado: \n");
    scanf ("%s", cpf);
    
    strcpy (arquivo, cpf); // Responsável por copiar os valores da string 'cpf' e deixa-lo como elemento chave de busca para CONSULTA DE USUÁRIO
	
	//Criação do arquivo para ARMAZENAR os dados coletados dos vetores(strings)
	FILE *file;
	file = fopen (arquivo, "w"); //Abre o arquivo para "w"(escrever - write)
    fprintf (file, "\nCPF: "); //Adicionado para CONSULTAR o CPF
    fprintf (file, "%s", cpf); //Salva o dado 'cpf' desntro de uma váriavel
    fclose (file); 
	//Fecha o arquivo
	
    //Quebra de linha
    file = fopen (arquivo, "a");//Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "\n");
    fclose (file);
    
    
    //Registro NOME:
    printf ("Digite o nome a ser cadastrado: \n");
    scanf ("%s", nome);
    
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "\nNome: "); //Adicionado para CONSULTAR o NOME
    fprintf (file, "%s", nome); //Salva o dado 'nome' dentro de uma váriavel
    fclose (file);
    
    //Espaço entre NOME e SOBRENOME
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, " ");
    fclose (file);
    
    //Registro SOBRENOME:
    printf ("Digite o sobrenome a ser cadastrado: \n");
    scanf ("%s", sobrenome);
    
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "%s", sobrenome); //Adicioando para consultar o SOBRENOME
    fclose (file);
    
    /*OBS: não possui 
	fprintf (file, "\nSobrenome: ");
	para fins estéticos
	*/
	
	//Espaço
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "\n");
    fclose (file);
    
    //Resgistro de CARGO:
    printf ("Digite o cargo designado: \n");
    scanf ("%s", cargo);
    
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "\nCargo: "); //Adicionado para CONSULTAR o CARGO
    fprintf (file,"%s", cargo); //Salva o dado 'cargo' dentro de uma váriavel
    fclose (file);
    
    system ("pause");//Pausa o sistema e volta ao MENU
    
}

//Consulta do Usuário

int consulta()
{
	
	//Definição da línguagem
	setlocale (LC_ALL, "Portuguese"); 
	
	//Criação de vetores(strings) para LOCALIZAR no arquivo os dados já REGISTRADOS
	char cpf[40];
	char conteudo[200];
	char resp;
	
	//Salva a resposta dada, para realizar a consulta 'cpf'
	printf ("Digite o CPF a ser consultado: \n");
	scanf ("%s", cpf);
	
	//Abertura do arquivo com "r"(write - escreva)
	FILE *file;
	file = fopen (cpf, "r");
	
	//Se a resposta dada for igual a NULL(valor nulo):
	if (file == NULL)
	{	
		//Será apresentada a seguinte mensagem:
		printf ("Não foi possível localizar o usuário! \n");
	}
	
	//Se não se a resposta dada for diferente de NULL(valor nulo):
	else if (file != NULL)
	{
		//Será apresnetada a seguinte mensagem 
		printf ("\nEssas são as informações do usuário: \n");
		
		//enquanto "fgets"(realiza a leitura) for diferente de NULL, irá ler o arquivo
		while (fgets(conteudo, 200, file) != NULL) 
		{	
			//Leitura das váriaveis registradas 
			printf ("%s", conteudo);
		}
		printf("\n\n");
	}
	
	//Se não houver dados na resposta dada:
	else
	{ 
	printf("CPF inserido não localizado");
	}
		
	system ("pause");
}

//Deletar Usuário

int deletar()
{
	//Criação do vetor 'cpf' para consultar no registro
	char cpf[40];
	
	//Salva a resposta dada para realizar a consulta da váriavel 'cpf'
	printf ("Digite o CPF a ser deletado: \n");
	scanf ("%s", cpf);
	
	//remove o CPF
	remove(cpf);
	
	//Abre o arquivo com "r"(read - leitura)
	FILE *file;
	file = fopen(cpf, "r"); 
	
	//Se o arquivo for igual a NULL:
	if (file == NULL)
	{
		//Apresenterá a seguinte mensagem:
		printf("O usuário já não se encontra no sistema!\n");
		system("pause");
		
	}	
}

//MENU PRINCIPAL

int main()
{
	//Definindo as variáveis inteiras
	int opcao = 0; 
	int laco = 1;
	
	//Repetição do menu
	for(laco = 1;laco == 1;) 
	{	
		system("cls");
		
		//Definição da líguagem
		setlocale(LC_ALL, "Portuguese"); 
		
		//Início do menu
		printf("### Cartório da EBAC ###\n\n"); 
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); 
		//Final do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário 
	
		system("cls");
		
		switch(opcao)//Início do menu;
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
				
			case 3:	
			deletar();
			break;
				
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
			
		} //Fim da seleção
		
	}//Fim da repetição do menu

}
