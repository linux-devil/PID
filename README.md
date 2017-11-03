## PID project term2 SDC-ND

# COMPILATION

Project successfully compiles

# Dependencies

cmake >= 3.5
make >= 4.1
gcc/g++ >= 5.4
uWebSockets
Udacity Simulator


# Steps

cmake ..
make
./pid

# IMPLEMENTATION

PID has following components:

# P(Proportional)
CTE(Cross Track Error) is calculated which tells the deviation of car from middle line of the road. This parameter helps car to steer in proportion to CTE. For e.g.: if the car is on the left of the line one would like to steer to right. Higher  the deviation from the track, higher is the steering.

# I(Integral)
Integral signifies total error, i.e integral sum of all CTEs . Too many positive CTEs will sum up to signify that car has been on the right of the lane for the while.

# D (Derivative)
Signifies rate of change of CTE from one value to next. 

# Reflection

# 1.Proporțional
Setting higher value of P makes car oscillate , this is because car overcorrects / overshoots to the middle. 
Setting P too low will make car take longer to react and thus car goes off the centre.

# 2. Integral
Lower value of the coefficient will lead car to drift on either side for longer periods
Higher value will lead to quick oscillations and the car overshoots.

# 3. Derivative
Higher value leads to too much oscillation
Lower value it fails to recover from the effect of P.

These reflections are similar to expectations.

Tuning of PID

The parameters were tuned manually.

# Approach:

1. Keep P and I constant , and tried different values of D

2. After getting reasonable value of D ( whenever oscillations were low) , tried different values of P using selected value of D from step 1 and I as constant

3. Using P and D from steps above tuned different values of I

# Next Steps

Use algorithms such as twiddle and sgd to set values of PID.

