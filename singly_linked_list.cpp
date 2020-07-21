/* Để lưu trữ một đa thức thưa trong máy tính, người ta có thể sử dụng danh sách liên kết đơn, 
trong đó mỗi phần tử của đa thức (là các đơn thức) bao gồm một hệ số và số mũ. 

Ví dụ: 100x70 + 25x15 - 6x3 + 9. Anh chị hãy thực hiện các yêu cầu sau:

a. Hãy định nghĩa các cấu trúc dữ liệu cần thiết để lưu trữ một đa thức.
b. Viết hàm cộng 2 đa thức.
c. Viết hàm in đa thức lên màn hình.
*/

#include <iostream>
using namespace std;

//Cấu trúc của 1 node
struct NODE{
    float HeSo;
    int SoMu;
    NODE* pNext;
};

//Cấu trúc của 1 danh sách 
struct LIST{
    NODE* pHead;
    NODE* pTail;
};

//Tạo danh sách rỗng
void CreateEmptyList(LIST &L){
    L.pHead=NULL;
    L.pTail=NULL;
}

//Tạo node mới
NODE* CreateNode(float x,int y){
    NODE* p;
    p = new NODE;
    if( p == NULL)
        return NULL;
    p->HeSo = x;
    p->SoMu = y;
    p->pNext = NULL;
    return p;
}
/*
//hàm thêm node vào đầu
void AddHead(LIST &L, NODE* p){
    if(L.pHead == NULL){          // nếu danh sách rỗng
        L.pHead = p;              // pHead = p
        L.pTail = L.pHead;        // pTail = pHead
    }
    else{                         // ngược lại
        p->pNext = L.pHead;       // pNext = pHead
        L.pHead = p;              // pHead = p;
    }
} 

void InsertHead(LIST &L, float x, int y){
    NODE* p = CreateNode(x,y);
    if(p == NULL)
        return;
    AddHead(L,p);
}
*/

// Thêm node vào cuối danh sách
void AddTail(LIST &L,NODE* p){
    if(L.pTail == NULL)            // nếu danh sách rỗng
        L.pHead = L.pTail = p;     // pTail = pHead = p
    else                           // ngược lại
    { 
        L.pTail->pNext = p;        // pTail->pNext = p;
        L.pTail = p;               // pTail = p;
    }
    
}

void InsertTail(LIST &L,float x,float y){
    NODE*p =CreateNode(x,y);
    if(p==NULL)
        return;
    AddTail(L,p);
}

void NhapDaThuc(LIST &L){
    float HeSo;
    int SoMu;
    cout<<"\nBat dau nhap da thuc (nhap he so = 0 de ket thuc chuong trinh):\n";
    do{
        cout<<"Nhap he so ";
        cin>>HeSo;
        if(HeSo == 0 )
            break;
        cout<<"Nhap so mu ";
        cin>>SoMu;
        InsertTail(L,HeSo,SoMu);
    }while(HeSo != 0);
}

void XuatDanhSach(LIST L){
    NODE *p;
    p = L.pHead;
    while( p != NULL){
        if(p->HeSo > 0 )
            cout<<"+"<<p->HeSo<<"^"<<p->SoMu<<" ";
        else
            cout<<p->HeSo<<"^"<<p->SoMu<<" ";
        p=p->pNext;
    }
}

//L3 = L1+L2
void CongDaThuc(LIST L1,LIST L2, LIST &L3){
    NODE* p = L1.pHead;
    NODE* q = L2.pHead;
    float TongHeSo;
    while(p&&q){
        if(p->SoMu == q->SoMu){ // Hai số mũ = nhau
            TongHeSo = p->HeSo + q->HeSo;
            if(TongHeSo != 0)
                InsertTail(L3,TongHeSo,p->SoMu);
            p=p->pNext;
            q=q->pNext;
        }
        else{ 
            if(p->SoMu > q->SoMu){             // Số mũ p > q thì thêm p trước
                InsertTail(L3,p->HeSo,p->SoMu);
                p=p->pNext;
            }
            else                              // ngược lại số mũ p<q thì thêm q trước
                if(p->SoMu < q->SoMu){
                    InsertTail(L3,q->HeSo,q->SoMu);
                    q=q->pNext;
                }
        }
        while (q){ // biểu thức d1 (p) kết thúc trước
            InsertTail(L3,q->HeSo,q->SoMu);
            q=q->pNext;
        }
        while (p){  // biểu thức d2 (q) kết thúc trước
            InsertTail(L3,p->HeSo,p->SoMu);
            p=p->pNext;
        }
    }

}

int main(){
    LIST l1,l2,l3;
    CreateEmptyList(l1);
    CreateEmptyList(l2);
    CreateEmptyList(l3);
    cout<<"Nhap da thuc 1:";
    NhapDaThuc(l1);
    cout<<"Nhap da thuc 2:";
    NhapDaThuc(l2);
    CongDaThuc(l1,l2,l3);
    cout<<"Tong hai da thuc la: ";
    XuatDanhSach(l3);
    return 0;
}