#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>

void recebe_ptr(char **ptr_param, char *ptr_param2)
{
      
}

int main()
{
    char *ptr_char = NULL;

        recebe_ptr(&ptr_char,  ptr_char);

    char *ptr_char2 = "2";

        recebe_ptr(&ptr_char2,  ptr_char2);


    // variavel é guardada na stack - variavel estatica global
     char str[4] = "GfG"; /*One extra for string terminator*/
     /*    OR    */
     char str1[4] = {'G', 'f', 'G', '\0'}; /* '\0' is string terminator */

     str1[2] = 'H';

    // str_read_only is memory red-write stored
    // but the array "GfG" é armazenado como readonly block
     char *str_read_only  =  "GfG";


    // aqui a memoria é alocada na heap 
    // Strings are stored like other dynamically allocated things in C and can be shared among functions
    char *str_heap_allocated;
    int size = 4; /*one extra for ‘\0’*/
    str_heap_allocated = (char *)malloc(sizeof(char)*size);
    *(str_heap_allocated+0) = 'G'; 
    *(str_heap_allocated+1) = 'f';  
    *(str_heap_allocated+2) = 'G';  
    *(str_heap_allocated+3) = '\0'; 

    // memoria alocada na stack 
    char str[] = "GfG";  /* Stored in stack segment like other auto variables */
    *(str+1) = 'n';   /* No problem: String is now GnG */


}