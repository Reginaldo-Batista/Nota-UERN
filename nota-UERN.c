#include <stdio.h>

//Função que calcula quanto o aluno deve obter na 2ª nota para não ficar de 4ª prova.
float previsao_n1(float n1){
    return ((105 - 60 - n1 * 4) / 5.0);
}

//Função que calcula quanto o aluno precisará na 3ª avaliação.
float qnt_preciso(float n1, float n2){
    return ((105.0 - n1 * 4 - n2 * 5) / 6.0);
}

//Função que calcula a nota final aplicando os pesos 4, 5 e 6.
float media_final(float n1, float n2, float n3){ 
    return ((n1 * 4 + n2 * 5 + n3 * 6) / 15.0);
}

//Função que calcula qual nota o aluno precisará para a 4ª avaliação.
float nota_quarta(float n1, float n2, float n3){
    return 12 - media_final(n1, n2, n3);
}

int main(){

    float nota1, nota2, nota3, nota_necessaria;
    nota_necessaria = 7.0; //Caso a média final da UERN mude, só precisará alterar este valor manualmente.
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
                printf("Deve tirar pelo menos\nSegunda prova: %.2f\nTerceira prova: 10.00\n\n", previsao_n1(nota1));
            break;

            case 2:
                printf("\nNota prova 1: ");
                scanf("%f", &nota1);
                printf("Nota prova 2: ");
                scanf("%f", &nota2);
                printf("Precisara de: %.2f\n", qnt_preciso(nota1, nota2));

                if(qnt_preciso(nota1, nota2) <= 10)
                    printf("Da pra passar!\n\n");
                else{
                    printf("Ficou de quarta prova!\n");
                    printf("Se tirar 10.00 na terceira, precisara tirar na quarta prova: %.2f\n\n", nota_quarta(nota1, nota2, 10));
                }
            break;

            case 3:
                printf("\nNota prova 1: ");
                scanf("%f", &nota1);
                printf("Nota prova 2: ");
                scanf("%f", &nota2);
                printf("Nota prova 3: ");
                scanf("%f", &nota3);
                printf("\nSua nota final: %.2f\n", media_final(nota1, nota2, nota3));

                if(media_final(nota1, nota2, nota3) >= nota_necessaria)
                    printf("Passou! Parabens!\n\n");
                else if(nota_quarta(nota1, nota2, nota3) > 10){
                    printf("Infelizmente esta reprovado! Tente novamente no proximo periodo.\n");
                    printf("Voce precisaria tirar na quarta prova: %.2f\n\n", nota_quarta(nota1, nota2, nota3));
                }
                else{
                    printf("Ficou de quarta prova!\n");
                    printf("Precisara tirar na quarta prova: %.2f\n\n", nota_quarta(nota1, nota2, nota3));
                }
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