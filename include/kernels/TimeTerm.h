#pragma once
#include "ADTimeDerivative.h"

class TimeTerm : public ADTimeDerivative
{
    public:
        static InputParameters validParams();
        TimeTerm(const InputParameters & parameters);
    protected:
        virtual ADReal precomputeQpResidual() override;
};