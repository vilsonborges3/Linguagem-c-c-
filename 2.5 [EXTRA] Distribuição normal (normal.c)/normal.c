#include <stdio.h>
#include "stdlib.h"
#include <math.h>
#include <time.h>

void pseudo(double a, double b, double vet_pseldo[]);

int main() {
    srand(time(0));
    int i;
    double z[2], u1, u2;
    printf("Digite o numero de pontos da distribuicao: ");
    scanf("%d", &i);
    FILE *f, *g;
    g = fopen("arquivo.txt", "w");
    f = fopen("ark.m.txt", "w");
    fprintf(f, "x = [ ");
    fprintf(g, "y = [ ");
    for (; i > 0; i--) {
        u1 = rand() / (double) RAND_MAX;
        u2 = rand() / (double) RAND_MAX;
        pseudo(u1, u2, z);
        fprintf(f, "%lf ", z[0]);
        fprintf(g, "%lf ", z[1]);
        /*
         x = [ p1 p2 p3 p4];
         y = [p1 p2 p3 p4 ];
         plot(x,y);
         */
        //comando de cima gera graficos no matilab

    }
    fprintf(f, "];\n");
    fprintf(g, "];\nplot(x,y);");
    char vet[500];
    fclose(g);
    g = fopen("arquivo.txt", "r");
    while (!feof(g)) {
        fgets(vet, 500,g);
        fprintf(f, "%s", vet);
    }
    fclose(f);


    fclose(g);
   
	system("start ark.m.txt");

   
    return 0;
}

void pseudo(double a, double b, double vet_pseldo[]) {
    double resultimo = (cos(2 * M_PI * b));
    vet_pseldo[0] = (sqrt(-2 * log(a))) * (cos(2 * M_PI * b));
 //   printf("cos(%lf) =  %lf\n", 2 * M_PI * b, resultimo);
    vet_pseldo[1] = sqrt(-2 * log(a)) * (sin(2 * M_PI * b));
}


