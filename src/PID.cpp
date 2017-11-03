#include "PID.h"

//using namespace std;
#include <algorithm>

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

    PID::Kp = Kp;
    PID::Kd = Kd;
    PID::Ki = Ki;

    //Errors
    p_error = 0;
    i_error = 0;
    d_error = 0;

    prev_cte = 0.0;

    //counters
    ctr = 0;
    err_sum =0.0;
    minError = std::numeric_limits<double>::max();
    maxError = std::numeric_limits<double>::min();

}

void PID::UpdateError(double cte) {

  // Proptional error
  p_error = cte;

  // Integeral error
  i_error += cte;

  //Differetial error
  d_error = cte - prev_cte;
  prev_cte = cte;

  err_sum += cte;
  ctr++;

  if(cte>maxError){
    maxError = cte;
  }
  if(cte <minError){
    minError = cte;
  }
}

double PID::TotalError() {
  return p_error*Kp + (i_error*Ki) + (d_error*Kd);
}

double PID::AverageError() {
  return err_sum/ctr;
}

double PID::MaxError() {
  return maxError;
}

double PID::MinError() {
  return minError;
}
