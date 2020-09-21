//Janielson da Silva Moura
//Riquelmy Costa da silva
//Pedro Marinho

/*
1) faça um sistema para controlar biblioteca, O administrador geral cadastra:

Cadastrar Funcionário: nome, matricula, login,senha.
Cadastrar Livro: Nome, ISBN, curso.
Cadastrar Curso: nome, área.

Ao cadastrar o livro é exibido a lista de curso e o administrador associa ao livro. O administrador cadastra
 o aluno: nome, matricula e curso. O administrador realiza empréstimo: só poderá emprestar livro para alunos 
 matriculados, o aluno poderá emprestar até 3 livros. O administrador realiza devolução livro.

Pesquisa:

O nome do aluno, verificar os livros emprestados e devolve o livro deixando disponível no sistema para o 
próximo aluguel. O administrador terá relatório de livros emprestados, o aluno, o curso.

O funcionário realiza o cadastro dos alunos, empréstimo livro, devolução livro.

A) todos os cadastros no minimo.
B) procedimento.
C) registro.
*/

/*
cadastro de alunos
alunos: joao
matricula:123
aluno:maria
matricula:456

cadastro de curso
nome do curso: ti
area:exatas
nome do curso:medicina
area:biologicas

cadastro de livros
nome:Dom Quixote
isbn:997
nom:Guerra e Paz
isbn:99933


funcionario
nome:fabio
matricula:10
login:fabio 
senha:fabio
nome:joana
matricula:11
login:joana
senha:joana


*/

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//define o max de elementos que podem ser cadastrados
#define MAX 2

typedef struct Curso
{
    char nome_curso[30];
    char area[30];
} Curso;

typedef struct Livros
{
    char nome_livro[30];
    int isbn;
    Curso cursos;
    int disponivel; //saber se livro esta disponível
} Livros;

typedef struct Funcionario
{
    char nome_funcionario[120];
    int matricula;
    char login[60];
    char senha[60];
} Funcionario;

typedef struct Aluno
{
    char nome_aluno[30];
    int matricula;
    int livrosEmprestados;
    Curso cursos;
    Livros livros[MAX];
} Aluno;

void limparTela();
void limparPausarTela();

// menus de controle
void menuLogin();
void menuCadastroAdm();
void menuGerarAdm();
void menuAdm();
void menuFuncionario();

//cadastro de funcionarios
void cadastrarFuncionario();
void gerarFuncionario();

//cadastro e exibição de alunos
void cadastrarAlunos();
void gerarAlunos();
void exibirAlunos();

//cadastro e exibição de cursos
void exibirCurso();
void cadastroCurso();

//cadastro e exibição de livros
void cadastrarLivros();
void gerarLivros();
void exibirLivros();
void exibirLivrosDisponiveis();
void exibirLivrosNaoDisponiveis();

// sistema de controller de livros
void emprestimoLivro();
void devolucaoLivro();

void relatorio();

Funcionario func[MAX];
Aluno alunos[MAX];
Curso cursos[MAX];
Livros livros[MAX];

int isCurso = 0;

int main()
{

    setlocale(LC_ALL, "Portuguese");

    menuLogin();
    return 0;
} //fim do main

void limparTela()
{
    system("cls");
} //fim procedimento

void limparPausarTela()
{
    system("pause");
    limparTela();
} //fim procedimento

void menuLogin()
{
    do
    {
        int isValid = 1;
        printf("\nTipo de Usuario\n");
        printf("\n1 - Administrador");
        printf("\n2 - Funcionario");
        printf("\n0 - Sair");
        int op;
        do
        {
            printf("\nEscolha uma opção:");
            scanf("%d", &op);
            switch (op)
            {
            case 1:
                limparTela();
                menuAdm();
                break;
            case 2:
                limparTela();
                menuFuncionario();
                break;
            case 0:
                exit(1);
                break;

            default:
                isValid = 0;
                break;
            }
        } while (!isValid);
    } while (1);
} //fim procedimento

void menuAdm()
{
    int continuar = 1;
    do
    {
        int isValid = 1;
        printf("\nSistema do Adm\n");
        printf("\n1 - Cadastros");
        printf("\n2 - Realizar Emprestimo");
        printf("\n3 - Realizar Devolução");
        printf("\n4 - Relatorio");
        printf("\n5 - Gerar");
        printf("\n0 - Sair");
        int op;
        do
        {
            printf("\nEscolha uma opção:");
            scanf("%d", &op);
            switch (op)
            {
                //1 - Cadastrados
            case 1:
                limparTela();
                menuCadastroAdm();
                break;
                //2 - Emprestimo
            case 2:
                limparTela();
                emprestimoLivro();
                /* code */
                break;
                //3 - Devolução
            case 3:
                limparTela();
                devolucaoLivro();
                break;
                //4 - Relatorio
            case 4:
                limparTela();
                relatorio();
                break;
            case 5:
                limparTela();
                menuGerarAdm();
                break;

            case 0:
                limparTela();
                continuar = 0;
                break;

            default:
                isValid = 0;
                break;
            }
        } while (!isValid);
    } while (continuar);
} //fim procedimento

void menuCadastroAdm()
{
    int isValid = 1;
    printf("\nSistema de Cadastro do Adm\n");
    printf("\n1 - Funcionario");
    printf("\n2 - Curso");
    printf("\n3 - Livros");
    printf("\n4 - Cadastro Aluno");
    printf("\n0 - Sair");
    int op;
    do
    {
        printf("\nEscolha uma opção:");
        scanf("%d", &op);
        switch (op)
        {
        /// 1 - Funcionario
        case 1:
            limparTela();
            cadastrarFuncionario();
            break;
        //2 - Curso
        case 2:
            limparTela();
            cadastroCurso();
            break;
        //3 - Livros
        case 3:
            limparTela();
            cadastrarLivros();
            /* code */
            break;
        case 4:
            limparTela();
            cadastrarAlunos();
            break;
        case 0:
            limparTela();
            break;

        default:
            isValid = 0;
            break;
        }
    } while (!isValid);
} //fim do procedimento

void menuGerarAdm()
{
    int isValid = 1;
    printf("\nSistema de Gerar do Adm\n");
    printf("\n1 - Funcionario");
    printf("\n2 - Curso");
    printf("\n3 - Livros");
    printf("\n4 - Aluno");
    printf("\n5 - Todos");
    printf("\n0 - Sair");
    int op;
    do
    {
        printf("\nEscolha uma opção:");
        scanf("%d", &op);
        switch (op)
        {
        /// 1 - Funcionario
        case 1:
            limparTela();
            gerarFuncionario();
            break;
        //2 - Curso
        case 2:
            limparTela();
            gerarCursos();
            break;
        //3 - Livros
        case 3:
            limparTela();
            gerarLivros();
            /* code */
            break;
        //Aluno
        case 4:
            limparTela();
            gerarAlunos();
            break;
        //Aluno
        case 5:
            limparTela();
            gerarFuncionario();
            gerarCursos();
            gerarLivros();
            gerarAlunos();
            break;
        case 0:
            limparTela();
            break;

        default:
            isValid = 0;
            break;
        }
    } while (!isValid);
} //fim do procedimento

void menuFuncionario()
{
    int continuar = 1;
    do
    {
        int isValid = 1;
        printf("\nSistema do Funcionario\n");
        printf("\n1 - Cadastro aluno");
        printf("\n2 - Emprestimo");
        printf("\n3 - Devolucação");
        printf("\n0 - Sair");
        int op;
        do
        {
            printf("\nEscolha uma opção:");
            scanf("%d", &op);
            switch (op)
            {
            ///1 - Cadastro aluno
            case 1:
                limparTela();
                cadastrarAlunos();
                break;

            //2 - Emprestimo
            case 2:
                limparTela();
                emprestimoLivro();
                break;
            //3 - Devolucação
            case 3:
                limparTela();
                devolucaoLivro();
                break;
            case 0:
                limparTela();
                continuar = 0;
                break;

            default:
                isValid = 0;
                break;
            }
        } while (!isValid);
    } while (continuar);
} //fim do procedimento
void cadastrarFuncionario()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n______________________________________________________\n");
        printf("Nome:");
        fflush(stdin);
        gets(func[i].nome_funcionario);

        printf("\nMatricula:");
        scanf("%d", &func[i].matricula);

        printf("\nLogin:");
        fflush(stdin);
        gets(func[i].login);

        printf("\nSenha:");
        fflush(stdin);
        gets(func[i].senha);
    } //fim for de cadastro de funcionario
    limparPausarTela();
} //fim do procedimento de cadastro de funcionario

void gerarFuncionario()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(func[i].nome_funcionario, "Funcionario %d", i);
        sprintf(func[i].matricula, "matricula%d", i);
        sprintf(func[i].login, "login%d", i);
        sprintf(func[i].senha, "senha%d", i);
    }
    printf("\nDados do Funcionario gerados automaticamente\n");
    limparPausarTela();
} //fim do procedimento

void cadastrarAlunos()
{
    if (isCurso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            printf("Nome:");
            fflush(stdin);
            gets(alunos[i].nome_aluno);

            printf("\nMatricula:");
            scanf("%d", &alunos[i].matricula);

            alunos[i].livrosEmprestados = 0;
        } //fim for de cadastro de funcionario
    }
    else
    {
        printf("\nNenhum Curso cadastrado\n");
    }
    limparPausarTela();
} //fim do procedimento de cadastro de alunos

void gerarAlunos()
{
    if (isCurso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            sprintf(alunos[i].nome_aluno, "Aluno %d", i);
            sprintf(alunos[i].matricula, "matricula%d", i);
            alunos[i].livrosEmprestados = 0;
        }
        printf("\nDados do Alunos gerados automaticamente\n");
    }
    else
    {
        printf("\nNenhum Curso cadastrado\n");
    }
    limparPausarTela();
} //fim do procedimento

void exibirCurso()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%d - %s - %s\n", i, cursos[i].nome_curso, cursos[i].area);
    } //fim do for para exibir a lista de livros
    printf("\n______________________________________________________\n");
} //fim do procedimento para exibição dos livros

void cadastroCurso()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n______________________________________________________\n");
        printf("Nome do Curso:");
        fflush(stdin);
        gets(cursos[i].nome_curso);

        printf("\nÁrea:");
        fflush(stdin);
        gets(cursos[i].area);
    } //fim for do cadastro de cursos
    isCurso = 1;
    limparPausarTela();
} //fim do procedimento de cadastro de cursos

void gerarCursos()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(cursos[i].nome_curso, "curso %d", i);
        sprintf(cursos[i].area, "area%d", i);
    }
    printf("\nDados do Alunos gerados automaticamente\n");
    isCurso = 1;
    limparPausarTela();
} //fim do procedimento

void cadastrarLivros()
{
    if (isCurso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            printf("\n______________________________________________________\n");
            printf("Nome do Livro:");
            fflush(stdin);
            gets(livros[i].nome_livro);

            printf("\nIsbn:");
            scanf("%d", &livros[i].isbn);

            int op;
            exibirCurso();
            printf("\nSelecione um curso:");
            scanf("%d", &op);

            livros[i].cursos = cursos[op];

            livros[i].disponivel = 1;
        }
    }
    else
    {
        printf("\nNenhum Curso cadastrado\n");
    }
    limparPausarTela();
}

void gerarLivros()
{
    if (isCurso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            sprintf(livros[i].nome_livro, "Livro %d", i);
            livros[i].isbn = i;
            livros[i].cursos = cursos[i];
            livros[i].disponivel = 1;
        }
        printf("\nDados do livros gerados automaticamente\n");
    }
    else
    {
        printf("\nNenhum Curso cadastrado\n");
    }
    limparPausarTela();
} //fim do procedimento

void exibirLivros()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n%d - %s - %s", i, livros[i].nome_livro, livros[i].cursos.area);
    } //for de exibição de livros
    printf("\n______________________________________________________\n");
} //fim do procedimento de exibir livros

void exibirLivrosDisponiveis()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (livros[i].disponivel)
        {
            printf("\n%d - %s - %s", i, livros[i].nome_livro, livros[i].cursos.area);
        }
    } //for de exibição de livros
    printf("\n______________________________________________________\n");
} //fim do procedimento de exibir livros

void exibirLivrosNaoDisponiveis()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (!livros[i].disponivel)
        {
            printf("\n%d - %s - %s", i, livros[i].nome_livro, livros[i].cursos.area);
        }
    } //for de exibição de livros
    printf("\n______________________________________________________\n");
} //fim do procedimento de exibir livros


void exibirAlunos()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n%d - %s", i, alunos[i].nome_aluno);
    } //fim do fo de exibição de aluno
    printf("\n______________________________________________________\n");
} //fim do procedimento para exibir aluno

void emprestimoLivro()
{
    int selectAluno;
    printf("\nAlunos:\n");
    exibirAlunos();
    printf("\nSelecione um aluno:");
    scanf("%d", &selectAluno);

    limparTela();

    int continuarSelecao = 1;

    int i;
    for (i = 0; i < MAX; i++)
    {
        int selectLivro;
        printf("Livros:");
        exibirLivrosDisponiveis();
        printf("\nSelecione um livro:");
        scanf("%d", &selectLivro);
        alunos[selectAluno].livros[i] = livros[selectLivro];

        alunos[selectAluno].livrosEmprestados = i;

        livros[selectLivro].disponivel = 0;


        printf("\nDeseja emprestar outro livro? 1 -sim, 0- nao:");
        scanf("%d", &continuarSelecao);
        limparTela();
        if (!continuarSelecao)
        {
            break;
        }
        
    }
} //fim do procedimento de emprestimo
void devolucaoLivro()
{
    int selectAluno;
    int i, op, a, l;
    //exibir livros emprestados
    printf("Livros empretados:\n");

    for (i = 0; i < MAX; i++)
    {
        if (!livros[i].disponivel)
        {
            printf("\n______________________________________________________\n");
            printf("%d - %s", i, livros[i].nome_livro);
        }
    }

    printf("Selecione o livro que deseja devolver:\n");
    scanf("%d", &op);

    //for para copmpararação do aluno ao livro
    for (a = 0; a < MAX; a++)
    {
        for (l = 0; l < MAX; l++)
        {
            if (alunos[a].livros[l].nome_livro == livros[op].nome_livro)
            {
                strcpy(alunos[a].livros[l].nome_livro, " ");
                alunos[a].livros[l].isbn = 0;
                alunos[a].livros[l].disponivel = 1;
                strcpy(alunos[a].livros[l].cursos.nome_curso, " ");
                strcpy(alunos[a].livros[l].cursos.area, " ");
            }
        }
    }
    printf("Devolução realizada!");
    limparPausarTela();
} //fim do procedimento de devolução


void relatorio(){
    int i,l;
   /* printf("Sistema de Relatorio");

    printf("Livros não disponíveis");
    exibirLivrosNaoDisponiveis();
    */
   printf("Sistema de Relatorio");

   for(i=0;i<MAX;i++){
       for(l=0;l<3;l++){
           if(alunos[i].livrosEmprestados>0){
               printf("%d - %s - ");
           }
       }
   }
   
}