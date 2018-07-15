#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int size;
	int numb[500];
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
	int adiciona, numero, base, resto, inteiro, qt;
	char hexta[6] = "ABCDEF";
	int aux;
	scanf("%d", &qt);

	while(qt)
	{
		resto = 0;
		inteiro = 0;
		scanf("%d", &numero);
		scanf("%d", &base);
		while(numero)
		{
			inteiro = numero / base;
			resto = numero % base;
			push(pilha, resto);
			numero = inteiro;
		}
		while(pilha -> size)
		{
			aux = ver(pilha);
			if(base > 10)
			{
				if(aux >= 10 && aux <= 15)
				{
					printf("%c", hexta[aux-10]);
				}
				else printf("%d", aux);
				
			}
			else printf("%d", aux);
		}
		puts("");
		qt--;
		pilha -> size = 0;
	}

	return 0;
}
