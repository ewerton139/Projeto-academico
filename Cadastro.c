#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criação de estrutura do cliente - Será utilizada tanto para cadastro quanto para listagem de clientes
typedef struct cliente {
    int id;
    char nome[100];
    char email[120];
    char dataNascimento[20];
    char telefone[20];
    char cpf[20];
    char cursoMatriculado[20];
}
Cliente;

// Criação de estrutura do funcionários - Será utilizada tanto para cadastro quanto para listagem de funcionários
typedef struct funcionario {
    int id;
    char nome[100];
    char email[120];
    char dataNascimento[20];
    char telefone[20];
    char cpf[20];
    char cargo[20];
    char login[100];
    char senha[120];
}
Funcionario;

void cadastroCliente(Cliente *clientes, int quantidadeClientes) {
    // Cadastro de usuário. O Id do usuário será a quantidade de usuários + 1, para que assim não exista cliente de ID = 0
    clientes[quantidadeClientes].id = quantidadeClientes + 1;
    printf("--------------+++ CADASTRO DE CLIENTE +++--------------\n");
    printf("Criacao de cliente de ID: %d\n", quantidadeClientes + 1);
    printf("Entre com o nome do cliente: ");
    scanf("%s", &clientes[quantidadeClientes].nome);
    printf("Entre com o cpf do cliente: ");
    scanf("%s", &clientes[quantidadeClientes].cpf);
    printf("Entre com a data de nascimento do cliente: (dd-mm-aaaa) ");
    scanf("%s", &clientes[quantidadeClientes].dataNascimento);
    printf("Entre com o e-mail do cliente: ");
    scanf("%s", &clientes[quantidadeClientes].email);
    printf("Entre com o telefone do cliente: ");
    scanf("%s", &clientes[quantidadeClientes].telefone);
    printf("Entre com o curso matriculado: ");
    scanf("%s", &clientes[quantidadeClientes].cursoMatriculado);
    system("cls");
    printf("Cliente cadastrado com sucesso!");
    getchar();
    getchar();
}

void consultarCliente(Cliente *clientes, int quantidadeClientes) {
    int id, achou;
    printf("--------------+++ CONSULTA CLIENTE +++--------------\n");
    printf("Entre com o id do cliente: ");
    scanf("%d", &id);
    // Se a id for menor que 0 ou maior que o número de clientes será uma consulta inválida
    while (id < 0 || id > quantidadeClientes) {
        printf("ID invalido, tente novamente (0 - para sair): ");
        scanf("%d", &id);
        
        if (id == 0) {
            return;
        }
    }

    // Verificando em todos os clientes cadastrados para ver se algum tem o id que o usuário digitou
    for (int i = 0; i < quantidadeClientes; i ++) {
        if (clientes[i].id == id) {
            printf("Nome cliente: %s\n", clientes[i].nome);
            printf("Cpf cliente: %s\n", clientes[i].cpf);
            printf("Data de nascimento cliente: %s\n", clientes[i].dataNascimento);
            printf("E-mail cliente: %s\n", clientes[i].email);
            printf("Telefone cliente: %s\n", clientes[i].telefone);
            printf("Curso matriculado: %s", clientes[i].cursoMatriculado);
            
            // caso encontre o usuário ele lista na tela e atribribui o valor 1 para a variável achou
            achou = 1;
        }
    }
    // se a variável achou for igual a 0, significa que não achou
    if (achou == 0) {
        printf("Cliente nao encontrado");
        getchar();
        getchar();
    }
    getchar();
    getchar();

}

// É verificado em todos os clientes para caso algum tenha o id informado, se tiver atribui o valor de ID para -1. Com o ID de -1 o cliente não será listado em nenhuma consulta.
void excluirCliente(Cliente *clientes, int quantidadeClientes) {
    int id, achou, opcao;
    printf("--------------+++ EXCLUSAO CLIENTE +++--------------\n");
    printf("Entre com o id do cliente: ");
    scanf("%d", &id);
    for (int i = 0; i < quantidadeClientes; i ++) {
        if (clientes[i].id == id) {
            printf("Nome cliente: %s\n", clientes[i].nome);
            printf("Cpf cliente: %s\n", clientes[i].cpf);
            printf("Data de nascimento cliente: %s\n", clientes[i].dataNascimento);
            printf("E-mail cliente: %s\n", clientes[i].email);
            printf("Telefone cliente: %s\n", clientes[i].telefone);
            printf("Curso matriculado: %s\n\n", clientes[i].cursoMatriculado);
            achou = 1;
            printf("Deseja realmente excluir o cliente\n0 - Cancelar \n1 - Excluir: ");
            scanf("%d", &opcao);
            while (opcao != 1 && opcao != 0) {
                printf("opcao invalida, tente novamente: ");
                scanf("%d", &opcao);
            }
            if (opcao == 1){
                clientes[i].id = -1;
                printf("Cliente excluido com sucesso!");
                getchar();
                getchar();
            }
        }
    }
    if (achou == 0) {
        printf("Cliente nao encontrado");
        getchar();
        getchar();
    }
}

// Listagem de todos os clientes cadastrados, menos os que tem o id de -1, que são os excluídos.
void consultarClientes(Cliente *clientes, int quantidadeClientes) {
    printf("--------------+++ CONSULTA CLIENTES +++--------------\n");
    for (int i = 0; i < quantidadeClientes; i ++) {
        if (clientes[i].id != -1 ) {
            printf("Id cliente: %d\n", clientes[i].id);
            printf("Nome cliente: %s\n", clientes[i].nome);
            printf("Cpf cliente: %s\n", clientes[i].cpf);
            printf("Data de nascimento cliente: %s\n", clientes[i].dataNascimento);
            printf("E-mail cliente: %s\n", clientes[i].email);
            printf("Telefone cliente: %s\n", clientes[i].telefone);
            printf("Curso matriculado: %s\n", clientes[i].cursoMatriculado);
            printf("---------------------------------------------------------\n");
        }
    }
    getchar();
    getchar();
}

// Tela principal do gerenciamento de clientes.
void gerenciamentoClientes(Cliente *clientes, int *quantidadeClientes) {
    int opcao;
    do {
        int quantidadeClientesValor = *quantidadeClientes;
        system("cls");
        printf("--------------+++ GERENCIAMENTO DE CLIENTES +++--------------\n");
        printf("1 - Cadastrar um cliente\n");
        printf("2 - Consultar cliente\n");
        printf("3 - Consultar todos os clientes\n");
        printf("4 - Excluir cliente\n");
        printf("0 - Voltar ao menu\n");
        printf("--------------------");
        printf("\nEscolha sua opcao: ");
        scanf("%d", &opcao);

        while (opcao > 4 || opcao < 0) {
            printf("Opcao invalida, tente novamente: ");
            scanf("%d", &opcao);
        }
        system("cls");
        switch (opcao) {
            case 1:
                cadastroCliente(clientes, quantidadeClientesValor);
                (*quantidadeClientes) ++;
                break;
            case 2:
                consultarCliente(clientes, quantidadeClientesValor);
                break;
            case 3:
                consultarClientes(clientes, quantidadeClientesValor);
                break;
            case 4:
                excluirCliente(clientes, quantidadeClientesValor);
                break;
        }
    } while (opcao != 0);
}

// Cadastro de funcionários,
void cadastroFuncionario(Funcionario *funcionarios, int quantidadeFuncionarios) {
    char confirmarSenha[120];
    funcionarios[quantidadeFuncionarios].id = quantidadeFuncionarios + 1;
    // O Id do funcionários será a quantidade de funcionários + 1, para que assim não exista funcionário de ID = 0
    printf("--------------+++ CADASTRO DE FUNCIONARIO +++--------------\n");
    printf("Criacao de funcionario de ID: %d\n", quantidadeFuncionarios + 1);
    printf("Entre com o nome do funcionario: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios].nome);
    printf("Entre com o cpf do funcionario: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios].cpf);
    printf("Entre com a data de nascimento do funcionario: (dd-mm-aaaa) ");
    scanf("%s", &funcionarios[quantidadeFuncionarios].dataNascimento);
    printf("Entre com o e-mail do funcionario: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios].email);
    printf("Entre com o telefone do funcionario: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios].telefone);
    printf("Entre com o cargo: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios].cargo);
    printf("Entre com o login: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios].login);
    printf("Entre com a senha: ");
    scanf("%s", &funcionarios[quantidadeFuncionarios].senha);
    printf("Confirme a senha: ");
    scanf("%s", &confirmarSenha);
    // caso as senhas sejam divergentes, é perguntado ao usuário novamente a senha e a confimação de senha
    while (strcmp(funcionarios[quantidadeFuncionarios].senha, confirmarSenha) != 0) {
        printf("Senhas divergentes, tente novamente\n");
        printf("Entre com a senha: ");
        scanf("%s", &funcionarios[quantidadeFuncionarios].senha);
        printf("Confirme a senha: ");
        scanf("%s", confirmarSenha);
    }
    system("cls");
    printf("Funcionario cadastrado com sucesso!");
    getchar();
    getchar();
}

void consultarFuncionario(Funcionario *funcionarios, int quantidadeFuncionarios) {
    int id, achou;
    printf("--------------+++ CONSULTA FUNCIONARIO +++--------------\n");
    printf("Entre com o ID do funcionario: ");
    scanf("%d", &id);
    // Se a id for menor que 0 ou maior que o número de funcionários será uma consulta inválida
    while (id < 0 || id > quantidadeFuncionarios) {
        printf("ID invalido, tente novamente: (0 - para sair)");
        scanf("%d", &id);

        if (id == 0) {
            return;
        }
    }
    
    // Verificando em todos os funcionários cadastrados para ver se algum tem o id que o usuário digitou
    for (int i = 0; i < quantidadeFuncionarios; i ++) {
        if (funcionarios[i].id == id) {
            printf("Nome funcionario: %s\n", funcionarios[i].nome);
            printf("Cpf funcionario: %s\n", funcionarios[i].cpf);
            printf("Data de nascimento funcionario: %s\n", funcionarios[i].dataNascimento);
            printf("E-mail funcionario: %s\n", funcionarios[i].email);
            printf("Telefone funcionario: %s\n", funcionarios[i].telefone);
            printf("Cargo: %s\n", funcionarios[i].cargo);

            // caso encontre o usuário ele lista na tela e atribribui o valor 1 para a variável achou
            achou = 1;
        }
    }

    // se a variável achou for igual a 0, significa que não achou
    if (achou == 0) {
        printf("Funcionario nao encontrado");
        getchar();
        getchar();
    }
    getchar();
    getchar();

}

// Listagem de todos os funcionários cadastrados, menos os que tem o id de -1, que são os excluídos.
void consultarFuncionarios(Funcionario *funcionarios, int quantidadeFuncionarios) {
    printf("--------------+++ CONSULTA FUNCIONARIOS +++--------------\n");
    for (int i = 0; i < quantidadeFuncionarios; i ++) {
        if (funcionarios[i].id != -1 ) {
            printf("Id funcionario: %d\n", funcionarios[i].id);
            printf("Nome funcionario: %s\n", funcionarios[i].nome);
            printf("Cpf funcionario: %s\n", funcionarios[i].cpf);
            printf("Data de nascimento funcionario: %s\n", funcionarios[i].dataNascimento);
            printf("E-mail funcionario: %s\n", funcionarios[i].email);
            printf("Telefone funcionario: %s\n", funcionarios[i].telefone);
            printf("Cargo: %s\n", funcionarios[i].cargo);
            printf("---------------------------------------------------------\n");
        }
    }
    getchar();
    getchar();
}

// É verificado em todos os clientes para caso algum tenha o id informado, se tiver atribui o valor de ID para -1. Com o ID de -1 o cliente não será listado em nenhuma consulta.
void excluirFuncionario(Funcionario *funcionarios, int quantidadeFuncionarios) {
    int id, achou, opcao;
    Funcionario funcionarioNovo;
    printf("--------------+++ EXCLUSÃO FUNCIONARIO +++--------------\n");
    printf("Entre com o ID do funcionario: ");
    scanf("%d", &id);
    for (int i = 0; i < quantidadeFuncionarios; i ++) {
        if (funcionarios[i].id == id) {
            printf("Nome funcionario: %s\n", funcionarios[i].nome);
            printf("Cpf funcionario: %s\n", funcionarios[i].cpf);
            printf("Data de nascimento funcionario: %s\n", funcionarios[i].dataNascimento);
            printf("E-mail funcionario: %s\n", funcionarios[i].email);
            printf("Telefone funcionario: %s\n", funcionarios[i].telefone);
            printf("Cargo: %s\n", funcionarios[i].cargo);
            achou = 1;
            printf("Deseja realmente excluir o funcionario\n0 - Cancelar \n1 - Excluir: ");
            scanf("%d", &opcao);
            while (opcao != 1 && opcao != 0) {
                printf("opcao invalida, tente novamente: ");
                scanf("%d", &opcao);
            }
            if (opcao == 1){
                funcionarios[i].id = -1;
                printf("Funcionario excluido com sucesso!");
                getchar();
                getchar();
            }
        }
    }
    if (achou == 0) {
        printf("Funcionario nao encontrado");
        getchar();
        getchar();
    }
}

// tela principal de gerenciamento de funcionários
void gerenciamentoFuncionario(Funcionario *funcionarios, int *quantidadeFuncionarios) {
    int opcao;
    do {
        int quantidadeFuncionariosValor = *quantidadeFuncionarios;
        system("cls");
        printf("--------------+++ GERENCIAMENTO DE FUNCIONARIOS +++--------------\n\n");
        printf("1 - Cadastrar um funcionario\n");
        printf("2 - Consultar funcionario\n");
        printf("3 - Consultar todos os funcionarios\n");
        printf("4 - Excluir funcionario\n");
        printf("0 - Voltar ao menu\n\n");
        printf("--------------------");
        printf("\nEscolha sua opcao: ");
        scanf("%d", &opcao);

        while (opcao > 4 || opcao < 0) {
            printf("Opcao invalida, tente novamente: ");
            scanf("%d", &opcao);
        }
        system("cls");
        switch (opcao) {
            case 1:
                cadastroFuncionario(funcionarios, quantidadeFuncionariosValor);
                (*quantidadeFuncionarios) ++;
                break;
            case 2:
                consultarFuncionario(funcionarios, quantidadeFuncionariosValor);
                break;
            case 3:
                consultarFuncionarios(funcionarios, quantidadeFuncionariosValor);
                break;
            case 4:
                excluirFuncionario(funcionarios, quantidadeFuncionariosValor);
                break;
        }
    } while (opcao != 0);
}

// Relatórios simples, é mostrados o número total de clientes e funcionários
void relatorio(Cliente *clientesCadastrados, Funcionario *funcionariosCadastrados, int *quantidadeCliente, int *quantidadeFuncionario) {
    printf("--------------+++ RELATORIO +++--------------\n");
    int clientesCadastradosValor = *quantidadeCliente;
    int funcionariosCadastradosValor = *quantidadeFuncionario;

    printf("Total de clientes cadastrados: %d\n", clientesCadastradosValor);
    printf("Total de funcionarios cadastrados: %d\n", funcionariosCadastradosValor);
    getchar();
    getchar();
}

// Menu principal
void menu(Cliente *clientesCadastrados, Funcionario *funcionariosCadastrados, int *quantidadeCliente, int *quantidadeFuncionario) {
    int opcao;
    do {
        system("cls");
        printf("--------------+++ MENU PRINCIPAL +++--------------\n");
        printf("1 - Gerenciamento de clientes\n");
        printf("2 - Gerenciamento de funcionarios\n");
        printf("3 - Acessar relatorios\n");
        printf("0 - Sair\n\n");
        printf("Escolha sua opcao: ");
        scanf("%d", &opcao);

        // caso a opcao seja maior que o número de opcoes, ou menor que 0, será uma opcao inválida
        while (opcao > 3 || opcao < 0) {
            printf("Opcao invalida, tente novamente: ");
            scanf("%d", &opcao);
        }

        system("cls");
        switch (opcao) {
            case 1:
                gerenciamentoClientes(clientesCadastrados, quantidadeCliente);
                break;
            case 2:
                gerenciamentoFuncionario(funcionariosCadastrados, quantidadeFuncionario);
                break;
            case 3:
                relatorio(clientesCadastrados, funcionariosCadastrados, quantidadeCliente, quantidadeFuncionario);
                break;
        }
    } while (opcao != 0);
    return;
}

int recuperarSenhar() {
    char user[15];
    int opcao;
    int id, senha=0, senha2=1;
    do {
        system("cls");
        printf("--------------+++ RECUPERAR SENHA +++--------------\n");
        printf("\nDigite o nome de usuario: ");
        scanf("%s", &user);
        printf("\nDigite o ID do seu usuario: ");
        scanf("%d", &id);
        if (id != 123) {
            system("cls");
            printf("\nID nao pertence a esse usuario");
            getchar();
            getchar();
        } else {
            printf("\nDigite a sua nova senha de 4 digitos: ");
            scanf("%d", &senha);
            printf("Repita a sua nova senha de 4 digitos: ");
            scanf("%d", &senha2);
        }
        if (senha == senha2) {
            printf("\nNova senha cadastrado com sucesso!\n\n");
            getchar();
            getchar();
            return 1;
        } else if(senha != 0 && senha2 != 1) {
            system("cls");
            printf("\nSenhas divergentes, tente novamente (0 - para sair, 1 - para continuar): ");
            scanf("%d", &opcao);
            while (opcao != 0 && opcao != 1)
            {
                printf("\nOpcao incorreta, tente novamente: ");
                scanf("%d", &opcao);
            }

            if (opcao == 0){
                return 0;
            }
            senha = 0;
            senha2 = 1;
        }
    } while(senha != senha2);
}


int login() {
    char usuario[30];
    char senha[30];
    int opcao;
    do {
        system("cls");
        printf("--------------+++ TELA DE LOGIN +++--------------\n");
        printf("Entre com o usuario: ");
        scanf("%s",&usuario);
        printf("Entre com a senha: ");
        scanf("%s",&senha);
        if(strcmp(usuario,"admin") != 0 || strcmp(senha,"admin") != 0 ){
            printf("\nUsuario ou senha incorretos, deseja tentar novamente? (0 - para sair, 1 - para continuar): \n");
            scanf("%d", &opcao);
            while(opcao != 1 && opcao != 0) {
                printf("Opcao incorreta, tente novamente: ");
                scanf("%d", &opcao);
            }
            if (opcao == 0){
                return 0;
            }
        }
    } while(strcmp(usuario,"admin") != 0 || strcmp(senha,"admin") != 0);
    return 1;
}

int inicio()
{
    int opcao;
    do {
        system("cls");
        printf("------------+++ Bem vindo ao gestao B&L +++----------------\n");
        printf("\n1- Efetuar login");
        printf("\n2- Esqueci senha");
        printf("\n0- Sair do programa\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        while(opcao > 2 || opcao < 0) {
            printf("opcao incorreta, tente novamente");
            scanf("%d", &opcao);
        }
        system("cls");
        switch (opcao)
        {
            case 1:
                if (login() == 1){
                    return 1;
                } 
                break;
            case 2:
                if (recuperarSenhar() == 1){
                    return 1;
                } 
                break;
        }

    } while(opcao != 0);
    return 0;
}

void main() {
    // As variáveis são declaradas na main para que não sejam sobrescritas nos métodos. As variáveis quantidadeCliente e quantidadeFuncionarios são passadas por referência, isso é, o valor que é atribuido à elas nas funções é mantido independente da função.
    Cliente clientesCadastrados[1000];
    Funcionario funcionariosCadastrados[1000];
    int quantidadeCliente, quantidadeFuncionario;
    if (inicio() == 1){
        menu(clientesCadastrados, funcionariosCadastrados, &quantidadeCliente, &quantidadeFuncionario);
    }
}