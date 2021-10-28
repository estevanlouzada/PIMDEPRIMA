

typedef enum
{
    diabetes = 1,
    obesidade = 2,
    hipertensao = 3,
    tuberculose = 4,
    outro = 5,
    SemComorbidade = 6
} Comorbidade;

struct endereco
{
    char Rua[255];
    char Numero[255];
    char bairro[255];
    char cidade[255];
    char estado[255];
    char CEP[255];
};

struct profissionalSaude
{
    char Nome[255];
    char CPF[255];
    char Telefone[255];
    char DataNascimento[255];
    char Email[255];
    char DataDiagnostico[255];
    Comorbidade comorbidade;
};
