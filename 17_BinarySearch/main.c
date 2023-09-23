#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void BubbleSort(int a[], int n){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(a[j] < a[j-1]){
				swap(&a[j],&a[j-1]);
			}
		}
	}
}
void shuffle(int *array, int n){
    for(int i = 0; i<n; i++){
        int j = rand() % (i+1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
int BinarySearch(int *a, int l, int r, int x){
    if(r>=l){
        int mid = l + (r-l)/2;
        if(a[mid] == x) return mid;
        else if(a[mid] > x)
            return BinarySearch(a, l, mid-1, x);
        else if(a[mid] < x) 
            return BinarySearch(a, mid-1, r, x);\
    }
    return -1;
}
void main(){
    int a[10000];
    
    for(int i = 0; i<10000; i++){
        a[i] = i;
    }
    srand(time(NULL));
    shuffle(a, 10000);
    for(int i = 0; i<10000; i++){
        printf("%d ", a[i]);
    }
    BubbleSort(a, 10000);
    int x;
    printf("Nhap gia tri can tim:\n");
    scanf("%d", &x);
    int res = BinarySearch(a, 0, 10000-1, x);
    if(res == -1) printf("Khong tim thay\n");
    else printf("Tim thay %d tai vi tri %d\n", x, res);
    

}