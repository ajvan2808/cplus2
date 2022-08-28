#include <stdio.h>

void nhapMangMotChieu(int a[], int n){
	int i;
	printf("Nhap vao gia tri cac phan tu:");

	for(i=0; i<n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]); 
	}
}

void xuatMang(int a[], int n){
	int i;
	printf("Mang gom cac phan tu: \n");
	for(i=0; i<n; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
}

void sapXepTangDan(int a[], int n){
	int temp, i, j;
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if (a[i] > a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

// CHÈN TĂNG DẦN 
void chenTangDan(int a[], int n , int x) {
	int i,j;
	for (i=0; i< n;i++) {
		if (x < a[i]) {
			break;
		}
    }
	n++;
	for (j=n; j>i; j--) {
		a[j]=a[j-1];
    }
	a[i]= x;
}

// cach 2: *** lenh while ****
void chenTang(int a[], int n, int x) {
	int i=n-1;
	while (i>=0 && x< a[i]) {
		a[i+1]= a[i];
		i--;
		}
	a[i+1]=x;
	n++;
}

void sapXepGiamDan(int a[], int n){
	int temp, i, j;
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if (a[i] < a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main()
{
	int a[20], n, x;
	printf("Nhap so phan tu n trong mang a: ");
	scanf("%d", &n);

	nhapMangMotChieu(a, n);
	printf("Xuat mang: ");
	xuatMang(a, n);

	sapXepTangDan(a, n);
	printf("Mang tang dan: ");
	xuatMang(a, n);

	sapXepGiamDan(a, n);
	printf("Mang giam dan: ");
	xuatMang(a, n);

	chenTangDan(a, n, x = 5);
	printf("Mang chen tang dan: ");
	xuatMang(a, n);

	return 0;
}
