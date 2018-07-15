#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int size;
	char numb[50];
};
typedef struct Stack stack;

stack* creat()
{
	stack* pilha = (stack*)malloc(sizeof(stack));
	pilha -> size = 0;
	return pilha;
}

void push(stack* pilha, char item)
{
	pilha -> numb[pilha -> size++] = item;
}

void pop(stack* pilha)
{
	if(pilha -> size)
	pilha -> size -= 1;
}

int main() 
{
	stack* parentes = creat();
	stack* cochetes = creat();
	char expressao[100];
	int tam, i;

	scanf("%s", expressao);
	tam = strlen(expressao);

	for(i = 0 ; i < tam ; i++)
	{
		if(expressao[i] == '(') push(parentes, expressao[i]);
		if(expressao[i] == '[') push(cochetes, expressao[i]);

		if(expressao[i] == ')') pop(parentes);
		if(expressao[i] == ']') pop(cochetes);
	}

	if(!parentes -> size && !cochetes -> size) puts("BALANCEADO");
	
	else puts("NAO BALANCEADO");

	return 0;
}