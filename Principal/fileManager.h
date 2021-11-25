#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

// char *get_string(char *ptr, int size)
// {
//    int offset = 0;

//    char Aux[size];

//    for (size_t i = 0; i < size; i++)
//    {
//       char * ptr_caracter = *(ptr + offset);
//       Aux[i] = ptr_caracter;
//       ++offset;
//    }

//   return 
// }

char *string_AddChar(char n, char *str)
{

   if (str == NULL)
      return str;

   int tamanho = size(str);
   /*
   char Aux[] = get_string(str, tamanho);
   char *new_char = malloc(++tamanho);

   free(str);

   
   
   for (size_t i = 0; i < ++tamanho; i++)
   {
      new_char = Aux[i];
   }
   new_char[++tamanho] = '\0';

   return new_char;
   */
}

void OpenFileAndRead(FILE *fptr)
{
   char *word;
   char **dictionary;

   word = (char *)malloc(sizeof(char));
   dictionary = (char **)malloc(sizeof(char *));

   int idx = 0;    // index of word
    int widx = 0;   // index of char in word

   fptr = fopen("Arquivo.txt", "r");

   if (fptr == NULL)
   {
      printf("Não foi possivel abrir o arquivo");
   }
      
   char ch;

   while ((ch = getc(fptr)) != EOF)
   {
        if(ch == ';')
        {
            widx++;
            word = (char *)realloc(word, sizeof(char) * (widx));
            *(word + widx-1) = '\0'; // add no final \0
            idx++;
            dictionary = (char **)realloc(dictionary, sizeof(char *) * (idx));
            *(dictionary+idx-1) = word; // add word 
            widx = 0;
            word = NULL;

        } else{

            widx++;
            word = (char *)realloc(word, sizeof(char) * (widx));
            *(word + widx-1) = (char)ch;
        }
   }

    // print words
    int n = idx;
    for(int i = 0; i < n; i++){
        printf("%d - %s \n", i, *(dictionary+i));
        if(i == 0)
        {
           // comparar a string com o nome
           char nome[]  = "estevan"; 
           char *replicaword;
           replicaword = *(dictionary+i);

           if( strcmp(replicaword, nome) == 0)
           {
               printf("entrou");
           };
        }
    }

   fclose(fptr);
}
// read file 

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