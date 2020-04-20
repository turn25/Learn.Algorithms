#include <iostream>
using namespace std;

void InputArray(int [],int&);
void OutputArray(int [],int);
void InsertionSort(int [],int);

int main()
{
    int a[50];
    int n;
    InputArray(a,n);
    OutputArray(a,n);
    //int a[]={5,7,4,9,3}; //Ví dụ
    //int n=sizeof(a)/sizeof(a[0]); //Tìm độ dài của mảng a;
    InsertionSort(a,n);
    cout<<" Sorted Array: ";
    OutputArray(a,n);
    return 1;
}

void InputArray(int a[],int &n) //Trả về n là tham chiếu
{
    do{
        cout<<"Input n : ";
        cin>>n;
    }while(n<=0); //Giá trị input phải lớn hơn 0 thì mới thực hiện tiếp
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

void InsertionSort(int a[],int n) //Xếp từ NHỎ đến LỚN
{
    int key,j;
    for(int i=1;i<n;i++) //Xét từ i=1 (phần tử đầu tiên là i=0) đến hết
    {
        key=a[i]; // Đặt key để xét
        j=i-1; // Đặt j đứng trước i

        // Di chuyển phần tử có giá trị LỚN hơn về phía sau , đẩy giá trị NHỎ lên phía trước
        while(j>=0&& a[j]>key) //Thỏa cả 2 điều kiện thì thực hiện tiếp, xét j=>0 và xét a[j] với KEY
        {
            a[j+1]=a[j]; //Lùi giá trị a[j] về 1 đơn vị
            j=j-1; //Giảm giá trị j tiếp tục xét vòng lặp, đến khi j=-1 hoặc ko thỏa a[j]>key thì 
        }          //KẾT THÚC vòng lặp
        a[j+1]=key; //Kết thúc vòng lặp, do trong vòng lặp có j=j-1 nên kết thúc vòng lặp phải + thêm 1 cho j  
    }               //nên để thành a[j+1] , đặt giá trị key vào chỗ a[j+1],

// [0] [1] [2]  XÉT VỚI KEY
// Ví dụ        n = 3 
// 4   2   3         
// VÒNG LẶP ĐẦU   i = 1, key =a[i]= 2, j = i-1 =0             ĐK VÒNG LẶP : i<n
// 4   2   3      j=0 >=0 && a[j]= a[0]= 4 > key = a[1] = 2 -> thỏa     ĐK VÒNG LẶP: j>=0 && a[j]>key
// 4   4   3          a[j+1]=a[1] == a[j]=a[0]=4
//                    j = j-1 = 0-1 =-1 -> trở về xét ĐK vòng lặp j=-1 < 0  -> KO THỎA
// 2   4   3      a[j+1] = a[-1+1]=a[0] == key = a[1] = 2
// VÒNG LẶP ĐẦU   i = 2, key =a[i]= 3, j = i-1 =0  
// 2   4   3      j=1 >=0 && a[j]= a[1] = 4 > key = a[2] = 3 -> thỏa
// 2   4   4          a[j+1]=a[2] == a[j] = a[1] = 4
//                    j = j-1 = 1-1 =0  -> trở về điều xét ĐK vòng lặp a[j]=a[0]= 2 < key = a[2] = 4 -> KO THỎA
// 2   3   4      a[j+1] = a[0+1] = a[1] = key = a[2] = 3
// VÒNG LẶP ĐẦU   i=3 = n -> KO THỎA


}
