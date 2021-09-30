/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2]; /* create temp arrays */

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
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


/* Driver code */
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

	mergeSort(arr, 0, arr_len - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_len);

	write_to_txt(arr, arr_len);
}