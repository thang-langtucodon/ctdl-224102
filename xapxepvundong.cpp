#include <iostream>
using namespace std;
//ham tao mang
void inramang(int a[], int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
//ham vun dong
void vundong(int a[], int n, int i){
	int nutcha = i ;
	int trai = 2*i+1;
	int phai = 2*i+2;
//node lon nhat
    if (trai < n && a[trai] > a[nutcha]) nutcha = trai;
    if (phai < n && a[phai] > a[nutcha]) nutcha = phai;
//sua lai cay khi hoan doi
if (nutcha != i) {
        swap(a[i], a[nutcha]);
        vundong(a, n, nutcha);    
    }
}
void heapsort(int a[], int n){
	cout << "\ncac buoc tao nut cha\n ";
	for(int i= n/2 - 1; i >=0; i--){
	
	cout << "\n vun dong tai node\n"<<i << endl;
	vundong (a, n, i);}
	cout <<"trang thai hien tai : ";
	inramang(a, n);
	 for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);

        cout << "dua phan tu lon nhat ve cuoi: ";
        inramang(a, n);

        vundong(a, i, 0);

        cout << "sau vun dong: ";
        inramang(a, n);
}
}
int main() {
    int a[] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7,};//slide
    int n1 = 10;

    heapsort(a, n1);

    cout << "ket qua: ";
    inramang(a, n1);
//cay tren bang
    int b[] = {0, 11, 54, 32, 106, 38, 78, 203, 16, 84, 17, 39, 15};
    int n2 = 12;

    heapsort(b, n2);

    cout << "ket qua: ";
    inramang(b, n2);


    return 0;
}