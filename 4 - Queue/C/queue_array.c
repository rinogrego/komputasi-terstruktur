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

void enqueue(int data){
    array_data[array_size++] = data;
}

void dequeue(){
    if (!isEmpty()) {
        int index = 0;
        int dequeue_data = array_data[index];
        
        printf("Dequeue element: %d\n", dequeue_data);
        while(index <= array_size){
            array_data[index] = array_data[index+1];
            index++;
        }
        array_size--;
    } else {
        printf("Array kosong, tidak bisa dequeue!\n");
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

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(7);
    enqueue(12);
    enqueue(23);

    while (true) {
        printf("\n");
        printf("size: %d\n", length());
        printArray(array_data, length());
        printf("What you want to do?\n");
        printf("1: enqueue\n");
        printf("2: dequeue\n");
        printf("3: cek array kosong\n");
        printf("4: exit\n");
        printf("Masukkan pilihan: "); scanf("%d", &pilihan);

        if (pilihan == 1){
            printf("Masukkan angka yang ingin dimasukkan ke dalam antrian: ");
            scanf("%d", &elemen);
            enqueue(elemen);
        } else if (pilihan == 2) {
            dequeue();
        } else if (pilihan == 3) {
            printf("apakah array kosong? %s\n", isEmpty()? "YA":"TIDAK");
        } else if (pilihan == 4) {
            break;
        } else {
            printf("masukkan angka opsi antara 1, 2, 3, atau 4\n");
        }
    }

}