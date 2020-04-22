#include <iostream>
using namespace std;

void InputArray(int [],int &); //tham chiếu
void OutputArray(int [],int );
void InsertionSort(int [],int );

/*  in-place, online sorting
    Thuật toán chia mảng làm 2 phần liền kề; 1 bên đã sắp xếp và 1 bên chưa sắp xếp (phần tử đứng 1 mình đc coi là đã sắp xếp)
Lần lượt đem từng phần tử đầu tiên bên mảng chưa sắp xếp qua mảng đã sắp xếp rồi chèn vào vị trí thích hợp để mảng vẫn có thứ tự.
Tốn khoảng n-1 lần để sắp xếp xong mảng
Best Case O(n)     ; Average Case O(n^2)      ;Worse Case O(n^2)               */

int main()
{
    int a[50];
    int n;
    InputArray(a,n);
    cout<<"Array: ";
    OutputArray(a,n);
    InsertionSort(a,n);
    cout<<"\nSorted Array: ";
    OutputArray(a,n);
    return 0;
}

void InputArray(int a[],int &n)  //tham chiếu
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

void InsertionSort(int a[],int n) //Tăng dần
{
    for(int i=1;i<n;i++)
    {
        int x=a[i]; // lưu lại giá trị phần tử để tránh bị ghi đè khi dời chỗ
        int pos=i-1; //tìm vị trí để chèn x
        while(pos>=0 && a[pos]>x)  //Dời chỗ các phần tử nếu thỏa cả 2 đk 
        {
            a[pos+1]=a[pos]; //dời phần tử sang phải 1 đơn vị trong mảng
            pos--; // giảm giá trị để tiếp tục xét vòng lặp,đến pos=-1 hoặc a[pos]<=x thì ko thỏa đk, kết thúc vòng lặp while 
        }
        a[pos+1]=x;  //chèn x vào đây, pos+1 vì trên vòng lặp while có pos--
    }
}