#include <stdio.h>
#include "ProfissionalSaude.h"
#include <stdbool.h>
#include "fileManager.h"
#include <string.h>

enum
{
    TelaMenuInicial = 1,
    TelaLogado = 2,
    Sair = 3
} StatesTela;

void TelaCadastroDeNovoLogin()
{

}

void VerificacaoDeSenha()
{

}

void TelaMenuInicial1()
{
    printf("MENU DE ATENDIMENTO\n ");
    printf("Faça seu login de usuario \n");
    char login[255];
    scanf("%s", login);
}

bool VerificaExistenciaDecadastro()
{
    // TODO : Verifica se existe o txt e se existir procura o login utilizado
    return true;
}

bool VerificaSenha(char senha[255])
{
    // TODO: procura a senha do usuario de login para bater
    return true;
}
void CadastroDeNovoLogin()
{
    //TODO: insere no arquivo o novo login
}
bool ConfirmacaoParaRegistroDeCadastro()
{
    printf("Login não cadastrado . \n");
    printf("Deseja cadastrar o login ? \n");
    printf("Se sim S não N : ");
    char escolha;
    scanf("%s", escolha);

    if (escolha == 'S')
    {
        return true;
    }
    else
    {

        return false;
    }
}

int MenuInicial1(FILE * p )
{
    // Menu Inicial - 1
    TelaMenuInicial1();

    if (VerificaExistenciaDecadastro())
    {
        VerificacaoDeSenha();
        return TelaLogado;
    }
    else
    {
        // TODO : registro de novo cadastro
        if (ConfirmacaoParaRegistroDeCadastro())
        {
            TelaCadastroDeNovoLogin();

            return TelaMenuInicial;
        }
        else
        {
            return TelaMenuInicial;
        };
    }
}

void cadastroDeNovoPaciente()
{
    struct profissionalSaude novo;
    struct endereco novoEndereco;
    // TODO : abre o txt e grava um novo paciente

    printf("\n Nome: ");
    scanf("%s", novo.Nome);

    printf("\n CPF: ");
    scanf("%s", novo.CPF);

    printf("\n Telefone: ");
    scanf("%s", novo.Telefone);

    printf("\n DataNascimento: ");
    scanf("%s", novo.DataNascimento);

    printf("\n Email: ");
    scanf("%s", novo.Email);

    printf("\n DataDiagnostico: ");
    scanf("%s", novo.DataDiagnostico);

    printf("\n Tem comorbidade ?: \n 1 - diabetes\n 2 - obesidade,\n 3 - hipertensao,\n 4 - tuberculose,\n 5 - outro \n 6 - Sem comorbidade");
    scanf("d", novo.comorbidade);

    printf("\n Rua: ");
    scanf("%s", novoEndereco.Rua);

    printf("\n bairro: ");
    scanf("%s", novoEndereco.bairro);

    printf("\n cidade: ");
    scanf("%s", novoEndereco.cidade);

    printf("\n estado: ");
    scanf("%s", novoEndereco.estado);

    printf("\n CEP: ");
    scanf("%s", novoEndereco.CEP);

    // TODO: calculo de idade do paciente 
    // TODO: Idade maior que 65 anos salvar Idade e o CEP 
    // estrutura do novo paciente completa pode ser gravada
}

int UsarioLogado()
{
    // TODO: Menu de uma usuario logado
    printf("1 - Cadastrar novo paciente . \n");
    printf("Se sim S se não N  ou Exit para s .. \n");
    
    char opcao;

    switch (opcao)
    {
    case 'S':
        /* TODO: cadastro de novo paciente */
        cadastroDeNovoPaciente();
        break;
    case 'N':
        /* code */
        break;

    case 's':

        break;
    default:
        break;
    }
}

int main(int argc, char *argv[])
{

    FILE *Ponteiro;
    Ponteiro = fopen("arquivo.txt", "a");
    fclose(Ponteiro);

    bool exit = false;
    StatesTela = 1;
    do
    {

        switch (StatesTela)
        {
        case TelaMenuInicial:
            StatesTela = MenuInicial1(Ponteiro);
            break;

        case TelaLogado:

            break;

        case Sair:
            exit = true;
            break;

        default:
            break;
        }

    } while (exit == false);

    // TODO: salvar em texto o cep a idade do paciente

    return 0;
}