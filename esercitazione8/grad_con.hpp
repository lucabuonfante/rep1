#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
double condA(const Eigen::MatrixXd& A)
{
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
  Eigen::VectorXd singularValuesA = svd.singularValues();
  return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int grad_con(const double tol, Eigen::MatrixXd& A, const unsigned int it_max, Eigen::VectorXd& x){
        
    if (abs(A.determinant()) < tol){
        return -1;
    }
    unsigned int n = A.rows();
    Eigen::VectorXd x_ex= Eigen::VectorXd::Ones(n);
    Eigen::VectorXd b = A * x_ex;

    
    Eigen::VectorXd res = b - A * x;
    double res_norm_0 = res.norm();
    
    
    unsigned int it = 0;
    const double res_tol = 1.0e-12;
    
    std::cout.precision(2);
    std::cout<< std::scientific<< "Matrix Cond: "<< condA(A)<< std::endl;

    double a=0;
    double beta=0;
    Eigen::VectorXd p= res;
    
    while (it < it_max && res.norm() > res_tol * res_norm_0){
        a=p.dot(res)/(p.dot(A*p));
        x=x+a*p;
        res=b-A*x;
        beta=p.dot(A*res)/(p.dot(A*p));
        p=res-beta*p;
        it=it+1;

    }

    double err_rel=(x-x_ex).norm()/x_ex.norm();

    std::cout.precision(4);
    std::cout<< std::scientific<< "it"<< "/"<< "it_max: "<< std::endl;
    std::cout<< std::scientific<< it<< "/"<< it_max<< std::endl;
    std::cout<< std::scientific<< "\n res"<< "/"<< "res_tol: "<< std::endl;
    std::cout<< std::scientific<< res.norm() / res_norm_0 << "/"<< res_tol<< std::endl;
    std::cout<< std::scientific<< "err_rel: "<< std::endl;
    std::cout<< std::scientific<< err_rel<< std::endl;
    std::cout<< std::scientific<< "soluzione"<< std::endl;
    std::cout<< std::scientific<< x << std::endl;


  return 0;

}