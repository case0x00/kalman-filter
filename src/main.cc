#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <math.h>
#include <sstream>
#include <fstream>

#include "kalman.h"

//#define DURATION    200

int main(int argc, char* argv[]) {
    // grab measurement and groundtruth from files
    std::string meas_filename(argv[1]);
    std::string gt_filename(argv[2]);

    std::ifstream meas_file(meas_filename.c_str());
    std::ifstream gt_file(gt_filename.c_str());

    std::string line;

    std::vector<double> measurements;
    std::vector<double> groundtruth;

    // read measurement file
    while(std::getline(meas_file, line)) {

        std::stringstream iss(line);
        float val;
        iss >> val;
        measurements.push_back(val);
    }

    // read groundtruth file
    while(std::getline(gt_file, line)) {

        std::stringstream iss(line);
        float val;
        iss >> val;
        groundtruth.push_back(val);
    }

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

    KalmanFilter kf(A, B, H, Q, P, R);

    // initial states guess
    Eigen::VectorXd x0(n);
    x0 << measurements[0], 0, -9.81;
    kf.init(x0);

    double t = 0;
    Eigen::VectorXd z(m), u(l), g(m);

    // time, z_k measurement value, 

    for(int i=0; i<measurements.size(); ++i) {
        t += dt;
        z << measurements[i];
        u << 0;
        g << groundtruth[i];
        kf.predict(u);
        kf.update(z);
        // time, z_k measurement, x_hat state estimate
        std::cout << t << "," << z.transpose() << "," << kf.state().transpose()[0] << "," << groundtruth[i] << std::endl;
    }
    return 0;
}
