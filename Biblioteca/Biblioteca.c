//Janielson da Silva Moura
//Riquelmy Costa da silva

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

//comentario
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

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
    int disponivel;
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
    Livros livro[3];
} Aluno;

void limparTela();
void limparPausarTela();
void menuLogin();
void menuCadastroAdm();
void menuAdm();
void cadastrarFuncionario();
void cadastrarAluno();
void exibirCurso();
void cadastroCurso();
void cadastrarLivro();
void menuFuncionario();
void exibirLivros();
void emprestimoLivro();
void devolucaoLivro();
void exibirAluno();

Funcionario func[MAX];
Aluno alunos[MAX];
Curso cursos[MAX];
Livros livros[MAX];

int main()
{

    setlocale(LC_ALL, "Portuguese");

    menuLogin();
    return 0;
}

void limparTela()
{
    system("cls");
}

void limparPausarTela()
{
    system("pause");
    limparTela();
}

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
}

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
            case 2:emprestimoLivro();
                limparTela();
                /* code */
                break;
                //3 - Devolução
            case 3:
                limparTela();
                /* code */
                break;
                //4 - Relatorio
            case 4:
                limparTela();
                /* code */
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
}

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
            cadastrarLivro();
            /* code */
            break;
        case 4:
            limparTela();
            cadastrarAluno();
            break;
        case 0:
            limparTela();
            break;

        default:
            isValid = 0;
            break;
        }
    } while (!isValid);
}

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
                cadastrarAluno();
                break;

            //2 - Emprestimo
            case 2:
                limparTela();
                break;
            //3 - Devolucação
            case 3:
                limparTela();
                /* code */
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
}
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

void cadastrarAluno()
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
    limparPausarTela();
} //fim do procedimento de cadastro de alunos

void exibirCurso()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%d - %s - %s\n", i, cursos[i].nome_curso, cursos[i].area);
    } //fim do for para exibir a lista de livros
} //fim do procedimento para exibição dos livros

void cadastroCurso()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("Nome do Curso:");
        fflush(stdin);
        gets(cursos[i].nome_curso);

        printf("\nÁrea:");
        fflush(stdin);
        gets(cursos[i].area);
    } //fim for do cadastro de cursos
    limparPausarTela();
} //fim procedimento de cdastro de cursos

void cadastrarLivro()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
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

        livros[i].disponivel =1;
        livros[i].disponivel =1;
    }
}

void exibirLivros()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n%d - %s - %s", i, livros[i].nome_livro, livros[i].cursos.area);
    }//for de exibição de livros
}//fim do procedimento de exibir livros

void exibirAluno(){
    int i;
    for(i=0;i<MAX;i++){
        printf("\n%d - %s - %d",i,alunos[i].nome_aluno,alunos[i].matricula);
    }//fim do fo de exibição de aluno
}//fim do procedimento para exibir aluno

void emprestimoLivro()
{
    int selectAluno;
    printf("\nAlunos:\n");
    exibirAluno();
    printf("\nSelecione um aluno:");
    scanf("%d",&selectAluno);

    int selectLivro;
    printf("Livros:");
    exibirLivros();
    scanf("%d", selectLivro);
    int continuarSelecao = 1;
    ///int 
    int cont= 0;
    do{
        printf("Selecione um livro:");
        scanf("%d",&selectLivro);
        if(alunos[selectAluno].livrosEmprestados<=3){   
            alunos[selectAluno].livro[cont]=livros[selectLivro];
        }

        printf("\nDeseja emprestar outro livro? 1 -sim, 0- nao:");
        scanf("%d",&continuarSelecao);
        cont++;
        alunos[selectAluno].livrosEmprestados=cont;
    }while(continuarSelecao);

}//fim do procedimento de emprestimo
void devolucaoLivro()
{
     int selectAluno;
     exibirAluno();
     prinf("");

     int selectLivro;
}//fim do procedimento de devolução