# Kalman Filter

Kalman filter implemented in C++. Groundtruth was set to a sinusoidal waveform and the state measurements was this waveform with added gaussian noise with a mean of 0 and standard deviation of 0.5 (generated in `tests/gen.py`). Results were written to stdout and piped to a python script which plotted the data using matplotlib. 

## theory

Kalman filters consist of two parts: predicting and updating. In the prediction step, the system model is used to calculate the a priori state estimate and the error covariance. The update step uses these a priori estimates and updates them to find the posterior estimates of the state and the error covariance. the kalman gain is calculated such that it minimizes the posterior error covariance. These posterior values are fed into the prediction phase and the cycle is repeated. 

<p align="center"><img src="https://raw.githubusercontent.com/onlycase/kalman-filter/master/assets/diagram.png"/></p>

## method and results

The duration the filter was tested over was arbitrary, as was the characteristics of the waveform. Duration was determined in both `tests/gen.py` in `DUR` and in `src/main.cc` in `DURATION`. The sinusoidal wave was generated according to the following.

```python
y = lambda x : 2 * np.sin(2 * np.sin * NUMCYC * x / DUR) + 4
```

where `NUMCYC` is the number of full cycles (periods) present.

The results are as shown. To produce the two different plots, set `BOUNDS` in `tests/main.py` to either `True` or `False`. It doesn't perfectly estimate the state as evident of the deviation from the ground truth (measure RMSE?) but it does a solid job at ignoring the outliers.


<p align="center"><img src="https://raw.githubusercontent.com/onlycase/kalman-filter/master/plots/kalman.png"/></p>


Including a bounding box for +/- 0.5 (noise stddev), the state estimate mostly lies within this range which is expected, ignoring the outliers outside of the bounds. I would liek to get the state estimate to hug the ground truth more though.

<p align="center"><img src="https://raw.githubusercontent.com/onlycase/kalman-filter/master/plots/kalman-bounds.png"/></p>

## dependencies

* Eigen
* matplotlib
* numpy


## to run

to purely build

```bash
./run.sh --build
```

to purely run

```bash
./run.sh --run
```

and to both

```bash
./run.sh
```


## good resources
* https://courses.cs.washington.edu/courses/cse571/03wi/notes/welch-bishop-tutorial.pdf

## todo
* implement RMSE
* EKF, UKF
* dont assume A or H to be constant (dynamically update)
