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
        type = ConservativeAdvection
        variable = H
        velocity = "1.0 1.0 1.0"
    []
    [ker2]
        type = ConservativeAdvection
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
        type = InflowBC
        variable = H
        inlet_conc = 1133820.0
        boundary = "left"
        velocity = "1.0 1.0 1.0"
    []
    [bc2]
        type = OutflowBC
        variable = P
        outlet_conc = 15500000.0
        boundary = "right"
        velocity = "1.0 1.0 1.0"
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
[]

[Preconditioning]
  [./SMP]
    type = SMP
    full = true
  [../]
[]

[Executioner]
    type = Steady
    automatic_scaling = true
    solve_type = 'NEWTON'
    petsc_options = '-snes_converged_reason -ksp_converged_reason -snes_linesearch_monitor'
    l_tol = 1e-10
    nl_rel_tol = 1e-10
    nl_abs_tol = 1e-10
    line_search = 'none'
    petsc_options_iname = '-pc_type -sub_pc_factor_levels -ksp_gmres_restart'
    petsc_options_value = 'asm  6  200'
    #petsc_options_iname = '-ksp_type -pc_type -pc_factor_shift_type -pc_factor_shift_amount -snes_linesearch_minlambda'
    #petsc_options_value = 'gmres lu NONZERO 1.e-10 1e-3'
    #petsc_options_iname = '-pc_type -pc_hypre_type -pc_hypre_boomeramg_strong_threshold'
    #petsc_options_value = 'hypre boomeramg 0.7'
[]

[Outputs]
    exodus = true
    csv = true
[]