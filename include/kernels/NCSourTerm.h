#pragma once
#include "ADKernel.h"
class NCSourTerm: public ADKernel
{
public:
    static InputParameters validParams();

    NCSourTerm(const InputParameters & parameters);

protected:
    virtual ADReal computeQpResidual() override;
};