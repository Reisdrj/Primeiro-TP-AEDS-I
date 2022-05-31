#include <stdio.h>

void main() {
    int i = 0, op = 0, cr = 0, mcr = 0, mcralto = 0, codigo = 0, cond = 0;
    char homem = 'M', mulher = 'F';
    int dados[20][4] = {};
    while(1){
        printf("\n\n------Menu de opções------"); 
        printf("\n1 - Vizualizar dados \n2 - Preencher Matriz \n3 - Verificar CR mais alto \n4 - Ver cursos \n5 - Sair do programa\n\n");
        printf("Opção desejada: ");
        scanf("%d", &op);
        if(op == 1){
            if(i == 0){
                printf("\nDados não inseridos, a matriz está vazia!\n");
            }
            else{
                printf("\n Matrícula---Curso--Sexo---CR\n");
                for(int  j = 0; j < 20; j++){
                    for(int k = 0; k < 4; k++){
                        if(k == 0){
                            printf(" %9d ", dados[j][0]); /*Alinhamento do código da matrícula, caso tenha 9 dígitos ou menos*/
                        }
                        if(k == 1) {
                            printf("   %4d", dados[j][1]);
                        }
                        else if(k == 2){     /*Para imprimir o sexo como M ou F*/
                            if((dados[j][2]) == 1){
                                printf("  %3c  ", homem);
                            }
                            else if((dados[j][2]) == 2){
                                printf("  %3c  ", mulher);
                            }
                        }
                        else if(k == 3){
                            printf("%4d", dados[j][3]); /*Alinhamento do código do curso, caso tenha 4 dígitos ou menos*/
                        }
                    }
                    printf("\n");
                }
            }
        }
        if(op == 2){
            for(int j = 0; j < 20; j++){
                printf("---------------------------\n");
                printf("Insira a matícula: \n");
                scanf("%d", &dados[j][0]);

                do{
                printf("\nInsira o código do curso: \n");
                scanf("%d", &dados[j][1]);
                }while((dados[j][1] / 10000) >= 1);  /*Condição para o código ter no máximo 4 dígitos*/

                do{
                printf("\nInsira o sexo: \n1 - Masculino \n2 - Feminino\n");
                scanf("%d", &dados[j][2]);
                }while((dados[j][2] > 2) || (dados[j][2] < 1)); 

                do{
                printf("\nInsira o CR (Coeficinte de Rendimento) em %%: \n");
                scanf("%d", &dados[j][3]);
                printf("---------------------------");
                }while((dados[j][3] > 100) || (dados[j][3] < 0)); /*CR inserido deve estar entre 0 e 100*/
            }
            i++;
        }
        if(op == 3){
            printf("Insira o código do curso para saber o CR mais alto: \n");
            scanf("%d", &codigo);
            if(i == 0){
                printf("Nenhum CR informado!");
            }
            else{
                for(int j = 0; j < 20; j++){
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
            }
            if(i != 0){
                printf("\nO CR mais alto é %d e pertence a %d", mcr, mcralto);
            }
        }
        if(op == 4){
            if(i == 0){
                printf("\nNenhum Curso Listado !");
            }
            else{
                printf("\n---------------------");
                printf("\nCursos Listados: \n");
                printf("\n%d\n", dados[0][1]); /*Imprime o primeiro código de curso*/
                for(int i = 1; i < 20; i++){
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
                printf("---------------------");
                printf("\n");
            }
        }
        if(op == 5){
            break;
        }
    }
}
