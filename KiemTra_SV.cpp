#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct THISINH
{
	char MS[6];
	char Ho_ten[31];
	float Toan;
	float Ly;
	float Hoa;
	float Diem_tong_cong;
}THISINH;

void Nhap_thong_tin(THISINH &sv);
void Xuat_thong_tin(THISINH &sv);
void Xuat_danh_sach_TS(THISINH sv[], int n);
void DS_TS_SUCCES(THISINH sv[], int n);
void Thi_sinh_Toan_Yeu(THISINH sv[], int n);
void swap(THISINH &a, THISINH &b);
void SX_G_BY_DTC(THISINH sv[], int &dau, int &cuoi); 	// sap xep theo thuat toan quicksort

int main()
{
	printf("Nhap so luong thi sinh du thi: "); int soluong; scanf("%d", &soluong);
	THISINH sv[soluong];
	for(int i = 1; i <= soluong; i++)
	{
		printf("Nhap thong tin thi sinh thu %d \n", i);
		Nhap_thong_tin(sv[i]);
	}
	Xuat_danh_sach_TS(sv, soluong);
	DS_TS_SUCCES(sv, soluong);
	Thi_sinh_Toan_Yeu(sv, soluong);
	
	// còn loi
	int t = 1;
	SX_G_BY_DTC(sv, t, soluong);

}

void Nhap_thong_tin(THISINH &sv)
{
	printf("Nhap Ma So: "); fflush(stdin); gets(sv.MS);
	printf("Nhap Ho & Ten: "); fflush(stdin); gets(sv.Ho_ten);
	printf("Nhap diem Toan: "); fflush(stdin); scanf("%f", &sv.Toan);	
	printf("Nhap diem Ly: "); fflush(stdin); scanf("%f", &sv.Ly);
	printf("Nhap diem Hoa: "); fflush(stdin); scanf("%f", &sv.Hoa);	
	sv.Diem_tong_cong = (sv.Toan + sv.Ly + sv.Hoa);
}

void Xuat_thong_tin(THISINH &sv)
{
	printf("|\t%s ", sv.MS); 
	printf("|\t%20s  ", sv.Ho_ten); 
	printf("|\t%2.2f ", sv.Toan);
	printf("|\t%2.2f ", sv.Ly);
	printf("|\t%2.2f ", sv.Hoa);
	printf("|\t%15.2f |", sv.Diem_tong_cong);
	printf("\n+-----------+-------------------------+-------+------+-------+------------------+\n");
}

void Xuat_danh_sach_TS(THISINH sv[], int n)
{
	printf("\n===============================Thong Tin Sinh Vien===============================\n");
	printf("+--Ma So----+-------Ho & Ten----------+--Toan-+--Ly--+--Hoa--+--Diem Tong Cong--+\n");
	for(int i = 1; i <= n; i++)
		Xuat_thong_tin(sv[i]);	
}

void DS_TS_SUCCES(THISINH sv[], int n)
{
	printf("\n===========================Danh Sach THi Dau====================================\n");
	printf("+--Ma So----+-------Ho & Ten---------+-Toan-+--Ly--+-Hoa--+--Diem Tong Cong--+\n");
	int KT = 0 ;
	for(int i = 1; i <= n; i++)
		if(sv[i].Diem_tong_cong > 15.0 && sv[i].Toan > 0.0 && sv[i].Ly > 0.0 && sv[i].Hoa >0.0)
		{
			KT++;
			Xuat_thong_tin(sv[i]);
		} 
	if (KT == 0)
		printf("Khong  co thi sinh nao thi dau !!");
}
void Thi_sinh_Toan_Yeu(THISINH sv[], int n)
{
	int sum = 0;
	printf("\n=================Danh Sach THi Sinh TOAN DUOI 5=================================\n");
	for (int i = 1; i <= n; i++)
	if(sv[i].Toan < 5)
	{
		Xuat_thong_tin(sv[i]);
		sum++;
	}
	printf("\nSo thi sinh co diem toan duoi 5 la %d\n", sum);
}
void swap(THISINH &a, THISINH &b)
{
	THISINH c = a;
	a = b;
	b = c;
}
void SX_G_BY_DTC(THISINH sv[], int &dau, int &cuoi) 
{
	// sap xep theo thuat toan quicksort
	int i, j;
    if(dau >= cuoi) return;
    THISINH x = sv[(dau+cuoi)/2];
    i = dau; j = cuoi;
    while(i <= j) {
        while(sv[i].Diem_tong_cong > x.Diem_tong_cong) i++;
        while(sv[j].Diem_tong_cong < x.Diem_tong_cong) j--;
            if(i <= j)
            {
                swap(sv[i], sv[j]);
                i++;    j--;
            }
    }
    SX_G_BY_DTC(sv, dau, j);

	printf("\n===============================Sap Xep Sinh Vien===============================\n");
	for(int i = 1; i<= cuoi; i++)
		Xuat_thong_tin(sv[i]);
}
