import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


def dataReading():

    file = ("C:/projekti/viikko5/file.csv")
    data = pd.read_csv(file,delimiter=";")
    
    return data

def dataProcessing(data):

    global randomMax 
    global randomMin

    numberOfRows = len(data)
    numberOfRows = int(numberOfRows)

    dataMatrix = np.zeros((numberOfRows,3))
    dataMatrix[:,0] = data.values[0::,5]
    dataMatrix[:,1] = data.values[0::,6]
    dataMatrix[:,2] = data.values[0::,7]

    position = data.values[0::,9]

    randomMax = np.max(data.values[0::,5:7])
    randomMin = np.min(data.values[0::,5:7])

    return dataMatrix,numberOfRows, position

def randomData():

    random = np.random.randint(randomMin,randomMax,size=(6,3))

    return random

def kMeans(dataMatrix,random,numberOfRows,position):
    values = np.zeros(6)
    counts = np.zeros(6)
    flag = np.zeros(6)
    averageDistance = np.zeros((6,3))
    centerPointCumulativeSum = np.zeros((6,3))
    for i in range(numberOfRows):
        for j in range(6):
            value1 = np.abs(np.sqrt(np.power((random[j,0]-dataMatrix[i,0]),2) + np.power((random[j,1]-dataMatrix[i,1]),2) + np.power((random[j,2]-dataMatrix[i,2]),2)))
            values[j] = value1
        
        index = np.argmin(values)
        counts[index] += 1
        centerPointCumulativeSum[index,0:3] += dataMatrix[i,0:3]
        flag[index] = position[i]
        print("flag",flag)
        
    pienin_counts = np.min(counts)
    y = 0

    if pienin_counts == 0:
        random = randomData()
        kMeans(dataMatrix,random,numberOfRows,position)
    elif pienin_counts != 0:
        for y in range(6):
            averageDistance[y] = (centerPointCumulativeSum[y] / counts[y])

        plotter(averageDistance,dataMatrix,numberOfRows)
        iter = iteration(averageDistance,dataMatrix,numberOfRows)
        
        
        while True:
            iter2 = iter
            iter = iteration(averageDistance,dataMatrix,numberOfRows)
            print("Iteroitu tulos: ", iter)
            if (iter2 == iter).all():
                break

        plotter(averageDistance,dataMatrix,numberOfRows)
        exporting(averageDistance,flag)

def iteration(averageDistance,dataMatrix,numberOfRows):
    averageDistance = averageDistance
    dataMatrix = dataMatrix
    numberOfRows = numberOfRows
    values = np.zeros(6)
    counts = np.zeros(6)
    centerPointCumulativeSum = np.zeros((6,3))
    for i in range(numberOfRows):
        for j in range(6):
            value1 = np.abs(np.sqrt(np.power((averageDistance[j,0]-dataMatrix[i,0]),2) + np.power((averageDistance[j,1]-dataMatrix[i,1]),2) + np.power((averageDistance[j,2]-dataMatrix[i,2]),2)))
            values[j] = value1
        
        index = np.argmin(values)
        counts[index] += 1
        centerPointCumulativeSum[index,0:3] += dataMatrix[i,0:3]
   
    y = 0  
    for y in range(6):
        averageDistance[y] = (centerPointCumulativeSum[y] / counts[y])
        f= open("keskipisteet.h","w+")
        f.write(str(averageDistance % (i+1)))

    return counts

def plotter(averageDistance,dataMatrix,numberOfRows):
    
    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')
    x = 0
    i = 0
    for x in range(numberOfRows):
        ax.scatter(dataMatrix[x,0],dataMatrix[x,1], dataMatrix[x,2], color="blue")
    for i in range(6):
        ax.scatter(averageDistance[i,0],averageDistance[i,1], averageDistance[i,2], marker="*",s=200)

    ax.set_xlabel('X Label')
    ax.set_ylabel('Y Label')
    ax.set_zlabel('Z Label')
    
    plt.show()
    

def exporting(averageDistance,flag):

    print(averageDistance)

    with open('keskipisteet.h', 'w') as f:
        line = "float w[6][6] = {"
        for i in range(5):
            line = line + "{"
            outputThis = np.array2string(averageDistance[i,:],precision=3,separator=',')
            line = line + outputThis[1:len(outputThis)-1]
            line = line + ","+str(int(flag[i]))
            line = line + "},"
        outputThis = np.array2string(averageDistance[5,:],precision=3,separator=',')
        line = line + "{"
        line = line + outputThis[1:len(outputThis)-1]
        line = line + ","+str(int(flag[5]))
        line = line + "}"
        line = line + "};"
        f.write(line)
        f.write('\n')

    f.close()


if __name__ == "__main__":
    data = dataReading()
    dataMatrix, numberOfRows, position = dataProcessing(data)
    random = randomData()
    kMeans(dataMatrix,random,numberOfRows,position)
