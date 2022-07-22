#include "CoupledTimeTerm.h"
registerMooseObject("steadysingelphaseApp", CoupledTimeTerm);

InputParameters
CoupledTimeTerm::validParams()
{
    InputParameters params = ADCoupledTimeDerivative::validParams();

    return params;
}

CoupledTimeTerm::CoupledTimeTerm(const InputParameters & parameters): ADCoupledTimeDerivative(parameters)
{
}

ADReal
CoupledTimeTerm::precomputeQpResidual()
{
    ADReal A = 0.00049087;
    ADReal W = 0.3911;
    return (-1.0) * (A / W) * ADCoupledTimeDerivative::precomputeQpResidual();
}