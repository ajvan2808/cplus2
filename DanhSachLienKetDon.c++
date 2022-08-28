#include <stdio.h>


// Cấu trúc dữ liệu của Node 
typedef struct  tagNode 
{    int Info;      
    struct  tagNode *Next;
}Node; 


// Cấu trúc dữ liệu của DSLK đơn
typedef struct  tagList 
{    Node  *Head;
    Node  *Tail;
}List;


// Tạo DSLK rỗng 
void CreateList(List &l)
{
    l.Head=NULL;
    l.Tail=NULL;
}

// Hàm trả về địa chỉ phần tử mới tạo 
Node *CreateNode(int data) 
{
    Node *p = new Node;
    p->Info = data;
    p->Next = NULL;
    return p;
}

// add Head Node
void addHead(List &l, Node *p)
{
    if(l.Head==NULL)
    {
        l.Head=p;
        l.Tail=p;
    }
    else
    {
        p->Next = l.Head;
        l.Head = p;
    }
}


// Add Tail Node
void AddTail(List&l, Node *p)
{
    if(l.Head==NULL)
    {
        l.Head=p;
        l.Tail=p;
    }
    else
    {
        l.Tail->Next=p;
        l.Tail=p;
    }
}

// In DS
void PrintList(List l)
{
    Node *p;
    p=l.Head;
    while(p!=NULL)
    {   
        printf("%d\t",p->Info);
        p=p->Next;
    }
}


// Tính tổng 
int sumList(List l) {
    Node *p;
    p = l.Head;
    int s = 0;
    while(p != NULL) {
        s += p->Info;
        p = p->Next;
    }
    return s;
}


// Đếm số phần tử X có trong DSLK đơn
int demX (List l, int x) {
    Node *p;
    p=l.Head;
    int count=0;
    while (p!=NULL) {
        if (p->Info ==x) count++;
        p = p->Next;
    }
    return count;
}


// Tìm X trong DSLK
Node* timX(List l, int x)
{   Node *p;
    p=l.Head;
    while((p!=NULL)&&(p->Info!=x))
    {
        p=p->Next;
    }
    return p; 
}


// Xoá Node Head
void deleteHead(List &l) 
{
    Node *p;
    p= l.Head;
    l.Head= p ->Next;
    if (l.Head==NULL) 
        l.Tail=NULL;
        
    delete p;
}


// Xoá x node
void deleteX(List &l, int x) 
{
    Node *p, *q;
    q = NULL;
    p = l.Head;
    while((p!= NULL)&&(p->Info != x))
    {
        q = p;
        p = p->Next;
    }
    if (p != NULL) 
    {
        if (q == NULL) 
        { // p la l.Head
            deleteHead(l);
        } 
        else 
        {
            q->Next = p->Next;
            if (l.Tail==p) 
            { // p la l.Tail
                l.Tail = q;
            }
            delete p;
        }
    }
}


// Sắp xếp Node tăng dần
void sapXepTang(List l)
{
    Node *i, *j;
    int x;
    for(i = l.Head; i !=L.Tail; i=i->Next){
        for(j = i->Next; j!=NULL; j=j->Next)
        {
            if(j->Info<i->Info)
            {
                x = i->Info;
                i->Info = j->Info;
                j->Info = x;       
            }
        }
    }
}


// ------------- MAIN ----------------
int main()
{
    List l1;
    Node *p;
    int i,x;
    CreateList(l1);
    for(i=0;i<3;i++)
    {
        printf("Nhap info =");
        scanf("%d",&x);
        p=CreateNode(x);
        AddTail(l1,p);
    }
    printf("In list:");
    PrintList(l1);
    printf("Tong cac phan tu trong mang =%d",sumList(l1));
    printf("Nhap x =");
    scanf("%d",&x);
    printf("So pt co gt = x: %d\n",demX(l1,x));
    
    printf("Nhap x can tim =");
    scanf("%d",&x);
    if(timX(l1,x)==NULL)
        printf("Khong tim thay\n");
    else 
        printf("Tim thay\n");
    
    return 0;
}