#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 10

struct Stack
{
	int tamanho;
	int itens[SIZE];
};
typedef struct Stack stack;

stack* start_stack()
{
	stack* pilha = (stack*) malloc(sizeof(stack));
	pilha -> tamanho = 0;
	return pilha;
}

void push(stack* pilha, int item)
{
	if(pilha -> tamanho > SIZE)
	{
		puts("STACK OVERFLOW");
	}
	else
	{
		pilha -> itens[pilha -> tamanho++] = item;
	}
}

int pop(stack* pilha)
{
	if(pilha -> tamanho == 0)
	{
		puts("STACK EMPTY");
	}
	else
	{
		return pilha -> itens[--pilha -> tamanho];	
	}
}

int top(stack* pilha)
{
	return pilha -> itens[pilha -> tamanho-1];
}

void calcular(stack* pilha, int *i)
{
	if(pilha -> tamanho)
	{
		*i += pop(pilha) * pow(2, pilha -> tamanho);
		calcular(pilha, &*i);
	}
}

void print(stack* pilha)
{
	int i;

	for(i = 0 ; i < pilha -> tamanho ; i++)
	{
		printf("%c", pilha -> itens[i]);
	}
	puts("");
}

int main()
{
	stack* pilhaPrincipal = start_stack();
	
	int escolha, qt, tam, i, decimal = 0, a;
	char entrada[SIZE];
	printf("DIGITE O BINARIO: ");
	scanf("%s", entrada);

	tam = strlen(entrada);
	
	for(i = tam-1 ; i >= 0 ; i--)
	{
		a = entrada[i] - 48;
		push(pilhaPrincipal, a);
	}
	i = 0;
	calcular(pilhaPrincipal, &i);
	printf("DECIMAL:%d\n", i);


	return 0;
}
