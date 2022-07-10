#include <stdio.h>
#include <string.h>
#define MAX 12000
struct carro
{
	char marca[16];
	int ano;
	char cor[11];
	float preco;
	char placa[9];
};
struct tData
{
	int dia;
	int mes;
	int anoano;
};
/*
Objetivo:gravar as informações em um arquivo texto
Parâmetro:struct carro vetcar[], int i, struct tData data[], int escolha
Retorno: void
*/
void gravarf(struct carro vetcar[], int i, struct tData data[], int escolha)
{
	FILE *carros;
	carros = fopen("carros.txt", "a");
	fprintf(carros, "Relatorio do item %d\n", escolha);
	fprintf(carros, "Carro: %d\n", i + 1);
	fprintf(carros, "Marca: %s\n", vetcar[i].marca);
	fprintf(carros, "Ano: %d\n", vetcar[i].ano);
	fprintf(carros, "Cor: %s\n", vetcar[i].cor);
	fprintf(carros, "Preco: %f\n", vetcar[i].preco);
	fprintf(carros, "Placa: %s\n", vetcar[i].placa);
	fprintf(carros, "Data: %d %d %d\n", data[i].dia, data[i].mes, data[i].anoano);
	fclose(carros);
}
/*
Objetivo:gravar as informações em um arquivo bin
Parâmetro:struct carro vetcar[], int i, struct tData data[]
Retorno:void
*/


void gravarbinf(struct carro vetcar[], int i, struct tData data[])
{
	int j;
	FILE *carros;
	carros = fopen("carros.bin", "wb");
	fwrite(&i, sizeof(int ), 1, carros);
	for(j = 0; j < i + 1; j++)
	{
		fwrite(&vetcar[j], sizeof(struct carro), 1, carros);
		fwrite(&data[j], sizeof(struct tData), 1, carros);
	}
	fclose(carros);
}
/*
Objetivo:gravar no vetor as informações do carro
Parâmetro:struct carro vetcar[MAX], int i, struct tData data[MAX]
Retorno:void
*/
void option1(struct carro vetcar[MAX], int i, struct tData data[MAX])
{
	printf("Carro %d\n", i + 1);
	printf("Qual a marca do carro? ");
	scanf("%s", vetcar[i].marca);
	printf("Qual o ano?");
	scanf("%d", &vetcar[i].ano);
	printf("Qual a cor do carro? ");
	scanf("%s", vetcar[i].cor);
	printf("Qual o preco? ");
	scanf("%f", &vetcar[i].preco);
	printf("Qual a placa?");
	scanf("%s", vetcar[i].placa);
	printf("Qual a data de aquisição do veiculo(Em dd mm aa:)");
	scanf("%d %d %d", &data[i].dia, &data[i].mes, &data[i].anoano);
	printf("\n");

}
/*
Objetivo:Localizar um carro atraves da placa
Parâmetro:struct carro vetcar[MAX],int i, struct tData data[MAX]
Retorno:void
*/
void option2(struct carro vetcar[MAX], int i, struct tData data[MAX])
{
	int j;
	char placa[123];
	printf("Qual a placa quer utilizar? ");
	scanf("%s", placa);
	for(j = 0; j < i; j++)
	{
		if(strcmp(placa, vetcar[j].placa) == 0)
		{
			printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\nData de aquisição: %d/%d/%d\n", vetcar[j].marca, vetcar[j].ano, vetcar[j].cor, vetcar[j].preco, data[i].dia, data[i].mes, data[i].anoano);
		}
		else
		{
			printf("Nao existe carro com essa placa");
		}
	}
}
/*
Objetivo:Retirar um conjunto de informações dos vetores atraves de uma sobreposição de valores.
Parâmetro:struct carro vetcar[MAX], int i, struct tData data[MAX]
Retorno:void
*/
void option3(struct carro vetcar[MAX], int i, struct tData data[MAX])
{
	int escolha;
	printf("Qual carro deseja remover?");
	scanf("%d", &escolha);
	for(; escolha - 1 < i; escolha++)
	{
		vetcar[escolha - 1].ano = vetcar[escolha].ano;
		vetcar[escolha - 1].preco = vetcar[escolha].preco;
		strcpy( vetcar[escolha - 1].placa, vetcar[escolha].placa);
		strcpy( vetcar[escolha - 1].marca, vetcar[escolha].marca);
		strcpy( vetcar[escolha - 1].cor, vetcar[escolha].cor);
		data[escolha - 1].dia = data[escolha].dia;
		data[escolha - 1].mes = data[escolha].mes;
		data[escolha - 1].anoano = data[escolha].anoano;

	}
}
/*
Objetivo:Mostra relatorios na tela a parti de como o usuario desejar que seja feito o relatorio alem de gravar em um arquivo texto o relatorio se assim desejado pelo usuario
Parâmetro:struct carro vetcar[MAX], int i, struct tData data[MAX]
Retorno:void
*/
void option4(struct carro vetcar[MAX], int i, struct tData data[MAX])
{
	int escolha2;
	int escolha, j;
	float preco;
	int ano;
	char marca[20100];
	int x = 1;
	while(x == 1)
	{
		printf("1 - Listar carros\n2 - Listar carros por limite de preco\n3 - Listar carros por limite de ano\n4 - Listar carros de uma marca\n5 - Listar carros de marca e ano\n0 - Sair\n");
		scanf("%d", &escolha);
		switch(escolha)
		{
		case 1:
			printf("CARROS CADASTRADOS: \n");
			for(j = 0; j < i; j++)
			{
				printf("Carro %d\n", i);
				printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\nData de aquisição: %d/%d/%d\n", vetcar[j].marca, vetcar[j].ano, vetcar[j].cor, vetcar[j].preco, data[j].dia, data[j].mes, data[j].anoano);
				printf("\n");
				printf("Deseja guardar o relatorio em texto?\n1 - Sim\n2 - Nao\n");
				scanf("%d", &escolha2);
				if(escolha2 == 1)
				{
					gravarf(vetcar, j, data, escolha);
				}
			}
			break;

		case 2:
			printf("Qual preço quer utilizar? ");
			scanf("%f", &preco);
			for(j = 0; j < i; j++)
			{
				if(preco >= vetcar[i].preco)
				{
					printf("Carro %d\n", i);
					printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\nData de aquisição: %d/%d/%d\n", vetcar[j].marca, vetcar[j].ano, vetcar[j].cor, vetcar[j].preco, data[j].dia, data[j].mes, data[j].anoano);
					printf("\n");
					printf("Deseja guardar o relatorio em texto?\n1 - Sim\n2 - Nao\n");
					scanf("%d", &escolha2);
					if(escolha2 == 1)
					{
						gravarf(vetcar, j, data, escolha);
					}
				}
			}
			break;

		case 3:
			printf("Qual ano quer utilizar? ");
			scanf("%d", &ano);
			for(j = 0; j < i; j++)
			{
				if(ano >= vetcar[i].ano)
				{
					printf("Carro %d\n", i);
					printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\nData de aquisição: %d/%d/%d\n", vetcar[j].marca, vetcar[j].ano, vetcar[j].cor, vetcar[j].preco, data[j].dia, data[j].mes, data[j].anoano);
					printf("\n");
					printf("Deseja guardar o relatorio em texto?\n1 - Sim\n2 - Nao\n");
					scanf("%d", &escolha2);
					if(escolha2 == 1)
					{
						gravarf(vetcar, j, data, escolha);
					}
				}
			}
			break;

		case 4:
			printf("Qual marca quer utilizar? ");
			scanf("%s", marca);
			for(j = 0; j < i; j++)
			{
				if(strcmp(marca, vetcar[i].marca) == 0)
				{
					printf("Carro %d\n", i);
					printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\nData de aquisição: %d/%d/%d\n", vetcar[j].marca, vetcar[j].ano, vetcar[j].cor, vetcar[j].preco, data[j].dia, data[j].mes, data[j].anoano);
					printf("\n");
					printf("Deseja guardar o relatorio em texto?\n1 - Sim\n2 - Nao\n");
					scanf("%d", &escolha2);
					if(escolha2 == 1)
					{
						gravarf(vetcar, j, data, escolha);
					}
				}
			}
			break;
		case 5:
			printf("Qual marca quer utilizar? ");
			scanf("%s", marca);
			printf("Qual ano quer utilizar? ");
			scanf("%d", &ano);
			for(j = 0; j < i; j++)
			{
				if(strcmp(marca, vetcar[i].marca) == 0 && ano == vetcar[i].ano)
				{
					printf("Carro %d\n", i);
					printf("Marca: %s\nAno: %d\nCor: %s\nPreco: %f\nData de aquisição: %d/%d/%d\n", vetcar[j].marca, vetcar[j].ano, vetcar[j].cor, vetcar[j].preco, data[j].dia, data[j].mes, data[j].anoano);
					printf("\n");
					printf("Deseja guardar o relatorio em texto?\n1 - Sim\n2 - Nao\n");
					scanf("%d", &escolha2);
					if(escolha2 == 1)
					{
						gravarf(vetcar, j, data, escolha);
					}

				}
			}

		default:
			x = 0;
			break;
		}
	}
}
int main()
{
	int escolha, i, j;
	int carroslidos;
	struct carro vetcar[MAX];
	struct tData data[MAX];
	FILE *carros;
	carros = fopen("carros.bin", "rb");
	if (carros)
	{
		carroslidos = fread(&i, sizeof(int ), 1, carros);
		for(j = 0; j < i; j++)
		{
			fread(&vetcar[j], sizeof(vetcar[j]), 1, carros);
			fread(&data[j], sizeof(data[j]), 1, carros);
		}
		printf("Aquivos lidos\n");
	}
	else
	{
		printf ("Arquivo \".bin\" nao existente\n");
	}
	fclose(carros);
	while(1)
	{
		printf("MENU\n1 - Cadartrar carro\n2 - Localizar carro\n3 - Remover carro\n4 - Relatorios\n0 - Sair\n");
		scanf("%d", &escolha);
		switch(escolha)
		{
		case 1:
			printf("OPCAO 1 DO MENU\n");
			option1(vetcar, i, data);
			i++;
			break;
		case 2:
			printf("OPCAO 2 DO MENU\n");
			option2(vetcar, i, data);
			break;
		case 3:
			printf("OPCAO 3 DO MENU\n");
			option3(vetcar, i, data);
			break;
		case 4:
			printf("OPCAO 4 DO MENU\n");
			option4(vetcar, i, data);
			break;
		default:
			gravarbinf(vetcar, i, data);
			return 0;
		}
	}
	return 0;
}
