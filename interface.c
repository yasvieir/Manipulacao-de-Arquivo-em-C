#include "interface.h"

void Menu(){
    printf("01. CADASTRAR FRUTAS: \n"
           "02. LISTAR FRUTAS: \n"
           "03. EDITAR FRUTAS: \n"
           "04. SAIR");
    int escolha;
    scanf("%i", &escolha);
    fflush(stdin);

    switch(escolha){
    case 1:
        limpatela();
        telacadastro();
        break;
    case 2:
        limpatela();
        //telalista();
        break;
    case 3:
        limpatela();
        //telaedita();
        break;
    case 4:
        limpatela();
        break;
    default :
        printf("\n\n Escolha uma das opções acima!!!\n");
        Sleep(1000);
    }
    limpatela();
}
void telacadastro(){
    char frutas[50];
    //chamando tipo de arquivo//criando um ponteiro
    FILE *arquivo;

    //verificar se existe//r=lendo o arquivo
    arquivo = fopen("frutas.txt","w");
    if(arquivo == NULL){
        printf("ERRO AO CRIAR O ARQUIVO");
        return 1;
    }
    printf("INSIRA O NOME DA FRUTA: ");
    fgets(frutas, sizeof(frutas),stdin);//ja sabe o tamanho dela
    fflush(stdin);
    frutas[strcspn(frutas,"\n")] = 0;//remove o \ da string//impede o armazenamento do
    fprintf(arquivo, "%s", frutas);
    fclose(arquivo);
    printf("CADASTRO REALIZADO COM SUCESSO %s", frutas);
    pausatela();
}
