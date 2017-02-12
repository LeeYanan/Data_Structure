#include <stdio.h>
#include <stdlib.h>

typedef struct _LList
{
	int data;
	struct _LList* next;
}LList;

LList* Create();
void Add(LList* head, int value);
void Insert(LList* head, int index, int value);

int main()
{
	LList* p = Create();
	Add(p, 10);
	Add(p, 20);
	Add(p, 30);
	Add(p, 40);

	Insert(p, -1, 10);
	
	return 0;
}

// ����һ���յ�����������ͷ����ͷָ��
LList* Create()
{
	LList* head; // head pointer
	head = (LList*)malloc(sizeof(LList));

	//create failed
	if (head==NULL) 
	{ 
        printf("��������ʧ�ܣ�");
        return NULL;
    }

	head->next = NULL;
	return head;
}

// ������β������Ԫ��
void Add(LList* head, int value)
{
	LList* ptemp = head;

	// if ptemp does not point to the tail node,
	// move ptemp to the next node until to the tail node
	while(ptemp->next != NULL)
	{
		ptemp = ptemp->next;
	}

	// Create a new node
	LList* pnew;
	pnew = (LList*)malloc(sizeof(LList));
	//����ʧ�ܷ���
	if (pnew==NULL) 
	{ 
        printf("��������ʧ�ܣ�");
        return;
    }
	pnew->next = NULL;
	pnew->data = value; // assign a value

	// Add the new node
	ptemp->next = pnew;
}

// ���ܣ�������������Ϊ index ��λ�ò���һ��ֵ value
void Insert(LList* head, int index, int value)
{
	LList* pnew;
	pnew = (LList*)malloc(sizeof(LList));
	//����ʧ�ܷ���
	if (pnew==NULL) 
	{ 
        printf("�������ʧ�ܣ�");
        return;
    }
	pnew->next = NULL;
	pnew->data = value;

	LList* ptemp = head;
	while (index != 0)
	{
		ptemp = ptemp->next;
		if (ptemp == NULL)
		{
			printf("Please enter a valid index!\n");
			return;
		}
		index--;
	}
	pnew->next = ptemp->next;
	ptemp->next = pnew;
}