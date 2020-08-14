# Kalman Filter

Basic kalman filter implemented in C++. Kalman filters consist of two parts: predicting and updating. In the prediction step, the system model is used to calculate the a priori state estimate and the error covariance. The update step uses these a priori estimates and updates them to find the posterior estimates of the state and the error covariance. the kalman gain is calculated such that it minimizes the posterior error covariance. These posterior values are fed into the prediction phase and the cycle is repeated. 


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


## results

Using the data supplied in the std::vector<double> measurements, the state measurement and the estimates were plotted over the duration.

<p align="center"><img src="https://raw.githubusercontent.com/onlycase/kalman-filter/master/plots/kalman.png"/></p>


## good resources
* https://courses.cs.washington.edu/courses/cse571/03wi/notes/welch-bishop-tutorial.pdf

## todo
* better worked example with actual data
* EKF, UKF
* dont assume A or H to be constant (dynamically update)
