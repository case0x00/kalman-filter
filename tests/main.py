import sys
import numpy as np
import matplotlib.pyplot as plt
import matplotlib
from textwrap import wrap

if __name__ == "__main__":

    # whether to plot the error bounds
    BOUNDS=False

    # duration of the test
    DUR = 200

    stdin_arr = []
    time = []
    zk = []
    xhat = []
    gtu = []
    gtl = []
    gt = []

    # for generating the upper and lower bounds
    yu = lambda x: 2*np.sin(2*np.pi*2*x/DUR)+4+0.5
    yl = lambda x: 2*np.sin(2*np.pi*2*x/DUR)+4-0.5

    for i in range(DUR):
        gtu.append(yu(i+1))
        gtl.append(yl(i+1))


    for line in sys.stdin:

        # split the input by ,
        stdin_arr = line.split(",")
        
        # idx 0 is time
        time.append(int(stdin_arr[0]))

        # idx 1 is z_k measurement
        zk.append(float(stdin_arr[1]))

        # idx 2 is x_hat state estimate
        xhat.append(float(stdin_arr[2]))

        # idx 3 is the ground truth value
        gt.append(float(stdin_arr[3].strip("\n")))


    plt.scatter(time, zk, color="g", marker="x")
    plt.plot(time, xhat, color="r")
    plt.plot(time, gt, color="b")
    plt.xlabel("time (s)")
    plt.ylabel("position")
    plt.title("Kalman Filter State Estimation of\n%s" % "\n".join(wrap("Sinusoidal Waveform with Gaussian Noise", width=60)))

    if BOUNDS:
        plt.plot(time, gtu, color="b", linestyle=":", markersize=8)
        plt.plot(time, gtl, color="b", linestyle=":",  markersize=8)
        plt.legend(["state estimate","ground truth", "upper bound (+0.5)", "lower bound (-0.5)", "state measurement"])
        plt.savefig("plots/kalman-bounds.png")
    else:
        plt.legend((["state estimate", "ground truth", "state measurement"]))
        plt.savefig("plots/kalman.png")

    # dont need to show() but whatever
    plt.show()
