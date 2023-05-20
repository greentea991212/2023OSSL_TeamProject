#define BUFFER_SIZE    100
#define DATA_SIZE   50

typedef struct _food{

    char f_name[BUFFER_SIZE];
    char wiki[BUFFER_SIZE];
    char f_category[10];
    int f_idx;

}Food;

/*
arr[idx]를 초기화 할 수 있는 함수가 필요하다.

*/
void f_inint(Food *p);              //구조체 변수 초기화
void f_recipe_add(Food *p);        //요리 레시피 추가
void f_recipe_list(Food **p, int count);       //전체 출력
void f_recipe_update(Food **p, int count);     //요리 레시피 수정
void f_recipe_delete(Food **p,int count);     //요리 레시피 삭제

void f_file_lode();         //.txt 파일 읽어오기
void f_file_save();         //.txt 파일 저장하기


void f_find_cat(Food **p, int count);          //카테고리로 레시피 출력
Food* f_find_name(Food **p, int count);         //이름으로 레시피 찾기
Food* f_find_index(Food **p, int count);        //레시피 관리 번호로 레시피 찾기

Food* f_random(Food **p, int count);            //음식 레피시 추천 뽑아주기

int select_menu();




