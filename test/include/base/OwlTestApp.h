//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef OWLTESTAPP_H
#define OWLTESTAPP_H

#include "MooseApp.h"

class OwlTestApp;

template <>
InputParameters validParams<OwlTestApp>();

class OwlTestApp : public MooseApp
{
public:
  OwlTestApp(InputParameters parameters);
  virtual ~OwlTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* OWLTESTAPP_H */
