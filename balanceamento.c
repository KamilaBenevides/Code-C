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
int top(stack* pilha)
{
	return pilha -> numb[pilha -> size-1];
}
int main() 
{
	stack* balanceia = creat();
	char expressao[100];
	int tam, i;

	scanf("%s", expressao);
	tam = strlen(expressao);

	for(i = 0 ; i < tam ; i++)
	{
		if(expressao[i] == '(') push(balanceia, expressao[i]);
		if(expressao[i] == '[') push(balanceia, expressao[i]);
		if(expressao[i] == '{') push(balanceia, expressao[i]);

		if(expressao[i] == ')' && top(balanceia) == '(') pop(balanceia);

		else if(expressao[i] == ')' && top(balanceia) != '(') push(balanceia, '0');

		if(expressao[i] == ']' && top(balanceia) == '[') pop(balanceia);

		else if(expressao[i] == ']' && top(balanceia) != '[') push(balanceia, '0');

		if(expressao[i] == '}' && top(balanceia) == '{') pop(balanceia);

		else if(expressao[i] == '}' && top(balanceia) != '{') push(balanceia, '0');
	}

	if(!balanceia -> size) puts("BALANCEADO");
	
	else puts("NAO BALANCEADO");

	return 0;
}
