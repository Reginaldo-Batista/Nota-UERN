#include "funcoes.h"

int main(){

    float nota1, nota2, nota3;
    int escolha, repetidor = 1; //Repetidor recebe inicialmente 1, que equivale a 'verdadeiro', abrindo o loop.

    do{
        printf("[1] Qual o minimo devo tirar na segunda nota?\n");  
        printf("[2] Quanto preciso na terceira nota?\n");
        printf("[3] Qual minha nota final?\n");
        printf("[4] Para sair do programa\n");
        printf("Sua escolha: ");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                printf("\nNota prova 1: ");
                scanf("%f", &nota1);
                f_previsao_n1(nota1);
            break;

            case 2:
                printf("\nNota prova 1: ");
                scanf("%f", &nota1);
                printf("Nota prova 2: ");
                scanf("%f", &nota2);
                f_qnt_preciso(nota1, nota2);
                
            break;

            case 3:
                printf("\nNota prova 1: ");
                scanf("%f", &nota1);
                printf("Nota prova 2: ");
                scanf("%f", &nota2);
                printf("Nota prova 3: ");
                scanf("%f", &nota3);
                f_media_final(nota1, nota2, nota3);
            break;

            case 4:
                printf("Programa encerrado!\n\n");
                repetidor = 0; //Repetidor recebe 0, que equivale a 'falso' fechando o loop.
            break;

            default:
                printf("Comando invalido!\n\n");
        }
    }while(repetidor);

return 0;
}
