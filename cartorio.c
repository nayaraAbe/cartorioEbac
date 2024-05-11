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
	
	//Se a resposta dada for diferente de NULL
	else if(file != NULL)
	{
		//Será apresnetada a seguinte mensagem +
		printf ("\nEssas são as informações do usuário: \n");
		//enquanto "fgets"(realiza a leitura) for diferente de NULL, irá ler o arquivo
		while (fgets(conteudo, 200, file) != NULL) 
		{
			//Leitura das variáveis registradas 
			printf ("%s", conteudo);
		}
	}
	
	//Condição apresentada caso queira consultar mais de um usuário
	printf ("\n\nAinda deseja consultar um usuário? Se sim digite (S), se não (N): \n");
	
	getchar(); //Registra o caracter apresentado
	resp = getchar(); //Váriavel 'resp' recebe o caracter
		
	//Enquanto variável 'resp' receber valor igual a s/S	
	while (resp == 's' || resp == 'S')
	{
		//realiza a operação de consulta novamente
		printf ("\nDigite o CPF a ser consultado: \n");
		scanf ("%s", cpf);
		
		FILE *file;
		file = fopen (cpf, "r");
	
		if (file == NULL)
		{
			printf ("\nNão foi possível localizar o usuário! \n");
		}
	
		else if(file != NULL)
		{
			printf ("\nEssas são as informações do usuário: \n");
			while (fgets(conteudo, 200, file) != NULL) 
			{
				printf ("%s", conteudo);
			}
		}
				
		//Realiza a pergunta de consulta novamente e salva na variável 'resp'
		printf ("\n\nDeja consultar mais um usuário? Se sim digite (S), se não (N): \n");
		getchar();
		resp = getchar();
	}	
	
	//Se variável 'resp' receber valor igual a n/N
	if (resp == 'n' || resp == 'N')
	{
		//Será pausado o sistema e retornará ao MENU
		printf("\nRetorno ao Menu Principal. \n");
		system("pause");		
	}
	//Caso a variável 'resp' não receba valor correspondente
	else
	{
		//Será pausado o sistema e retornará ao MENU
		printf("\nOpção inválida! Retorno ao Menu Principal.\n"); 
		system("pause");
	}	
	printf ("\n\n");
	fclose (file); //Fechamento do arquivo
}

//Deletar Usuário

int deletar()
{
	//Criação do vetor 'cpf' para consultar no registro
	char cpf[40];
	
	//Salva a resposta dada para realizar a consulta da variável 'cpf'
	printf ("Digite o CPF a ser deletado: \n");
	scanf ("%s", cpf);
	
	//Abre o arquivo com "r"(read - leitura)
	FILE *file;
	file = fopen(cpf, "r"); 
	
	//Se arquivo for igual a NULL
	if (file == NULL) 
	{
		//Será dada a seguinte resposta e o sistema será pausado com retorno ao MENU
		printf ("Usuário não encontado no sistema!\n");
		system ("pause");
		return 0; //Retorno para tela inicial
	}
	
	fclose (file); //Fechando e confirmando a existecia do arquivo 
	
	//confimação do usuário para deletar os arquivos
	
	printf ("Deseja realmente deletar este usuário do sistema?\n");
	printf ("%s", cpf);
	printf ("\nDigite (S) para confimar ou (N) caso não deseje deletar o usuário: \n");
	
	getchar(); //Função responsável por salvar o caractere digitado 
	
	//Variável caractere criada
	char opcao;
	opcao = getchar(); //A variável 'pega' o valor escreito pelo usuário e o salva em 'getchar'(pegar o caracter)
	
	//se for digitado (s)
	if (opcao == 's' || opcao == 'S')
	{
		if (cpf != NULL) //confere se a remoção foi bem sucedida com a seguinte mensagem
		{
		remove(cpf);//remove o arquivo 'cpf'
		printf("\nO usuário foi deletado com sucesso!\n");
		printf("\nRetorno ao Menu Principal.\n");
		system("pause");
		}
	}
	
	//se for digitado (n)
	else if (opcao == 'n' || opcao == 'N')
	{
		printf ("\nVocê será retornado(a) ao Menu Principal. \n");
		system ("pause");
	}
	
	//Caso o cpf inserido não exista
	else
	{
		printf("Opção inválida");
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
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Saída do sistema\n\n");
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
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
				
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
			
		} //Fim da seleção
		
	}//Fim da repetição do menu

}
