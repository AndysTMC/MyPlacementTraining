def insertion(arr):
    n = len(arr)
    for i in range(1,n):
        key = arr[i]
        j = i-1
        while j>=0 and arr[j]>key:
            arr[j+1] = arr[j]
            j = j-1
        arr[j+1] = key
        
arr = [4, 7, 3, 7, 2, 9, 4, 74, 68, 2, 9, 0, 552]
insertion(arr)
print(arr)