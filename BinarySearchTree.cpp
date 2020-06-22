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

TNODE* CreateTNode(int x){
    TNODE *p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

int Insert(TREE &T,TNODE *p){
    if(T){
        if (T->key == p->key) return 0;
        if (T->key > p->key)
            return Insert(T->pLeft, p);
        return Insert(T->pRight, p);
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
    Q.push(T);
    while(Q.empty() == false){
        TNODE *x = Q.front();
        Q.pop();
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
    while(Q.empty() == false){
        int NodeCount = Q.size();
        while(NodeCount > 0){
            TNODE *x = Q.front();
            Q.pop();
            if(x->pLeft != NULL)
                Q.push(x->pLeft);
            if(x->pRight != NULL)
                Q.push(x->pRight);
            cout<<x->key<<" ";
            NodeCount --;
        }
        cout<<"\n";
    }
    
}

TNODE* FindMax(TREE T){
    if(T==NULL)
        return 0;
    while(T->pRight != NULL)
        T=T->pRight;
    return T;
}

int SumAllNode(const TREE &T){
    if(T==NULL) return 0;
    int a = SumAllNode(T->pRight);
    int b = SumAllNode(T->pLeft);
    return a+b+T->key;
}

void SumNode(TREE &T, int &sum)
{
    if(T){
        SumNode(T->pLeft,sum);
        SumNode(T->pRight,sum);
        sum+=T->key;
    }
}

int Height(const TREE &T) {
	if (T == NULL) return -1;
	int a = Height(T->pRight);
	int b = Height(T->pLeft);
	return (a > b ? a : b) + 1;
}

int SumInternalNode(const TREE &T){
    if(T==NULL) return 0;
    bool isInternal = 0;
    int a = SumInternalNode(T->pLeft);
    int b = SumInternalNode(T->pRight);
    if( T->pLeft)
        isInternal=1;
    if(T->pRight)
        isInternal=1;
    if(isInternal)
        return a+b+T->key;
    return a+b;
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