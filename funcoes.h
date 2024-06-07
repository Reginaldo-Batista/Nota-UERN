#include <stdio.h>
#define nota_necessaria 7.0 //Caso a média final da UERN mude, só precisará alterar este valor manualmente.

void f_previsao_n1(float n1){//Função que calcula quanto o aluno deve obter na 2ª nota para não ficar de 4ª prova.
    float precisa_segunda = ((105 - 60 - n1 * 4) / 5.0);
    printf("\nDeve tirar pelo menos\nSegunda prova: %.2f\nTerceira prova: 10.00\n\n", precisa_segunda);
}

float f_nota_quarta(float n1, float n2, float n3){//Função que calcula qual nota o aluno precisará para a 4ª avaliação.
    return (12 - (n1 * 4 + n2 * 5 + n3 * 6) / 15.0);
}

void f_qnt_preciso(float n1, float n2){//Função que calcula quanto o aluno precisará na 3ª avaliação.
    float nota_2_necessaria = ((105.0 - n1 * 4 - n2 * 5) / 6.0);
    printf("\nPrecisara de: %.2f\n", nota_2_necessaria);
    if(nota_2_necessaria <= 10)
        printf("Da pra passar!\n\n");
    else{
        printf("Ficou de quarta prova!\n");
        printf("Se tirar 10.00 na terceira, precisara tirar na quarta prova: %.2f\n\n", f_nota_quarta(n1, n2, 10));
    }
}

void f_media_final(float n1, float n2, float n3){//Função que calcula a nota final aplicando os pesos 4, 5 e 6.
    float media = ((n1 * 4 + n2 * 5 + n3 * 6) / 15.0);
    float nota_necess_quarta = f_nota_quarta(n1, n2, n3);
    printf("\nSua nota final: %.2f\n", media);
    if(media >= nota_necessaria)
        printf("Passou! Parabens!\n\n");
    else if(nota_necess_quarta > 10){
        printf("Infelizmente esta reprovado! Tente novamente no proximo periodo.\n");
        printf("Voce precisaria tirar na quarta prova: %.2f\n\n", nota_necess_quarta);
    }
    else{
        printf("Ficou de quarta prova!\n");
        printf("Precisara tirar na quarta prova: %.2f\n\n", nota_necess_quarta);
    }
}