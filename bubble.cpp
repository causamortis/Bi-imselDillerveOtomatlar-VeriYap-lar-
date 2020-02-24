#include <iostream>
using namespace std;
/* ÖDEV: Bubble Sort algoritmasýnýn Tek yönlü Baðlý Liste uygulamasý yapýlacaktýr. (C++)*/ 
void diziYaz(int *D, int N){
	int i,j;
	for(i=0;i<N;i++){
		cout<<D[i]<<"->";
	}
	cout<<endl;
}
void Bubble(int *D,int n){
	int i,j, tmp;
	
	for(i=n;i>0;i--){
		for(j=0;j<i-1;j++){
			if(D[j]>D[j+1]){
				tmp=D[j];
				D[j]=D[j+1];
				D[j+1]=tmp;
			}
			diziYaz(D,n);
		}
			
	}
}
oid selectSort(int arr[], int n) {
	int pos_min, temp;
	for (int i = 0; i < n - 1; i++) {
		pos_min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[pos_min])
				pos_min = j;
		}
		if (pos_min != i) {
			temp = arr[i];
			arr[i] = arr[pos_min];
			arr[pos_min] = temp;
		}
	}
}
void insertion(int arr[], int n) {
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		// diziYaz(arr,10);
	}
}
int main(int argc, char** argv) {
	int Dizi[10]={2,31,6,9,11,13,5,8,12,3};
//	Bubble(Dizi,10);
	cout<<"Siralamadan once"<<endl;
	diziYaz(Dizi,10);
	insertion(Dizi,10);
	cout<<"Siralamadan sonra"<<endl;
	diziYaz(Dizi,10);
	return 0;
}
