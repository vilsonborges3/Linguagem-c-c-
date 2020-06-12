//vilson borges 11821EEL001
#include <stdio.h>

int main() {
    unsigned int var = 0xFACA8421; //numero muito grande para se armazenar em int com 4 bytes
    unsigned int *ponteiro;
    ponteiro = &var;
    float aux;
    aux = *ponteiro;
    printf("\nEndereco da variavel: %i, valor da variavel em decimal: %.f",ponteiro,aux);
    unsigned char *pt = (unsigned char*)&var; 
    int i;
    printf("\nO valores armazenados em cada byte sao:");
    for(i=0; i<4; i++)
    printf("\n%d",*(pt+i));

    return 0;
}
