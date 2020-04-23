#include <iostream>
using namespace std;

void InputArray(int [],int &); // tham chiếu
void OutputArray(int [],int );
void Swap(int &,int &); // tham chiếu
void Heapify(int [],int, int );
void BuildHeap(int [],int );
void HeapSort(int [],int );

/* Ý tưởng:
Sử dụng BuildHeap tạo dãy heap a[1,...,n-1] với n là độ dài (tùy vào TH mà tạo dãy binary max-heap hoặc binary min-heap)
Lần lượt đưa a[0] về vị trí cuối cùng của dãy heap đang xét.(xét dãy heap đã loại bỏ phần tử cuối). Sử dụng heapify vị trí
a[0] để đưa dãy hiện tại về dãy có tính chất heap. Lặp lại cho đến khi dãy còn 1 phần tử.
Độ phức tạp O( n*log(n) ) / mỗi lần đưa dãy về tính chất heap chỉ tốn log(n)
*/
int main()
{
    int a[50];
    int n;
    InputArray(a,n);
    cout<<"Array: ";
    OutputArray(a,n);
    HeapSort(a,n);
    cout<<"\nSorted Array: ";
    OutputArray(a,n);
    return 0;
}

void InputArray(int a[],int &n) //tham chiếu
{
    do{
        cout<<"Input n: ";
        cin>>n;
    }while(n<=0);
    for(int i=0;i<n;i++)
    {
        cout<<"Input a["<<i<<"]: ";
        cin>>a[i];
    }
}

void OutputArray(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

void Swap(int &a,int &b) //tham chiếu
{
    int temp=a;
    a=b;
    b=temp;
}

void Heapify(int a[],int HeapSize,int i) // đưa dãy về tính chất heap
{
    int LeftChild=2*i+1;
    int RightChild=2*i+2;
    int max=i;
    if(LeftChild < HeapSize && a[LeftChild] > a[max])
        max=LeftChild;
    if(RightChild < HeapSize && a[RightChild] > a[max])
        max=RightChild;
    if(max != i)
    {
        Swap(a[i],a[max]); // hoán vị a[i] với max
        Heapify(a,HeapSize,max); //Heapify thay vị trí i = max, tìm leftchild,rightchild của max rồi đưa về tính chất dãy heap
    }
}

void BuildHeap(int a[],int n) //tạo dãy heap , trong TH này là binary max-heap (gtrị bất kì của 1 node trên cây đều > gtrị của node con)
{
    int HeapSize=n; //length[a] = n;
    for(int i= n/2 -1;i>=0;i-- ) // Công thức : i= parent = (n-1)/2 ; leftchild = 2i+1 ; rightchild = 2i+2
        // bottom-up manner : thực hiện Heapify từ dưới lên  ~ a[n/2-1] lên a[0]
        Heapify(a,HeapSize,i);  
}       

void HeapSort(int a[],int n) //Tăng dần
{
    int HeapSize=n;
    BuildHeap(a,n); // tạo dãy heap
    for(int i=n-1; i>=1;i--) // n-1 là vị trí cuối của dãy heap, i-- sau mỗi vòng lặp xét đến khi i=1 
    {   // Thực hiện đến khi dãy còn 1 phần tử
        Swap(a[0],a[i]); // hoán vị a[0] với phần tử cuối của dãy heap đang xét
        HeapSize--; //độ dài dãy heap - 1 vì vừa đưa a[0] về vị trí cuối nên ko xét vị trí đó nữa
        Heapify(a,HeapSize,0); // Heapify lại phần tử a[0] để đưa dãy về tính chất Heap
    }
}