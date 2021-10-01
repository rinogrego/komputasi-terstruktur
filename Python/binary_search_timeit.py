import timeit

waktu = timeit.timeit(stmt = """
def binary_search(arr, left, right, x):
    if right >= left:
        mid = left + (right - left) / 2
        if arr[mid] == x:
            return mid
        if arr[mid] >= x:
            return binary_search(arr, left, mid-1, x)
        return binary_search(arr, mid+1, right, x)
    return -1

arr = [4, 12, 23, 56, 71, 124, 342, 531, 766, 863, 1002, 1853, 1900, 2051, 3690, 4005]
n = len(arr)

x = 863
result = binary_search(arr, 0, n-1, x)
""", number=1000)
print(waktu)