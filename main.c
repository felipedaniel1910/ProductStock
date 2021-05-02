// linha 47 - Verificacao de codigo repetido com defeito

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int x =0, t =1;
int y = 0;
FILE *arq;
char *conseguiuLer;
char linha[100];
int num_linha = 0;
int quant_pecas = 0;

struct cad_pecas {
	 char desc [20];
	 int cod;
	 float preco_C;
	 float preco_V;
	 int qnt;
} pecas [100];

void vender (){
	pecas[y].qnt = pecas[y].qnt - 1;
	printf("\nSua pe�a foi vendida com sucesso!!! ");
}


void cadastrar (){		// Fun��o respons�vel por cadastrar as pecas.
	
	arq = fopen ("database.txt.", "a");

	
	printf("\nDescrimina��o da pe�a: ");
	fflush(stdin);
	gets(pecas[x].desc);
   	printf("\nC�digo da pe�a: ");
	scanf("%d", &pecas[x].cod);
   	printf("\nValor de custo: ");
	scanf("%f", &pecas[x].preco_C);
	printf("\nValor de venda: ");
	scanf("%f", &pecas[x].preco_V);
	printf("\nQuantidade: \n");
	scanf("%d", &pecas[x].qnt);
	
	fputs(pecas[x].desc, arq);
	fputc('\n', arq);
	fprintf(arq, "%d", pecas[x].cod );
	fputc('\n', arq);
	fprintf(arq, "%f", pecas[x].preco_C );
	fputc('\n', arq);
	fprintf(arq, "%f", pecas[x].preco_V );
	fputc('\n', arq);
	fprintf(arq, "%d", pecas[x].qnt);
	fputc('\n', arq);
	
	
	fclose(arq);
	
	x++;
	
}

void consultar (){
	
	int codigo = 0, x = 0;
	
	printf("\nDigite o c�digo da pe�a: ");
	scanf("%d", &codigo);
	
	for (y=0; y<quant_pecas; y++){
		if (codigo == pecas[y].cod){
			printf("\nSua pe�a foi encontrada: \n\n");
			printf("\nDescrimina��o: %s", pecas[y].desc );
	   	   	printf("Pre�o de custo: %.2f", pecas[y].preco_C);
	   	   	printf("\nPre�o de venda: %.2f", pecas[y].preco_V);
			printf("\nQuantidade em estoque: %d\n\n", pecas[y].qnt);
			x = 1;
		}
	}
	if (x == 0 ){
		printf("\nC�gido de pe�a inexistente no sistema!!!");
	}
}

void recuperar (){
	
	arq = fopen ("database.txt.", "r");
	
	
	while (!feof(arq)){
		
		conseguiuLer = fgets(linha, 100, arq);
		
		if (linha != '\000'){
		
		if (conseguiuLer){
			
			switch(num_linha){
				
				case 0:
					strcpy(pecas[y].desc, linha);
					break;
				case 1:
					pecas[y].cod = atoi(linha);
					break;
				case 2:
					pecas[y].preco_C = atof(linha);
					break;
				case 3:
					pecas[y].preco_V = atof(linha);
					break;
				case 4:
					pecas[y].qnt = atoi(linha);
					break;	
			}
			
			num_linha++;		// Da um inclemento no numero da linha
			
			if (num_linha == 5){
				y ++;		// Faz com que seja recuperado os dados da proxima peca
				quant_pecas++; 		// Faz a contagem da quantidade de pe�as (numero de pecas menos 1)
				num_linha = 0;
				
			}
			
		}
		}
			
	}
	

		fclose(arq);
					  
}

int main (){
	
	setlocale(LC_ALL,"Portuguese");	
	int escolha = 0;
	
	do {		// Responsavel pela repeticao do MENU, possibilitanto assim fazer varias a��es
		system("pause");
		system("cls");
		printf("****MENU****\n");  		// Apresenta o MENU do sistema
		printf("\n1- Cadastrar pe�a ");
		printf("\n2- Consultar pe�a ");
		printf("\n3- Vender pe�a ");
		printf("\n4- Sair ");
		scanf("%d", &escolha);
		
		switch (escolha){
			case 1: 		// Cadastro das pe�as
					   	   
	   			cadastrar ();
	   			break;
		   	   
   	 	 	 case 2:
   	 	 	 	
   	 	 	 	recuperar();
   	 	 	 	consultar ();
	 	 	 	break;
			   
			 case 3:
  			 	recuperar ();
				consultar();
				vender();
				 break;	
			   
			 case 4:
			   	exit(1);
				break;		  
		}
		
	} while (1);
}
	

