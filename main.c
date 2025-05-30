/* (1) 지능형전자시스템전공, (2) 2310131, (3) 김수안, (4) main.c (5) 2025.05.30 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//큐 노드 구조:이름저장 
typedef struct qNode{
	char name[30];
	struct qNode* next;
}qNode; 
//헤더노드 정의
typedef struct hNode{
	qNode* front;
	qNode* rear;
	int length;
}hNode; 

//입소 함수
void enqueue(hNode* h, char person[]){
	qNode* newNode;
	newNode=(qNode*)malloc(sizeof(qNode));//??
	strcpy(newNode->name, person);//복사함수 
	newNode->next = NULL; //끝에 삽입
	if(h->length==0){
		h->front = h->rear = newNode;  
	} 
	else{
		h->rear->next = newNode; //삽입 
		h->rear = newNode; //끝 옮기기 
	}
	h->length ++; //삽입 후 길이 증가 
}
//우선 입소 함수
void enqueue_front(hNode* h, char person[]){
	qNode* newNode;
	newNode=(qNode*)malloc(sizeof(qNode));//??
	strcpy(newNode->name, person);//복사함수 
	if(h->length==0){
		h->front = h->rear = newNode;
		newNode->next = NULL; //뒤에 노드 없음 
	} 
	else{
		newNode->next = h->front; //앞에 삽입 
		h->front = newNode; //맨앞 옮기기 
	}
	h->length ++; //삽입 후 길이 증가 
}
//퇴소:오래대기한 피난민 제거 
void dequeue(hNode* h){
	if(h->length==0){
		printf("퇴소할 피난민이 없습니다.\n");
		exit(1);
	} 
	else{
		qNode* temp = h->front; //삭제할 노드 
		h->front = h->front->next; //맨앞 옮기기
		free(temp); //메모리 반납
		h->length--; 
		printf("퇴소:%s\n",temp->name); 
	}
}

 
int main(int argc, char *argv[]) {
	//피난소 입소 대기열 시스템 구현
	hNode *waiting; //공백대기열 생성
	waiting->length = 0;
	waiting->front = waiting->rear = NULL;
	 
	//1.일반 피난민 대기열 등록
	enqueue(waiting,"Alice");
	printf("현재 큐 상태:") 
	enqueue(waiting,"Bob");
	//2.VIP피난민 등록 
	enqueue_front(waiting,"Zena");
	//3.퇴소 먼저 입장하신 분의 퇴소 (FIFO) 
	dequeue(waiting);
	enqueue(waiting,"Tom"); 
	 
	return 0;
}
