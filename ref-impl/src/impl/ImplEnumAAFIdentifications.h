//@doc
//@class    EnumAAFIdentifications | Implementation class for EnumAAFIdentifications
#ifndef __ImplEnumAAFIdentifications_h__
#define __ImplEnumAAFIdentifications_h__


//=---------------------------------------------------------------------=
//
// $Id: ImplEnumAAFIdentifications.h,v 1.12 2009/06/01 11:47:09 stuart_hc Exp $ $Name:  $
//
// The contents of this file are subject to the AAF SDK Public Source
// License Agreement Version 2.0 (the "License"); You may not use this
// file except in compliance with the License.  The License is available
// in AAFSDKPSL.TXT, or you may obtain a copy of the License from the
// Advanced Media Workflow Association, Inc., or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.  Refer to Section 3.3 of the License for proper use
// of this Exhibit.
//
// WARNING:  Please contact the Advanced Media Workflow Association,
// Inc., for more information about any additional licenses to
// intellectual property covering the AAF Standard that may be required
// to create and distribute AAF compliant products.
// (http://www.amwa.tv/policies).
//
// Copyright Notices:
// The Original Code of this file is Copyright 1998-2009, licensor of the
// Advanced Media Workflow Association.  All rights reserved.
//
// The Initial Developer of the Original Code of this file and the
// licensor of the Advanced Media Workflow Association is
// Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

#include "ImplAAFEnumerator.h"

#include "ImplAAFIdentification.h"

typedef ImplAAFEnumerator<ImplAAFIdentification> ImplEnumAAFIdentifications;

#endif // ! __ImplEnumAAFIdentifications_h__


