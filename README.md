# Blood-flow-sisko-rheology-Ansys-Fluent-UDF
This UDF defines a function that calculates the viscosity of blood at a given cell and thread in Fluent. The UDF uses the following parameters and variables:

•  sisko_viscosity: the name of the user-defined function that takes two arguments: c and t.

•  c: a variable that represents a cell in the cell loop.

•  t: a pointer to the thread structure of the fluid zone where the viscosity is calculated.

•  mu: a scalar that represents the viscosity of blood at the cell c. It has units of Pa.s.

•  mu_inf: a scalar that represents the viscosity of blood at infinite shear rate. It has units of Pa.s. It has a constant value of 0.0035 Pa.s.

•  k: a scalar that represents the consistency coefficient of blood. It has units of Pa.s^n. It has a constant value of 0.056 Pa.s^n.

•  n: a scalar that represents the power-law index of blood. It is a dimensionless parameter that measures how much the viscosity changes with shear rate. It has a constant value of 0.3568.

•  gamma_dot: a scalar that represents the shear rate magnitude at the cell c. It has units of 1/s.

•  C_STRAIN_RATE_MAG: a macro that returns the shear rate magnitude at the cell c and thread t.

The UDF performs the following steps:


It defines some constants and variables for the simulation.
It calculates
the shear rate magnitude at
the cell c using C_STRAIN_RATE_MAG and stores it in gamma_dot.
It calculates
the viscosity of blood at
the cell c using the Sisko model and stores it in mu. The model is given by $$\mu = \mu_{\infty} + k \dot{\gamma}^{n - 1}$$ where $\mu$, $\mu_{\infty}$, $k$, $n$, and $\dot{\gamma}$ are as defined above.
It returns mu as
the output
of
the function.
# Refrence
https://www.sciencedirect.com/science/article/abs/pii/S0169260719323168
