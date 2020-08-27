#include "kksm_02App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
kksm_02App::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

kksm_02App::kksm_02App(InputParameters parameters) : MooseApp(parameters)
{
  kksm_02App::registerAll(_factory, _action_factory, _syntax);
}

kksm_02App::~kksm_02App() {}

void
kksm_02App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"kksm_02App"});
  Registry::registerActionsTo(af, {"kksm_02App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
kksm_02App::registerApps()
{
  registerApp(kksm_02App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
kksm_02App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kksm_02App::registerAll(f, af, s);
}
extern "C" void
kksm_02App__registerApps()
{
  kksm_02App::registerApps();
}
