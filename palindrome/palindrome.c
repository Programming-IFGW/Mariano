#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void print_string(char *string, int char_size){
    for(int i = 0; i<char_size; i++){
        printf("%c",string[i]);
    };
    printf("\n");
}

void print_substring(char *string, int init, int final){
    for(int i = init; i<final; i++){
        printf("%c",string[i]);
    };
    printf("\n");
}

char* find_palindrome(char *string, int char_size, int *new_size){

    int i_pal = 0;
    int large_pal=0;

    int first_i = 0;

    print_string(string,char_size);
    bool is_the_first = true;

    for(int i = 0; i<char_size; i++){
        int pal_size = 0; 
        int inside_i = i;      
        for(int j = char_size-1; j>=0; j--)
        {
            
            printf("--: %c(%d),%c(%d)\t %d:  %d\n",string[inside_i],inside_i,string[j],j,pal_size,is_the_first);
            if(string[inside_i]==string[j])
            {
                pal_size++;
                printf("XX: %c(%d),%c(%d)\t %d:  %d\n",string[inside_i],inside_i,string[j],j,pal_size,is_the_first);
                is_the_first = false;
                inside_i++;                            
            }
        };//END FOR
    };//END FOR
    printf("%d,%d\n",first_i,large_pal);
    print_substring(string,first_i,first_i+large_pal);

    *new_size=char_size;
    char *new_string = malloc( *new_size*sizeof (char) );

    for(int i = 0; i<char_size; i++){
        new_string[i]=string[i];
    };
    return new_string;
}

void main(){

    int char_size = 6;
    char string_test[6] = "banana";

    char *string;
    string = malloc( char_size*sizeof (char) );
    for(int i = 0; i<char_size; i++)
        string[i] = string_test[i];


    char *result;
    int new_size;
    result = palindrome_substring(string, char_size, &new_size);
    //print_string(result,new_size);
    

    free (string);
    free (result);
}