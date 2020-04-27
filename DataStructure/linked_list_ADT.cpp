#include <stdlib.h>
#include <stdio.h>

typedef int ElementType; //�������Ԫ������
typedef struct Node Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List CreatList();                               //����
Position NewNode(ElementType x);                //�½��ڵ�
List MakeEmpty(List L);                         //����
ElementType IsEmpty(List L);                    //�ж�Ϊ��
ElementType IsLast(Position P, List L);         //�Ƿ����һ��Ԫ��
Position Find(ElementType x, List L);           //����
void Delete(ElementType x, List L);             //ɾ��Ԫ��
Position FindPrevious(ElementType x, List L);   //��ǰ��
void Insert(ElementType x, List L, Position P); //����
void DeleteList(List L);                        //ɾ����
void PrintList(List L);


struct Node
{
	ElementType Element; //������
	Position Next;       //ָ����(ָ��struct��ָ��)
};

//������
int main(int argc, char const *argv[])
{
	List L = CreatList(); //�����˱�ͷ
	/*
	��ز���
	*/
	system("pause");
	return 0;
}

List CreatList() //��ͷ
{
	List L = (List)malloc(sizeof(Node));
	if (L == NULL)
	{
		printf("Out of memory");
		exit(1);
	}
	L->Next = NULL;
	return L;
}

Position NewNode(ElementType x) //�½��ڵ�
{
	Position newNode = (Position)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Out of memory");
		exit(1);
	}
	newNode->Element = x;
	newNode->Next = NULL;

	return newNode;
}

List MakeEmpty(List L) //���
{
	if (L != NULL)
		DeleteList(L); //�ǿ���ɾ����
	L = (List)malloc(sizeof(Node));
	if (L == NULL)
	{
		printf("Out of memory");
		exit(1);
	}
	L->Next = NULL;
	return L;
}

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position Find(ElementType x, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != x)
		P = P->Next;
	return P;
}

void Delete(ElementType x, List L) //ɾ��Ԫ��
{
	Position TmpCell;
	Position P;
	P = FindPrevious(x, L);
	if (!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}
Position FindPrevious(ElementType x, List L) //��ǰ��
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Element != x)
	{
		P = P->Next;
	}
	return P;
}
void Insert(ElementType x, List L, Position P) //����
{
	Position TmpCell;
	TmpCell = NewNode(x);
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
void DeleteList(List L) //ɾ����
{
	Position P, TmpCell;
	P = L->Next;
	L->Next = NULL;
	while (P != NULL)
	{
		TmpCell = P->Next;
		free(P);
		P = TmpCell;
	}
}
void PrintList(List L)
{
	Position Ptr;
	Ptr = L->Next;
	while (Ptr != NULL)
	{
		printf("%5d", Ptr->Element);
		Ptr = Ptr->Next;
	}
	printf("\n");
}
