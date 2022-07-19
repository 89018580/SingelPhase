#pragma once
#include "ADKernel.h"
#include "LinearInterpolation.h"
class SourTerm: public ADKernel
{
public:
    static InputParameters validParams();

    SourTerm(const InputParameters & parameters);

protected:
    virtual ADReal computeQpResidual() override;

    const ADVariableValue & _Enth;
};