#pragma once
#include "ADCoupledTimeDerivative.h"

class CoupledTimeTerm : public ADCoupledTimeDerivative
{
    public:
        static InputParameters validParams();
        CoupledTimeTerm(const InputParameters & parameters);
    protected:
        virtual ADReal precomputeQpResidual() override;
};