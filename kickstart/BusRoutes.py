## BusRoutes.py
## https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83bf

def canComplete(startDay, endDay, busArr, hashMap):
    # print("Start day %d" %(startDay))
    # print(hashMap)
    nBuses = len(busArr)

    if not(startDay in hashMap.get(busArr[0])):
        # print("Cant start")
        return False
    # busArr = busArr[1:]
    busIndex = 1
    if busIndex == nBuses:
        return True
    for bus in busArr[busIndex:]:
        runnableDays = hashMap.get(bus)
        flag = 0
        for someday in runnableDays:
            if someday >=startDay:
                startDay = someday
                flag = 1
                busIndex +=1
                break
        if flag == 0 :
            return False
    if busIndex == nBuses:
        return True
    return False
         
    '''    
        for i in range(startDay, endDay+1):
            if i % busArr[busIndex] == 0:
                busIndex+=1
                for bus in busArr[busIndex:]:
                    if i%bus==0:
                        busIndex+=1
                    else:
                        break
            if busIndex == nBuses:
                break
        if busIndex == nBuses:
            return True
        return False
    '''
def MultiplesUnderX(MultArray,X):
    return [i for i in range(X+1) if any(i % x == 0 for x in MultArray)]
        
        
for case_n in range(0, int(input())):
    n, day = list(map(int, input().split()))
    busArr = list(map(int, input().split()))
    startDay = -1
    hashMap = {}
    for bus in busArr:
        hashMap[bus] = MultiplesUnderX([bus], day)[1:]
    for nDay in range(day, 0, -1):
        if canComplete(nDay, day, busArr, hashMap):

            startDay = nDay
            break    
    print("Case #%d: %d" %(case_n+1, startDay))


