#include "GradTerm.h"
registerMooseObject("steadysingelphaseApp", GradTerm);

InputParameters
GradTerm::validParams()
{
    InputParameters params = ADKernel::validParams();
    // params.addRequiredParam<RealVectorValue>("velocity", "Velocity Vector");
    params.addClassDescription("The grad term of the equation");
    params.addRequiredParam<RealVectorValue>("velocity", "Just a vector to form REAL");
    return params;
}

GradTerm::GradTerm(const InputParameters & parameters): ADKernel(parameters),
_velocity(getParam<RealVectorValue>("velocity"))
{
}

ADReal
GradTerm::computeQpResidual()
{
    return   _test[_i][_qp] *  _grad_u[_qp] * _velocity ;
}