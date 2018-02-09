#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Error: Incorrect number of arguments");
        return -1;
    }

    int i,j,l,m;
    int k = 0;
    int day_size = atoi(argv[1]);
    int first_day = atoi(argv[2]);
    int calendar_Width;
    int string_insertion_point;
    int extra_space;
    int day_of_month;
    int day_of_week = first_day;
    int month_length;
    int box_count;

    char vertical_Seperators = '|';
    char horizontal_Seperators = '-';
    char blank_Space = ' ';

    if(day_size < 2) {
        printf("Daysize is too small, please enter an integer greater than or equal to 2\n");
        return -1;
    }
    if(first_day < 1 || first_day > 7){
        printf("Error: Please choose a first day inbetween 1(Sunday) and 7(Saturday)");
        return -1;
    }

    const char *month[12];
    month[0] = "January";
    month[1] = "February";
    month[2] = "March";
    month[3] = "April";
    month[4] = "May";
    month[5] = "June";
    month[6] = "July";
    month[7] = "August";
    month[8] = "September";
    month[9] = "October";
    month[10] = "November";
    month[11] = "December";

    char day[7][(day_size+1)];
    memcpy(day[0], "Sunday", day_size*sizeof(char));
    memcpy(day[1], "Monday", day_size*sizeof(char));
    memcpy(day[2], "Tuesday", day_size*sizeof(char));
    memcpy(day[3], "Wednesday", day_size*sizeof(char));
    memcpy(day[4], "Thursday", day_size*sizeof(char));
    memcpy(day[5], "Friday", day_size*sizeof(char));
    memcpy(day[6], "Saturday", day_size*sizeof(char));

    day[0][day_size] = '\0';
    day[1][day_size] = '\0';
    day[2][day_size] = '\0';
    day[3][day_size] = '\0';
    day[4][day_size] = '\0';
    day[5][day_size] = '\0';
    day[6][day_size] = '\0';

    calendar_Width = (((day_size + 3) * 7) + 1);

    for(i = 0; i < 12; i++) {
        //Constructs top seperator lines
        for(j = 0; j < calendar_Width; j++){
            if(j == 0) {
                printf("%c", vertical_Seperators);
            }
            else if(j == (calendar_Width - 1)){
                printf("%c\n", vertical_Seperators);
            }
            else {
                printf("%c", horizontal_Seperators);
            }
        }

        //Constructs 2nd Line and Month name
        for(j = 0; j < calendar_Width; j++){
            string_insertion_point = ((calendar_Width)/2) - (strlen(month[i])/2);
            if(j == 0) {
                printf("%c", vertical_Seperators);
            }
            else if(j == (calendar_Width -1)){
                printf("%c\n", vertical_Seperators);
            }
            else if(j == string_insertion_point) {
                printf("%s", month[i]);
                j = j + strlen(month[i]) - 1;
            }
            else {
                printf("%c", blank_Space);
            }
        }

        //Constructs 2 seperator line under month name
        for(j = 0; j < calendar_Width; j++){
            if(j == 0) {
                printf("%c", vertical_Seperators);
            }
            else if(j == (calendar_Width - 1)){
                printf("%c\n", vertical_Seperators);
            }
            else {
                printf("%c", horizontal_Seperators);
            }
        }

        //Constructs day of week row
        for(j = 0; j < calendar_Width; j++){
            if(j == 0) {
                printf("%c %s", vertical_Seperators, day[k]);
                if(strlen(day[k]) < day_size) {
                    extra_space = day_size - strlen(day[k]);
                    for(l = 0; l < extra_space; l++){
                        printf("%c", blank_Space);
                    }
                }
                j = j + day_size + 1;
                k = k + 1;
            }
            else if(j == calendar_Width - 1){
                printf("%c\n", vertical_Seperators);
            }
            else if(j%(calendar_Width/7) == 0) {
                printf("%c %s", vertical_Seperators, day[k]);
                if(strlen(day[k]) < day_size) {
                    extra_space = day_size - strlen(day[k]);
                    for(l = 0; l < extra_space; l++){
                        printf("%c", blank_Space);
                    }
                }
                j = j + day_size + 1;
                k = k + 1;
                if(k == 7) {
                    k = 0;
                }
            }
            else {
                printf("%c", blank_Space);
            }
        }

        //Constructs third seperator line under day of week row
        for(j = 0; j < calendar_Width; j++){
            if(j == 0) {
                printf("%c", vertical_Seperators);
            }
            else if(j == (calendar_Width - 1)){
                printf("%c\n", vertical_Seperators);
            }
            else {
                printf("%c", horizontal_Seperators);
            }
        }

        if(day_of_week > 6){
            month_length = 6;
        }
        else {
            month_length = 5;
        }

        box_count = 0;
        day_of_month = 1;
        for(j = 0; j < month_length; j++){
            for(l = 0; l < calendar_Width;){
                if(l == 0) {
                    printf("%c", vertical_Seperators);
                    box_count++;
                    l++;
                }
                if(box_count == day_of_week && day_of_month <= 30){
                    printf(" %d ", day_of_month);
                    day_of_month++;
                    l = l+3;
                    if(day_of_month <= 10){
                        printf(" ");
                        l++;
                    }
                    if(day_size > 2) {
                        for(m = 0; m < day_size - 2; m++){
                            printf(" ");
                            l++;
                        }
                    }
                    if(box_count == 7) {
                        printf("%c\n", vertical_Seperators);
                        box_count = 0;
                        day_of_week = 1;
                        break;
                    }
                    else {
                        printf("|");
                        l++;
                        day_of_week++;
                        box_count++;
                    }
                }
                else {
                    for(m = 0; m < day_size+2; m++){
                        printf("%c", blank_Space);
                        l++;
                    }
                    if(l >= calendar_Width - (calendar_Width/7)){
                        printf("%c\n", vertical_Seperators);
                        box_count++;
                        break;
                    }
                    printf("%c", vertical_Seperators);
                    l++;
                    box_count++;
                }
            }
        }

        if(i == 11){
            for(j = 0; j < calendar_Width; j++){
                if(j == 0) {
                    printf("%c", vertical_Seperators);
                }
                else if(j == (calendar_Width - 1)){
                    printf("%c\n", vertical_Seperators);
                }
                else {
                    printf("%c", horizontal_Seperators);
                }
            }
        }
    }

    return 0;
}
