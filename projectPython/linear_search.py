def linear_search(arr, n, x):
    for i in range(0, n):
        if arr[i] == x:
            return i
    return -1

arr = [4, 12, 23, 56, 71, 124, 342, 531, 766, 863, 1002, 1853, 1900, 2051, 3690, 4005]
n = len(arr)

x = int(input("Masukkan angka yang ingin dicarai di list: "))
result = linear_search(arr, n, x)
if result == -1:
    print("Elemen yang ingin dicari tidak ada di dalam array")
else:
    print("Elemen {0} ada di index {1}".format(x, result))