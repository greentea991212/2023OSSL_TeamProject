## 🛠 stack 🛠

<div align="center">
      <img src="https://img.shields.io/badge/C-239DFF?style=flat-square&logo=c&logoColor=white"/>
      <img src="https://img.shields.io/badge/vscode-007ACC?style=flat-square&logo=visualstudiocode&logoColor=white"/>
      <img src="https://img.shields.io/badge/github-181717?style=flat-square&logo=github&logoColor=white"/>
</div>


# 💻 2023OSSL_Project 

<div align="center">
      <img src = "./images/frying-pan (1).png" width="300" height="300"/>
      <h2>Project Name  - <strong><em>Cooking recipe</em></strong></h2>
</div>


## 🥢프로젝트 주제
* 사용자(일반인)들은 카테고리(한식, 중식, 일식)별로 음식에 대한 레시피 정보를 얻을 수 있는 서비스입니다.
* 또 다른 사용자(요리사)들은 음식에 대한 자신의 레시피를 등록하여 일반인들에게 정보를 제공 할 수 있는 서비스입니다.  

## 🥢프로젝트 기능

### 🥄CRUD
> C : 요리 이름과 설명 레시피
>
> R : 모든 요리 나열과 선택에 따라 자세히 나오는 레시피
>
> U : 요리 이름 및 레시피 설명 내용 수정
>
> D : 요리 레시피 삭제

### 🥄파일 Read/Write 
> Lode : .txt 파일 읽어 오기
>
> Save : 데이터 .txt 파일에 저장

### 🥄데이터 검색 (3가지 방법)
> 1. 이름으로 검색 (ex. 순두부 찌개)
> 2. 카테고리로 검색 (ex. 한식)
> 3. 레피시 관리 번호 검색 (ex. 10)

### 🥄랜덤 요리 추천
> (일반인) 사용자에게 랜덤으로 요리를 추천해 주는 기능

## 🥢데이터 및 기능 함수

```c
      #define BUFFER_SIZE    100        //문자열 버퍼 저장 크기
      #define DATA_SIZE   50        //프로그램에 저장되어지는 음식 데이터 수

      typedef struct _food{

          char f_name[BUFFER_SIZE];       //음식 이름을 저장하는 문자열 변수
          char wiki[BUFFER_SIZE];         //음식 레시피를 저장하는 문자열 변수
          char f_category[10];            //[한식, 중식, 일식, 양식] 중 하나의 음식 종류를 저장하는 문자열 변수
          int f_idx;                      //음식 마다 (등록 순으로) 저장되어지는 자숫자

      }Food;

      void f_inint(Food *p);                     //구조체 변수 초기화하는 함수
      void f_recipe_add(Food *p);               //요리를 추가하는 함수
      void f_recipe_list(Food **p, int count);       //등록된 요리를 모두 출력하는 함수
      void f_recipe_update(Food **p, int count);     //요리에 대한 정보를 수정하는
      void f_recipe_delete(Food **p,int count);     //요리 레시피 삭제

      void f_file_lode();         //.txt 파일 읽어오기
      void f_file_save();         //.txt 파일 저장하기


      void f_find_cat(Food **p, int count);            //음식 종류를 통해 음식을 탐색해주는 함수
      Food* f_find_name(Food **p, int count);         //이름으로 음식을 탐색하는 함수
      Food* f_find_index(Food **p, int count);        //음식의 번호로 음식을 탐색하는 함수

      Food* f_random(Food **p, int count);            //랜덤으로 음식을 추천해주는 함수

      int select_menu();                              //Menu driven을 구현하는 함수
```
 
    
_____________________________
### 🧑‍🍳 Member 👩‍🍳
#### 21900103 김민혁
* PL(Project Leader)

  * 참고자료 조사 (구글링)
  * 문서작성
  * 구현 단계에서의 리드
  * wiki관리

#### 21900505 이민우 
* PM(Project Manager) 


  * 회의 일정 조정
  * 전반적인 프로젝트 관리
  * 상세 설계 책임
  * 소프트웨어 버그 발견 책임
