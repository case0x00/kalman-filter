# Kalman Filter

Basic kalman filter implemented in C++. Kalman filters consist of two parts: predicting and updating. In the prediction step, the system model is used to calculate the a priori state estimate and the error covariance. The update step uses these a priori estimates and updates them to find the posterior estimates of the state and the error covariance. the kalman gain is calculated such that it minimizes the posterior error covariance. These posterior values are fed into the prediction phase and the cycle is repeated. 

It works like so.

<p align="center"><img src="https://raw.githubusercontent.com/onlycase/kalman-filter/master/assets/diagram.png"/></p>

## dependencies

Eigen

## to run

to purely build

```
./run.sh --build
```

to purely run

```
./run.sh --run
```

and to do both

```
./run.sh
```

with expected output
```
Running kalman filter
Initial state estimate with z_k being measurement at k and x_hat being state estimate.
t = 0, x_hat_0 = 1.73838
t = 0.05, z_0 = 1.73838, x_hat_0 = 1.73838
t = 0.1, z_1 = 1.18471, x_hat_1 = 1.30619
t = 0.15, z_2 = 1.18462, x_hat_2 = 1.13676
t = 0.2, z_3 = 1.10396, x_hat_3 = 1.00316
t = 0.25, z_4 = 1.72826, x_hat_4 = 1.20547
t = 0.3, z_5 = 1.74216, x_hat_5 = 1.31744
t = 0.35, z_6 = 2.11672, x_hat_6 = 1.51138
t = 0.4, z_7 = 2.14529, x_hat_7 = 1.63911
t = 0.45, z_8 = 2.1603, x_hat_8 = 1.72151
t = 0.5, z_9 = 2.21269, x_hat_9 = 1.7853
t = 0.55, z_10 = 2.38104, x_hat_10 = 1.8695
t = 0.6, z_11 = 2.19372, x_hat_11 = 1.87699
t = 0.65, z_12 = 2.3891, x_hat_12 = 1.92652
t = 0.7, z_13 = 2.41932, x_hat_13 = 1.97025
t = 0.75, z_14 = 2.51949, x_hat_14 = 2.02961
t = 0.8, z_15 = 2.88371, x_hat_15 = 2.17229
t = 0.85, z_16 = 2.93825, x_hat_16 = 2.30741
t = 0.9, z_17 = 2.82825, x_hat_17 = 2.39316
t = 0.95, z_18 = 3.00073, x_hat_18 = 2.51022
t = 1, z_19 = 3.12941, x_hat_19 = 2.64194
t = 1.05, z_20 = 4.84319, x_hat_20 = 3.20345
t = 1.1, z_21 = 4.53108, x_hat_21 = 3.58995
t = 1.15, z_22 = 4.28445, x_hat_22 = 3.84192
t = 1.2, z_23 = 4.46543, x_hat_23 = 4.09067
t = 1.25, z_24 = 4.51612, x_hat_24 = 4.30151
t = 1.3, z_25 = 2.31989, x_hat_25 = 3.90497
t = 1.35, z_26 = 2.83783, x_hat_26 = 3.69627
t = 1.4, z_27 = 2.61436, x_hat_27 = 3.46009
t = 1.45, z_28 = 2.13514, x_hat_28 = 3.14045
t = 1.5, z_29 = 2.35256, x_hat_29 = 2.92333
t = 1.55, z_30 = 2.30289, x_hat_30 = 2.72848
t = 1.6, z_31 = 2.02064, x_hat_31 = 2.49842
t = 1.65, z_32 = 1.94393, x_hat_32 = 2.28806
t = 1.7, z_33 = 1.84938, x_hat_33 = 2.09092
t = 1.75, z_34 = 1.52523, x_hat_34 = 1.85388
t = 1.8, z_35 = 1.86128, x_hat_35 = 1.73086
t = 1.85, z_36 = 1.18085, x_hat_36 = 1.48124
t = 1.9, z_37 = 1.11578, x_hat_37 = 1.25904
t = 1.95, z_38 = 0.925247, x_hat_38 = 1.0338
t = 2, z_39 = 0.819345, x_hat_39 = 0.824309
t = 2.05, z_40 = 0.593096, x_hat_40 = 0.603677
t = 2.1, z_41 = 0.354654, x_hat_41 = 0.371622
t = 2.15, z_42 = -0.155663, x_hat_42 = 0.0755749
t = 2.2, z_43 = -0.381148, x_hat_43 = -0.217418
t = 2.25, z_44 = -0.704914, x_hat_44 = -0.526583
```


## good resources
* https://courses.cs.washington.edu/courses/cse571/03wi/notes/welch-bishop-tutorial.pdf

## todo
* better worked example with actual data
* EKF, UKF
* dont assume A or H to be constant (dynamically update)
