#include <stdio.h>
#include <string.h>

// void sapXepGiam(int a[], int n)
// {
// 	int i, j, temp;
// 	for (i = 0; i < n-1; i++)
// 	{
// 		for (j = i+1; j < n; j++)
// 		{
// 			if (a[i] < a[j])
// 			{
// 				temp = a[i];
// 				a[i] = a[j];
// 				a[j] = temp;
// 			}
			
// 		}
		
// 	}
	
// }


// KHai bao cau truc du lieu dang pointer cua danh sach lien ket don de luu ds nhan vien
typedef struct{
	char maNV[10];
	char tenNV[20];
	float luong;
} NV;

typedef struct tagNode
{
	NV Info;
	struct  tagNode *Next;
} Node;

typedef struct OnTap
{
	Node *Head;
	Node *Tail;
} List;


// create Node
Node createNode(NV x) {
	Node *p;
	p = new Node;
	p->Info = x;
	p->Next = NULL;
	return p;
}

void createList(List &l) {
	l.Head = NULL;
	l.Tail = NULL;
}

void addHead(List &l, Node *p) {
	if (l.Head == NULL)
	{
		l.Head = p;
		l.Tail = p;
	}
	else
    {
        p->Next=l.Head;
        l.Head=p;
    }
}

// Nhap vao thong tin nhan vien
void NhapNNhanVien(List &l)
{ 
    int i;
    NV x;
    Node *p;
    float tam;
    for(i=1;i<=3;i++)
    {
        printf("Nhap nhan vien thu %d\n",i);
        printf("Ma so:");
        fflush(stdin);
        gets(x.maNV)
        printf("ten:");
        fflush(stdin);
        gets(x.tenNV)
        printf("Luong:");
        scanf("%f",&tam);
        x.luong = tam;
        p=CreateNode(x);
        addHead(l,p);
    }
}

// In DSNV
void InDSNV(List l)
{
    Node *p;
    p=l.Head;
    while(p!=NULL)
    {
        printf("%s\t%s\t%0.2f\n",p->Info.maNV,p->Info.tenNV,p->Info.luong);
        p=p->Next;
    }
}

float luongMax(List l) {
	float max;
	Node *p;
	p = l.Head;
	max = p->Info.luong;
	while (p!= NULL)
	{
		if (p->Info.luong > max) {
			max = p->Info.luong;
		}
		p = p->Next;
	}
	return max;
}

// Tim kiem NV theo maNV
Node* searchID(List l, char id[]) {
	Node *p;
	p = l.Head;
	while ((p != NULL) && (strcmp(p->Info.maNV, id)!=0))
	{
		p = p->Next;
	}
	return p;
}

// Sap xep theo luong tang dan
void sortList(List l) {
	NV temp;
	Node *p, *q;
	for ( p = l.Head; p != l.Tail; p = p->Next)
	{
		for ( q = p->Next; q != NULL; q = q->Next)
		{
			if (q->Info.luong < p->Info.luong) {
				temp = q->Info;
				q->Next = p->Info;
				p->Info = temp

			}
		}
		
	}
	
}

// MAIN 
int main()
{
    List l1;
    char maSo[10];
    CreateList(l1);
    NhapNNhanVien(l1);
    inDSNV(l1);
    /*
    printf("Luong lon nhat:%d\n",luongMax(l1));
    if(searchId(l1,maSo)==NULL)
        printf("Tim khong thay\n");
    else
        printf("Tim thay\n");
    sortList(l1);*/
    return 0;
}
