# Find all the pairs of Array such that A[i] - A[j] = 1 in O(n).

def pair_Difference_Equal_To_One(A):
    # write your code in Python 3.6
    if (len(A)==0 or len(A)==1):
        return False
    
    if(len(A)==2):
        if(A[0]-A[1]==1):
            return True
        else: return False
        
    dictionary = dict()
    lst = list()
    for i in range(0, len(A)):
        if A[i] not in dictionary:
            dictionary[A[i]] = 1
        else:
            val = dictionary[A[i]]
            val+=1
            dictionary[A[i]] = val
    target = 1        
    for i in range(0, len(A)):
        diff = A[i] - target
        
        if diff in dictionary:
            value = dictionary[diff]
            if value > 0:
                tup = (diff, A[i])
                lst.append(tup)
                value = dictionary[diff]
                value-=1
                dictionary[diff] = value
    print(lst)
    if(len(lst)==0):
        return False
    else:
        return True
    
if __name__ == "__main__":
    A = [4,10,8,5,9]
    solution(A)
