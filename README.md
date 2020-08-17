# Kalman Filter

Kalman filter implemented in C++. Groundtruth was set to a sinusoidal waveform and the state measurements was this waveform with added gaussian noise with a mean of 0 and standard deviation of 0.5 (generated in `tests/gen.py`). Results were written to stdout and piped to a python script which plotted the data using matplotlib. 

## theory

Kalman filters consist of two parts: predicting and updating. In the prediction step, the system model is used to calculate the a priori state estimate and the error covariance. The update step uses these a priori estimates and updates them to find the posterior estimates of the state and the error covariance. the kalman gain is calculated such that it minimizes the posterior error covariance. These posterior values are fed into the prediction phase and the cycle is repeated. 

<p align="center"><img src="https://raw.githubusercontent.com/onlycase/kalman-filter/master/assets/diagram.png"/></p>


## method and results

The duration the filter was tested over was arbitrary, as was the characteristics of the waveform. Duration and the number of cycles over the duration are set by environment variables `DUR` and `NUMCYC` by exporting them, for example

```
export DUR=400`
export NUMCYC=4 
```

The sinusoidal wave was generated according to the equation below, in `tests/gen.py`. 

```python
y = lambda x : 2 * np.sin(2 * np.sin * NUMCYC * x / DUR) + 4
```

Example results are shown below, with more in the `plots/` directory. Both bound and unbounded are produced for each run. It doesn't perfectly estimate the state as evident of the deviation from the ground truth (measure RMSE?) but it does a solid job at ignoring the outliers. Some of the other examples are a little iffy, so its not a perfect filter but its okay.

<p align="center"><img src="https://raw.githubusercontent.com/onlycase/kalman-filter/master/plots/kalman.png"/></p>


Including a bounding box for +/- 0.5 (noise stddev), the state estimate mostly lies within this range which means the estimate still fluctuate according to the noise but it mostly ignores the outliers outside of the bounds which is good as they serve as statistical anomalies. I would like to get the state estimate to hug the ground truth more though. I would also be curious what would happen if I added more outliers.

<p align="center"><img src="https://raw.githubusercontent.com/onlycase/kalman-filter/master/plots/kalman-bounds.png"/></p>

## dependencies

* Eigen
* matplotlib
* numpy


## to run

Everything is handed through the `run.sh` script. The `-t` flag is the run type and the `-n` flag is the name to save the images as. To generate the groundtruth and measurement text files after setting the environment variables, run

```bash
./run.sh -t gen
```

To build

```bash
./run.sh -t build
```

To run and plot with an example name, which I like to set with DUR-NUMCYC like 400s duration with 1 cycle shown below.

```bash
./run.sh -t run -n 400-1
```

And to both build and run which I tend to avoid since its better to solely build and check for errors.

```bash
./run-sh -t all -n 400-1
```

## good resources
* https://courses.cs.washington.edu/courses/cse571/03wi/notes/welch-bishop-tutorial.pdf

## todo
* error handling for some robustness
* implement RMSE
* EKF, UKF
* dont assume A or H to be constant (dynamically update)
