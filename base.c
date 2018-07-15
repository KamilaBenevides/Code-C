#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int size;
	int numb[50];
};
typedef struct Stack stack;

stack* creat()
{
	stack* pilha = (stack*)malloc(sizeof(stack));
	pilha -> size = 0;
	return pilha;
}

void push(stack* pilha, int item)
{
	pilha -> numb[pilha -> size++] = item;
}

int ver(stack* pilha)
{
	return pilha -> numb[--pilha -> size];
}

int main() 
{
	stack* pilha = creat();
	int adiciona, n, resto = 0, inteiro = 0;

	printf("ENTRE COM O NUMERO: ");
	scanf("%d", &n);

	while(n)
	{
		inteiro = n / 2;
		resto = n % 2;
		push(pilha, resto);
		n = inteiro;
	}
	while(pilha -> size)
	{
		printf("%d ", ver(pilha));
	}
	puts("");

	return 0;
}