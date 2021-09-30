#include <stdio.h>

int binary_search(int arr[], int left, int right, int x){

    if (right >= left){
        int mid = left + (right - left) / 2;
        // Elemen ditemukan
        if (arr[mid] == x)
            return mid;
        // Elemen tengah lebih besar dari x, pencarian bergeser ke kiri
        if (arr[mid] > x)
            return binary_search(arr, left, mid - 1, x);
        // Elemen tengah lebih kecil dari x, pencarian bergeser ke kanan
        return binary_search(arr, mid + 1, right, x);        
    }
    // Elemen tidak ditemukan
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
    int result = binary_search(arr, 0, n-1, x);
    if (result == -1){
        printf("Elemen yang dicari tidak ditemukan di dalam list");
    } else {
        printf("Elemen %d ditemukan di index ke %d", x, result);
    }
    printf("\n");
}