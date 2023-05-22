#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//include<windows.h>
//#include<unistd.h>
#include"cooking_recipe.h"

void f_inint(Food *p){

    memset(p->f_name,0,sizeof(p->f_name));
    memset(p->f_category,0,sizeof(p->f_category));
    memset(p->wiki,0,sizeof(p->f_category));
    p->f_idx = 0;
}


void f_recipe_add(Food *p){

    while(1){
        printf("메뉴 종류 [한식, 중식, 일식, 양식 중 택 1] : ");
        scanf("%s",p->f_category);
        if(strcmp(p->f_category,"한식") == 0 || strcmp(p->f_category,"중식") == 0 || strcmp(p->f_category,"일식") == 0 || strcmp(p->f_category,"양식") == 0) break;
        else printf("\n등록할 수 있는 카테고리가 아닙니다.\n\n");
        Sleep(150);
        system("cls");
    }

    getchar();
    printf("메뉴 이름 : ");
    fgets(p->f_name,BUFFER_SIZE,stdin);
    p->f_name[strlen(p->f_name)-1] = '\0';

    printf("%s의 레시피 내용 : ",p->f_name);
    fgets(p->wiki,BUFFER_SIZE,stdin);
    p->wiki[strlen(p->wiki)-1] = '\0';

    printf("\n메뉴 추가가 완료되었습니다!\n");
    Sleep(300);
    return;

}

void f_recipe_list(Food **p, int count){

    if(count == 0){

        printf("등록된 레시피가 존재하지 않습니다.\n\n");
        return ;
    }
    printf("\n\t< 등록된 레시피 목록 >\n\n");

    for(int i = 0; i < count; i++){
        printf("%d) %s \t종류 : %s\n\n",p[i]->f_idx,p[i]->f_name,p[i]->f_category);
    }
    
    printf("\n");
}

void f_find_cat(Food **p, int count){

    int idx;
    char input[BUFFER_SIZE];

    while(1){

        printf("메뉴 종류 [한식, 중식, 일식, 양식 중 택 1] : ");
        fgets(input,BUFFER_SIZE,stdin);
        input[strlen(input)-1] = '\0';

        if(strcmp(input,"한식") == 0 || strcmp(input,"중식") == 0 || strcmp(input,"일식") == 0 || strcmp(input,"양식") == 0) break;
        else printf("입력하신 카테고리는 존재하지 않습니다.\n\n");

        //getchar();
    }

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

            //idx = i;
            return p[i];
            //break;
        }
    }

    printf("입력하신 메뉴는 존재하지 않습니다.\n\n");
    Sleep(300);
    system("cls");
    return NULL;
   
}

Food* f_find_index(Food **p, int count){

    int num;
    int idx;

    printf("\n\n레시피 번호를 입력해 주세요.\n레시피 번호 : ");
    scanf("%d",&num);

    for(int i = 0; i < count; i++){

        if(p[i]->f_idx == num){

            //idx = i;
            //break;
            return p[i];
        }
    }

    printf("입력하신 메뉴는 존재하지 않습니다.\n\n");
    return NULL;
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
        if(tmp == NULL) return ;
    }
    else if(menu == 2){

        f_find_cat(p, count);
        tmp = f_find_index(p, count);
        if(tmp == NULL) return ;
    }
    else if(menu == 3){

        f_recipe_list(p, count);
        tmp = f_find_index(p, count);
        if(tmp == NULL) return ;
    }

    printf("\n\t[ 수정 세부사항 선택 ]\n\n");
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

        while(1){


        printf("메뉴 종류 [한식, 중식, 일식, 양식 중 택 1] : ");
        scanf("%s",tmp->f_category);
        if(strcmp(tmp->f_category,"한식") == 0 || strcmp(tmp->f_category,"중식") == 0 || strcmp(tmp->f_category,"일식") == 0 || strcmp(tmp->f_category,"양식") == 0) break;
        else printf("\n등록할 수 있는 카테고리가 아닙니다.\n\n");
        
        }
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

    printf("\t[  삭제할 레시피 검색  ]\n\n");
    printf("1. 메뉴명 검색\n");
    printf("2. 카테고리 검색\n");
    printf("3. 번호 검색\n");
    printf("\n메뉴 선택 => ");
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

    f_inint(tmp);  //삭제할 데이터의 메모리 초기화

    // memset(tmp->f_name,0,sizeof(tmp->f_name));
    // memset(tmp->f_category,0,sizeof(tmp->f_category));
    // memset(tmp->wiki,0,sizeof(tmp->f_category));
    // tmp->f_idx = 0;
    printf("\n해당 레시피가 삭제되었습니다.\n\n");
}

Food* f_random(Food **p, int count){

    int rand_num;
    int idx;

    if(count == 0){

        printf("\n등록된 메뉴가 존재하지 않습니다.\n\n");
        return NULL;
    }
    srand(time(NULL));
    while(1){

        rand_num =  rand() % count;
        if(p[rand_num]->f_idx != 0){

            idx = rand_num;
            break;
        }

    }
    int menu;

    printf("\t[ 오늘의 음식 추천 ]\n\n");
    printf("%d) %s \t종류 : %s\n\n",p[idx]->f_idx,p[idx]->f_name,p[idx]->f_category);

    printf("1. 상세정보 보기\n");
    printf("2. 뒤로 돌아가기\n");

    printf("\n메뉴 선택 => ");
    scanf("%d",&menu);
    if(menu == 1){

        printf("\n\t[   레시피  ]\n\n");
        printf("%s\n\n",p[idx]->wiki);
    }
    else if(menu == 2) return p[idx];
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


int f_file_load(Food **p)
{
    int idx=0;
    FILE * fp;
    fp = fopen("recipe.txt", "rt");
    char c;
    if(fp == 0x0) 
        printf("txt 파일 내용이 없습니다. :<\n");
    else
    {
        while(1)
        {
            if((fgetc(fp)) == EOF) break;

            int count = fscanf(fp, "%s", p[idx]->f_category);

            if(count <= 0) break;
            
            fgets(p[idx]->f_name, BUFFER_SIZE, fp);
            p[idx]->f_name[strlen(p[idx]->f_name)-1] = '\0';
            
            fgets(p[idx]->wiki, BUFFER_SIZE, fp);
            p[idx]->wiki[strlen(p[idx]->wiki)-1] = '\0';
            idx++;
        }
    }
    fclose(fp);
    return idx;
}         
void f_file_save(Food **p, int idx)
{
    FILE * fp;
    fp = fopen("recipe.txt","wt");
    
    for(int i=0 ; i<idx ; i++)
    {
        fprintf(fp,"%s %s\n%s\nquit\n",p[i]->f_category, p[i]->f_name, p[i]->wiki);
    }
    fclose(fp);
}