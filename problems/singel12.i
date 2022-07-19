[Mesh]
    type = GeneratedMesh
    dim = 1
    nx = 50
    xmax = 1.0
    xmin = 0
    element_type = EDGE
[]

[Variables]
    [H]
        order = FIRST
        family = LAGRANGE
    []
[]

[Kernels]
    [ker2]
        type = GradTerm
        variable = H
        velocity = "1.0 1.0 1.0"
    []
    [source2]
        type = ValTerm
        variable = H
    []
[]

[BCs]
    [bc1]
        type = DirichletBC
        variable = H
        value = 1133820.0
        boundary = "left"
    []
[]

[VectorPostprocessors]
  [H]
    type = NodalValueSampler
    variable = H
    block = 0
    execute_on = 'initial timestep_end' 
    use_displaced_mesh = true
    sort_by = x
  []
[]

[Executioner]
    type = Steady
    solve_type = 'JFNK'
[]

[Outputs]
    exodus = true
    csv = true
[]