#include <stdio.h>
#define nota_necessaria 7.0 //Caso a média final da UERN mude, só precisará alterar este valor manualmente.

//Função que calcula quanto o aluno deve obter na 2ª nota para não ficar de 4ª prova.
float f_previsao_n1(float n1){
    return ((105 - 60 - n1 * 4) / 5.0);
}

//Função que calcula quanto o aluno precisará na 3ª avaliação.
float f_qnt_preciso(float n1, float n2){
    return ((105.0 - n1 * 4 - n2 * 5) / 6.0);
}

//Função que calcula a nota final aplicando os pesos 4, 5 e 6.
float f_media_final(float n1, float n2, float n3){ 
    return ((n1 * 4 + n2 * 5 + n3 * 6) / 15.0);
}

//Função que calcula qual nota o aluno precisará para a 4ª avaliação.
float f_nota_quarta(float n1, float n2, float n3){
    return 12 - f_media_final(n1, n2, n3);
}

int main(){

    float nota1, nota2, nota3;
    float media, f_nota_quarta_prova, nota_2_necessaria;
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
                printf("\nDeve tirar pelo menos\nSegunda prova: %.2f\nTerceira prova: 10.00\n\n", f_previsao_n1(nota1));
            break;

            case 2:
                printf("\nNota prova 1: ");
                scanf("%f", &nota1);
                printf("Nota prova 2: ");
                scanf("%f", &nota2);
                nota_2_necessaria = f_qnt_preciso(nota1, nota2);
                printf("\nPrecisara de: %.2f\n", nota_2_necessaria);

                if(nota_2_necessaria <= 10)
                    printf("Da pra passar!\n\n");
                else{
                    printf("Ficou de quarta prova!\n");
                    f_nota_quarta_prova = f_nota_quarta(nota1, nota2, 10);
                    printf("Se tirar 10.00 na terceira, precisara tirar na quarta prova: %.2f\n\n", f_nota_quarta_prova);
                }
            break;

            case 3:
                printf("\nNota prova 1: ");
                scanf("%f", &nota1);
                printf("Nota prova 2: ");
                scanf("%f", &nota2);
                printf("Nota prova 3: ");
                scanf("%f", &nota3);
                media = f_media_final(nota1, nota2, nota3);
                f_nota_quarta_prova = f_nota_quarta(nota1, nota2, nota3);
                printf("\nSua nota final: %.2f\n", media);

                if(media >= nota_necessaria)
                    printf("Passou! Parabens!\n\n");
                else if(f_nota_quarta_prova > 10){
                    printf("Infelizmente esta reprovado! Tente novamente no proximo periodo.\n");
                    printf("Voce precisaria tirar na quarta prova: %.2f\n\n", f_nota_quarta_prova);
                }
                else{
                    printf("Ficou de quarta prova!\n");
                    printf("Precisara tirar na quarta prova: %.2f\n\n", f_nota_quarta_prova);
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