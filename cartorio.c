#include <stdio.h> //bibl�oteca de comunica��o com o usu�rio
#include <stdlib.h> //bibl�oteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bibl�oteca de aloca��o de texto por regi�o
#include <string.h> //bibl�oteca respons�vel por cuidar das strings

//Registro de Usu�rio

int registro()
{
	//Cria��o dos vetores(strings) para REGISTRAR os dados do usu�rio
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Registro CPF:
	printf ("Digite o CPF a ser cadastrado: \n");
    scanf ("%s", cpf);
    
    strcpy (arquivo, cpf); // Respons�vel por copiar os valores da string 'cpf' e deixa-lo como elemento chave de busca para CONSULTA DE USU�RIO
	
	//Cria��o do arquivo para ARMAZENAR os dados coletados dos vetores(strings)
	FILE *file;
	file = fopen (arquivo, "w"); //Abre o arquivo para "w"(escrever - write)
    fprintf (file, "\nCPF: "); //Adicionado para CONSULTAR o CPF
    fprintf (file, "%s", cpf); //Salva o dado 'cpf' desntro de uma v�riavel
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
    fprintf (file, "%s", nome); //Salva o dado 'nome' dentro de uma v�riavel
    fclose (file);
    
    //Espa�o entre NOME e SOBRENOME
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, " ");
    fclose (file);
    
    //Registro SOBRENOME:
    printf ("Digite o sobrenome a ser cadastrado: \n");
    scanf ("%s", sobrenome);
    
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "%s", sobrenome); //Adicioando para consultar o SOBRENOME
    fclose (file);
    
    /*OBS: n�o possui 
	fprintf (file, "\nSobrenome: ");
	para fins est�ticos
	*/
	
	//Espa�o
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "\n");
    fclose (file);
    
    //Resgistro de CARGO:
    printf ("Digite o cargo designado: \n");
    scanf ("%s", cargo);
    
    file = fopen (arquivo, "a"); //Abre o arquivo para "a"(adicionar/atualizar)
    fprintf (file, "\nCargo: "); //Adicionado para CONSULTAR o CARGO
    fprintf (file,"%s", cargo); //Salva o dado 'cargo' dentro de uma v�riavel
    fclose (file);
    
    system ("pause");//Pausa o sistema e volta ao MENU
    
}

//Consulta do Usu�rio

int consulta()
{
	
	//Defini��o da l�nguagem
	setlocale (LC_ALL, "Portuguese"); 
	
	//Cria��o de vetores(strings) para LOCALIZAR no arquivo os dados j� REGISTRADOS
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
		//Ser� apresentada a seguinte mensagem:
		printf ("N�o foi poss�vel localizar o usu�rio! \n");
	}
	
	//Se n�o se a resposta dada for diferente de NULL(valor nulo):
	else if (file != NULL)
	{
		//Ser� apresnetada a seguinte mensagem 
		printf ("\nEssas s�o as informa��es do usu�rio: \n");
		
		//enquanto "fgets"(realiza a leitura) for diferente de NULL, ir� ler o arquivo
		while (fgets(conteudo, 200, file) != NULL) 
		{	
			//Leitura das v�riaveis registradas 
			printf ("%s", conteudo);
		}
		printf("\n\n");
	}
	
	//Se n�o houver dados na resposta dada:
	else
	{ 
	printf("CPF inserido n�o localizado");
	}
		
	system ("pause");
}

//Deletar Usu�rio

int deletar()
{
	//Cria��o do vetor 'cpf' para consultar no registro
	char cpf[40];
	
	//Salva a resposta dada para realizar a consulta da v�riavel 'cpf'
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
		//Apresenter� a seguinte mensagem:
		printf("O usu�rio j� n�o se encontra no sistema!\n");
		system("pause");
		
	}	
}

//MENU PRINCIPAL

int main()
{
	//Definindo as vari�veis inteiras
	int opcao = 0; 
	int laco = 1;
	
	//Repeti��o do menu
	for(laco = 1;laco == 1;) 
	{	
		system("cls");
		
		//Defini��o da l�guagem
		setlocale(LC_ALL, "Portuguese"); 
		
		//In�cio do menu
		printf("### Cart�rio da EBAC ###\n\n"); 
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); 
		//Final do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio 
	
		system("cls");
		
		switch(opcao)//In�cio do menu;
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
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
			
		} //Fim da sele��o
		
	}//Fim da repeti��o do menu

}
