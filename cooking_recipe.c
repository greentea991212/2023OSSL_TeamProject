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
        printf("�޴� ���� [�ѽ�, �߽�, �Ͻ�, ��� �� �� 1] : ");
        scanf("%s",p->f_category);
        if(strcmp(p->f_category,"�ѽ�") == 0 || strcmp(p->f_category,"�߽�") == 0 || strcmp(p->f_category,"�Ͻ�") == 0 || strcmp(p->f_category,"���") == 0) break;
        else printf("\n����� �� �ִ� ī�װ��� �ƴմϴ�.\n\n");
        Sleep(150);
        system("cls");
    }

    getchar();
    printf("�޴� �̸� : ");
    fgets(p->f_name,BUFFER_SIZE,stdin);
    p->f_name[strlen(p->f_name)-1] = '\0';

    printf("%s�� ������ ���� : ",p->f_name);
    fgets(p->wiki,BUFFER_SIZE,stdin);
    p->wiki[strlen(p->wiki)-1] = '\0';

    printf("\n�޴� �߰��� �Ϸ�Ǿ����ϴ�!\n");
    Sleep(300);
    return;

}

void f_recipe_list(Food **p, int count){

    if(count == 0){

        printf("��ϵ� �����ǰ� �������� �ʽ��ϴ�.\n\n");
        return ;
    }
    printf("\n\t< ��ϵ� ������ ��� >\n\n");

    for(int i = 0; i < count; i++){
        printf("%d) %s \t���� : %s\n\n",p[i]->f_idx,p[i]->f_name,p[i]->f_category);
    }
    
    printf("\n");
}

void f_find_cat(Food **p, int count){

    int idx;
    char input[BUFFER_SIZE];

    while(1){

        printf("�޴� ���� [�ѽ�, �߽�, �Ͻ�, ��� �� �� 1] : ");
        fgets(input,BUFFER_SIZE,stdin);
        input[strlen(input)-1] = '\0';

        if(strcmp(input,"�ѽ�") == 0 || strcmp(input,"�߽�") == 0 || strcmp(input,"�Ͻ�") == 0 || strcmp(input,"���") == 0) break;
        else printf("�Է��Ͻ� ī�װ��� �������� �ʽ��ϴ�.\n\n");

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

    printf("�޴� �̸� �˻� : ");
    fgets(input,BUFFER_SIZE,stdin);
    input[strlen(input)-1] = '\0';
    
    for(int i = 0; i < count; i++){

        if(strcmp(p[i]->f_name,input) == 0){

            //idx = i;
            return p[i];
            //break;
        }
    }

    printf("�Է��Ͻ� �޴��� �������� �ʽ��ϴ�.\n\n");
    Sleep(300);
    system("cls");
    return NULL;
   
}

Food* f_find_index(Food **p, int count){

    int num;
    int idx;

    printf("\n\n������ ��ȣ�� �Է��� �ּ���.\n������ ��ȣ : ");
    scanf("%d",&num);

    for(int i = 0; i < count; i++){

        if(p[i]->f_idx == num){

            //idx = i;
            //break;
            return p[i];
        }
    }

    printf("�Է��Ͻ� �޴��� �������� �ʽ��ϴ�.\n\n");
    return NULL;
}


void f_recipe_update(Food **p, int count){

    Food *tmp;
    int menu;
    
    printf("\n\t[   ������ ������ �˻�  ]\n\n");
    printf("1. �޴��� �˻�\n");
    printf("2. ī�װ� �˻�\n");
    printf("3. ��ȣ �˻�\n");
    printf("\n\n�޴� ���� => ");
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

    printf("\n\t[ ���� ���λ��� ���� ]\n\n");
    printf("1. �޴��� ����\n");
    printf("2. ī�װ� ����\n");
    printf("3. ������ ���� ����\n");
    printf("\n�޴� ���� => ");
    scanf("%d",&menu);
    getchar();

    if(menu == 1){


        memset(tmp->f_name,0,sizeof(tmp->f_name));
        printf("�޴� �̸� : ");
        fgets(tmp->f_name,BUFFER_SIZE,stdin);
        tmp->f_name[strlen(tmp->f_name)-1] = '\0';
    }
    else if(menu == 2){

        while(1){


        printf("�޴� ���� [�ѽ�, �߽�, �Ͻ�, ��� �� �� 1] : ");
        scanf("%s",tmp->f_category);
        if(strcmp(tmp->f_category,"�ѽ�") == 0 || strcmp(tmp->f_category,"�߽�") == 0 || strcmp(tmp->f_category,"�Ͻ�") == 0 || strcmp(tmp->f_category,"���") == 0) break;
        else printf("\n����� �� �ִ� ī�װ��� �ƴմϴ�.\n\n");
        
        }
    }

    else if(menu == 3){

        memset(tmp->wiki,0,sizeof(tmp->f_category));
        printf("%s�� ������ ���� : ",tmp->f_name);
        fgets(tmp->wiki,BUFFER_SIZE,stdin);
        tmp->wiki[strlen(tmp->wiki)-1] = '\0';
        
    }

    printf("\n�����Ϸ�!\n\n");

}

void f_recipe_delete(Food **p, int count){

    Food *tmp;
    int menu;

    printf("\t[  ������ ������ �˻�  ]\n\n");
    printf("1. �޴��� �˻�\n");
    printf("2. ī�װ� �˻�\n");
    printf("3. ��ȣ �˻�\n");
    printf("\n�޴� ���� => ");
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

    f_inint(tmp);  //������ �������� �޸� �ʱ�ȭ

    // memset(tmp->f_name,0,sizeof(tmp->f_name));
    // memset(tmp->f_category,0,sizeof(tmp->f_category));
    // memset(tmp->wiki,0,sizeof(tmp->f_category));
    // tmp->f_idx = 0;
    printf("\n�ش� �����ǰ� �����Ǿ����ϴ�.\n\n");
}

Food* f_random(Food **p, int count){

    int rand_num;
    int idx;

    if(count == 0){

        printf("\n��ϵ� �޴��� �������� �ʽ��ϴ�.\n\n");
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

    printf("\t[ ������ ���� ��õ ]\n\n");
    printf("%d) %s \t���� : %s\n\n",p[idx]->f_idx,p[idx]->f_name,p[idx]->f_category);

    printf("1. ������ ����\n");
    printf("2. �ڷ� ���ư���\n");

    printf("\n�޴� ���� => ");
    scanf("%d",&menu);
    if(menu == 1){

        printf("\n\t[   ������  ]\n\n");
        printf("%s\n\n",p[idx]->wiki);
    }
    else if(menu == 2) return p[idx];
}

int select_menu(){

    int menu;
    printf("\t[   ��  ��  ]\n\n");
    printf("1. ���ο� ������ �߰�\n");
    printf("2. ��� �޴� ���\n");
    printf("3. �޴� ���� ����\n");
    printf("4. ������ ����\n");
    printf("5. �����޴� ��õ\n");
    printf("0. ����\n");

    printf("\n�޴� ���� => ");
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
        printf("txt ���� ������ �����ϴ�. :<\n");
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