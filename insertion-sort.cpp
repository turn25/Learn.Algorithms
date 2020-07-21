/*II.	Dùng mảng 1 chiều để quản lý một bãi đậu xe mô tô gồm N xe. 
Biết rằng mỗi xe mô tô gồm các thông tin sau: Biển số xe (dạng chuỗi), Phân khối xe (kiểu nguyên).

a.	Khai báo các cấu trúc dữ liệu cần thiết để quản lý danh sách xe. 
b.	Cài đặt hàm cho phép nhập và xuất mảng gồm N xe. 
c.	Sắp xếp danh sách xe giảm dần theo Biển số xe sử dụng thuật toán Insertion Sort.
d.	Viết màn main để chạy các hàm trên.
*/

#define maxn 100;
#include <iostream>
using namespace std;

struct XE{
    string BSX;
    int PKX;
};

void Input(XE a[],int &n){
    do{
        cout<<"Nhap so xe (nhap 0 de thoat): ";
        cin>>n;
    }while(n<0);
    for(int i =0;i<n;i++){
        cout<<"\nNhap bien so cua xe thu "<<i+1<<": ";
        cin>>a[i].BSX;
        cout<<"\nNhap phan khoi cua xe thu "<<i+1<<": ";
        cin>>a[i].PKX;
    }
}

void Output(XE a[],int n){
    for(int i=0;i<n;i++){
        cout<<i+1<<"\nBien so:"<<a[i].BSX<<"\nPhan khoi: "<<a[i].PKX<<endl;
    }
}

void InsertionSort(XE a[],int n){
    int pos; //vị trí các phần tử
    XE x; // lưu giá trị a[i] tránh bị ghi đè khi dời chỗ các phần tử
    for(int i=0;i<n;i++){ // đoạn a[9] đã đc sắp rồi
        x = a[i];
        pos = i-1; // tìm vị trí chèn x;
        while(pos>= 0 && (a[pos].BSX < x.BSX)){
            // dời chỗ các phần tử đứng sau x trong dãy mới
            a[pos+1] = a[pos]; // dời sang bên phải 1 đơn vị
            pos--;
        }
        a[pos+1] = x; // chèn x vào dãy 
    }
}

int main(){
    XE a[100];
    int n;
    Input(a,n);
    InsertionSort(a,n);
    Output(a,n);
    return 0;
}