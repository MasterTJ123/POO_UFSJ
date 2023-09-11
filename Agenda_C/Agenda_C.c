#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONTADOR_TAREFAS_AUX Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_tarefas
#define CONTADOR_REUNIOES_AUX Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_reunioes
#define CONTADOR_ANIVERSARIOS_AUX Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_aniversarios

// Aqui são definidos os diferentes tipos de eventos, agendas e usuários

typedef struct tarefa{
    char assunto[30];
    int horario_inicio;
    int horario_termino;
    int grau_esforco;
    int prioridade;
} TAREFA;

typedef struct reuniao{
    char assunto[30];
    int horario_inicio;
    int horario_termino;
    char local[30];
    int presenca;
} REUNIAO;

typedef struct aniversario{
    char assunto[30];
    int horario_inicio;
    int horario_termino;
    char local[30];
    char nome_aniversariante[30];
} ANIVERSARIO;

typedef struct evento{
    TAREFA* Tarefa;
    REUNIAO* Reuniao;
    ANIVERSARIO* Aniversario;
    int contador_tarefas;
    int contador_reunioes;
    int contador_aniversarios;
} EVENTO;

typedef struct agenda{
    EVENTO Evento;
    int contador_eventos;
} AGENDA;

typedef struct usuario{
    char nome[30];
    char email[30];
    AGENDA Agenda;
} USUARIO;

typedef struct lista_usuario{
    USUARIO* Usuario;
} LISTA_USUARIO;

void erro_comando_invalido(){
    system("cls");
    printf("Erro! Comando invalido!\n\n");
    system("pause");
    system("cls");
}

int main()
{
    LISTA_USUARIO Lista_Usuario;
    int contador_usuarios = 0;

    char assunto_aux[30];
    int horario_inicio_aux;
    int horario_termino_aux;
    int grau_esforco_aux;
    int prioridade_aux;
    char local_aux[30];
    int presenca_aux;
    char nome_aniversariante_aux[30];

    int escolha_menu = 0;
    int indice_agenda_aux = -1;

    char nome_aux[30];
    char email_aux[30];

    int flag_horario_coincidente = 0;

    do{
        system("cls");
        printf("---------------------------------------------------------------\n              Bem-vindo ao Gerenciador de Eventos  \n---------------------------------------------------------------\n\n");
        printf("1- Criar usuario\n");
        printf("2- Listar usuarios\n");
        printf("3- Entrar na agenda\n");
        printf("4- Sair\n\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &escolha_menu);
        fflush(stdin);
            if(escolha_menu == 1){
                system("cls");
                printf("Informe seu nome: ");
                scanf(" %[^\n]%*c", nome_aux);
                fflush(stdin);
                printf("Informe seu e-mail: ");
                scanf("%s", email_aux);
                fflush(stdin);
                if(contador_usuarios == 0){
                    Lista_Usuario.Usuario = (USUARIO*) malloc(sizeof(USUARIO));
                } else {
                    Lista_Usuario.Usuario = (USUARIO*) realloc(Lista_Usuario.Usuario, (contador_usuarios+1)*sizeof(USUARIO));
                }
                strcpy(Lista_Usuario.Usuario[contador_usuarios].nome, nome_aux);
                strcpy(Lista_Usuario.Usuario[contador_usuarios].email, email_aux);
                Lista_Usuario.Usuario[contador_usuarios].Agenda.contador_eventos = 0;
                Lista_Usuario.Usuario[contador_usuarios].Agenda.Evento.contador_tarefas = 0;
                Lista_Usuario.Usuario[contador_usuarios].Agenda.Evento.contador_reunioes = 0;
                Lista_Usuario.Usuario[contador_usuarios].Agenda.Evento.contador_aniversarios = 0;
                system("cls");
                printf("Usuario cadastrado com sucesso!\n\n");
                system("pause");
                system("cls");
                contador_usuarios++;
            } else if(escolha_menu == 2){
                system("cls");
                if(contador_usuarios > 0){
                    for(int i=0; i < contador_usuarios; i++){
                        printf("Usuario %d\n", i+1);
                        printf("Nome: %s\n", Lista_Usuario.Usuario[i].nome);
                        printf("Email: %s\n\n", Lista_Usuario.Usuario[i].email);
                    }
                    system("pause");
                    system("cls");
                } else {
                    printf("Nao existe nenhum usuario cadastrado no momento!\n\n");
                    system("pause");
                    system("cls");
                }
            } else if(escolha_menu == 3){
                if(contador_usuarios > 0){
                    system("cls");
                    indice_agenda_aux = -1;
                    printf("Por favor, informe o nome do Usuario: ");
                    scanf(" %[^\n]%*c", nome_aux);
                    fflush(stdin);
                    for(int i=0; i < contador_usuarios; i++){
                        if(!(strcmp(nome_aux, Lista_Usuario.Usuario[i].nome))){
                            indice_agenda_aux = i;
                            break;
                        }
                    }
                    if(indice_agenda_aux == -1){
                        system("cls");
                        printf("Erro! Usuario nao encontrado!\n\n");
                        system("pause");
                    } else {
                        system("cls");
                            do{
                                system("cls");
                                printf("---------------------------------------------------------------\n              Agenda  \n---------------------------------------------------------------\n\n");
                                printf("1- Cadastrar evento\n");
                                printf("2- Imprimir agenda\n");
                                printf("3- Sair\n\n");
                                printf("Selecione uma opcao: ");
                                scanf("%d", &escolha_menu);
                                fflush(stdin);
                                    if(escolha_menu == 1){
                                        do{
                                            system("cls");
                                            printf("---------------------------------------------------------------\n              Cadastrar Evento  \n---------------------------------------------------------------\n\n");
                                            printf("1- Cadastrar tarefa\n");
                                            printf("2- Cadastrar reuniao\n");
                                            printf("3- Cadastrar aniversario\n");
                                            printf("4- Sair\n\n");
                                            printf("Selecione uma opcao: ");
                                            scanf("%d", &escolha_menu);
                                            fflush(stdin);
                                                if(escolha_menu == 1){
                                                    system("cls");
                                                    printf("Assunto: ");
                                                    scanf(" %[^\n]%*c", assunto_aux);
                                                    fflush(stdin);
                                                    printf("Horario de inicio: ");
                                                    scanf("%d", &horario_inicio_aux);
                                                    fflush(stdin);
                                                        if(horario_inicio_aux < 0 || horario_inicio_aux > 23){
                                                            system("cls");
                                                            printf("Erro! O horario de inicio esta fora da faixa de valores permitida (entre 0 e 23)\n\n");
                                                            system("pause");
                                                            system("cls");
                                                            break;
                                                        }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_tarefas; i++){
                                                            if( (horario_inicio_aux >= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_inicio) && (horario_inicio_aux < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_termino) ){
                                                                system("cls");
                                                                printf("Erro! O horario de inicio coincide com o horario de outra tarefa!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_reunioes; i++){
                                                            if( (horario_inicio_aux >= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_inicio) && (horario_inicio_aux < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_termino) ){
                                                                system("cls");
                                                                printf("Erro! O horario de inicio coincide com o horario de outra reuniao!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_aniversarios; i++){
                                                            if( (horario_inicio_aux >= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_inicio) && (horario_inicio_aux < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_termino) ){
                                                                system("cls");
                                                                printf("Erro! O horario de inicio coincide com o horario de outro aniversario!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                    printf("Horario de termino: ");
                                                    scanf("%d", &horario_termino_aux);
                                                    fflush(stdin);
                                                        if(horario_termino_aux < 0 || horario_termino_aux > 23){
                                                            system("cls");
                                                            printf("Erro! O horario de termino esta fora da faixa de valores permitida (entre 0 e 23)\n\n");
                                                            system("pause");
                                                            system("cls");
                                                            break;
                                                        }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_tarefas; i++){
                                                            if( (horario_termino_aux <= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_termino) && (horario_termino_aux > Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_inicio) ){
                                                                system("cls");
                                                                printf("Erro! O horario de termino coincide com o horario de outra tarefa!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_reunioes; i++){
                                                            if( (horario_termino_aux <= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_termino) && (horario_termino_aux > Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_inicio) ){
                                                                system("cls");
                                                                printf("Erro! O horario de termino coincide com o horario de outra reuniao!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_aniversarios; i++){
                                                            if( (horario_termino_aux <= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_termino) && (horario_termino_aux > Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_inicio) ){
                                                                system("cls");
                                                                printf("Erro! O horario de termino coincide com o horario de outro aniversario!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                    printf("Grau de esforco: ");
                                                    scanf("%d", &grau_esforco_aux);
                                                    fflush(stdin);
                                                        if(grau_esforco_aux < 1 || grau_esforco_aux > 5){
                                                            system("cls");
                                                            printf("Erro! O grau de esforco esta fora da faixa de valores permitida (entre 1 e 5)\n\n");
                                                            system("pause");
                                                            system("cls");
                                                            break;
                                                        }
                                                    printf("Prioridade: ");
                                                    scanf("%d", &prioridade_aux);
                                                    fflush(stdin);
                                                        if(prioridade_aux < 1 || prioridade_aux > 5){
                                                            system("cls");
                                                            printf("Erro! A prioridade esta fora da faixa de valores permitida (entre 1 e 5)\n\n");
                                                            system("pause");
                                                            system("cls");
                                                            break;
                                                        }
                                                    if(Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_tarefas == 0){
                                                        Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa = (TAREFA*) malloc(sizeof(TAREFA));
                                                    } else {
                                                        Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa = (TAREFA*) realloc(Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa, (Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_tarefas+1)*sizeof(TAREFA));
                                                    }
                                                    strcpy(Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[CONTADOR_TAREFAS_AUX].assunto, assunto_aux);
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[CONTADOR_TAREFAS_AUX].horario_inicio = horario_inicio_aux;
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[CONTADOR_TAREFAS_AUX].horario_termino = horario_termino_aux;
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[CONTADOR_TAREFAS_AUX].grau_esforco = grau_esforco_aux;
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[CONTADOR_TAREFAS_AUX].prioridade = prioridade_aux;
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.contador_eventos++;
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_tarefas++;
                                                    system("cls");
                                                    printf("Tarefa cadastrada com sucesso!\n\n");
                                                    system("pause");
                                                    system("cls");
                                                } else if(escolha_menu == 2){
                                                    system("cls");
                                                    printf("Assunto: ");
                                                    scanf(" %[^\n]%*c", assunto_aux);
                                                    fflush(stdin);
                                                    printf("Horario de inicio: ");
                                                    scanf("%d", &horario_inicio_aux);
                                                    fflush(stdin);
                                                        if(horario_inicio_aux < 0 || horario_inicio_aux > 23){
                                                            system("cls");
                                                            printf("Erro! O horario de inicio esta fora da faixa de valores permitida (entre 0 e 23)\n\n");
                                                            system("pause");
                                                            system("cls");
                                                            break;
                                                        }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_tarefas; i++){
                                                            if( (horario_inicio_aux >= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_inicio) && (horario_inicio_aux < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_termino) ){
                                                                system("cls");
                                                                printf("Erro! O horario de inicio coincide com o horario de outra tarefa!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_reunioes; i++){
                                                            if( (horario_inicio_aux >= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_inicio) && (horario_inicio_aux < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_termino) ){
                                                                system("cls");
                                                                printf("Erro! O horario de inicio coincide com o horario de outra reuniao!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_aniversarios; i++){
                                                            if( (horario_inicio_aux >= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_inicio) && (horario_inicio_aux < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_termino) ){
                                                                system("cls");
                                                                printf("Erro! O horario de inicio coincide com o horario de outro aniversario!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                    printf("Horario de termino: ");
                                                    scanf("%d", &horario_termino_aux);
                                                    fflush(stdin);
                                                        if(horario_termino_aux < 0 || horario_termino_aux > 23){
                                                            system("cls");
                                                            printf("Erro! O horario de termino esta fora da faixa de valores permitida (entre 0 e 23)\n\n");
                                                            system("pause");
                                                            system("cls");
                                                            break;
                                                        }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_tarefas; i++){
                                                            if( (horario_termino_aux <= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_termino) && (horario_termino_aux > Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_inicio) ){
                                                                system("cls");
                                                                printf("Erro! O horario de termino coincide com o horario de outra tarefa!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_reunioes; i++){
                                                            if( (horario_termino_aux <= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_termino) && (horario_termino_aux > Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_inicio) ){
                                                                system("cls");
                                                                printf("Erro! O horario de termino coincide com o horario de outra reuniao!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_aniversarios; i++){
                                                            if( (horario_termino_aux <= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_termino) && (horario_termino_aux > Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_inicio) ){
                                                                system("cls");
                                                                printf("Erro! O horario de termino coincide com o horario de outro aniversario!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                    printf("Local: ");
                                                    scanf(" %[^\n]%*c", local_aux);
                                                    fflush(stdin);
                                                    printf("Presenca (0 ou 1): ");
                                                    scanf("%d", &presenca_aux);
                                                    fflush(stdin);
                                                    if(Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_reunioes == 0){
                                                        Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao = (REUNIAO*) malloc(sizeof(REUNIAO));
                                                    } else {
                                                        Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao = (REUNIAO*) realloc(Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao, (Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_reunioes+1)*sizeof(REUNIAO));
                                                    }
                                                    strcpy(Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[CONTADOR_REUNIOES_AUX].assunto, assunto_aux);
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[CONTADOR_REUNIOES_AUX].horario_inicio = horario_inicio_aux;
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[CONTADOR_REUNIOES_AUX].horario_termino = horario_termino_aux;
                                                    strcpy(Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[CONTADOR_REUNIOES_AUX].local, local_aux);
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[CONTADOR_REUNIOES_AUX].presenca = presenca_aux;
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.contador_eventos++;
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_reunioes++;
                                                    system("cls");
                                                    printf("Reuniao cadastrada com sucesso!\n\n");
                                                    system("pause");
                                                    system("cls");
                                                } else if( escolha_menu == 3){
                                                    system("cls");
                                                    printf("Assunto: ");
                                                    scanf(" %[^\n]%*c", assunto_aux);
                                                    fflush(stdin);
                                                    printf("Horario de inicio: ");
                                                    scanf("%d", &horario_inicio_aux);
                                                    fflush(stdin);
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_tarefas; i++){
                                                            if( (horario_inicio_aux >= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_inicio) && (horario_inicio_aux < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_termino) ){
                                                                system("cls");
                                                                printf("Erro! O horario de inicio coincide com o horario de outra tarefa!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_reunioes; i++){
                                                            if( (horario_inicio_aux >= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_inicio) && (horario_inicio_aux < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_termino) ){
                                                                system("cls");
                                                                printf("Erro! O horario de inicio coincide com o horario de outra reuniao!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_aniversarios; i++){
                                                            if( (horario_inicio_aux >= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_inicio) && (horario_inicio_aux < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_termino) ){
                                                                system("cls");
                                                                printf("Erro! O horario de inicio coincide com o horario de outro aniversario!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                    printf("Horario de termino: ");
                                                    scanf("%d", &horario_termino_aux);
                                                    fflush(stdin);
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_tarefas; i++){
                                                            if( (horario_termino_aux <= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_termino) && (horario_termino_aux > Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_inicio) ){
                                                                system("cls");
                                                                printf("Erro! O horario de termino coincide com o horario de outra tarefa!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_reunioes; i++){
                                                            if( (horario_termino_aux <= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_termino) && (horario_termino_aux > Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_inicio) ){
                                                                system("cls");
                                                                printf("Erro! O horario de termino coincide com o horario de outra reuniao!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                        for(int i=0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_aniversarios; i++){
                                                            if( (horario_termino_aux <= Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_termino) && (horario_termino_aux > Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_inicio) ){
                                                                system("cls");
                                                                printf("Erro! O horario de termino coincide com o horario de outro aniversario!\n\n");
                                                                system("pause");
                                                                system("cls");
                                                                flag_horario_coincidente = 1;
                                                                break;
                                                            }
                                                        }
                                                            if(flag_horario_coincidente == 1){
                                                                flag_horario_coincidente = 0;
                                                                break;
                                                            }
                                                    printf("Local: ");
                                                    scanf(" %[^\n]%*c", local_aux);
                                                    fflush(stdin);
                                                    printf("Nome do aniversariante: ");
                                                    scanf(" %[^\n]%*c", nome_aniversariante_aux);
                                                    fflush(stdin);
                                                    if(Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_aniversarios == 0){
                                                        Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario = (ANIVERSARIO*) malloc(sizeof(ANIVERSARIO));
                                                    } else {
                                                        Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario = (ANIVERSARIO*) realloc(Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario, (Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_aniversarios+1)*sizeof(ANIVERSARIO));
                                                    }
                                                    strcpy(Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[CONTADOR_ANIVERSARIOS_AUX].assunto, assunto_aux);
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[CONTADOR_ANIVERSARIOS_AUX].horario_inicio = horario_inicio_aux;
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[CONTADOR_ANIVERSARIOS_AUX].horario_termino = horario_termino_aux;
                                                    strcpy(Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[CONTADOR_ANIVERSARIOS_AUX].local, local_aux);
                                                    strcpy(Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[CONTADOR_ANIVERSARIOS_AUX].nome_aniversariante, nome_aniversariante_aux);
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.contador_eventos++;
                                                    Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_aniversarios++;
                                                    system("cls");
                                                    printf("Aniversario cadastrada com sucesso!\n\n");
                                                    system("pause");
                                                    system("cls");
                                                } else if( escolha_menu == 4){
                                                    system("cls");
                                                    break;
                                                } else {
                                                    erro_comando_invalido();
                                                }
                                            } while(1);
                                    } else if(escolha_menu == 2){
                                        system("cls");
                                            for(int i = 0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_tarefas; i++){
                                                printf("Tarefa %d\n", i+1);
                                                printf("Assunto: %s\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].assunto);
                                                printf("Horario de inicio: %d\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_inicio);
                                                printf("Horario de termino: %d\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].horario_termino);
                                                printf("Grau de esforco: %d\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].grau_esforco);
                                                printf("Prioridade: %d\n\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Tarefa[i].prioridade);
                                            }
                                            for(int i = 0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_reunioes; i++){
                                                printf("Reuniao %d\n", i+1);
                                                printf("Assunto: %s\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].assunto);
                                                printf("Horario de inicio: %d\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_inicio);
                                                printf("Horario de termino: %d\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].horario_termino);
                                                printf("Local: %s\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].local);
                                                printf("Presenca: %d\n\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Reuniao[i].presenca);
                                            }
                                            for(int i = 0; i < Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.contador_aniversarios; i++){
                                                printf("Aniversario %d\n", i+1);
                                                printf("Assunto: %s\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].assunto);
                                                printf("Horario de inicio: %d\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_inicio);
                                                printf("Horario de termino: %d\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].horario_termino);
                                                printf("Local: %s\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].local);
                                                printf("Nome do aniversariante: %s\n\n", Lista_Usuario.Usuario[indice_agenda_aux].Agenda.Evento.Aniversario[i].nome_aniversariante);
                                            }
                                            system("pause");
                                            system("cls");
                                    } else if(escolha_menu == 3){
                                        system("cls");
                                        break;
                                    } else {
                                        erro_comando_invalido();
                                    }
                            } while(1);
                    }
                } else {
                    system("cls");
                    printf("Nao existe nenhum usuario cadastrado no momento!\n\n");
                    system("pause");
                    system("cls");
                }
            } else if(escolha_menu == 4){
                system("cls");
                printf("Programa encerrado com sucesso!\n\n");
                system("pause");
                return 0;
            } else {
                erro_comando_invalido();
            }
    } while(1);
    return 0;
}
