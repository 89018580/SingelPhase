#include "ValTerm.h"
registerMooseObject("steadysingelphaseApp", ValTerm);

InputParameters
ValTerm::validParams()
{
    InputParameters params = ADKernel::validParams();
    return params;
}

ValTerm::ValTerm(const InputParameters & parameters): ADKernel(parameters)
{
}

ADReal
ValTerm::computeQpResidual()
{
    ADReal Uh = 0.0785398;
    ADReal W = 0.3911;
    ADReal q = 1273239.545;
    ADReal t = (q*Uh)/W;
    return _test[_i][_qp] * t * (-1.0);
}