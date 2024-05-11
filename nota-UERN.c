#include <stdio.h>

//Função que calcula a nota final aplicando os pesos 4, 5 e 6.
float media_final(float n1, float n2, float n3){ 
    return ((n1 * 4 + n2 * 5 + n3 * 6) / 15);
}

//Função que calcula quanto o aluno precisará na 3ª avaliação.
float qnt_preciso(float n1, float n2){
    return ((105.0 - n1 * 4 - n2 * 5) / 6.0);
}

int main(){

    float nota1, nota2, nota3, nota_necessaria;
    nota_necessaria = 7.0; //Caso a média final da UERN mude, só precisará alterar este valor manualmente.
    int escolha, repetidor = 1; //Repetidor recebe inicialmente 1, que equivale a 'verdadeiro', abrindo o loop.

    do{
        printf("[1] Qual minha nota final?\n");
        printf("[2] Quanto preciso na terceira nota?\n");
        printf("[3] Para sair do programa\n");
        printf("Sua escolha: ");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                printf("Nota prova 1: ");
                scanf("%f", &nota1);
                printf("Nota prova 2: ");
                scanf("%f", &nota2);
                printf("Nota prova 3: ");
                scanf("%f", &nota3);
                printf("Sua nota final: %.2f\n", media_final(nota1, nota2, nota3));
                (media_final(nota1, nota2, nota3) >= nota_necessaria) ? printf("Passou! Parabens!\n\n") : printf("Vish...\n\n");
            break;

            case 2:
                printf("Nota prova 1: ");
                scanf("%f", &nota1);
                printf("Nota prova 2: ");
                scanf("%f", &nota2);
                printf("Precisara de: %.2f\n", qnt_preciso(nota1, nota2));
                (qnt_preciso(nota1, nota2) <= 10.0) ? printf("Da pra passar se pah\n\n") : printf("NUMVAIDANAO\n\n");
            break;

            case 3:
                printf("Programa encerrado!\n\n");
                repetidor = 0; //Repetidor recebe 0, que equivale a 'falso' fechando o loop.
            break;

            default:
                printf("Comando invalido!\n\n");
        }
    }while(repetidor);

return 0;
}