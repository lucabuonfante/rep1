#include "grad_con.hpp"
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

int main(){
    const unsigned int n=3;
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
    Eigen::MatrixXd A=B.transpose()*B;
    const double tol=10e-5;
    const unsigned int it_max=10000;
    Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
    int s= grad_con(tol,A,it_max,x);
    std::cout << "0=successo, 1 =insuccesso: \n "<< s;
}