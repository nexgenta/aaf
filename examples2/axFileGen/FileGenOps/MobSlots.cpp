//=---------------------------------------------------------------------=
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
// The Original Code of this file is Copyright 1998-2001, Licensor of the
// AAF Association.
// 
//=---------------------------------------------------------------------=

#include <axFileGen.h>

#include <axDictionary.h>
#include <axMob.h>
#include <axMobSlot.h>
#include <axIterator.h>

namespace {

//=---------------------------------------------------------------------=

AXFG_OP_DECLARATION( MobSlotSet )

// A collection of operations on MobSlots, all implemented by the same
// AxFGOp.

AXFG_OP_FACTORY_DECLARATION_B(
  MobSlotSet,
  MobSlotSetPhysNum,
  L"MobSlotSetPhysNum",
  L"Set the physical track number for any mob slot.",
  L"MobSlotName phys_num",
  L"",
  3,
  3 )

MobSlotSet::~MobSlotSet()
{}

void MobSlotSet::Execute( const std::vector<AxString>& argv )
{
	AxString opName   = argv[0];
	AxString slotName = argv[1];
	// See below for further opName specific arguments.

	IAAFMobSlotSP spSlot;
	GetInstance( slotName ).GetCOM( spSlot );
	AxMobSlot axSlot( spSlot );

	if ( opName == L"MobSlotSetPhysNum" ) {
		AxString physNum = argv[2];
		axSlot.SetPhysicalNum( AxStringUtil::strtol( physNum ) );
	}
	else {
		// This should never happen in a correct implementation.
		// If it does, one of strings used in the above opName
		// comparisons is probably wrong.
		throw AxFGEx( L"bad implementation" );
	}
}

//=---------------------------------------------------------------------=

AXFG_OP(
  TimeLineMobSlot,           
  L"TimeLineMobSlot",
  L"Creates a TimeLineMobSlot.",
  L"FileName SlotName origin edit_rate_num edit_rate_den",
  L"The origin and edit rates are integers.",
  6,
  6 ) 

TimeLineMobSlot::~TimeLineMobSlot()
{}

void TimeLineMobSlot::Execute( const std::vector<AxString>& argv )
{
	AxString fileName = argv[1];
	AxString slotName = argv[2];
	AxString origin   = argv[3];
	AxString rateNum  = argv[4];
	AxString rateDen  = argv[5];

	AxDictionary axDict( DictionaryFromFileOp( fileName ) );
	IAAFTimelineMobSlotSP spSlot;
	AxCreateInstance( axDict, spSlot );
	AxTimelineMobSlot axSlot( spSlot );

	axSlot.Initialize();

	aafPosition_t originVal = AxStringUtil::strtol( origin );
	axSlot.SetOrigin( originVal );

	aafRational_t editRateVal = { AxStringUtil::strtol( rateNum ),
								  AxStringUtil::strtol( rateDen ) };
	axSlot.SetEditRate( editRateVal );

	SetCOM( spSlot );
	RegisterInstance( slotName );
}


//=---------------------------------------------------------------------=

AXFG_OP(
  GetMobSlot,           
  L"GetMobSlot",
  L"Fetches a mob slot from a mob..",
  L"MobName slot_id SlotName",
  L"The fetched slot is reference using SlotName.",
  4,
  4 ) 

GetMobSlot::~GetMobSlot()
{}

void GetMobSlot::Execute( const std::vector<AxString>& argv )
{
	AxString mobName = argv[1];
	AxString slotId = argv[2];
	AxString slotName = argv[3];
  
	IAAFMobSP spMob;
	GetInstance( mobName ).GetCOM( spMob );
	AxMob axMob( spMob );

	int slotIdVal = AxStringUtil::strtol( slotId );

	AxMobSlotIter axSlotIter( axMob.GetSlots() );
	IAAFMobSlotSP nextSlot;
	bool notAtEnd;

	for( notAtEnd = axSlotIter.NextOne( nextSlot );
	     notAtEnd;
		 notAtEnd = axSlotIter.NextOne( nextSlot ) ) {
		AxMobSlot axSlot( nextSlot );
		if ( slotIdVal == axSlot.GetSlotID() ) {
			break;
		}
	}

	if ( notAtEnd ) {
		SetCOM( nextSlot );
		RegisterInstance( slotName );
	}
	else {
		throw AxFGOpUsageEx( *this, slotId + L" not found" );
	}
}

//=---------------------------------------------------------------------=

AXFG_OP(
  GetSlotSegment,
  L"GetSlotSegment",
  L"Get a Segment from a MobSlot.",
  L"SlotName SegmentName",
  L"",
  3,
  3 )

GetSlotSegment::~GetSlotSegment()
{}

void GetSlotSegment::Execute( const std::vector<AxString>& argv )
{
	AxString slotName = argv[1];
	AxString segName = argv[2];

	IAAFMobSlotSP spSlot;
	GetInstance( slotName ).GetCOM( spSlot );
	AxMobSlot axSlot( spSlot );

	SetCOM( axSlot.GetSegment() );
	RegisterInstance( segName );
}


} // end of namespace

