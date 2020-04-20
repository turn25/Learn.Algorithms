#include <iostream>
using namespace std;
void InputArray(int [],int &);
void OutputArray(int [],int);
int ChooseSortType(int);
void Swap(int &,int &);
void BubbleSort(int [],int );
void InsertionSort(int[],int );

int main()
{
    int a[50];
    int n,number;
    InputArray(a,n);
    cout<<"Array : ";
    OutputArray(a,n);
    if(ChooseSortType(number)==1)
    {
        BubbleSort(a,n);
        cout<<"Bubble Sort";
    }
    else
    {
        InsertionSort(a,n);
        cout<<"Insertion Sort";
    }
    cout<<"\nSorted Array : ";
    OutputArray(a,n);
    return 0;
}

int ChooseSortType(int number)
{
    do{
        cout<<"\nChoose Sort Type:\n1.Bubble Sort\n2.InsertionSort\n";
        cin>>number;
    }while(number!=1 && number !=2);
    if(number==1)
        return 1;
    return 0;
}
void InputArray(int a[],int &n)
{
    do{
        cout<<"Input n ";
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
    {
        cout<<a[i]<<" ";
    }
}

void Swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void BubbleSort(int a[], int n) //Sort từ NHỞ đến LỚN
{
    for(int i=0;i<n;i++)  // Array a bắt đầu từ 0 chạy đến n-1
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])     // ĐỔI DẤU > thành < để Sort từ LỚN đến NHỎ
                Swap(a[j],a[j+1]);
        }
    }
}

void InsertionSort(int a[], int n) //Sort từ NHỎ đến LỚN
{
    for(int i=1;i<n;i++)
    {
        int key = a[i];
        int j = i - 1;
        while(j>=0 && a[j] > key ) // j>=0 để khi j=j-1 = -1 kết thúc vòng lặp, a[j] > key để SORT từ NHỎ đến LỚN    
        {
            a[j+1] = a[j]; // Lùi vị trí a[j] về 1 đơn vị trong mảng
            j=j-1;         
        }
        a[j+1]=key; // Gán giá trị của key cho a[j+1] , j+1 để trả về vị trí của a[j] vì cuối vòng lặp có câu lệnh j=j-1;
    }
}