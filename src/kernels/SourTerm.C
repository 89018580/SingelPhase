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
    ADReal f = 0.125500020011;
    ADReal k = -0.0003616;
    ADReal Ue = 0.0785398;
    ADReal Uh = 0.0785398;
    ADReal A = 0.00049087;
    ADReal W = 0.3911;
    ADReal g = 9.8;
    ADReal q = 1273239.545;
    ADReal t1 = (W*W*k*q*Uh)/(A*A*rho*rho*W);
    ADReal t2 = (f*Ue*W*W)/(8*A*A*A*rho);
    ADReal t3 = rho*g;
    return _test[_i][_qp] * (t1-t2-t3) * (-1.0);
}