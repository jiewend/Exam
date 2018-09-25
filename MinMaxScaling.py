import numpy as np

def MinMaxScaling(input):
    minVal = np.min(input)
    maxVal = np.max(input)
    input = (input - minVal) / float(maxVal - minVal)
    return input

if __name__ == '__main__':
    input = np.array([1,2, 3, 8])
    print input
    print MinMaxScaling(input)


    
