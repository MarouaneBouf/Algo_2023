# TRI PAR SELECTION - IMPLEMENTATION RECURSIVE
def minIndex( a , i , j ):
    if i == j:
        return i
    k = minIndex(a, i + 1, j)
    return i if a[i] < a[k] else k
     

def sort_rec(a,taille, index = 0):
    if index ==taille:
        return -1
    k = minIndex(a, index,taille-1)
    if k != index:
        a[k], a[index] = a[index], a[k]
    sort_rec(a,taille, index + 1)
  
def main():   
    arr = [3, 1, 5, 2, 7, 0]
    
    sort_rec(arr,len(arr))
    for i in arr:
        print(i)
        
        
if __name__ == "__main__":
    main()
    
    
