def selectionSort(arr):
    n = len(arr)
    for i in range(n):
        min = i
        for j in range(i,n):
            if(arr[j]<arr[min]): min = j
        if i!=min: arr[i],arr[min] = arr[min],arr[i]

arr = [4,7,3,7,2,9,4,74,68,2,9,0,552]
selectionSort(arr)
print(arr)