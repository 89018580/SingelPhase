#include "SourTerm.h"
registerMooseObject("steadysingelphaseApp", SourTerm);

InputParameters
SourTerm::validParams()
{
    InputParameters params = ADKernel::validParams();
    params.addRequiredCoupledVar("some_variable", "The value of this variable will be used to calculate the source.");
    return params;
}

SourTerm::SourTerm(const InputParameters & parameters)
    : ADKernel(parameters),
      _Enth(adCoupledValue("some_variable"))
{
}

ADReal
SourTerm::computeQpResidual()
{
    ADReal rho = -0.0003616*_Enth[_qp] + 1209;
    Real f = 0.125500020011;
    Real k = -0.0003616;
    Real Ue = 0.0785398;
    Real Uh = 0.0785398;
    Real A = 0.00049087;
    Real W = 0.3911;
    Real g = 9.8;
    Real q = 1273239.545;
    ADReal t1 = (W*W*k*q*Uh)/(A*A*rho*rho*W);
    ADReal t2 = (f*Ue*W*W)/(2*A*A*A*rho);
    ADReal t3 = rho*g;
    return _test[_i][_qp] * (t1-t2-t3) * (-1);
}