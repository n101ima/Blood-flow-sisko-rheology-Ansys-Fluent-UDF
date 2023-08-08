#include "udf.h"

DEFINE_PROPERTY(sisko_viscosity, c, t)
{
	real mu;
	real mu_inf = 0.0035; // viscosity at infinite shear rate [Pa.s]
	real k = 0.056; // consistency coefficient [Pa.s^n]
	real n = 0.3568; // power-law index
	real gamma_dot; // shear rate [1/s]

	gamma_dot = C_STRAIN_RATE_MAG(c, t); // calculate the shear rate magnitude using a macro

	mu = mu_inf + k * pow(gamma_dot, n - 1); // calculate the viscosity using the Sisko model

	return mu;
}