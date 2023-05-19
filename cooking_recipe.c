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

    printf("�޴� ���� [�ѽ�, �߽�, �Ͻ� �� �� 1] : ");
    scanf("%s",p->f_category);
    getchar();
    printf("�޴� �̸� : ");
    fgets(p->f_name,BUFFER_SIZE,stdin);
    p->f_name[strlen(p->f_name)-1] = '\0';

    printf("%s�� ������ ���� : ",p->f_name);
    fgets(p->wiki,BUFFER_SIZE,stdin);
    p->wiki[strlen(p->wiki)-1] = '\0';

    printf("\n�޴� �߰��� �Ϸ�Ǿ����ϴ�!\n");

    //�� �����ǿ� �ε���(�ѹ���) �ο� ��� ���� �� �߰����� �ڵ� �ۼ� �ʿ�
}

void f_recipe_list(Food **p, int count){

    printf("\n\t< ��ϵ� ������ ��� >\n\n");

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

    printf("�޴� �̸� �˻� : ");
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

    printf("������ ��ȣ�� �Է��� �ּ���.\n������ ��ȣ : ");
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
    
    printf("\n\t[   ������ ������ �˻�  ]\n\n");
    printf("1. �޴��� �˻�\n");
    printf("2. ī�װ� �˻�\n");
    printf("3. ��ȣ �˻�\n");
    printf("\n\n�޴� ���� => ");
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

    printf("\n\t[   ���� ���λ��� ���� ]\n");
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

        memset(tmp->f_category,0,sizeof(tmp->f_category));
        printf("ī�װ� [�ѽ�, �Ͻ�, �߽�] : \n");
        scanf("%s",tmp->f_category);
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

    printf("\t[  ������ ������ �˻�  ]\n");
    printf("1. �޴��� �˻�\n");
    printf("2. ī�װ� �˻�\n");
    printf("3. ��ȣ �˻�\n");
    printf("\n�޴� ���� => ");
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
    1.������ �����Ϳ� ���� ������ �����ִ� �ڵ� �ۼ��ʿ�
    2.������ ������ �ε����� ���� �����ʿ�
    */
    printf("�ش� �����ǰ� �����Ǿ����ϴ�.\n\n");
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
        �ڵ� �߰� �ۼ��ʿ�
    */

    
    return p[rand_num];
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
