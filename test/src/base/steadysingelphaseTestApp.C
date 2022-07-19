//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "steadysingelphaseTestApp.h"
#include "steadysingelphaseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
steadysingelphaseTestApp::validParams()
{
  InputParameters params = steadysingelphaseApp::validParams();
  return params;
}

steadysingelphaseTestApp::steadysingelphaseTestApp(InputParameters parameters) : MooseApp(parameters)
{
  steadysingelphaseTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

steadysingelphaseTestApp::~steadysingelphaseTestApp() {}

void
steadysingelphaseTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  steadysingelphaseApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"steadysingelphaseTestApp"});
    Registry::registerActionsTo(af, {"steadysingelphaseTestApp"});
  }
}

void
steadysingelphaseTestApp::registerApps()
{
  registerApp(steadysingelphaseApp);
  registerApp(steadysingelphaseTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
steadysingelphaseTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  steadysingelphaseTestApp::registerAll(f, af, s);
}
extern "C" void
steadysingelphaseTestApp__registerApps()
{
  steadysingelphaseTestApp::registerApps();
}
