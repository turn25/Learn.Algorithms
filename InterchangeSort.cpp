#include <iostream>
using namespace std;

void InputArray(int [],int &); // tham chiếu
void OutputArray(int [],int );
void Swap(int &,int &);
void InterchangeSort(int [],int );

/*Xuất phát từ đầu dãy, tìm tất các các nghịch thế chứa phần tử này, 
triệt tiêu chúng bằng cách đổi chỗ 2 phần tử trong cặp nghịch thế. 
Lặp lại xử lý trên với phần tử kế trong dãy cho đến khi dãy còn 1 phần tử.
*/

/* Ý tưởng
Thuật toán duyệt tất cả cặp giá trị và Swap vị trí nếu 
2 phần tử trong cặp giá trị NGHỊCH THẾ.

một cặp giá trị đc gọi là NGHỊCH THẾ khi cả 2 phần tử trong cặp ko thỏa đk sắp thứ tự
*/

int main()
{
    int a[50];
    int n;
    InputArray(a,n);
    cout<<"Array: ";
    OutputArray(a,n);
    InterchangeSort(a,n);
    cout<<"Sorted Array: ";
    OutputArray(a,n);
    return 0;
}

/*int main()
{
    int a[4]={5,3,1,2};
    int size = sizeof(a)/sizeof(int);
    InterchangeSort(a,size);
    OutputArray(a,size);
    return 0;
}*/

void InputArray(int a[],int &n)
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

void Swap(int &a,int &b) //truyền đối số cho hàm là  tham chiếu
{
    int temp=a;
    a=b;
    b=temp;
}

void InterchangeSort(int a[],int n) //Sort từ NHỎ đến LỚN
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                Swap(a[i],a[j]);
            }
        }
    }
}
