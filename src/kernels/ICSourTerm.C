#include "ICSourTerm.h"
registerMooseObject("steadysingelphaseApp", ICSourTerm);

InputParameters
ICSourTerm::validParams()
{
    InputParameters params = ADKernel::validParams();
    return params;
}

ICSourTerm::ICSourTerm(const InputParameters & parameters)
    : ADKernel(parameters)
{
}

ADReal
ICSourTerm::computeQpResidual()
{
    ADReal rho = 781.0669374;
    ADReal f = 0.125500020011;
    ADReal k = -0.0003616;
    ADReal Ue = 0.0785398;
    ADReal Uh = 0.0785398;
    ADReal A = 0.00049087;
    ADReal W = 0.3911;
    ADReal g = 9.8;
    ADReal q = 1273239.545;
    // ADReal t1 = (W*W*k*q*Uh)/(A*A*rho*rho*W);
    ADReal t2 = (f*Ue*W*W)/(8*A*A*A*rho);
    ADReal t3 = rho*g;
    return _test[_i][_qp] * (t2 + t3);
}