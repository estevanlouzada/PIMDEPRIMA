#include <stdio.h>
#include<string.h>
#include <stdbool.h>

struct endereco
{
    char Rua[60];
    char Numero[60];
    char bairro[60];
    char cidade[60];
    char estado[60];
    char CEP[60];
};

struct Paciente
{
    char Nome[60];
    char CPF[60];
    char Telefone[60];
    char DataNascimento[60];
    char Email[60];
    char DataDiagnostico[60];
    struct endereco endereco;
    char comorbidade[60];
};

 enum Estados {
     ESTADO_LOGIN = 0,
     ESTADO_LOGADO = 1,
     ESTADO_CADASTRO = 2
 };

  char LOGIN[] = "Estevan";
  char SENHA[] = "admin";
  int USUARIOLOGADO = 0;

  void LoginUsuario( int * estado)
  {
    char senha[20];
    char login[20];

    puts("Menu de entrada faça o login : \n");
    printf("login: ");
    scanf("%s", login);
    puts("Senha :");
    scanf("%s", senha);

    int compara_senha = strcmp(senha, SENHA);
    int compara_login = strcmp(login, LOGIN);

    if(compara_senha == 0 && compara_login == 0)
    {
         puts("senha bateu");
        *estado = 1;
       
    } else {
        puts("senha não bateu ");
        *estado = 0;
    }
  }

  void UsuarioLogado(int * estado, bool * exit)
  {
            int escolha;
              puts("Usuario logado com sucesso \n");
              puts("Deseja cadastrar um novo usuario ?");
              puts("se sim : 1 ");
              puts("se nao : 2 ");
              scanf("%d", &escolha);
              if(escolha == 2)
              {
                   *exit = true;
              }
              if(escolha == 1)
              {
                   *estado = 2;
              }
  }

  void CadastroDePaciente(int * estado, bool * exit)
  {
      struct Paciente paciente; 
      puts("Cadastro dos dados pessoais do paciente");
      puts("Informe os dados pessoais do paciente");
      puts("Nome: ");
      scanf("%s", &paciente.Nome);
      puts("CPF:");
      scanf("%s", &paciente.CPF);
      puts("Telefone:");
      scanf("%s", &paciente.Telefone);
      puts("Endereco rua:");
      scanf("%s", &paciente.endereco.Rua);
      puts("numero:");
      scanf("%s", &paciente.endereco.Numero);
      puts("bairro:");
      scanf("%s", &paciente.endereco.bairro);
      puts("cidade:");
      scanf("%s", &paciente.endereco.cidade);
      puts("estado:");
      scanf("%s", &paciente.endereco.estado);
      puts("CEP:");
      scanf("%s", &paciente.endereco.CEP);
      puts("Data de nascimento:");
      scanf("%s", &paciente.DataNascimento);
      puts("E-mail:");
      scanf("%s", &paciente.Email);
      puts("Data do diagnóstico:");
      scanf("%s", &paciente.DataDiagnostico);
      puts("Comorbidade do paciente:");
      scanf("%s", &paciente.comorbidade);

      FILE *fh;

        /* open/create the file */
        fh = fopen("registroPaciente.txt","a");
        if( fh == NULL )
        {
            puts("Falha o inserir o registro.");
            *exit = true;
        }


        /* write the 10 structures */
        fprintf(fh, "Nome:%s \n CPF:%s \n Telefone:%s \n Endereco rua:%s \n numero:%s \n bairro:%s \n cidade:%s \n estado:%s \n CEP:%s \n Data de nascimento:%s \n E-mail:%s \n Data do diagnóstico:%s \n Comorbidade do paciente:%s \n", 
        paciente.Nome,
        paciente.CPF,
        paciente.Telefone,
        paciente.endereco.Rua,
        paciente.endereco.Numero,
        paciente.endereco.bairro,
        paciente.endereco.cidade,
        paciente.endereco.estado,
        paciente.endereco.CEP,
        paciente.DataNascimento,
        paciente.Email,
        paciente.DataDiagnostico,
        paciente.comorbidade);

        puts("cadastro feito com sucesso !!");

        int opcoes;
        puts("1 - sair \n 2 - novo cadastro \n");
        scanf("%d",&opcoes );
       // if(opcoes == 1){ }
        if(opcoes == 1){ *exit = true;}

        /* close the file */
        fclose(fh);

  }

int main (int argc, char *argv[]) {

          bool exit = false;

    
    enum Estados AtualEstado;
    AtualEstado = ESTADO_LOGIN;
    int _estado = 0;
    do{
        switch (_estado)
        {

        case ESTADO_LOGIN:
            LoginUsuario(&_estado);
            break;
        case ESTADO_LOGADO:
           UsuarioLogado(&_estado, &exit);
            break;
        case ESTADO_CADASTRO:
            CadastroDePaciente(&_estado, &exit);
            break;
        default:
            break;
        }

        
    }while(exit == false);
    

    puts("Obrigao por utilizar o sistema sus de cadastros.");

   

   return 0;
}   