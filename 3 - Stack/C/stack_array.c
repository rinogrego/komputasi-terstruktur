#include <stdio.h>
#include <stdbool.h>

int array_data[10000];
int array_size = 0;

bool isEmpty(){
    return array_size == 0;
}

int length(){
    return array_size;
}

void push(int data){
    array_data[array_size++] = data;
}

void pop(){
    if (!isEmpty()) {
        int pop_data = array_data[array_size-1];
        printf("pop element: %d\n", pop_data);
        array_size--;
    } else {
        printf("Array kosong, tidak bisa pop!\n");
    }
}

int peek(){
    if (!isEmpty()){
        int atas = array_data[array_size-1];
        printf("elemen paling atas: %d\n", atas);
    } else {
        printf("Array kosong, tidak ada elemen teratas!\n");
    }
}

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void main(){
    int pilihan;
    int elemen;

    push(1);
    push(2);
    push(3);
    push(7);
    push(12);
    push(23);

    while (true) {
        printf("\n");
        printf("size: %d\n", length());
        printArray(array_data, length());
        printf("What you want to do?\n");
        printf("1: push\n");
        printf("2: pop\n");
        printf("3: cek array kosong\n");
        printf("4: peek elemen paling atas\n");
        printf("5: exit\n");
        printf("Masukkan pilihan: "); scanf("%d", &pilihan);

        if (pilihan == 1){
            printf("Masukkan angka yang ingin dimasukkan ke dalam antrian: ");
            scanf("%d", &elemen);
            push(elemen);
        } else if (pilihan == 2) {
            pop();
        } else if (pilihan == 3) {
            printf("apakah array kosong? %s\n", isEmpty()? "YA":"TIDAK");
        } else if (pilihan == 4) {
            peek();
        } else if (pilihan == 5) {
            break;
        } else {
            printf("masukkan angka opsi antara 1, 2, 3, 4 atau 5\n");
        }
    }

}