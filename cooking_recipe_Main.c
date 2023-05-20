#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "cooking_recipe.h"
#include<windows.h>

int main(void){

    Food *arr[DATA_SIZE];
    int menu;
    int idx = 0;    //저장되어진 데이터수를 카운팅 및 배열의 인덱스로 활용하기 위한 변수

    while(1){

        menu = select_menu();
        getchar();
        //system("cls");  
        if(menu == 0) break;
        if(menu == 1){

            arr[idx] = (Food*)malloc(sizeof(Food));
            f_inint(arr[idx]);
            f_recipe_add(arr[idx]);
            arr[idx]->f_idx = idx+1;
            idx++;
            system("cls");
        }
        else if(menu == 2){

            system("cls");
            f_recipe_list(arr,idx);
        }
        else if(menu == 3){

            system("cls");
            f_recipe_update(arr,idx);
        }
        else if(menu == 4){

            system("cls");
            f_recipe_delete(arr,idx);
        }
        else if(menu == 5){

            system("cls");
            f_random(arr,idx);
        }

    }
    
    return 0;
}