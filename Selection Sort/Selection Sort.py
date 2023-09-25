import sys

def selectionSort(a, n):
    countCmpOps = 0 #비교 연산자 실행 횟수
    countSwap = 0 # swap 함수 실행 횟수

    for i in range(n-1):
        jMin = i

        for j in range(i+1, n):
            if(a[j] < a[jMin]):
                jMin = j
                countCmpOps += 1
            if(jMin != 1):
                t = a[jMin]
                a[jMin] = a[j]
                a[j] = t
                countSwap += 1

    print(countCmpOps + " " + countSwap)



numTestCases = int(input())

for i in range(0, numTestCases):
    num = list(map(int, sys.stdin.readline().split()))
    a = [0 for k in range(num[0])]
    
    for j in range(0, num[0]):
       a[j] = num[j+1]
        
    selectionSort(a, num[0])