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
    typedef struct {
      char * f_name; //음식 이름
      char * f_recipe_wiki; //음식 레시피 위키 (내용)
      char * f_cat; //음식 카테고리 ("cat"egory)
      int f_index; //레시피 관리 번호
    }f_recipe;
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
