#pragma once
#include "ADKernel.h"

class GradTerm :public ADKernel
{
public:
    static InputParameters validParams();

    GradTerm(const InputParameters & parameters);

protected:
    virtual ADReal computeQpResidual() override;

    const RealVectorValue & _velocity;

// private:
//     const RealVectorValue & _velocity;
};