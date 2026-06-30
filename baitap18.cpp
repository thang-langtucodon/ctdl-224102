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
}