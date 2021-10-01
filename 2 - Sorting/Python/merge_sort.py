import os

# Python program for implementation of MergeSort
def mergeSort(arr):
	if len(arr) > 1:
		# Finding the mid of the array
		mid = len(arr)//2

		# Dividing the array elements
		L = arr[:mid]

		# into 2 halves
		R = arr[mid:]

		# Sorting the first half
		mergeSort(L)

		# Sorting the second half
		mergeSort(R)

		i = j = k = 0

		# Copy data to temp arrays L[] and R[]
		while i < len(L) and j < len(R):
			if L[i] < R[j]:
				arr[k] = L[i]
				i += 1
			else:
				arr[k] = R[j]
				j += 1
			k += 1

		# Checking if any element was left
		while i < len(L):
			arr[k] = L[i]
			i += 1
			k += 1

		while j < len(R):
			arr[k] = R[j]
			j += 1
			k += 1

# Code to print the list
def printList(arr):
	for i in range(len(arr)):
		print(arr[i], end=" ") # syntax python 3.x
	print()

# Driver Code
if __name__ == '__main__':
    # arr = [12, 11, 13, 5, 6, 7]
    
    # INPUT_FILENAME = raw_input("Masukkan nama file yang akan isi datanya akan di-sort (tanpa .txt): ") # python 3.x
    INPUT_FILENAME = input("Masukkan nama file yang akan isi datanya akan di-sort (tanpa .txt): ") # python 3.x
    INPUT_FILENAME += '.txt'
    with open(INPUT_FILENAME, "r") as f:
        row_data = f.read()
        arr = row_data.split(',')
        for i in range(len(arr)):
            try:
                arr[i] = int(arr[i])
            except:
                print("Ada data yang tidak sesuai format")
                print('arr[{0}] = {i}'.format(i, arr[i]))

    print("Given array is", end="\n")
    printList(arr)
    mergeSort(arr)
    print("Sorted array is: ", end="\n")
    printList(arr)

    # WRITE DATA KE FILE BARU
    # FILENAME = raw_input("Masukkan nama file yang akan menampung data yang telah di sort (tanpa .txt): ") # python 2.x
    FILENAME = input("Masukkan nama file yang akan menampung data yang telah di-sort (tanpa .txt): ") # python 3.x
    FILENAME += '.txt'
    data_for_txt = ''
    for i in range(len(arr)):
        data_for_txt += "{0},".format(arr[i])

    PATH = os.getcwd()
    with open(os.path.join(PATH, FILENAME), "w") as f:
        f.write(data_for_txt)

# Most of the code is contributed by Mayank Khanna