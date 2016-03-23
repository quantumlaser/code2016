#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
void bubbleSort(int a[], int N);
void insertSort(int a[], int N);
void quickSort(int a[], int left, int right);
void testSort();
void testA(int a[], int N){
	bool ok=true;
	for(int i=0; i<N-1; i++){
		if(a[i]>a[i+1]){
			ok = false;
			break;
		}
	}
	if(!ok){
		for(int i=0; i<N; i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;		
	}
}
int main(){
	testSort();
	return 0;
}

void testSort(){
	int a[15];
	int N=15;
	int b[15];
	int testNum=1000;
	for(int i=0; i<testNum; i++){
		for(int j=0; j<N; j++){
			a[j] = rand()%1000;
		}
		memcpy(b, a, sizeof(a));
		bubbleSort(b, N);
		testA(b, N);
		
		memcpy(b, a, sizeof(a));
		quickSort(b, 0, N);
		testA(b, N);
	}
}

void bubbleSort(int a[], int N){
	int minNum,minInd;
	for(int i=0; i<N; i++){
		minNum = a[i];
		minInd = i;
		for(int j=i+1; j<N; j++){
			if(minNum > a[j]){
				minNum = a[j];
				minInd = j;
			}
		}
		a[minInd] = a[i];
		a[i] = minNum;
	}
}

void quickSort(int a[], int left, int right){
	if(right-left <= 1)
		return;
	int p=a[left];
	int i=left+1,j=right;
	int temp;
	while(i<=j){
		while(i<=j && a[i]<p) i++;
		while(i<=j && a[j]>=p) j--;
		if(i<j){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		} else {
			a[left] = a[j];
			a[j] = p;
		}
	}
	quickSort(a, left, j-1);
	quickSort(a, j+1, right);
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