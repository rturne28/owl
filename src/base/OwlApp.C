#include "OwlApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<OwlApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

OwlApp::OwlApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  OwlApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  OwlApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  OwlApp::registerExecFlags(_factory);
}

OwlApp::~OwlApp() {}

void
OwlApp::registerApps()
{
  registerApp(OwlApp);
}

void
OwlApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"OwlApp"});
}

void
OwlApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"OwlApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
OwlApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
OwlApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
OwlApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
OwlApp__registerApps()
{
  OwlApp::registerApps();
}

extern "C" void
OwlApp__registerObjects(Factory & factory)
{
  OwlApp::registerObjects(factory);
}

extern "C" void
OwlApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  OwlApp::associateSyntax(syntax, action_factory);
}

extern "C" void
OwlApp__registerExecFlags(Factory & factory)
{
  OwlApp::registerExecFlags(factory);
}
