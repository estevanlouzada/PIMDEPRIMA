#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include <stdio.h>

struct fileManage
{
   FILE * File;

   void (* OpenFileAndRead)(FILE * fptr); 
  
   void * OpenWriteOverrrideAndCreateFile;

   void (* OpenAndReadAndWrite)(FILE * fprt);
};


void OpenFileAndRead(FILE * fptr)
{
   fptr = fopen("PathFile", "r");

   if(fptr == NULL)
   printf("Não foi possivel abrir o arquivo");


}

void OpenWriteOverrrideAndCreateFile(FILE * fptr)
{
 fptr = fopen("PathFile", "w");
 if(fptr == NULL)
   printf("Não foi possivel abrir o arquivo");

}

void OpenAndReadAndWrite(FILE * fptr)
{
 fptr = fopen("PathFile", "r+");
 if(fptr == NULL)
   printf("Não foi possivel abrir o arquivo");

}

void OpenForAppend(FILE * fptr)
{
 fptr = fopen("PathFile", "a");
 if(fptr == NULL)
   printf("Não foi possivel abrir o arquivo");

}

void OpenForAppendAndReading(FILE * fptr)
{
 fptr = fopen("PathFile", "a+");
 if(fptr == NULL)
   printf("Não foi possivel abrir o arquivo");
}

void WriteInFileTheString(char * str, FILE * ftpr)
{
    fprintf(ftpr, "%s", str);
}

void ReadFromFileString(char * str , FILE * ftpr)
{
    fscanf(ftpr, "%d", str);
}

#endif