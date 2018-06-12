//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "OwlTestApp.h"
#include "OwlApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<OwlTestApp>()
{
  InputParameters params = validParams<OwlApp>();
  return params;
}

OwlTestApp::OwlTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  OwlApp::registerObjectDepends(_factory);
  OwlApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  OwlApp::associateSyntaxDepends(_syntax, _action_factory);
  OwlApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  OwlApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    OwlTestApp::registerObjects(_factory);
    OwlTestApp::associateSyntax(_syntax, _action_factory);
    OwlTestApp::registerExecFlags(_factory);
  }
}

OwlTestApp::~OwlTestApp() {}

void
OwlTestApp::registerApps()
{
  registerApp(OwlApp);
  registerApp(OwlTestApp);
}

void
OwlTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
OwlTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
OwlTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
OwlTestApp__registerApps()
{
  OwlTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
OwlTestApp__registerObjects(Factory & factory)
{
  OwlTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
OwlTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  OwlTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
OwlTestApp__registerExecFlags(Factory & factory)
{
  OwlTestApp::registerExecFlags(factory);
}
