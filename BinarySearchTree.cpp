#include <iostream>
#include <queue>
using namespace std;

struct TNODE{
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;

//Tạo cây rỗng
void CreateEmptyTree(TREE &T){
    T=NULL;
}


//Tạo node
TNODE* CreateTNode(int x){
    TNODE *p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}


//Insert gía trị vào node
int Insert(TREE &T,TNODE *p){
    if(T){
        if (T->key == p->key) return 0; //Nếu bị trùng THÌ return 0;
        if (T->key > p->key) // NẾU root > giá trị đc insert 
            return Insert(T->pLeft, p); // -> THÌ đệ quy insert giá trị về bên trái
        return Insert(T->pRight, p); // đệ quy insert giá trị qua qua bên phải
    }
    T = p;
    return 1;
}

void CreateTree(TREE &T) {
    int x;
    do{
        cout<<"Input data(-1 to cancel): ";
        cin>>x;
        if(x == -1) break;
        Insert(T,CreateTNode(x));
    }while(true);
}

void RNL(TREE T){
    if(T==NULL)
        return;
    RNL(T->pRight);
    cout<<T->key<<" ";
    RNL(T->pLeft);
}

void PrintTreeRNL(const TREE &T){
    if(T==NULL)
        cout<<"Empty Tree.";
    else
        RNL(T);
}

void PrintTreeBFS(TREE &T) {
    if(T == NULL ){
        cout<<"Empty Tree.";
        return;
    }
    queue <TNODE*> Q;
    Q.push(T); //enqueue
    while(Q.empty() == false){   //hàng đợi còn giá trị
        TNODE *x = Q.front();   // lấy giá trị đầu
        Q.pop(); //dequeue
        if(x->pLeft != NULL)
            Q.push(x->pLeft);
        if(x->pRight != NULL)
            Q.push(x->pRight);
        cout<<x->key<<" ";
    }
}

void PrintLevelOrder(TREE &T) {
    if(T == NULL ){
        cout<<"Empty Tree.";
        return;
    }
    queue <TNODE*> Q;
    Q.push(T);
    while(Q.empty() == false){ // nếu hàng đợi còn giá trị / khác rỗng
        int NodeCount = Q.size(); //đếm số phần tử trong hàng đợi ở level hiện tại
        //dequeue tất cả các node ở lvl hiện tại
        //enquêu các node ở lvl kế tiếp
        while(NodeCount > 0){ //vòng lặp chạy n lần với n là số phần tử trong hàng đợi
            TNODE *x = Q.front();
            Q.pop();
            if(x->pLeft != NULL) // bên trái có node con thì enqueue
                Q.push(x->pLeft);
            if(x->pRight != NULL) // bên phải có node con thì enqueue
                Q.push(x->pRight);
            cout<<x->key<<" ";
            NodeCount --; // đk dừng
        }
        cout<<"\n"; // xuống dòng để tạo level order
    }
    
}

//Tìm giá trị lớn nhất
TNODE* FindMax(TREE T){
    if(T==NULL)
        return 0;
    while(T->pRight != NULL) // giá trị cuói cùng bên phải của cây
        T=T->pRight;
    return T;
}

//Tính tổng các node 
void SumNode(TREE &T, int &sum) // sum =0; truyền tham chiếu cho sum
{
    if(T){
        SumNode(T->pLeft,sum); // Tổng các node bên trái
        SumNode(T->pRight,sum); // Tổng các node bên phải
        sum+=T->key; // sum = sum + T->key;
    }
}

//Tính tổng các node đệ quy
int SumAllNode(const TREE &T){ // const = hằng số
    if(T==NULL) return 0;// null -> return gt 0
    int a = SumAllNode(T->pRight); // chạy hết node bên PHẢI
    int b = SumAllNode(T->pLeft); // chạy tiếp bên trái của node cuối cùng bên PHẢI
    return a+b+T->key; // trái node hiện tại + 2 node con
}

//Tìm độ sâu / chiều cao cây
int Height(const TREE &T) {
	if (T == NULL) return -1; // nếu ko có node nào ở vị trí đang xét(NULL) -> RETURN -1
	int a = Height(T->pRight);
	int b = Height(T->pLeft);
	return (a > b ? a : b) + 1; // max(a,b) +1 = lấy giá trị lớn nhất giữa a,b +1, (-1+1 =0);
}

//Tổng các node trong / internal node ( là các node có hơn 1 node con)
int SumInternalNode(const TREE &T){
    if(T==NULL) return 0; // check có node nào ở vị trí đang xét ko nếu 0 có thì return 0.
    bool isInternal = 0; // tạo biến kiêu bool = 0
    int a = SumInternalNode(T->pLeft); //chạy hết node bên trái ...
    int b = SumInternalNode(T->pRight); // -> chạy tiếp node bên phải
    if( T->pLeft) // có node con bên trái
        isInternal=1; // bool =1
    if(T->pRight) // có node con bên phải
        isInternal=1; // bool =1
    if(isInternal) // NẾU là internalnode( node con bên trái hoặc bên phải hoặc cả 2)
        return a+b+T->key; // RETURN gt: node hiện tại + 2 node con trái phải
    return a+b; //NẾU ko phải (trái + phải) = 0 + 0 (0 vì ở dòng đầu có đk check có phải NULL ko)
}

int main() {
    TNODE* T;
    CreateEmptyTree(T);
    CreateTree(T);
    cout<<"Print binary tree by RNL: ";
    PrintTreeRNL(T);
    cout<<"\n"<<"Print binary tree by BFS: ";
    PrintTreeBFS(T);
    cout<<"\n";
	if(T!=NULL)
        cout <<"Maximum value in the tree is: "<< FindMax(T)->key <<"\n";
    int sum=0;
    SumNode(T,sum);
    cout<<"Sum of all nodes in the tree is: "<<sum<<"\n";
    cout<<"Sum of all nodes in the tree is(recursive): "<<SumAllNode(T)<<"\n";
    if(T!=NULL)
        cout<<"Height of the tree is: "<<Height(T)<<"\n";
    cout<<"Sum of all internal nodes in the tree is: "<<SumInternalNode(T)<<"\n";
    cout<<"Print Level Order of the Tree:\n";
    PrintLevelOrder(T);
    return 1;
}