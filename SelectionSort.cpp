#include <iostream>
using namespace std;

void InputArray(int [],int &); // tham chiếu
void OutputArray(int [] ,int );
void Swap(int &, int &); // tham chiếu 
void SelectionSort(int [],int ); //O(n^2) với mọi trường hợp ,
/* Trong trường hợp SORT từ NHỎ đến LỚN
Tìm phần từ nhỏ nhất trong mảng sau đó swap vị trí của phần tử đó với 
phần từ ở ĐẦU ĐOẠN chưa SẮP XẾP ( KO phải ở đầu MẢNG)
*/

int main()
{
    int a[50];
    int n;
    InputArray(a,n);
    cout<<"Array: ";
    OutputArray(a,n);
    SelectionSort(a,n);
    cout<<"Sorted Array: ";
    OutputArray(a,n);
    return 0;
}

void InputArray(int a[],int &n) // n là tham chiếu 
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

void Swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void SelectionSort(int a[],int n) //SORT từ NHỎ đến LỚN
{
    for(int i=0;i<n-1;i++)    //Cho i là vị trí ở đầu ĐOẠN chưa SẮP XẾP nên ...chạy đến n-1
    {
        int min=i;   //vị trí nhỏ nhất hiện tại trong mảng GÁN bằng vị trí đầu ĐOẠN chưa SẮP XẾP
        for(int j=i+1;j<n;j++)  // cho j=i+1 tăng dần để xét
        {    //TÌM VỊ TRÍ NHỎ NHẤT
            if(a[j]<a[min])  //NẾU a[j]>a[min]
                min=j; // gán cho (vị trí) min = (vị trí) j ... rồi quay về vòng for tăng giá trị j xét tiếp
        }
        Swap(a[i],a[min]);  //swap vị trí có giá trị NHỎ NHẤT với vị trí ĐẦU ĐOẠN chưa SẮP XẾP
    }
}
