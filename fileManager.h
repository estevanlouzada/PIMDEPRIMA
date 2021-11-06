#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include <stdio.h>

struct fileManage
{
   FILE *File;

   void (*OpenFileAndRead)(FILE *fptr);

   void *OpenWriteOverrrideAndCreateFile;

   void (*OpenAndReadAndWrite)(FILE *fprt);
};

enum
{
   NOME,
   SENHA
} USUARIO;

struct usuario_log
{
   char *Nome;
   char *Senha;

} usuario_log;

int size(char *ptr)
{
   //variable used to access the subsequent array elements.
   int offset = 0;
   //variable that counts the number of elements in your array
   int count = 0;

   //While loop that tests whether the end of the array has been reached
   while (*(ptr + offset) != '\0')
   {
      //increment the count variable
      ++count;
      //advance to the next element of the array
      ++offset;
   }
   //return the size of the array
   return count;
}

char *get_string(char *ptr, int size)
{

   int offset = 0;

   char Aux[size];

   for (size_t i = 0; i < size; i++)
   {
      Aux[i] = *(ptr + offset);
      ++offset;
   }

   return Aux;
}

char *string_AddChar(char n, char *str)
{

   if (str == NULL)
      return str;

   int tamanho = size(str);
   char Aux[] = get_string(str, tamanho);
   char *new_char = malloc(++tamanho);

   free(str);

   for (size_t i = 0; i < ++tamanho; i++)
   {
      new_char = Aux[i];
   }
   new_char[++tamanho] = '\0';

   return new_char;
}

void OpenFileAndRead(FILE *fptr)
{
   fptr = fopen("Arquivo.txt", "r");

   if (fptr == NULL)
      printf("Não foi possivel abrir o arquivo");

   printf("Conteudo do arquivo ");
   char ch;

   char text[500][100];

   int row = 0;
   int columns = 0;

   int usuario_struct = 0;

   char *str;
   int escrit = 0;

   struct usuario_log user;

   while ((ch = fgetc(fptr)) != EOF)
   {
      if (ch == '\n')
      {
         row = 0;
         text[columns++][row];
      }
      else if (ch == ';')
      {
         switch (usuario_struct)
         {

            case (int)NOME:
               usuario_struct++;
               unsigned int len = strlen(str);
               strncpy(&user.Nome, str, len);
               break;

            case (int)SENHA:
               usuario_struct++;
               unsigned int len3 = strlen(str);
               strncpy(&user.Senha, str, len3);
               break;

            default:
               usuario_struct = 0;
               break;
         }

         str = NULL;
      }
      else
      {
         text[columns][row] = ch;
         str[escrit++] = ch;
      }

      printf("%c", ch);

      text[columns][row++];
   }

   fclose(fptr);
}

void OpenWriteOverrrideAndCreateFile(FILE *fptr)
{
   fptr = fopen("PathFile", "w");
   if (fptr == NULL)
      printf("Não foi possivel abrir o arquivo");
}

void OpenAndReadAndWrite(FILE *fptr)
{
   fptr = fopen("PathFile", "r+");
   if (fptr == NULL)
      printf("Não foi possivel abrir o arquivo");
}

void OpenForAppend(FILE *fptr)
{
   fptr = fopen("PathFile", "a");
   if (fptr == NULL)
      printf("Não foi possivel abrir o arquivo");
}

void OpenForAppendAndReading(FILE *fptr)
{
   fptr = fopen("PathFile", "a+");
   if (fptr == NULL)
      printf("Não foi possivel abrir o arquivo");
}

void WriteInFileTheString(char *str, FILE *ftpr)
{
   fprintf(ftpr, "%s", str);
}

void ReadFromFileString(char *str, FILE *ftpr)
{
   fscanf(ftpr, "%d", str);
}

#endif