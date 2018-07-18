#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 50

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
		//puts("STACK OVERFLOW");
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

stack* soma(stack* pilha, stack* p1, stack* p2, int *car)
{
	if(p1 -> tamanho > 0 || p2 -> tamanho > 0)
	{
		if(top(p1) == '1' && top(p2) == '1')
		{
			if(*car == 0)
			{
				push(pilha, '0');
				*car = 1;
			}
			else if(*car)
			{
				push(pilha, '1');
				*car = 1;
			}
		}

		else if(top(p1) == '0' && top(p2) == '0')
		{
			if(*car == 0)
			{
				push(pilha, '0');
				*car = 0;
			}
			else if(*car)
			{
				push(pilha, '1');
				*car = 0;
			}
		}
		else
		{
			if(*car == 0)
			{
				push(pilha, '1');
				*car = 0;
			}
			else if(*car)
			{
				push(pilha, '0');
				*car = 1;
			}	
		}
		pop(p1);
		pop(p2);
		return soma(pilha, p1, p2, &*car);	
	}
	return pilha;

}

void print(stack* pilha)
{
	int i;
	int a = pilha -> tamanho;

	for(i = a ; i >= 0 ; i--)
	{
		printf("%c", pilha -> itens[i]);
	}
	puts("");
}

int main()
{
	stack* pilha1 = start_stack();
	stack* pilha2 = start_stack();
	stack* pilhaResult = start_stack();

	int i, tam1, tam2;
	char sobra;
	char primeiro[SIZE], segundo[SIZE];
	int car = 0;

	scanf(" %s", primeiro);
	scanf(" %s", segundo);

	tam1 = strlen(primeiro);
	tam2 = strlen(segundo);

	for(i = tam1-1 ; i >= 0 ; i--)
	{
		push(pilha1, primeiro[i]);
	}
	for(i = tam2-1 ; i >= 0 ; i--)
	{
		push(pilha2, segundo[i]);	
	}
	pilhaResult = soma(pilhaResult, pilha1, pilha2, &car);
	if(car) push(pilhaResult, '1');
	print(pilhaResult);


	return 0;
}
