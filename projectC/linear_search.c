#include <stdio.h>

int search(int arr[], int n, int x){

    int i;

    for (i = 0; i < n; i++){
        if (arr[i] == x){
            // elemen ditemukan
            return i;
        }
    }
    // indikasi bahwa elemen tidak ditemukan
    return -1;
}


void main(){
    
    int arr[] = {4, 12, 23, 56, 71, 124, 342, 531, 766, 863, 1002, 1853, 1900, 2051, 3690, 4005};
    int x;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Input data
    printf("Masukkan angka yang ingin dicari di list: ");
    scanf("%d", &x);

    // Function call
    int result = search(arr, n , x);
    if (result == -1) {
        printf("Element yang ingin dicari tidak ada di dalam array");
    }
    else {
        printf("Element %d ada di index %d", x, result);
    };
    printf("\n");

}