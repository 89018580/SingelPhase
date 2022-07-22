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
        variable = P
        velocity = "1.0 1.0 1.0"
    []
    [ker2]
        type = ICSourTerm
        variable = P
    []
    [ker3]
        type = TimeTerm
        variable = H
    []
    [ker4]
        type = GradTerm
        variable = H
        velocity = "1.0 1.0 1.0"
    []
    [ker5]
        type = ValTerm
        variable = H
    []
    [ker6]
        type = CoupledTimeTerm
        variable = H
        v = P
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

#[VectorPostprocessors]
  #[H]
    #type = NodalValueSampler
    #variable = H
    #boundary = 'bottom'
    #block = 0
    #execute_on = 'initial timestep_end' 
    #use_displaced_mesh = true
    #sort_by = x
  #[]
  #[P]
    #type = NodalValueSampler
    #variable = P
    #boundary = 'bottom'
    #block = 0
    #execute_on = 'initial timestep_end' 
    #use_displaced_mesh = true
    #sort_by = x
  #[]
#[]

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
    type = Transient
    automatic_scaling = true
    solve_type = 'JFNK'
    shceme = bdf2
    petsc_options = '-snes_converged_reason -ksp_converged_reason -snes_linesearch_monitor'
    l_tol = 1e-10
    nl_rel_tol = 1e-10
    nl_abs_tol = 1e-10
    line_search = 'none'
    petsc_options_iname = '-pc_type -sub_pc_factor_levels -ksp_gmres_restart'
    petsc_options_value = 'asm  6  200'
    num_steps = 100000
    dt = 0.00001
    #petsc_options_iname = '-ksp_type -pc_type -pc_factor_shift_type -pc_factor_shift_amount -snes_linesearch_minlambda'
    #petsc_options_value = 'gmres lu NONZERO 1.e-10 1e-3'
    #petsc_options_iname = '-pc_type -pc_hypre_type -pc_hypre_boomeramg_strong_threshold'
    #petsc_options_value = 'hypre boomeramg 0.7'
[]

[Outputs]
    exodus = true
    csv = true
[]