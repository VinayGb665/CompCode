for case_n in range(0, int(input())):
    n = int(input())
    inpArr = list(map(int, input().split()))
    prev = inpArr[0]
    count = 0
    # print(inpArr)
    for i in range(1, n-1):
        if inpArr[i] > prev and  inpArr[i] > inpArr[i+1]:
            count+=1
        prev = inpArr[i]
    print("Case #%d: %d" %(case_n+1, count))