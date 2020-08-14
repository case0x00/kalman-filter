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

    double dt = 1.0;
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
      17.3837871316, 11.8471040016, 11.8461955419, 11.0395731746, 17.2825901034,
      17.4216489744, 21.1672039768, 21.4529225112, 21.6029641405, 22.1269371128,
      23.8103718341, 21.9371847141, 23.8910173133, 24.1931941312, 25.1949135133,
      28.8371476541, 29.382474427, 28.2824626221, 30.007301145, 31.2940532469,
      48.4319389135, 45.3108471304, 42.8445314961, 44.6543115790, 45.1611689931,
      23.1989481935, 28.3783473354, 26.1435642622, 21.3513951353, 23.5256432362,
      23.0289276741, 20.2064173178, 19.4393197929, 18.4937531199, 15.2523414133,
      18.6127801341, 11.8084681356, 11.1577924641, 9.2524663782, 8.1934515246,
      5.93096451597, 3.5465362465, -1.5566315135, -3.81147960012, -7.04913577886
  };

    // initial states guess
    Eigen::VectorXd x0(n);
    x0 << measurements[0], 0, -9.81;
    kf.init(x0);

    double t = 0;
    Eigen::VectorXd z(m), u(l);

    // time, z_k measurement value, 

    for(int i=0; i<measurements.size(); i++) {
        t += dt;
        z << measurements[i];
        u << 0;
        kf.predict(u);
        kf.update(z);
        // time, z_k measurement, x_hat state estimate
        std::cout << t << "," << z.transpose() << "," << kf.state().transpose()[0] << std::endl;
    }
    return 0;
}
