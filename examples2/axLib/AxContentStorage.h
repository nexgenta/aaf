#ifndef __AxContentStorage_h__
#define __AxContentStorage_h__

//=---------------------------------------------------------------------=
//
// $Id: AxContentStorage.h,v 1.5 2004/02/27 14:26:38 stuart_hc Exp $ $Name:  $
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

#include "AxTypes.h"
#include "AxSmartPointer.h"
#include "AxObject.h"

#include <iosfwd>

class AxContentStorage : public AxObject {

public:
	
	AxContentStorage( IAAFContentStorageSP spIaafContentStorage );
	virtual ~AxContentStorage();

	IAAFMobSP LookupMob( const aafMobID_t& );

	IAAFEssenceDataSP LookupEssenceData( const aafMobID_t& id );
	aafUInt32 CountEssenceData() const;
	aafBoolean_t IsEssenceDataPresent( const aafMobID_t& id ) const;

	IEnumAAFMobsSP GetMobs(  const aafSearchCrit_t* pCriteria = 0 ) const;

	IEnumAAFEssenceDataSP EnumEssenceData() const;

	std::wostream& dump( std::wostream& os ) const;

private:

	AxContentStorage();
	AxContentStorage( const AxContentStorage& );
	AxContentStorage& operator=( const AxContentStorage& );

	mutable IAAFContentStorageSP _spIaafContentStorage;
};

std::wostream& operator<<( std::wostream& os, const AxContentStorage& obj );

#endif
