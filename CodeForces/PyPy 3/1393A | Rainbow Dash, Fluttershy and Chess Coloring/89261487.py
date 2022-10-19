def solve(n):
    
    
    if n >= 2:
        if n%2 == 0:
            return 2 + ((n-2)//2)  
        elif n%2 == 1:
            
            return 2 + ((n-3)//2) 
    else:
        return 1
        
 
 
 
def solveRec(n):
    if n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return 1 + solveRec(n-2)
    
 
 
tests = int(input())
for case in range(tests):
    n = int(input())
    print(solve(n))