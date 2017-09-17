#include "PID.h"

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double gain_p, double gain_i, double gain_d) {
  Kp = gain_p;
  Ki = gain_i;
  Kd = gain_d;

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

}

void PID::UpdateError(double cte) {
  p_error = cte;
  i_error += cte;
  d_error = cte - prev_error;

  prev_error = p_error;
}

double PID::TotalError() {
  return -(Kp * p_error) - (Ki * i_error) - (Kd * d_error);
}

