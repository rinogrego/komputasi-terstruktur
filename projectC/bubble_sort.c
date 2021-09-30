// C program for implementation of Bubble sort
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
int i, j;
for (i = 0; i < n-1; i++)	

	// Last i elements are already in place
	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int *read_input(char FILENAME[], int *ARRAY_LENGTH){
	FILE *file;
    static int array[30][30];
    char row_data[300];

    // MENARUH DATA INPUT KE DALAM ARRAY
    file = fopen(FILENAME, "r");
    fgets(row_data, 200, file);
    char *TOKEN = strtok(row_data, ",");
    int i = 0;
    while (TOKEN != NULL) {
        array[1][i] = atoi(TOKEN);
        // printf("%d ", array[1][i]);
        TOKEN = strtok(NULL, ",");
        i++;
    }
	// SETTING LENGTH DARI ARRAY / ARRAY SIZE
	*ARRAY_LENGTH = i;
    fclose(file);
    // printf("\n");

	return array[1];
}

void write_to_txt(int arr[], int arr_len){
	FILE *newfile;
	char namafile[54];
	char word[20];
	
	printf("\nMasukkan nama file yang ingin disave: ");
    scanf("%s", namafile);
	strcat(namafile, ".txt");
	newfile = fopen(namafile, "w");
	for (int i = 0; i < arr_len; i++){
		sprintf(word, "%d", arr[i]);
		strcat(word, ",");
		fprintf(newfile, word);
	}
	fclose(newfile);
}

// Driver program to test above functions
void main()
{
	char FILENAME[54];
	int *arr;
	int arr_len; // Nanti diubah via memory address

    printf("Masukkan nama file yang ingin memiliki data untuk di-sort: ");
    scanf("%s", FILENAME);

	arr = read_input(FILENAME, &arr_len);
	printf("Length of the Array: %d\n\n", arr_len);

    printf("Given array is \n");
	printArray(arr, arr_len);

	bubbleSort(arr, arr_len);

	printf("\nSorted array is \n");
	printArray(arr, arr_len);

    write_to_txt(arr, arr_len);
}
