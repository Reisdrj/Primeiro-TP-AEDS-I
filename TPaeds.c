#include <stdio.h>

void main() {
    int i = 0, op = 0, cr = 0, mcr = 0, mcralto = 0, codigo = 0, cond = 0;
    int dados[5][4] = {NULL};
    while(1){
        printf("\n\n------Menu de opções------"); 
        printf("\n1 - Vizualizar dados \n2 - Preencher Matriz \n3 - Verificar CR mais alto \n4 - Ver cursos \n5 - Sair do programa\n\n");
        printf("Opção desejada: ");
        scanf("%d", &op);
        if(op == 1){
            if(i == 0){
                printf("Dados não inseridos, a matriz está vazia!\n");
            }
            else{
                printf("\nMatricula--Curso--Sexo--CR\n");
                for(int  j = 0; j < 5; j++){
                    for(int k = 0; k < 4; k++){
                        if(k == 2){
                            if((dados[j][2]) == 1){
                                printf(" M ");
                            }
                            else if((dados[j][2]) == 2){
                                printf(" F ");
                            }
                        }
                        else{
                            printf(" %4d  ", dados[j][k]);
                        }
                    }
                    printf("\n");
                }
            }
        }
        if(op == 2){
            for(int j = 0; j < 5; j++){
                printf("---------------------------\n");
                printf("Insira a matícula: \n");
                scanf("%d", &dados[j][0]);

                printf("Insira o código do curso: \n");
                scanf("%d", &dados[j][1]);

                printf("Insira o sexo: \n1 - Masculino \n2 - Feminino\n");
                scanf("%d", &dados[j][2]);

                printf("Insira o CR (Coeficinte de Rendimento): \n");
                scanf("%d", &dados[j][3]);
                printf("---------------------------");
            }
            i++;
        }
        if(op == 3){
            printf("Insira o código do curso para saber o CR mais alto: \n");
            scanf("%d", &codigo);

            for(int j = 0; j < 5; j++){
                if(codigo == (dados[j][1])){
                    if((dados[j][2]) == 2){
                        if(j == 0){
                            mcr = cr = dados[j][3];
                            mcralto = dados[j][0];
                        }
                        else{
                            if((dados[j][3]) >= mcr){
                                mcr = dados[j][3];
                                mcralto = dados[j][0];
                            }
                        }
                    }
                }
            }

            printf("O CR mais alto é %d e pertence a %d", mcr, mcralto);
        }
        if(op == 4){
            printf("Cursos Lisados: \n");
            printf("\n%d\n", dados[0][1]); /*Imprime o primeiro código de curso*/
            for(int i = 1; i < 5; i++){
                int b = i - 1;
                for(int c = b; c >= 0; c--){    
                    if((dados[i][1]) == dados[c][1]){  /*Se houver um código igual ao que está sendo verificado, ele adiciona 1 na condição*/
                        cond++;
                    }    
                }
                if(cond == 0){         /*Se não houver nenhum código igual, a cond é zero e ele imprime o código do curso*/
                    printf("%d\n", dados[i][1]);
                }
                cond = 0;
            }
            printf("\n");
        }
        if(op == 5){
            break;
        }
    }
}
