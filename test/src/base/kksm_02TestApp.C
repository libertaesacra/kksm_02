//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "kksm_02TestApp.h"
#include "kksm_02App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
kksm_02TestApp::validParams()
{
  InputParameters params = kksm_02App::validParams();
  return params;
}

kksm_02TestApp::kksm_02TestApp(InputParameters parameters) : MooseApp(parameters)
{
  kksm_02TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

kksm_02TestApp::~kksm_02TestApp() {}

void
kksm_02TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  kksm_02App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"kksm_02TestApp"});
    Registry::registerActionsTo(af, {"kksm_02TestApp"});
  }
}

void
kksm_02TestApp::registerApps()
{
  registerApp(kksm_02App);
  registerApp(kksm_02TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
kksm_02TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kksm_02TestApp::registerAll(f, af, s);
}
extern "C" void
kksm_02TestApp__registerApps()
{
  kksm_02TestApp::registerApps();
}
