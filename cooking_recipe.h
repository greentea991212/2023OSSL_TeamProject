#define BUFFER_SIZE    100
#define DATA_SIZE   50

typedef struct _food{

    char f_name[BUFFER_SIZE];
    char wiki[BUFFER_SIZE];
    char f_category[10];
    int f_idx;

}Food;

/*
arr[idx]�� �ʱ�ȭ �� �� �ִ� �Լ��� �ʿ��ϴ�.

*/
void f_inint(Food *p);              //����ü ���� �ʱ�ȭ
void f_recipe_add(Food *p);        //�丮 ������ �߰�
void f_recipe_list(Food **p, int count);       //��ü ���
void f_recipe_update(Food **p, int count);     //�丮 ������ ����
void f_recipe_delete(Food **p,int count);     //�丮 ������ ����

void f_file_lode();         //.txt ���� �о����
void f_file_save();         //.txt ���� �����ϱ�


void f_find_cat(Food **p, int count);          //ī�װ��� ������ ���
Food* f_find_name(Food **p, int count);         //�̸����� ������ ã��
Food* f_find_index(Food **p, int count);        //������ ���� ��ȣ�� ������ ã��

Food* f_random(Food **p, int count);            //���� ���ǽ� ��õ �̾��ֱ�

int select_menu();




