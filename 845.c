#include <stdio.h>
#include <stdlib.h>

void hordena(int *array, int tam)
{
	int i, j, key;
	for (i = 0; i < tam; i++)
	{
		key = array[i];
		j = i - 1;

		while( (j >= 0) && (array[j] > key) )
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
}
int busca(int *array,int tamanho,int elemento,int inicio,int final,int meio)
{	
	int i, soma = 0;
	for(i = meio ; i < final ; i++)
	{
		soma += array[meio+1] - array[meio];
	}
	printf("soma:%d\n", soma);
	if(soma == elemento)
	{
		return meio;
	}
	else if(soma < elemento)
	{
		return busca(array, tamanho, elemento, inicio, meio, (meio/2)+1);
	}
	else if(soma > elemento)
	{
		return busca(array, tamanho, elemento, meio, final, (final+meio)/2);
	}

	else return -1;
}

int main() 
{
	int qt_arvores, madeira, i;
	int arvores[1000000];
	
	scanf("%d %d", &qt_arvores, &madeira);

	for(i = 0 ; i < qt_arvores ; i++)
	{
		scanf("%d", &arvores[i]);
	}
	hordena(arvores, qt_arvores);
	
	printf("%d\n", busca(arvores, qt_arvores, madeira, 0, qt_arvores, (qt_arvores/2)));

	return 0;
}