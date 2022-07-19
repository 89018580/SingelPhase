[Mesh]
    type = GeneratedMesh
    dim = 1
    nx = 50
    xmax = 1.0
    xmin = 0
[]

[Variables]
    [H]
        order = FIRST
        family = LAGRANGE
    []
    [P]
        order = FIRST
        family = LAGRANGE
    []
[]

[Kernels]
    [ker1]
        type = GradTerm
        variable = H
        velocity = "1.0 1.0 1.0"
    []
    [ker2]
        type = GradTerm
        variable = P
        velocity = "1.0 1.0 1.0"
    []
    [source1]
        type = ValTerm
        variable = H
    []
    [source2]
        type = SourTerm
        variable = P
        some_variable = H
    []
[]

[BCs]
    [bc1]
        type = DirichletBC
        variable = H
        value = 1133820.0
        boundary = "left"
    []
    [bc2]
        type = DirichletBC
        variable = P
        value = 15500000.0
        boundary = "right"
    []
[]

[VectorPostprocessors]
  [H]
    type = NodalValueSampler
    variable = H
    #boundary = 'bottom'
    block = 0
    execute_on = 'initial timestep_end' 
    use_displaced_mesh = true
    sort_by = x
  []
  [P]
    type = NodalValueSampler
    variable = P
    #boundary = 'bottom'
    block = 0
    execute_on = 'initial timestep_end' 
    use_displaced_mesh = true
    sort_by = x
  []
[]

[Problem]
    type = FEProblem
    coord_type = XYZ
    rz_coord_axis = X
[]

[Preconditioning]
  [./SMP]
    type = SMP
    full = true
    solve_type = 'NEWTON'
  [../]
[]

[Executioner]
    type = Steady
    automatic_scaling = true
    #nl_max_its = 100
    #l_max_its = 100
    #petsc_options_iname = '-ksp_type -pc_type -pc_factor_shift_type -pc_factor_shift_amount -snes_linesearch_minlambda'
    #petsc_options_value = 'gmres lu NONZERO 1.e-10 1e-3'
[]

[Outputs]
    exodus = true
    csv = true
[]