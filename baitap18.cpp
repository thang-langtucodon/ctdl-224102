#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;
const int Sotinh_max = 11;
const int INF = 1e9;    
//tao ma tran ke  nhu slide
const string DSTinh[Sotinh_max] = { "HN", "TN", "BN", "BG", "UB", "HP", "HD", "HY", "PL", "HB", "ST" }; 

struct Matran {   // khai báo
    int Sotinhxet;
    int matrix[Sotinh_max][Sotinh_max];
};
void Khoitaomatran(Matran &g, int n) { 
    g.Sotinhxet = n;
    for (int i = 0; i < n; i++) {     // mtr rong
        for (int j = 0; j < n; j++)  g.matrix[i][j] = 0; }
        
}void ThemDuongMaTran(Matran &g, int u, int v, int matuyen) {
    g.matrix[u][v] = matuyen;  
    g.matrix[v][u] = matuyen; }

struct CanhChon {  
     int u, v;   };
void Prim(Matran &g) { //hàm thuận toán prim
    int n = g.Sotinhxet;
    bool Daduyet[Sotinh_max] = {false};  
    Daduyet[9] = true;     

    CanhChon dsCanh[Sotinh_max];
    int soCanh = 0;
    cout << " PRIM tu dinh Hoa Binh:";
    for (int i = 0; i < n - 1; i++) { // n đỉnh
        int trso_min = INF;
        int u_min = -1, v_min = -1;  // đánh dấu

    for (int i = 0; i < n; i++) {
        if (Daduyet[i]) {   // duyệt đỉnh cây khung
            for (int j = 0; j < n; j++) {  
            if (!Daduyet[j] && g.matrix[i][j] > 0 && g.matrix[i][j] < trso_min) { 
                trso_min = g.matrix[i][j];    
                u_min = i;
                v_min = j; }  
             } }
        }
     if (u_min != -1 && v_min != -1) { // nếu tìm dfduowjc đường mới
        cout << "chọn cạnh " << DSTinh[u_min] << " -> " << DSTinh[v_min] << " = " << trso_min << endl;
        Daduyet[v_min] = true;     // Kết nạp đỉnh mới vào cây
        dsCanh[soCanh++] = {u_min, v_min};   }   // lưu vào mảng để in ra kq
    else  break;    } 

    cout << "Cây khung min: ";
    for (int i = 0; i < soCanh; i++) {
        cout << DSTinh[dsCanh[i].u] << " -> " << DSTinh[dsCanh[i].v]; // in ra số cạnh vừa chọn
        if (i < soCanh - 1) {
            cout << ", "; 
        }
    }
    cout << endl;
}