import sys
import numpy as np
import matplotlib.pyplot as plt

if __name__ == "__main__":

    stdin_arr = []
    time = []
    zk = []
    xhat = []

    for line in sys.stdin:

        # split the input by ,
        stdin_arr = line.split(",")
        
        # idx 0 is time
        time.append(int(stdin_arr[0]))

        # idx 1 is z_k measurement
        zk.append(int(float(stdin_arr[1])))

        # idx 2 is x_hat state estimate
        xhat.append(int(float(stdin_arr[2].strip("\n"))))

    plt.plot(time, zk)
    plt.plot(time, xhat)
    plt.locator_params(axis="x", nbins=10)
#    plt.locator_params(axis="y", nbins=10)
    plt.xlabel("time (s)")
    plt.ylabel("position")
    plt.title("Kalman filter state estimate")
    plt.legend(["state measurement","state estimate"])
    plt.savefig("plots/kalman.png")
