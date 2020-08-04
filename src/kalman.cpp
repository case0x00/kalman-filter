#include <iostream>
#include <stdexcept>

#include "kalman.hpp"

/*
 * X = A x_{k-1} + B u_{k-1}
 * p = APA^T + Q
 *
 * K = p H^T (HpH^T + R)^{-1}
 * x_k = X + K(z-HX)
 * P x_k = (I-KH)p
 *
 * X state variable
 * u action
 * P covariance matrix of confidence
 * Q covariance matrix of noise
 * K update matrix 
 * H sensor matrix
 * R confidence
 * z measurements
 * I identity
 * A model
 * B model
 *
 *
 *
 */

KalmanFilter::KalmanFilter(
        const Eigen::MatrixXd& A, // relates state at k-1 to k
        const Eigen::MatrixXd& B, // relates optimal control input to x
        const Eigen::MatrixXd& H, // relates state to measurement z_k
        const Eigen::MatrixXd& Q, // process noise covariance
        const Eigen::MatrixXd& P,
        const Eigen::MatrixXd& R) // measurement noise covariance
    : A(A), B(B), H(H), Q(Q), P0(P), R(R),
    m(H.rows()), n(A.rows()), l(B.cols()), initialized(false),
    I(n,n), x_hat(n)
{
    I.setIdentity();
}

void KalmanFilter::init(const Eigen::VectorXd& x0) {
    x_hat = x0;
    P = P0;
    initialized = true;
}


void KalmanFilter::predict(const Eigen::VectorXd& u) {

    if (!initialized) {
        std::cout << "Not initialized. Initializing at origin." << std::endl;
        init();
    }

    // project state ahead
    x_hat = A * x_hat + B * u;
    // project error covarianceahead
    P = A * P * A.transpose() + Q;

}

void KalmanFilter::update(const Eigen::VectorXd& z_k) {

    // compute kalman gain K
    K = P * H.transpose() * (H*P*H.transpose() + R).inverse();
    // measure process and generate an a posteriori state
    x_hat = x_hat + K*(z_k - H * x_hat);
    // obtain an a posteriori error covariance
    P = (I - K * H) * P;

}
