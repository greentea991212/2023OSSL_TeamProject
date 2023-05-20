#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"cooking_recipe.h"

void f_inint(Food *p){

    memset(p->f_name,0,sizeof(p->f_name));
    memset(p->f_category,0,sizeof(p->f_category));
    memset(p->wiki,0,sizeof(p->f_category));
    p->f_idx = 0;
}


void f_recipe_add(Food *p){

    printf("메뉴 종류 [한식, 중식, 일식 중 택 1] : ");
    scanf("%s",p->f_category);
    getchar();
    printf("메뉴 이름 : ");
    fgets(p->f_name,BUFFER_SIZE,stdin);
    p->f_name[strlen(p->f_name)-1] = '\0';

    printf("%s의 레시피 내용 : ",p->f_name);
    fgets(p->wiki,BUFFER_SIZE,stdin);
    p->wiki[strlen(p->wiki)-1] = '\0';

    printf("\n메뉴 추가가 완료되었습니다!\n");

    //각 레시피에 인덱스(넘버링) 부여 방식 논의 및 추가적인 코드 작성 필요
}

void f_recipe_list(Food **p, int count){

    printf("\n\t< 등록된 레시피 목록 >\n\n");

    for(int i = 0; i < count; i++){

        printf("%d) %s\n",i+1,p[i]->f_name);
    }

    printf("\n");
}

void f_find_cat(Food **p, int count){

    int idx;
    char input[BUFFER_SIZE];
    fgets(input,BUFFER_SIZE,stdin);
    input[strlen(input)-1] = '\0';

    for(int i = 0; i < count; i++){

        if(strcmp(p[i]->f_category,input) == 0){

            printf("%d) %s\n",p[i]->f_idx,p[i]->f_name);
        }
    }
}

Food* f_find_name(Food **p, int count){

    int idx;
    char input[BUFFER_SIZE];

    printf("메뉴 이름 검색 : ");
    fgets(input,BUFFER_SIZE,stdin);
    input[strlen(input)-1] = '\0';
    
    for(int i = 0; i < count; i++){

        if(strcmp(p[i]->f_name,input) == 0){

            idx = i;
            break;
        }
    }

    return p[idx];
}

Food* f_find_index(Food **p, int count){

    int num;
    int idx;

    printf("레시피 번호를 입력해 주세요.\n레시피 번호 : ");
    scanf("%d",&num);

    for(int i = 0; i < count; i++){

        if(p[i]->f_idx == num){

            idx = i;
            break;
        }
    }

    return p[idx];
}


void f_recipe_update(Food **p, int count){

    Food *tmp;
    int menu;
    
    printf("\n\t[   수정할 레시피 검색  ]\n\n");
    printf("1. 메뉴명 검색\n");
    printf("2. 카테고리 검색\n");
    printf("3. 번호 검색\n");
    printf("\n\n메뉴 선택 => ");
    scanf("%d",&menu);
    getchar();

    if(menu == 1){

        tmp = f_find_name(p, count);
    }
    else if(menu == 2){

        f_find_cat(p, count);
        tmp = f_find_index(p, count);
    }
    else if(menu == 3){

        f_recipe_list(p, count);
        tmp = f_find_index(p, count);
    }

    printf("\n\t[   수정 세부사항 선택 ]\n");
    printf("1. 메뉴명 수정\n");
    printf("2. 카테고리 수정\n");
    printf("3. 레시피 내용 수정\n");
    printf("\n메뉴 선택 => ");
    scanf("%d",&menu);
    getchar();

    if(menu == 1){


        memset(tmp->f_name,0,sizeof(tmp->f_name));
        printf("메뉴 이름 : ");
        fgets(tmp->f_name,BUFFER_SIZE,stdin);
        tmp->f_name[strlen(tmp->f_name)-1] = '\0';
    }
    else if(menu == 2){

        memset(tmp->f_category,0,sizeof(tmp->f_category));
        printf("카테고리 [한식, 일식, 중식] : \n");
        scanf("%s",tmp->f_category);
    }
    else if(menu == 3){

        memset(tmp->wiki,0,sizeof(tmp->f_category));
        printf("%s의 레시피 내용 : ",tmp->f_name);
        fgets(tmp->wiki,BUFFER_SIZE,stdin);
        tmp->wiki[strlen(tmp->wiki)-1] = '\0';
        
    }

    printf("\n수정완료!\n\n");

}

void f_recipe_delete(Food **p, int count){

    Food *tmp;
    int menu;

    printf("\t[  삭제할 레시피 검색  ]\n");
    printf("1. 메뉴명 검색\n");
    printf("2. 카테고리 검색\n");
    printf("3. 번호 검색\n");
    printf("\n메뉴 선택 => ");
    scanf("%d",&menu);

    if(menu == 1){

        tmp = f_find_name(p, count);
    }
    else if(menu == 2){

        f_find_cat(p, count);
        tmp = f_find_index(p, count);
    }
    else if(menu == 3){

        f_recipe_list(p, count);
        tmp = f_find_index(p, count);
    }

    f_inint(tmp);
    // memset(tmp->f_name,0,sizeof(tmp->f_name));
    // memset(tmp->f_category,0,sizeof(tmp->f_category));
    // memset(tmp->wiki,0,sizeof(tmp->f_category));
    // tmp->f_idx = 0;

    /*
    1.삭제된 데이터에 대한 정보를 보여주는 코드 작성필요
    2.데이터 삭제시 인덱스값 하향 조정필요
    */
    printf("해당 레시피가 삭제되었습니다.\n\n");
}

Food* f_random(Food **p, int count){

    int rand_num;
    int idx;
    srand(time(NULL));

    while(1){

        rand_num =  rand() % count;
        if(p[rand_num]->f_idx != 0){

            idx = rand_num;
            break;
        }

    }
    /*
        코드 추가 작성필요
    */

    printf("\t[ 오늘의 음식 추천 ]\n\n");
    printf("%d) %s\n",p[idx]->f_idx,p[idx]->f_name);
    return p[idx];
}

int select_menu(){

    int menu;
    printf("\t[   메  뉴  ]\n\n");
    printf("1. 새로운 레시피 추가\n");
    printf("2. 모든 메뉴 출력\n");
    printf("3. 메뉴 정보 수정\n");
    printf("4. 레시피 삭제\n");
    printf("5. 랜덤메뉴 추천\n");
    printf("0. 종료\n");

    printf("\n메뉴 선택 => ");
    scanf("%d",&menu);
    return menu;

}
