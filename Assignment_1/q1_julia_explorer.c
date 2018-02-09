#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    char new_line[] = " \n";
    char input_buffer[100];
    char output_buffer[100];
    char search_A[] = "#A#";
    char search_B[] = "#B#";
    char replace_A[10];
    char replace_B[10];
    char *replacer;

    //Error checking. If the number of arguments is not 4, the
    //command is wrong. Also, if both floats are 0, either
    // they were both entered as 0 or the arguments were in fact
    // characters and not numbers.
    if(argc != 4){
        printf("Incorrect number of arguements!\n");
        return -1;
    }

    if(atof(argv[2]) == 0 && atof(argv[3]) == 0) {
        printf("Error: bad float arg\n");
        return -1;
    }

    //Here I copy argv[2] and argv[3] into a larger piece
    //of memory, and add the new line modifier to the end
    sprintf(replace_A, "%.6f" ,atof(argv[2]));
    sprintf(replace_B, "%.6f" ,atof(argv[3]));

    strcat(replace_A, new_line);
    strcat(replace_B, new_line);

    //The julia_plot file is opened in read mode, and
    //we then check to make sure the file was opened correctly
    FILE* julia_plot = fopen(argv[1], "r");

    if(julia_plot == NULL) {
        printf("Error: bad file\n");
        return -1;
    }

    //The file is read 100 characters at a time until we reach the end of
    //the file.
    while(fgets(input_buffer, 100, julia_plot) != NULL) {
        //If the #A# or #B# are found, the arguments are replaced
        //in the input buffer and copied to the output buffer
        if(strstr(input_buffer, search_A) != NULL) {
            replacer = strstr(input_buffer, search_A);
            strcpy(replacer, replace_A);
        }
        if (strstr(input_buffer, search_B) != NULL){
            replacer = strstr(input_buffer, search_B);
            strcpy(replacer, replace_B);
        }
        strcpy(output_buffer, input_buffer);
        printf("%s", output_buffer);
    }

    //file is then closed, and the program closes
    fclose(julia_plot);

    return 0;
}
