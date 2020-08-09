#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "kalman.h"

int main(int argc, char* argv[]) {
    int n = 3; // states
    int m = 1; // measurements
    int l = 1; // control inputs

    Eigen::MatrixXd A(n,n); // k-1 state to k
    Eigen::MatrixXd B(n,l); // input to x
    Eigen::MatrixXd H(m,n); // state to z_k
    Eigen::MatrixXd Q(n,n); // process noise covariance
    Eigen::MatrixXd P(n,n); // a posteriori estimate error covariance
    Eigen::MatrixXd R(m,m); // measurement noise covariance

    double dt = 1.0/20;
    A << 1, dt, 0, 0, 1, dt, 0, 0, 1;
    B << 0, 0, 0;
    H << 1, 0, 0;

    Q << .05, .05, .0, .05, .05, .0, .0, .0, .0;
    P << .1, .1, .1, .1, 10000, 10, .1, 10, 100;
    R << 5;

/*    std::cout << "A: \n" << A << std::endl;
*    std::cout << "B: \n" << B << std::endl;
*    std::cout << "H: \n" << H << std::endl;
*    std::cout << "Q: \n" << Q << std::endl;
*    std::cout << "P: \n" << P << std::endl;
*    std::cout << "R: \n" << R << std::endl;
*/
    KalmanFilter kf(A, B, H, Q, P, R);

    // noise position measurements
    std::vector<double> measurements = {
      1.73837871316, 1.18471040016, 1.18461955419, 1.10395731746, 1.72825901034,
      1.74216489744, 2.11672039768, 2.14529225112, 2.16029641405, 2.21269371128,
      2.38103718341, 2.19371847141, 2.38910173133, 2.41931941312, 2.51949135133,
      2.88371476541, 2.9382474427, 2.82824626221, 3.0007301145, 3.12940532469,
      4.84319389135, 4.53108471304, 4.28445314961, 4.46543115790, 4.51611689931,
      2.31989481935, 2.83783473354, 2.61435642622, 2.13513951353, 2.35256432362,
      2.30289276741, 2.02064173178, 1.94393197929, 1.84937531199, 1.52523414133,
      1.86127801341, 1.18084681356, 1.11577924641, 0.92524663782, 0.81934515246,
      0.593096451597, 0.35465362465, -0.15566315135, -0.381147960012, -0.704913577886
  };

    // initial states guess
    Eigen::VectorXd x0(n);
    x0 << measurements[0], 0, -9.81;
    kf.init(x0);

    double t = 0;
    Eigen::VectorXd z(m), u(l);

    std::cout << "Running kalman filter" << std::endl;
    std::cout << "Initial state estimate with z_k being measurement at k and x_hat being state estimate." << std::endl;
    std::cout << "t = " << t << ", " << "x_hat_0 = " << kf.state().transpose()[0] << std::endl;

    for(int i=0; i<measurements.size(); i++) {
        t += dt;
        z << measurements[i];
        u << 0;
        kf.predict(u);
        kf.update(z);
        std::cout << "t = " << t << ", " << "z_" << i << " = " << z.transpose() << ", x_hat_" << i << " = " << kf.state().transpose()[0] << std::endl;
    }
    return 0;
}
