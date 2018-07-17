#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

struct Stack
{
	int tamanho;
	char itens[SIZE];
};
typedef struct Stack stack;

stack* start_stack()
{
	stack* pilha = (stack*) malloc(sizeof(stack));
	pilha -> tamanho = 0;
	return pilha;
}

void push(stack* pilha, char item)
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

char pop(stack* pilha)
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

char top(stack* pilha)
{
	return pilha -> itens[pilha -> tamanho-1];
}

stack* troca(stack* pilha)
{
	int array[SIZE];
	int i, j, n = 0;
	for(i = 0 ; i < pilha -> tamanho ; i++)
	{
		array[i] = pilha -> itens[i];
	}
	for(j = i-1 ; j >= 0 ; j--, n++)
	{
		pilha -> itens[n] = array[j];
	}
	return pilha;
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
	stack* pilhaOperadores = start_stack();
	stack* pilhaNumeros = start_stack();
	
	int escolha, qt, tam, i;
	char entrada[SIZE];

	scanf("%s", entrada);

	tam = strlen(entrada);
	/*// PÓSFIXA
	for(i = 0 ; i < tam ; i++)
	{
		if(entrada[i] == '+' || entrada[i] == '*')
		{
			if(entrada[i] == '+' && top(pilhaOperadores) == '*')
			{
				push(pilhaPrincipal, pop(pilhaOperadores));
			}
			push(pilhaOperadores, entrada[i]);
		}
		
		else
		{
			push(pilhaPrincipal, entrada[i]);	
		}
	}
	while(pilhaOperadores -> tamanho)
	{
		push(pilhaPrincipal, pop(pilhaOperadores));
	}
	print(pilhaPrincipal);*/
	

	return 0;
}
