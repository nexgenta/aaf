//=---------------------------------------------------------------------=
//
// $Id: RequirementMismatchException.cpp,v 1.1 2005/09/20 17:35:39 ajakowpa Exp $ $Name:  $
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

#include "RequirementMismatchException.h"
#include <AxUtil.h>

namespace {

//using namespace aafanalyzer;

} // end of namespace


//======================================================================
//======================================================================
//======================================================================

namespace aafanalyzer 
{

RequirementMismatchException::RequirementMismatchException( const wchar_t* what )
  : AxEx( AxString(AxString(L"Requirement mismatch: ") + AxString(what)).c_str() )
{}

RequirementMismatchException::~RequirementMismatchException() throw()
{}

} // end of namespace diskstream