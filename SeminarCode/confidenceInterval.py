#!/usr/bin/python3

def getAverage(inputFile, lineCount):
    sum = 0
    for line in inputFile:
        sum += int(line)
    return sum / lineCount

def stdDeviation(average, inputFile, lineCount):
    sumSqrError = 0
    stdDev = 0
    for line in inputFile:
        sumSqrError += (average - int(line))**2
    return (sumSqrError / lineCount)**(1/2)

def confidenceInterval(average, lineCount, stdDev):
    criticalValue = 1.96
    interval = criticalValue*stdDev/(lineCount)**(1/2)

    return  average+interval, average-interval


def main():
    print("Enter the file: ")
    filename = input()
    inputFile = open(filename)
    lineCount = sum(1 for line in inputFile)
    inputFile.seek(0) 
    print("there are: "+str(lineCount)+" lines")
    if lineCount <= 0:
        print("Not a valid file")
    else:
        average = getAverage(inputFile, lineCount)
        inputFile.seek(0)
        print("The Average is: " +str(average))
        stdDev = stdDeviation(average, inputFile, lineCount)
        inputFile.seek(0)
        print("The standart deviation is: ", stdDev)
        upperBound, lowerBound = confidenceInterval(average, lineCount, stdDev)
        print("Upper and lower Bounds are: "+str(upperBound)+" and "+str(lowerBound))

if __name__ == "__main__":main()

