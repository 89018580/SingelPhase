#include "GradTerm.h"
registerMooseObject("steadysingelphaseApp", GradTerm);

InputParameters
GradTerm::validParams()
{
    InputParameters params = ADKernelGrad::validParams();
    // params.addRequiredParam<RealVectorValue>("velocity", "Velocity Vector");
    params.addClassDescription("The grad term of the equation");
    return params;
}

GradTerm::GradTerm(const InputParameters & parameters): ADKernelGrad(parameters)
{
}

ADRealVectorValue
GradTerm::precomputeQpResidual()
{
    return   -1.0 * _u[_qp] ;
}