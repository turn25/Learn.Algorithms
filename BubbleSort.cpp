#include <iostream>
using namespace std;
void InputArray(int [],int &); //tham chiếu
void OutputArray(int [],int);
void Swap(int &,int &); //tham chiếu
void BubbleSort(int [],int );

int main()
{
    int a[100];
    int n;
    InputArray(a,n);
    cout<<"Array: ";
    OutputArray(a,n);
    BubbleSort(a,n);
    cout<<"Sorted Array ";
    OutputArray(a,n);
    return 0;
}

void InputArray(int a[],int &n) //n là tham chiếu
{
    do{                   //Thực hiện câu lệnh trước 1 lần xong mới xét ĐK
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

void Swap(int &a ,int &b) // Truyền đối số cho hàm là tham chiếu
{
        int temp=a;
        a=b;
        b=temp;
}

void BubbleSort(int a[],int n) //Sort từ LỚN đến NHỎ
{
    for(int i=0;i<n;i++)  // Vòng lặp ngoài để cho phần tử nổi lên 
    {
        for(int k=0;k<n-1;k++)    //Chạy n-1 lần vì dưới đk có a[k+1] nếu để <n thì sẽ xảy ra lỗi
            if(a[k]<a[k+1])       // So sánh 2 phần tử liên tiếp trong mảng
                Swap(a[k],a[k+1]);
    }
}