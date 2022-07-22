#pragma once
#include "ADKernel.h"
class ICSourTerm: public ADKernel
{
public:
    static InputParameters validParams();

    ICSourTerm(const InputParameters & parameters);

protected:
    virtual ADReal computeQpResidual() override;
};