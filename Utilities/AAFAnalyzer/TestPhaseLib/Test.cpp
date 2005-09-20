//=---------------------------------------------------------------------=
//
// $Id: Test.cpp,v 1.5 2005/09/20 17:47:26 ajakowpa Exp $
//
// The contents of this file are subject to the AAF SDK Public
// Source License Agreement (the "License"); You may not use this file
// except in compliance with the License.  The License is available in
// AAFSDKPSL.TXT, or you may obtain a copy of the License from the AAF
// Association or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.
//
// The Original Code of this file is Copyright 1998-2004, Licensor of the
// AAF Association.
//
//=---------------------------------------------------------------------=

#include "Test.h"
#include "TestRegistry.h"

namespace {

using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{

Test::Test(std::wostream& os, const TestInfo& info)
: _os(os), _spCoveredRequirements(InitializeRequirements(info.GetName()))
{
}

const Test::ConstRequirementMapSP Test::InitializeRequirements(const AxString& name)
{
    TestRegistry& reg = TestRegistry::GetInstance();
    return reg.GetRequirementsForTest(name);
}

Test::~Test()
{
}

AxString Test::GetName() const
{
  AxString null;
  return null;
}

AxString Test::GetDescription() const
{
  AxString null;
  return null;
}

std::wostream& Test::GetOutStream() const
{
  return _os;
}

boost::shared_ptr<TestGraph> Test::GetTestGraph()
{
  return _spTestGraph;
}

void Test::SetTestGraph(boost::shared_ptr<TestGraph> spTestGraph)
{
  _spTestGraph = spTestGraph;
}

const Requirement::RequirementMap& Test::GetCoveredRequirements() const
{
    return *_spCoveredRequirements;
}

} // end of namespace diskstream
