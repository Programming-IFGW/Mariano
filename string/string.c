#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <rand.h>


int count_substring_ordered(char *string, int size){

    int count = 0;
    int large = 0;
    int i=0;

    do{
        if(string[i]+1==string[i+1]){
            count++;
        }else {
            if(count>large){
                large = count;
            };
            count = 0;
        };
        i++;
    }while(i<size);

    if(large!=0)
        large++;

    return large;
}

/*int count_substring(char *string, int size){

    int count = 0;
    int large = 0;
    int i=0;
    bool repeated = false;

    do{
        i++;
        do{
            if(string[i]==string[j]){
                out=true;
            }
        }while(!repeated);

    }while(i<size);

    if(large!=0)
        large++;

    return large;
}*/

void generate_string(char *string, int size){
    srand(clock());

    for(int i = 0; i<size; i++){

        int num = rand() % 25;
        char c = 'a'+num;
        string[i] = c;
        printf("%c",string[i]);
    };

}

void main(){
    
    int char_size = 19;

    char string[19] = "abrkaabcdefghijjxxx";
    clock_t t;

    /*char *string;    
    string = malloc( char_size*sizeof (char) );
    generate_string(string, char_size);
    printf("\n string: %c\n",string[0]);*/

    t = clock();
    int large = count_substring(string, char_size);
    t = clock()-t;

    printf("\nTempo:%f",(float) ( clock()/((float)CLOCKS_PER_SEC) ));
    printf("\n%d\n",large);

    //free (string);

}