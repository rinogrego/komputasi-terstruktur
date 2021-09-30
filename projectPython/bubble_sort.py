import os

# Python program for implementation of Bubble Sort
def bubbleSort(arr):
	n = len(arr)

	# Traverse through all array elements
	for i in range(n):
		# Last i elements are already in place
		for j in range(0, n-i-1):
			# traverse the array from 0 to n-i-1
			# Swap if the element found is greater than the next element
			if arr[j] > arr[j+1] :
				arr[j], arr[j+1] = arr[j+1], arr[j]


INPUT_FILENAME = raw_input("Masukkan nama file yang akan isi datanya akan di-sort (tanpa .txt): ") # python 3.x
# INPUT_FILENAME = input("Masukkan nama file yang akan isi datanya akan di-sort (tanpa .txt): ") # python 3.x
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

print ("Input array is:")
for i in range(len(arr)):
	print ("%d" %arr[i]), # syntax python 2.x

bubbleSort(arr)

print ("\n\nSorted array is:")
for i in range(len(arr)):
	print("%d" %arr[i]), # syntax python 2.x
print('\n')


# WRITE DATA KE FILE BARU
FILENAME = raw_input("Masukkan nama file yang akan menampung data yang telah di sort (tanpa .txt): ") # python 2.x
# FILENAME = input("Masukkan nama file yang akan menampung data yang telah di sort (tanpa .txt): ") # python 3.x
FILENAME += '.txt'
data_for_txt = ''
for i in range(len(arr)):
    data_for_txt += "{0},".format(arr[i])

PATH = os.getcwd()
with open(os.path.join(PATH, FILENAME), "w") as f:
    f.write(data_for_txt)