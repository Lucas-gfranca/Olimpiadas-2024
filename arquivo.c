#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<string.h>

//novo comentario

typedef struct elemento{
    int id;
    char nome[100];
    int dia;
    int mes;
    int ano;
    float altura;
    int Num_alojamento;
    int idade;
    char modalidade[100];
    char genero[100];
    char nacionalidade[100];
    char paisnatal[100];
    struct elemento *prox;
}Elemento;

Elemento* listaGeral; //lista geral de itens

//função para criar a lista: retorna uma lista vazia
Elemento* criar_lista(void){
    return NULL;
}

//Inserção no ínicio da lista
Elemento* inserir_no(Elemento* lista, int id, char nome[], float altura,int Num_alojamento, char modalidade[], char genero[], char nacionalidade[], char paisnatal[], int idade, int dia, int mes, int ano){
    Elemento * no = (Elemento*)malloc(sizeof(Elemento));
    no -> id = id;
    strcpy(no -> nome, nome);
    strcpy(no -> modalidade, modalidade);
    strcpy(no -> genero, genero);
    strcpy(no -> nacionalidade, nacionalidade);
    strcpy(no -> paisnatal, paisnatal);
    no ->dia = dia;
    no ->mes = mes;
    no ->ano = ano;
    no -> idade = idade;
    no -> altura = altura;
    no -> Num_alojamento = Num_alojamento;
    no -> prox = lista;
    return no;
}

void imprimir_lista(Elemento *lista){
    Elemento *p;//declarar ponteiro auxiliar p

    for(p = lista; p != NULL; p = p -> prox){
        printf("\nId: %d\n", p->id);
        printf("Nome: %s", p->nome);
        printf("Altura: %.2f\n", p->altura);
        printf("Idade: %d\n", p->idade);
        printf("Data de nascimento: %d %d %d\n", p->dia, p->mes, p->ano);
        printf("Modalidade: %s", p->modalidade);
        printf("Número do alojamento: %d\n", p->Num_alojamento);
        printf("Genêro: %s", p->genero);
        printf("Nacionalidade: %s", p->nacionalidade);
        printf("País Natal: %s", p->paisnatal);


    }
}

int verificar_lista_vazia(Elemento *lista){
    if(lista == NULL){
        return 1;//retorna 1 se vazia e 0 senão
    }else{
        return 0;
    }
}

int novo_id(Elemento *lista){
    Elemento *p;//declarar ponteiro auxiliar p
    int maxId=0;
    for(p = lista; p != NULL; p = p -> prox){
        if(maxId < p->id)
            maxId = p->id;
    }
    return maxId;
}

int tamanho_lista(Elemento *lista){
    int i=0;
    Elemento *p;

    for(p = lista; p != NULL; p = p -> prox){
        i++;
    }
    return i;
}

void deleta_no(Elemento **primeiro_no, int id)
{
    Elemento* temp = *primeiro_no, *anterior;

    if (temp != NULL && temp->id == id)
    {
        *primeiro_no = temp->prox;
        free(temp);
        return;
    }

    while (temp != NULL && temp->id != id)
    {
        anterior = temp;
        temp = temp->prox;
    }

    if (temp == NULL) return;

    anterior->prox = temp->prox;

    free(temp);

    return;
}
//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------TELA LOGIN----------------------------------------------------------
void login_tela(){

    //DECLARAÇÃO DE VARIÁVEIS
  char Login [30];
  char Senha [30];
  char RegLogin [30];
  char RegSenha [30];
  char Nome [40];
  char Confirma [1];

  // REGISTRO DE UM USUÁRIO
    printf("\n\t\t\t\t=================================");
    printf("\n\t\t\t\t====== REGISTRO DE USUÁRIO ======");
    printf("\n\t\t\t\t=================================");

    printf("\n\n\t\t\t\t=================================");
    printf("\n\t\t\t\t=== PREENCHA TODOS OS CAMPOS ====");
    printf("\n\t\t\t\t=================================");

  // ENTRADA DAS INFORMAÇÕES DIGITADAS PELO USUÁRIO
    printf("\n\n\t\t\t\tPrimeiro Nome: ");
      scanf("%s", Nome);

    printf("\n\n\t\t\t\tLogin: ");
      scanf("%s", RegLogin);

    printf("\n\n\t\t\t\tSenha: ");
      scanf("%s", RegSenha);

  //FINAL DO CADASTRO DAS INFORMAÇÕES
   system("cls");
    printf("\n\n\t\t\t\t====== USUÁRIO CADASTRADO ======");

  system("cls"); // LIMPAR A TELA PARA A PÁGINA DE LOGIN

  // TELA DE LOGIN COM AS INFORMAÇÕES REGISTRADAS
    printf("\n\t\t\t\t=================================");
    printf("\n\t\t\t\t========= TELA DE LOGIN =========");
    printf("\n\t\t\t\t=================================");

    printf("\n\n\t\t\t\t=================================");
    printf("\n\t\t\t\t=== PREENCHA TODOS OS CAMPOS ====");
    printf("\n\t\t\t\t=================================");

    printf("\n\n\t\t\t\tLogin: ");
      scanf("%s", Login);

    printf("\n\t\t\t\tSenha: ");
      scanf("%s", Senha);

  // COMPARAÇÃO DO LOGIN E SENHA DIGITADOS COM OS REGISTRADOS NO COMEÇO
  while((strcmp (Login, RegLogin) != 0) || (strcmp(Senha,RegSenha) != 0))
  {
  //SE FOREM DIFERENTES ELE VOLTA PARA A PARTE DE LOGIN
    printf("\n\n\t\t\t\t====== LOGIN E/OU SENHA INCORRETOS ======\n\n");

  system("pause");
  system("cls");

    printf("\n\t\t\t\t=================================");
    printf("\n\t\t\t\t========= TELA DE LOGIN =========");
    printf("\n\t\t\t\t=================================");

    printf("\n\n\t\t\t\t=================================");
    printf("\n\t\t\t\t=== PREENCHA TODOS OS CAMPOS ====");
    printf("\n\t\t\t\t=================================");

    printf("\n\n\t\t\t\t======== TENTE NOVAMENTE ========");

    printf("\n\n\t\t\t\tLogin: ");
      scanf("%s", Login);

    printf("\n\t\t\t\tSenha: ");
      scanf("%s", Senha);
  }
  // SE OS DADOS FOREM IGUAIS ELE LIMPA A TELA PARA A PRÓXIMA PARTE
  system("cls");

  //MENSAGEM DE BOAS VINDAS USANDO O NOME REGISTRADO NO COMEÇO
    printf("\t\t\t\t======= Seja Bem-Vindo %s ========\n\n\n", Nome);

    printf("\n\t\t\t\tAPERTE 'ENTER' PARA VER O MENU PRINCIPAL:\n\n\n ");

  system("pause");
  system("cls");

  return 0;
}
//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------SALVAR DADOS--------------------------------------------------------
void salvar_no_arquivo(Elemento *lista){
    FILE *f;

    f = fopen("arquivo.txt","w+");

    Elemento *p;

    for(p = lista; p != NULL; p = p -> prox){
        fprintf(f,"%d\n", p->id);
        fprintf(f,"%s", p->modalidade);
        fprintf(f,"%.2f\n", p->altura);
        fprintf(f,"%s", p->nome);
        fprintf(f,"%s", p->genero);
        fprintf(f,"%s", p->nacionalidade);
        fprintf(f,"%s", p->paisnatal);
        fprintf(f,"%d \n", p->Num_alojamento);
        fprintf(f,"%d \n", p->idade);
        fprintf(f,"%d \n", p->dia);
        fprintf(f,"%d \n", p->mes);
        fprintf(f,"%d \n", p->ano);




        fprintf(f,"@\n");
    }

    fclose(f);
}
//-------------------------------------------------------------------------------------------------------------

//-----------------------------------------CARREGAR DADOS-------------------------------------------------------
void carregar_do_arquivo(){
    system("clear||cls");

    FILE *f;
    size_t len = 255;
    char *line = malloc(sizeof(char) * len);

    f = fopen("arquivo.txt","r");

    if (f == NULL){
        printf("Could not open file");
        return;
    }

    free(listaGeral);
    listaGeral = criar_lista();

    int aux=0;
    int id;
    int dia;
    int mes;
    int ano;
    char nome[200];
    float altura;
    int Num_alojamento;
    int idade;
    char modalidade[300];
    char genero[15];
    char nacionalidade[100];
    char paisnatal[100];

    while (fgets(line, len, f) != NULL){
        if (!strcmp(line,"@\n")==0){
                if(aux==0)
                    //id = (int)*line;
                    id = atoi(line);
                else if(aux==1)
                   //nome = (char)*line;
                    strcpy(nome,line);
                else if(aux==2)
                    //altura = (float)*line;
                    altura = atof(line);
                else if(aux==3)
                    //modalidade = (char)*line;
                    strcpy(modalidade,line);
                else if(aux==4)
                   //genero = (char)*line;
                    strcpy(genero,line);
                else if(aux==5)
                   //nacionalidade = (char)*line;
                    strcpy(nacionalidade,line);
                else if(aux==6)
                   //paisnatal = (char)*line;
                    strcpy(paisnatal,line);
                else if(aux==7)
                  //idade = (int)*line;
                    idade = atoi(line);
                else if(aux==8)
                  //dia = (int)*line;
                    Num_alojamento = atoi(line);
                else if(aux==9)
                  //dia = (int)*line;
                    dia = atoi(line);
                else if(aux==10)
                  //mes = (int)*line;
                    mes = atoi(line);
                else if(aux==11)
                  //ano = (int)*line;
                    ano = atoi(line);


            aux++;
            //printf("%d %d %s %.2f %s %s %s %d %d %d %d \n",aux,id,nome, altura, modalidade, genero, paisnatal, dia, mes, ano, idade);
        }else if(strcmp(line,"@\n")==0){
            aux=0;
            listaGeral = inserir_no(listaGeral, id, nome, altura,Num_alojamento, modalidade, genero, nacionalidade, paisnatal,idade, dia, mes, ano);
        }
    }

    free(line);
    fclose(f);
}
//--------------------------------------------------------------------------------------------------------------------

//-----------------------------------------CABEÇALHO------------------------------------------------------------------
void cabecalho(){
    printf("\t\t----------  Sistema de Cadastro para gerenciamento de Olímpiadas de Paris 2024 XXXXX  ----------\n\n");
    printf("\t\t\t----------              Escolha a opção desejada        ----------\n\n");
    printf("\t\t\t\t\t----------------------------------\n");
}
//------------------------------------------------------------------------------------------------------------

//-----------------------------------------MENU DETALHES-------------------------------------------------------
void menuCadastro(){
    system("clear||cls");
    printf("\t\t\t********************************************************\n");
    printf("\t\t\t********************MENU CADASTRO***********************\n");
    printf("\t\t\t********************************************************\n\n");

    char op;

    do{
        system("clear||cls");
        printf("\t\t\t\t********************************************************\n");
        printf("\t\t\t\t********************MENU GERENCIAMENTO******************\n");
        printf("\t\t\t\t********************************************************\n\n");

        int id;
        int idade;
        int dia;
        int mes;
        int ano;
        char nome[100];
        float altura;
        int Num_alojamento;
        char modalidade[500];
        char genero[15];
        char nacionalidade[100];
        char paisnatal[100];

        if(verificar_lista_vazia(listaGeral))
            id = 1;
        else
            id = novo_id(listaGeral)+1;

        printf("\nDigite o nome do atleta: ");
        fgets(nome, sizeof nome, stdin);

        printf("\nDigite a modalidade do atleta: ");
        fgets(modalidade, sizeof modalidade, stdin);

        printf("\nDigite o genêro do atleta: ");
        fgets(genero, sizeof genero, stdin);

        printf("\nDigite a nacionalidade: ");
        fgets(nacionalidade, sizeof nacionalidade, stdin);

        printf("\nDigite o pais natal: ");
        fgets(paisnatal, sizeof paisnatal, stdin);

        printf("\nDigite a altura do atleta: ");
        scanf("%f",&altura);
        getchar();

        printf("\nDigite o número do alojamento:");
        scanf("%d",&Num_alojamento);
        getchar();


        printf("\nDigite a idade:");
        scanf("%d",&idade);
        getchar();

        printf("\nDigite a data de nascimento:");
        scanf("%d %d %d",&dia, &mes, &ano);
        getchar();

        listaGeral = inserir_no(listaGeral,id,nome,altura,Num_alojamento,modalidade,genero,nacionalidade,paisnatal,idade,dia,mes,ano);

        system("clear||cls");
        printf("\t\t\t\t********************************************************\n");
        printf("\t\t\t\t********************MENU CADASTRO***********************\n");
        printf("\t\t\t\t********************************************************\n\n");
        imprimir_lista(listaGeral);

        printf("\nDeseja cadastrar um novo Atleta? (s/n) ");
        scanf("%s", &op);
        getchar();

    }while(op=='s');

    menuPrincipal();
}
//-------------------------------------------------------------------------------------------------------------
//-----------------------------------------MENU LISTAGEM-------------------------------------------------------
void menuListagem(){

    char op;

    do{
        system("clear||cls");
        printf("\t\t\t\t********************************************************\n");
        printf("\t\t\t\t********************MENU LISTA DE ATLETAS***************\n");
        printf("\t\t\t\t********************************************************\n\n");

        if(tamanho_lista(listaGeral) > 0){
            imprimir_lista(listaGeral);

        }else{
            printf("\nNão existem registros cadastrados.\n");
        }

        printf("\nDeseja voltar ao menu principal? (s/n) ");
        scanf("%s", &op);
        getchar();

    }while(op=='n');

    menuPrincipal();
}
//-------------------------------------------------------------------------------------------------------------
//-----------------------------------------MENU PESQUISA-------------------------------------------------------

void menuPesquisa(){
    char op;
    int id;
    int achou = 0;
    do{
        system("clear||cls");
        printf("\t\t\t\t********************************************************\n");
        printf("\t\t\t\t********************MENU PESQUISA***********************\n");
        printf("\t\t\t\t********************************************************\n\n");

        printf("Digite o ID do Atleta: ");
        scanf("%d", &id);

        Elemento *p;
        for(p = listaGeral; p != NULL; p = p -> prox){
            if(p->id == id){
                printf("\nId: %d\n", p->id);
                printf("Nome: %s", p->nome);
                printf("Altura: %.2f\n", p->altura);
                printf("Número do Alojamento: %d\n", p->Num_alojamento);
                printf("Idade: %d\n", p->idade);
                printf("Nacionalidade: %s", p->nacionalidade);
                printf("Modalidade: %s", p->modalidade);
                printf("País: %s", p->paisnatal);
                printf("Genêro: %s", p->genero);
                printf("Data de nascimento: %d %d %d\n", p->dia, p->mes, p->ano);

                achou = 1;
            }
        }
        if(!achou){
            printf("\n*********************************************");
            printf("\nNão foi encontrado nenhum atleta com o id %d.", id);
            printf("\n*********************************************\n");
        }

        printf("\nDeseja realizar outra busca? (s/n) ");
        scanf("%s", &op);
        getchar();

    }while(op=='s');

    menuPrincipal();
}
//-----------------------------------------------------------------------------------------------------------

//-----------------------------------------MENU EDICAO-------------------------------------------------------

void menuEdicao(){
    char op;
    int id;
    int achou = 0;
    do{
        system("clear||cls");
        printf("\t\t\t\t********************************************************\n");
        printf("\t\t\t\t********************MENU EDIÇÃO*************************\n");
        printf("\t\t\t\t********************************************************\n\n");

        printf("\nDigite o ID do atleta:");
        scanf("%d", &id);

        Elemento *p;
        char nome[100];
        float altura;
        int Num_alojamento;
        int idade;
        int dia;
        int mes;
        int ano;
        char modalidade[300];
        char genero[15];
        char nacionalidade[100];
        char paisnatal[100];

        for(p = listaGeral; p != NULL; p = p -> prox){
            if(p->id == id){
                achou = 1;


                printf("\nNova altura: ");
                scanf("%f",&altura);
                getchar();

                printf("\nNovo nome do atleta: ");
                fgets(nome, sizeof nome, stdin);

                printf("\nNova idade: ");
                scanf("%d",&idade);
                getchar();

                printf("\nNovo numero do alojamento: ");
                scanf("%d",&Num_alojamento);
                getchar();

                printf("\nNova data de nascimento:");
                scanf("%d %d %d", &dia, &mes, &ano);
                getchar();

                printf("\nNova modalidade: ");
                fgets(modalidade, sizeof modalidade, stdin);

                printf("\nNovo genero: ");
                fgets(genero, sizeof genero, stdin);

                printf("\nNova nacionalidade: ");
                fgets(nacionalidade, sizeof nacionalidade, stdin);

                printf("\nNovo País Natal: ");
                fgets(paisnatal, sizeof paisnatal, stdin);


                strcpy(p->nome, nome);
                strcpy(p->nacionalidade, nacionalidade);
                strcpy(p->paisnatal, paisnatal);
                strcpy(p->modalidade, modalidade);
                strcpy(p->genero, genero);
                p->dia = dia;
                p->mes = mes;
                p->ano = ano;
                p->idade = idade;
                p->altura = altura;
                p->Num_alojamento = Num_alojamento;
            }
        }
        if(!achou){
            printf("\n*********************************************");
            printf("\nNão foi encontrado nenhum atleta com o id %d.", id);
            printf("\n*********************************************\n");
        }

        printf("\nDeseja realizar outra busca? (s/n) ");
        scanf("%s", &op);
        getchar();

    }while(op=='s');

    menuPrincipal();
}
//---------------------------------------------------------------------------------------------------------
//-----------------------------------------MENU EXCLUSÃO---------------------------------------------------
void menuExclusao(){
    char op;
    int id;
    int achou = 0;
    do{
        system("clear||cls");
        printf("\t\t\t\t********************************************************\n");
        printf("\t\t\t\t********************MENU EXCLUSÃO***********************\n");
        printf("\t\t\t\t********************************************************\n\n");

        printf("Digite o ID do ATLETA que sera EXCLUÍDO: ");
        scanf("%d", &id);

        Elemento *p;
        char nome[100];
        float altura;
        int Num_alojamento;
        int idade;
        int dia;
        int mes;
        int ano;
        char modalidade[100];
        char genero[15];
        char nacionalidade[100];
        char paisnatal[100];
        int resultado=0;

        deleta_no(&listaGeral,id);

        if(tamanho_lista(listaGeral) > 0){
            printf("\nListagem de cadastros atualizada:\n");
            imprimir_lista(listaGeral);

        }else{
            printf("\nNão existem registros cadastrados.\n");
        }

        printf("\nDeseja realizar outra busca? (s/n) ");
        scanf("%s", &op);
        getchar();

    }while(op=='s');

    menuPrincipal();
}


void ajuda_menu(){
char op;
int num;
system("cls");

        printf("\t\t\t\t********************************************************\n");
        printf("\t\t\t\t********************MENU AJUDA & COVID 19***************\n");
        printf("\t\t\t\t********************************************************\n\n");

        printf("\n 1 - COMO GERENCIAR SEUS DADOS\n");
        printf(" 2 - COVID 19\n");
        printf(" 3 - VOLTAR AO MENU INICIAL\n");

        printf("\nEscolha uma opção\n");
        scanf("%i", &num);


    if(num==1)
    {
        do{
        system("cls");
        printf("\t\t\t\t********************************************************\n");
        printf("\t\t\t\t****************GERENCIANDO SEUS DADOS********************\n");
        printf("\t\t\t\t********************************************************\n\n");

        printf("\t\n\n\nApós se registrar na tela de login, você será encaminhado para tela de gerenciamento onde tera opções para manipular os dados dos atletas, dentre elas:\n\n");

        printf("\n\n\t\t\t\tCADASTRAR ATLETA\n");
        printf("\t\n\n\nNessa tela e possivel a inserção de um novo atleta e de todos os seus dados, Nome, Modalidade, Genêro, Nacionalidade, País Natal, Altura, Nímero do Alojamento, Idade, Data de Nascimento(dia, mês, ano).\n\n");

        printf("\n\n\t\t\t\t\LISTA DE ATLETAS\n");
        printf("\t\n\n\nEm lista de atletas, e possível verificar todos os atletas cadastrados no programa, com opção de voltar ou nao para a tela inicial.\n\n");

        printf("\n\n\t\t\t\tPESQUISAR ATLETAS\n");
        printf("\t\n\n\n Ao escolher a opção Pesquisar Atletas, o usuário e direcionado para essa tela na qual e possível buscar um cadastro realizado pelo seu número de identificação (ID), e após realizar a busca e disponibilizado a opção de realizar outra busca de cadastro ou retornar a tela inicial.\n\n");

        printf("\n\n\t\t\t\tALTERAR CADASTRO\n");
        printf("\t\n\n\nBuscando o atleta por seu ID e possivel editar os dados cadastrados como informações pessoais e dados olímpicos.\n\n");

        printf("\n\n\t\t\t\tEXCLUIR CADASTRO\n");
        printf("\t\n\n\nAo escolher a opção de excluir cadastros, o usuário e encaminhado para essa tela onde será digitado o ID do Atleta que irá ser excluido.\n\n");

        printf("\n\n\t\t\t\tSALVAR DADOS\n");
        printf("\t\n\n\nApós escolher a opção Salvar Dados, o programa salvara todos os cadastros realizados em arquivo .txt.\n\n");

        printf("\n\n\t\t\t\tCARREGAR DADOS\n");
        printf("\t\n\n\n Ao escolher Carregar Dados, o programa irá disponibilizar todos cadastros salvos anteriormente.\n\n");

        printf("\n\n\t\t\t\tRELATORIOS\n");
        printf("\t\n\n\n Ao escolher a opção relatórios é possível acessar o Calendário Olímpico, Ranqueamento de Medalhas, Número total de medalhas e os Medalhistas.\n\n");

        printf("\nVoltar a Menu Ajuda & Covid 19 ? (s/n) ");
        scanf("%s", &op);
        getchar();

        }while(op=='n');

    ajuda_menu();

    }

    if(num==2)
    {
        do{
        system("cls");
       printf("\t\t\t\t********************************************************\n");
        printf("\t\t\t\t***********************COVID 19*************************\n");
        printf("\t\t\t\t********************************************************\n\n");

        printf("\t\t\t\t\t\tPARIS 2024\n\n");
        printf("\t\t\t\tATLETAS PRECISARAO SEGUIR PROTOCOLOS SANITÁRIOS\n\n");
        printf("\t\t\t\t'Descumprimento pode levar a exclusão dos jogo Olímpicos'\n\n");
        printf("\n\n\t\t\t\tMÁSCARA\n");
        printf("\t\n\n\nDeve ser usada a todo momento, exceto ao comer, treinar, competir, e conceder entrevistas\n\n");
        printf("\n\n\t\t\t\t\TESTE\n");
        printf("\t\n\n\nO atleta deve realizar o teste de covid antes de embarcar, na chegada a Paris e em todos dias durante a competição\n\n");
        printf("\n\n\t\t\t\tMONITORAMENTO DE TEMPERATURA\n");
        printf("\t\n\n\nDeve ser monitorada a temperatura, antes de entrar na Vila do Atleta ou no Hotel\n\n");
        printf("\n\n\t\t\t\tDEIXAR PARIS\n");
        printf("\t\n\n\nAte 48h após a competição ou após a eliminação do atleta\n\n");



        printf("\nVoltar a Menu Ajuda & Covid 19 ? (s/n) ");
        scanf("%s", &op);
        getchar();

    }while(op=='n');

    ajuda_menu();

}

    if(num==3)
    {
       menuPrincipal();
    }else{
            printf("\nOpcao nao encontrada\n");
            system("pause");
            ajuda_menu();
    }

}


void relatorios()
 {
    system("cls");
    int num;
    char op;

    printf("\t\t\t\t********************************************************\n");
    printf("\t\t\t\t********************MENU RELATÓRIOS***********************\n");
    printf("\t\t\t\t********************************************************\n\n");

    printf("\n 1 - CALENDÁRIO OLÍMPICO:\n");
    printf(" 2 - CONTAGEM DE MEDALHAS, RANQUEAMENTO:\n");
    printf(" 3 - MEDALHISTAS OLÍMPICOS:\n");
    printf(" 4 - NÚMERO TOTAL DE MEDALHAS:\n");
    printf(" 5 - VOLTAR AO MENU INICIAL\n");

    printf("\nEscolha uma Opção\n");
    scanf("%i", &num);


    if(num==1)
    {
    do{
        system("cls");
        printf("\n\n\n\t\t\t\t********************************************************\n");
       printf("\t\t\t\t********************CALENDÁRIO OLÍMPICO*****************\n");
        printf("\t\t\t\t********************************************************\n\n");
        printf("\t\t\t\tCerimônia de Abertura - 23 de julho de 2024\n");
 printf("\t\t\t\tCerimônia de Encerramento - 8 de agosto de 2024\n\n");
printf("\t\t\t\tEsporte - Datas das provas\n\n");
 printf("\t>>\tAtletismo - 30 de julho a 8 de agosto de 2024\n");
 printf("\t>>\tBadminton - 24 de julho a 2 de agosto de 2024\n");
 printf("\t>>\tBasquetebol (Basquete e Basquete 3×3) - 24 de julho a 8 de agosto de 2024\n");
 printf("\t>>\tBeisebol - 21 a 27 de julho de 2024\n");
 printf("\t>>\tBoxe - 24 de julho a 2 de agosto de 2024\n");
 printf("\t>>\tCanoagem (Slalom e Velocidade) - 25 a 30 de julho de 2024\n");
 printf("\t>>\tCaratê - 5 a 7 de agosto de 2024\n");
 printf("\t>>\tCiclismo (Ciclismo de estrada, Ciclismo de pista, BMX e Bicicleta de montanha) - 24 de julho a 8 de agosto de 2024\n");
 printf("\t>>\tEscalada esportiva - 3 a 6 de agosto de 2024");
 printf("\t>>\tEsgrima - 24 de julho a 1 de agosto de 2024\n");
 printf("\t>>\tFutebol - 21 de julho a 7 de agosto de 2024\n");
 printf("\t>>\tGinástica (Artística, Rítmica e Trampolim) - 24 de julho a 8 de agosto de 2024\n");
 printf("\t>>\tGolfe - 29 de julho a 7 de agosto de 2024\n");
 printf("\t>>\tHalterofilismo - 24 de julho a 4 de agosto de 2024\n");
 printf("\t>>\tHandebol - 24 de julho a 8 de agosto de 2024\n");
 printf("\t>>\tHipismo - 24 de julho a 6 de agosto de 2024\n");
 printf("\t>>\tHóquei sobre a grama - 24 de julho a 6 de agosto de 2024\n");
 printf("\t>>\tJudô - 24 a 31 de julho de 2024\n");
 printf("\t>>\tLutas (Wrestling) - 1 a 7 de agosto de 2024\n");
 printf("\t>>\tNatação - 24 de julho a 5 de agosto de 2024\n");
 printf("\t>>\tNatação artística - 2 a 7 de agosto de 2024\n");
 printf("\t>>\tPentatlo moderno - 5 a 7 de agosto de 2024\n");
 printf("\t>>\tPolo aquático - 24 de julho a 8 de agosto de 2024\n");
 printf("\t>>\tRemo - 23 a 30 de julho de 2024\n");
 printf("\t>>\tRugby Sevens - 26 a 31 de julho de 2024\n");
 printf("\t>>\tSaltos ornamentais - 25 de julho a 7 de agosto de 2024\n");
 printf("\t>>\tSkate - 25 de julho de 2021 a 5 de agosto de 2024\n");
 printf("\t>>\tSoftbol - 21 a 27 de julho de 2024\n");
 printf("\t>>\tSurfe - 25 a 27 de julho de 2024\n");
 printf("\t>>\tTaekwondo - 24 a 27 de julho de 2024\n");
 printf("\t>>\tTênis - 24 de julho a 1 de agosto de 2024\n");
 printf("\t>>\tTênis de mesa - 24 de julho a 6 de agosto de 2024\n");
 printf("\t>>\tTiro - 24 de julho a 2 de agosto de 202\n");
 printf("\t>>\tTiro com arco (Arco e Flecha) - 23 a 31 de julho de 2024\n");
 printf("\t>>\tTriatlo - 26 a 31 de julho de 2024\n");
 printf("\t>>\tVela - 25 de julho a 4 de agosto de 2024\n");
 printf("\t>>\tVoleibol (Vôlei e Vôlei de praia) - 24 de julho a 8 de agosto de 2024\n\n");
 printf("\t• Dia 21 de julho, quarta-feira\n");
 printf("\t• Dia 22 de julho, quinta-feira\n");
 printf("\t• Dia 23 de julho, sexta-feira\n");
 printf("\t• Dia 24 de julho, sábado\n");
 printf("\t• Dia 25 de julho, domingo\n");
 printf("\t• Dia 26 de julho, segunda-feira\n");
 printf("\t• Dia 27 de julho, terça-feira\n");
 printf("\t• Dia 28 de julho, quarta-feira\n");
 printf("\t• Dia 29 de julho, quinta-feira\n");
 printf("\t• Dia 30 de julho, sexta-feira\n");
 printf("\t• Dia 31 de julho, sábado\n");
 printf("\t• Dia 1 de agosto, domingo\n");
 printf("\t• Dia 2 de agosto, segunda-feira\n");
 printf("\t• Dia 3 de agosto, terça-feira\n");
 printf("\t• Dia 4 de agosto, quarta-feira\n");
 printf("\t• Dia 5 de agosto, quinta-feira\n");
 printf("\t• Dia 6 de agosto, sexta-feira\n");
 printf("\t• Dia 7 de agosto, sábado\n");
 printf("\t• Dia 8 de agosto, domingo\n");


        printf("\nVoltar a Relatorios ? (s/n) ");
        scanf("%s", &op);
        getchar();

    }while(op=='n');

    relatorios();
    }

    if(num==2)
    {
    do{
        system("cls");
        printf("\t\t\t\t********************************************************\n");
        printf("\t\t\t\t********************QUADRO DE MEDALHAS******************\n");
        printf("\t\t\t\t********************************************************\n\n");

        printf("\t\t\t--------------------------------------------------------------\n");
            printf("\t\t\t|\t                                                     |\n");
            printf("\t\t\t|\tPosição|    País       | Ouro | Prata |Bronze| Total |\n");
            printf("\t\t\t|\t    1  | EUA           |  39  |   41  |  33  |  113  |\n");
            printf("\t\t\t|\t    2  | CHINA         |  38  |   32  |  18  |  88   |\n");
            printf("\t\t\t|\t    3  | C.O.R         |  20  |   28  |  23  |  71   |\n");
            printf("\t\t\t|\t    4  | GRAN-BRETAMHA |  22  |   21  |  22  |  65   |\n");
            printf("\t\t\t|\t    5  | JAPÃO         |  27  |   14  |  17  |  58   |\n");
            printf("\t\t\t|\t    6  | AUSTRALIA     |  17  |   7   |  22  |  46   |\n");
            printf("\t\t\t|\t    7  | ITÁLIA        |  10  |   10  |  20  |  40   |\n");
            printf("\t\t\t|\t    8  | ALEMANHA      |  10  |   11  |  16  |  37   |\n");
            printf("\t\t\t|\t    9  | PAISES BAIXOS |  10  |   12  |  14  |  36   |\n");
            printf("\t\t\t|\t   10  | FRANÇA        |  10  |   12  |  11  |  33   |\n");
            printf("\t\t\t-------------------------------------------------------------\n\n");

            printf("\nVoltar a Relatórios ? (s/n) ");
            scanf("%s", &op);
            getchar();

    }while(op=='n');

    relatorios();

    }

    if(num==3)
    {
    do{
        system("cls");
        printf("\t\t\t\t********************************************************\n");
        printf("\t\t\t\t********************MEDALHISTAS OLÍMPICOS***************\n");
        printf("\t\t\t\t********************************************************\n\n");
        printf("1. Caeleb Dressel (EUA/natação) 5 medalhas no total, 5 ouros...\n");
        printf("2. Emma McKeon (AUS/natação) 7 medalhas no total, 4 ouros, 3 bronzes ...\n");
        printf("3. Kaylee McKeown (AUS/natação) 4 medalhas no total, 3 ouros, 1 bronze...\n");
        printf("4. An San (KOR/tiro com arco) 3 medalhas no total, 3 ouros...\n");
        printf("5. Lisa Carrington (NZL/canoagem) 3 medalhas no total, 3 ouros...\n");
        printf("6. Elaine Thompson-Herah (JAM/atletismo) 3 medalhas no total, 3 ouros...\n");
        printf("7. Katie Ledecky (EUA/natação) 4 medalhas no total, 2 ouros, 2 pratas...\n");
        printf("8. Zhang Yufei (CHN/natação) 4 medalhas no total, 2 ouros, 2 pratas...\n");
        printf("9. Ariarne Titmus (AUS/natação) 4 medalhas no total, 2 ouros, 1 prata, 1 bronze...\n");
        printf("10. Vitalina Batsarashkina (RUS/tiro) 3 medalhas no total, 2 ouros, 1 prata...\n");


        printf("\nVoltar a Relatórios ? (s/n) ");
        scanf("%s", &op);
        getchar();

    }while(op=='n');

    relatorios();
    }


    if(num==4)
    {
    do{
        system("cls");
        printf("\t\t\t\t********************************************************\n");
        printf("\t\t\t\t********************NÚMERO TOTAL DE MEDALHAS************\n");
        printf("\t\t\t\t********************************************************\n\n");
        printf(">>   287 Medalhas distribuídas\n\n");

        printf("\nVoltar a Relatorios ? (s/n) ");
        scanf("%s", &op);
        getchar();

    }while(op=='n');

    relatorios();
    }

    if(num==5)
    {
    menuPrincipal();
    }else{
            printf("\nOpção nao encontrada\n");
            system("pause");
            relatorios();
    }
}

void menuPrincipal(){
    int op;
    do{
        system("clear||cls");
        cabecalho();
        printf("\t\t\t\t******************************************************\n");
        printf("\t\t\t\t********************MENU PRINCIPAL********************\n");
        printf("\t\t\t\t******************************************************\n\n");
        printf("---------------------------------------------------\n");
        printf("Escolha dentre as opções abaixo:\n");
        printf("---------------------------------------------------\n");
        printf("1 - CADASTRAR ATLETA\n");
        printf("2 - LISTA DE ATLETAS\n");
        printf("3 - PESQUISAR ATLETAS\n");
        printf("4 - ALTERAR CADASTRO\n");
        printf("5 - EXCLUIR CADASTROS\n");
        printf("6 - SALVAR DADOS\n");
        printf("7 - CARREGAR DADOS\n");
        printf("8 - RELATÓRIOS\n");
        printf("9 - AJUDA & COVID 19\n");
        printf("10 - SAIR DO SISTEMA\n");
        printf("---------------------------------------------------\n");

        scanf("%d", &op);
        getchar();

        switch(op){
            case 1:
                menuCadastro();
                break;
            case 2:
                menuListagem();
                break;
            case 3:
                menuPesquisa();
                break;
            case 4:
                menuEdicao();
                break;
            case 5:
                menuExclusao();
                break;
            case 6:
                salvar_no_arquivo(listaGeral);
                break;
            case 7:
                carregar_do_arquivo();
                break;
            case 8:
                relatorios();
                break;
            case 9:
                ajuda_menu();
                break;
            case 10:
                exit(0);
                break;

        }

    }while(op!=10);
}

int main(void){
    setlocale(LC_ALL,"Portuguese");
    listaGeral = criar_lista();
    login_tela();
    menuPrincipal();
}
