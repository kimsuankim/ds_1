/* (1) ���������ڽý�������, (2) 2310131, (3) �����, (4) main.c (5) 2025.05.30 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//ť ��� ����:�̸����� 
typedef struct qNode{
	char name[30];
	struct qNode* next;
}qNode; 
//������ ����
typedef struct hNode{
	qNode* front;
	qNode* rear;
	int length;
}hNode; 

//�Լ� �Լ�
void enqueue(hNode* h, char person[]){
	qNode* newNode;
	newNode=(qNode*)malloc(sizeof(qNode));//??
	strcpy(newNode->name, person);//�����Լ� 
	newNode->next = NULL; //���� ����
	if(h->length==0){
		h->front = h->rear = newNode;  
	} 
	else{
		h->rear->next = newNode; //���� 
		h->rear = newNode; //�� �ű�� 
	}
	h->length ++; //���� �� ���� ���� 
}
//�켱 �Լ� �Լ�
void enqueue_front(hNode* h, char person[]){
	qNode* newNode;
	newNode=(qNode*)malloc(sizeof(qNode));//??
	strcpy(newNode->name, person);//�����Լ� 
	if(h->length==0){
		h->front = h->rear = newNode;
		newNode->next = NULL; //�ڿ� ��� ���� 
	} 
	else{
		newNode->next = h->front; //�տ� ���� 
		h->front = newNode; //�Ǿ� �ű�� 
	}
	h->length ++; //���� �� ���� ���� 
}
//���:��������� �ǳ��� ���� 
void dequeue(hNode* h){
	if(h->length==0){
		printf("����� �ǳ����� �����ϴ�.\n");
		exit(1);
	} 
	else{
		qNode* temp = h->front; //������ ���  
		printf("���:%s\n",temp->name); //��� ��û 
		h->front = h->front->next; //�Ǿ� �ű��
		free(temp); //�޸� �ݳ�
		h->length--;
	}
}

void qprint(hNode* h){
	int i;
	qNode* pp = h->front; //����Ʈ�Ұ� ������ 
	//pnode[h->length]; //����Ʈ�� �迭 ����
	printf("���� ť ����:"); 
	for(i=0;i<h->length-1;i++){ //�� ��� ������ ȭ��ǥ�ְ� 
		//if(pp->next!=NULL){
		printf("%s->",pp->name);
		//pNode[i]= pp->name
		pp=pp->next;//������� 
		//}
	}
	printf("%s\n",pp->name); //������ ��� 
	/*for(i=0;i<h->length;i++){
		printf("���� ť ����:%s\n",pp->name);
	}*/
	
}
 
int main(int argc, char *argv[]) {
	//�ǳ��� �Լ� ��⿭ �ý��� ����
	hNode *waiting; //�����⿭ ����
	waiting=(hNode*)malloc(sizeof(hNode));
	waiting->length = 0;
	waiting->front = waiting->rear = NULL;
	 
	//1.�Ϲ� �ǳ��� ��⿭ ���
	enqueue(waiting,"Alice");
	qprint(waiting); //���� �� ť����  ��� 
	enqueue(waiting,"Bob");
	qprint(waiting); //���� �� ť����  ���
	//2.VIP�ǳ��� ��� 
	enqueue_front(waiting,"Zena");
	qprint(waiting); //���� �� ť����  ���
	//3.��� ���� �����Ͻ� ���� ��� (FIFO) 
	dequeue(waiting);
	qprint(waiting); //���� �� ť����  ���
	enqueue(waiting,"Tom"); 
	qprint(waiting); //���� �� ť����  ���
	 
	return 0;
}
