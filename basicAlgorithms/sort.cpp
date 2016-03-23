#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
void bubbleSort(int a[], int N);
void insertSort(int a[], int N);
void quickSort(int a[], int left, int right);
void testSort();
void printA(int a[], int N) {
	for (int i = 0; i<N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void printA(int a[], int left,int right) {
	for (int i = left; i<=right; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void testA(int a[], int N) {
	bool ok = true;
	for (int i = 0; i<N - 1; i++) {
		if (a[i]>a[i + 1]) {
			ok = false;
			break;
		}
	}
	if (!ok) {
		cout << "false: ";
		printA(a, N);
	}
}
int main() {
	testSort();
	return 0;
}

void testSort() {
	const int N = 5;
	const int testNum = 1;
	int a[N], b[N];
	for (int i = 0; i<testNum; i++) {
		for (int j = 0; j<N; j++) {
			a[j] = rand() % 1000;
		}
		memcpy(b, a, sizeof(a));
		bubbleSort(b, N);
		testA(b, N);

		memcpy(b, a, sizeof(a));
		quickSort(b, 0, N-1);
		testA(b, N);
		
		memcpy(b, a, sizeof(a));
		insertSort(b, N);
		testA(b, N);
	}
}

void bubbleSort(int a[], int N) {
	int minNum, minInd;
	for (int i = 0; i<N; i++) {
		minNum = a[i];
		minInd = i;
		for (int j = i + 1; j<N; j++) {
			if (minNum > a[j]) {
				minNum = a[j];
				minInd = j;
			}
		}
		a[minInd] = a[i];
		a[i] = minNum;
	}
}

void quickSort(int a[], int left, int right) {
	if (right - left < 1)
		return;
	int p = a[left];
	int i = left, j = right;
	// printA(a, left, right);
	while (i < j) {
		while (i < j && a[j] >= p) j--;
		a[i] = a[j];
		while (i < j && a[i] <= p) i++;
		a[j] = a[i];	
	}
	a[i] = p;
	// printA(a, left, right);
	quickSort(a, left, j - 1);
	quickSort(a, j + 1, right);
}

void insertSort(int a[], int N){
	int *b = new int[N];
	b[0] = a[0];
	int j;
	for(int i=1; i<N; i++){
		j = 0;
		while(b[j]<a[i] && j<i) j++;
		for(int k=i; k>j; k--){
			b[k] = b[k-1];
		}
		b[j] = a[i];
		for(int k=0;k<=i;k++){
			cout<<b[k]<<" ";
		}
		cout<<endl;
	}
	cout<<sizeof(b)<<sizeof(a)<<endl;
	printA(a, N);
	memcpy(a, b, sizeof(a));
	printA(a, N);
}

void quickSort2(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}