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
void Prim(Matran &g) { //ham prim
    int n = g.Sotinhxet;
    bool Daduyet[Sotinh_max] = {false};  
    Daduyet[9] = true;     

    CanhChon dsCanh[Sotinh_max];
    int soCanh = 0;
    cout << " PRIM tu dinh Hoa Binh:";
    for (int i = 0; i < n - 1; i++) { // n dinh
        int trso_min = INF;
        int u_min = -1, v_min = -1;  // danh dau

    for (int i = 0; i < n; i++) {
        if (Daduyet[i]) {   // duyet dinh
            for (int j = 0; j < n; j++) {  
            if (!Daduyet[j] && g.matrix[i][j] > 0 && g.matrix[i][j] < trso_min) { 
                trso_min = g.matrix[i][j];    
                u_min = i;
                v_min = j; }  
             } }
        }
     if (u_min != -1 && v_min != -1) { // nneu tim duong moi
        cout << "chọn cạnh " << DSTinh[u_min] << " -> " << DSTinh[v_min] << " = " << trso_min << endl;
        Daduyet[v_min] = true;     // Kết nạp đỉnh mới vào cây
        dsCanh[soCanh++] = {u_min, v_min};   }   // luu vao mang
    else  break;    } 

    cout << "Cây khung min: ";
    for (int i = 0; i < soCanh; i++) {
        cout << DSTinh[dsCanh[i].u] << " -> " << DSTinh[dsCanh[i].v]; // in ra so canh da chon
        if (i < soCanh - 1) {
            cout << ", "; 
        }
    }
    cout << endl;
}
struct Canh {   int u, v, ts;  };  // thong tin 1 canh 
int Timgoc(int cha[], int i) {
    return (cha[i] == -1) ? i : Timgoc(cha, cha[i]);  }
void TTKruskal(Matran &g) {
    int n = g.Sotinhxet, socanh = 0;
    Canh ds[100]; 
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) { // nua tren ma tran doi ung
    if (g.matrix[i][j] > 0) {   
        ds[socanh] = {i, j, g.matrix[i][j]}; 
        socanh++;    } }
}
for (int i = 0; i < socanh - 1; i++) {   // xap sep theo thu tu trong so
    for (int j = i + 1; j < socanh; j++) {
        if (ds[i].ts > ds[j].ts) swap(ds[i], ds[j]);  }
}
    cout << "KRUSAL "; 
for (int i = 0; i < socanh; i++) {
    cout << DSTinh[ds[i].u] << " -> " << DSTinh[ds[i].v] << " = " << ds[i].ts << ((i < socanh - 1) ? ", " : "\n\n");} 
 int cha[Sotinh_max];
    for (int i = 0; i < n; i++) cha[i] = -1; 
 Canh caykhung[Sotinh_max]; 
    int socanhcay = 0;
for (int i = 0; i < socanh; i++) {
        int goc_u = Timgoc(cha, ds[i].u);
        int goc_v = Timgoc(cha, ds[i].v);
 if (goc_u != goc_v) {  // goc khac
        cout << " adding " << DSTinh[ds[i].u] << " -> " << DSTinh[ds[i].v] << " = " << ds[i].ts << endl; 
        caykhung[socanhcay++] = ds[i]; 
        cha[goc_u] = goc_v;            
    } }
cout << "Cây khung min: ";
    for (int i = 0; i < socanhcay; i++) {
        cout << DSTinh[caykhung[i].u] << " -> " << DSTinh[caykhung[i].v];
        if (i < socanhcay - 1) cout << ", "; }
    cout << endl;
}
void Inmatran(int P[Sotinh_max][Sotinh_max], int n) { // in ra ma trận
    cout << setw(6) << " ";
    for (int j = 0; j < n; j++) { cout << setw(5) << DSTinh[j]; }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(6) << DSTinh[i];
        for (int j = 0; j < n; j++)    cout << setw(5) << P[i][j];
        cout << endl;
    }  }   
    int main() {
    int n = Sotinh_max;
    Matran g; 
    Khoitaomatran(g, n);
    int duongdi[][3] = { {0, 6, 1}, {6, 7, 2}, {8, 7, 3}, {0, 8, 4}, {0, 9, 5},   
    {0, 10, 6},{0, 1, 7}, {0, 2, 8}, {2, 3, 9}, {3, 4, 10}, {2, 4, 11},  {4, 5, 12}, {6, 5, 13}   };
    int soTuyen = sizeof(duongdi) / sizeof(duongdi[0]);
     for(int i = 0; i < soTuyen; i++) { 
    ThemDuongMaTran(g, duongdi[i][0], duongdi[i][1], duongdi[i][2]);}
    cout << "Ma tran ban dau" << endl ; 
    Inmatran(g.matrix, n);
Prim(g);
    TTKruskal(g);
    return 0;
}