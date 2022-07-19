#pragma once
#include "ADKernel.h"
#include "LinearInterpolation.h"
class ValTerm: public ADKernel
{
public:
    static InputParameters validParams();

    ValTerm(const InputParameters & parameters);

protected:
    virtual ADReal computeQpResidual() override;
};