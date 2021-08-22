#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
	
	
	int q_words, i, j, k, n_words, n_text;
	char text[10000], aux1[10], aux2[10];
	
	char words[10000];
	char position [10000];
	int cont[10];
	
	for(i=0; i<10000; i++){
		text[i] = '\0';
		words[i] = '\0';
	}
	
	for(i=0; i<10; i++){
		aux1[i] = '\0';
	}
	
	printf("Digite o texto:\n");
	fflush(stdin);
	gets(text);
	
	printf("Digite o numero de palavras:\n");
	scanf("%i", &q_words);
	
	printf("Digite as %d palavras:\n", q_words);
	fflush(stdin);
	gets(words);
	
	n_words = strlen(words);
	n_text = strlen(text);
	
	i=0;
	while(text[i] != '\0'){ //convertendo valores entrados para minusculos
		text[i] = tolower(text[i]);
		i++;
	}
	
	i=0;
	while(words[i] != '\0'){ //convertendo valores entrados para minusculos
		words[i] = tolower(words[i]);
		i++;
	}
	
	for(k=0; k<10; k++){
		aux2[k] = '\0';
		aux1[k] = '\0';
	}

	words[n_words] = 32; //colocando um espaço no caractere posterior ao ultimo digitado para que a ultima falavra seje formada
	text[n_text] = 32; 
	printf("\n");
	for(i=0; i<n_words+1; i++){  //percorrer todos os caracteres da entrada das palavras e separa as palavras
	//na variavel auxiliar
		aux1[strlen(aux1)] = words[i];
		if(words[i] == 32){ //quando encontrar um espaço, e por que encontrou uma palavra e então já pode procurá-la no texto
			printf("%s: ", aux1);
				
			for(j=0; j<n_text+1; j++) { //começa percorrer texto para separar as palavras e depois verificá-las
				aux2[strlen(aux2)] = text[j];
				
				if(text[j] == 32){ //verifica que encontrou um espaço no texto e ja pode comparar a palavra achada anteriormente com a palavra no texto
					if(strcmp(aux1, aux2) == 0){ //verifica se as duas palavras são iguais
						printf("%d ", j);		
					}
					
					for(k=0; k<10; k++){
						aux2[k] = '\0';
					}
				}
			}
			printf("\n");
			for(k=0; k<10; k++){
				aux1[k] = '\0';
			}
		}	
	}
	system("PAUSE");
	return 0;
}


