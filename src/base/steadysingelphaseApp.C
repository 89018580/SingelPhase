#include "steadysingelphaseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
steadysingelphaseApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

steadysingelphaseApp::steadysingelphaseApp(InputParameters parameters) : MooseApp(parameters)
{
  steadysingelphaseApp::registerAll(_factory, _action_factory, _syntax);
}

steadysingelphaseApp::~steadysingelphaseApp() {}

void
steadysingelphaseApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"steadysingelphaseApp"});
  Registry::registerActionsTo(af, {"steadysingelphaseApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
steadysingelphaseApp::registerApps()
{
  registerApp(steadysingelphaseApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
steadysingelphaseApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  steadysingelphaseApp::registerAll(f, af, s);
}
extern "C" void
steadysingelphaseApp__registerApps()
{
  steadysingelphaseApp::registerApps();
}
