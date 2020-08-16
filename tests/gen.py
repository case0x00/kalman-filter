import math
import matplotlib.pyplot as plt
import numpy as np
import sys

if __name__ == "__main__":

    DUR = 200 
    NUMCYC=2

    measurement = []
    groundtruth = []

    t = np.arange(DUR)

    y = lambda x : 2*np.sin(2*np.pi*NUMCYC*x/DUR)+4

    noise = np.random.normal(0,0.5,DUR)

    for i in range(DUR):
        measurement.append(y(i+1))
        groundtruth.append(y(i+1))

    measurement+=noise

    # it would be better to not save to lists initally, but I do so I have the option to plot them to check the data
    if sys.argv[1] == "--gt":
        for j in range(len(groundtruth)):
            print(groundtruth[j])

    if sys.argv[1] == "--meas":
        for j in range(len(measurement)):
            print(measurement[j])
        

#    plt.scatter(t, measurement, marker="x")
#    plt.plot(t, groundtruth, "r")
#    plt.show()
