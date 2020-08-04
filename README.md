# Kalman Filter

Basic kalman filter implemented in C++. Kalman filters consist of two parts: predicting and updating. In the prediction step, the system model is used to calculate the a priori state estimate and the error covariance. The update step uses these a priori estimates and updates them to find the posterior estimates of the state and the error covariance. the kalman gain is calculated such that it minimizes the posterior error covariance. These posterior values are fed into the prediction phase and the cycle is repeated. 







## good resources
* https://courses.cs.washington.edu/courses/cse571/03wi/notes/welch-bishop-tutorial.pdf
