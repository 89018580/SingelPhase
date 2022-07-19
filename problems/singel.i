[Mesh]
    type = GeneratedMesh
    dim = 1
    nx = 20
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
    []
    [ker2]
        type = GradTerm
        variable = P
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

[Executioner]
    type = Steady
    solve_type = 'JFNK'
    automatic_scaling = true
    petsc_options_iname = '-pc_type -pc_hypre_type'
    petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
    exodus = true
    csv = true
[]