#include "TimeTerm.h"
registerMooseObject("steadysingelphaseApp", TimeTerm);

InputParameters
TimeTerm::validParams()
{
    InputParameters params = ADTimeDerivative::validParams();

    return params;
}

TimeTerm::TimeTerm(const InputParameters & parameters): ADTimeDerivative(parameters)
{
}

ADReal
TimeTerm::precomputeQpResidual()
{
    ADReal rho = 781.0669374;
    ADReal A = 0.00049087;
    ADReal W = 0.3911;
    return ((A * rho) / W) * ADTimeDerivative::precomputeQpResidual();
}