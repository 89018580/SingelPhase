#pragma once
#include "ADKernelGrad.h"

class GradTerm :public ADKernelGrad
{
public:
    static InputParameters validParams();

    GradTerm(const InputParameters & parameters);

protected:
    virtual ADRealVectorValue precomputeQpResidual() override;

// private:
//     const RealVectorValue & _velocity;
};