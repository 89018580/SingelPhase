[Mesh]
    type = GeneratedMesh
    dim = 1
    nx = 50
    xmax = 1.0
    xmin = 0
    element_type = EDGE
[]

[Variables]
    [P]
        order = FIRST
        family = LAGRANGE
    []
[]

[Kernels]
    [ker2]
        type = GradTerm
        variable = P
        velocity = "1.0 1.0 1.0"
    []
    [source2]
        type = NCSourTerm
        variable = P
    []
[]

[BCs]
    [bc2]
        type = DirichletBC
        variable = P
        value = 15500000.0
        boundary = "right"
    []
[]

[VectorPostprocessors]
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

[Executioner]
    type = Steady
    solve_type = 'NEWTON'
    automatic_scaling = true
[]

[Outputs]
    exodus = true
    csv = true
[]