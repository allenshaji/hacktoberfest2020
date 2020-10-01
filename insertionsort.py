llist=[int(x) for x in input().split()]
def insertionsort(A):#this is an expensive algorithm as it takes O(n2) time complexity
    n=len(A)
    for i in range(n):
        hole=i
        key=A[i]
        while(hole>0 and A[hole-1]>key):#we are finding the position in a[0....i-1] to fit in the key value
            A[hole]=A[hole-1] #we move values greater than key to the right
            hole=hole-1
        A[hole]=key
    return A #returns the sorted array
print(insertionsort(llist))
