#include <stdio.h>


void nhapMangMotChieu(int a[], int n){
	int i;
	printf("Nhap vao gia tri cac phan tu:");

	for(i=0; i<n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]); 
	}
}


void outputArray(int arr[], int n) {
	int i;
	printf("-------------------- \n");
	for (i = 0; i < n; i++) {
		printf("a[%d] = %d \n", i, arr[i]);
	}
}


// TÌM SỐ LỚN NHẤT
int findMax(int arr[], int n) {
	int i, max = 0;
	for(i=0; i<n; i++) {
		if (arr[i] > max)
		{
			arr[i] = max;
		}
	}
	return max;
}


// TÌM TỔNG
int sum(int arr[], int n) {
	int s=0, i;
	for (i=0; i<n; i++) {
		s += arr[i];
	}
	return s;
}


// ĐẾM SỐ PHẦN TỬ BẰNG X
int findEqualElement(int arr[], int n, int x) 
{
	int counter = 0, i;
	for (i=0; i<n; i++) {
		if (arr[i] == x) {
			counter++;
		}
	}

	return counter;
}


// TÌM PHẦN TỬ X TRONG MẢNG (CÓ - 1, KO - 0)
int findX (int arr[], int n, int x)
{
	int i, rs =0;
	while (i<n && rs == 0) {
		if (arr[i] == x) {
			rs = 1;
			i++;
		}
	}
	return rs;
}


int main ()
{
	int n;
	int arr[20];

	printf("Enter lenght of array: ");
	scanf("%d", &n);

	nhapMangMotChieu(arr, n);
	outputArray(arr, n);
	findMax(arr, n);
	sum(arr, n);

	int x;
	printf("Which element (x) you want to find: ");
	scanf("%d", &x);
	printf("Result: ");
	findX(arr, n, x);


	int y;
	printf("Enter element (y) you want to count: ");
	scanf("%d", &y);
	printf("Number of y found in array: ");
	findEqualElement(arr, n, y);
}
