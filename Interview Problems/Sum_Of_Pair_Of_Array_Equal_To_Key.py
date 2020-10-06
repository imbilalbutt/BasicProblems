#
# Author: Bilal Ahmad Butt
# GitHub: http://github.com/imbilalbutt 
#

def Pair_Sum_Equal_To_Key(A, key):
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
    for i in range(0, len(A)):
        diff = abs(A[i] - key)
        
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
    A = [5, 4, 6, 4, 7, 8, 3, 5, 7]
    key = 8
    Pair_Sum_Equal_To_Key(A, key)
