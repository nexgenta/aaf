//=---------------------------------------------------------------------=
//
// $Id$
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

//Edit Protocol Test files
#include "EPTrackContentsVisitor.h"
#include "EPTrackContentsTest.h"

//Test/Result files
#include <DetailLevelTestResult.h>
#include <TestRegistry.h>

//Requirement files
#include <RequirementRegistry.h>
#include <Requirement.h>

//Ax files
#include <AxMob.h>
#include <AxDefObject.h>
#include <AxMobSlot.h>
#include <AxIterator.h>
#include <AxComponent.h>
#include <AxMetaDef.h>

//STL files
#include <sstream>

namespace {

} // end of namespace

//======================================================================

namespace aafanalyzer {

using namespace boost;
 
EPTrackContentsVisitor::EPTrackContentsVisitor( wostream& log )
    : _log(log),
      _spResult( new DetailLevelTestResult( L"Edit Protocol Track Contents Visitor",
                                            L"Visit derivation chain material and make sure that their tracks contain the necessary data.",
                                            L"", // explain
                                            L"", // DOCREF REQUIRED
                                            TestResult::PASS,
                                            TestRegistry::GetInstance().GetRequirementsForTest( EPTrackContentsTest::GetTestInfo().GetName() )
               )                          )
{
}
    
EPTrackContentsVisitor::~EPTrackContentsVisitor()
{
}

bool EPTrackContentsVisitor::PreOrderVisit( EPTypedObjNode<IAAFCompositionMob, EPSubClipComposition>& node )
{
    bool testPassed = true;

    AxCompositionMob axCompMob( node.GetAAFObjectOfType() );
    shared_ptr<TrackSet> spEssenceTrack = this->GetEssenceTracks( axCompMob );

    TrackSet::const_iterator iter;
    for ( iter = spEssenceTrack->begin(); iter != spEssenceTrack->end(); iter++ )
    {
        if ( CountSegments( **iter, kAAFClassID_SourceClip ) != 1 )
        {
            AxString mobName = this->GetMobName( axCompMob, L"Sub-Clip Composition" );

            wstringstream ss;
            ss << L"Slot with ID ";
            ss << (*iter)->GetSlotID();
            ss << L" in " << mobName << L" does not have exactly one SourceClip.";

            AxString explain( ss.str().c_str() );
            AddFailure( L"REQ_EP_037", explain );
            testPassed = false;
        }
    }
    
    return testPassed;
}

bool EPTrackContentsVisitor::PreOrderVisit( EPTypedObjNode<IAAFCompositionMob, EPAdjustedClipComposition>& node )
{
    bool testPassed = true;

    AxCompositionMob axCompMob( node.GetAAFObjectOfType() );
    shared_ptr<TrackSet> spEssenceTrack = this->GetEssenceTracks( axCompMob );

    TrackSet::const_iterator iter;
    for ( iter = spEssenceTrack->begin(); iter != spEssenceTrack->end(); iter++ )
    {
        if ( CountSegments( **iter, kAAFClassID_OperationGroup ) != 1 )
        {
            AxString mobName = this->GetMobName( axCompMob, L"Adjusted-Clip Composition" );

            wstringstream ss;
            ss << L"Slot with ID ";
            ss << (*iter)->GetSlotID();
            ss << L" in " << mobName << L" does not have exactly one OperationGroup.";

            AxString explain( ss.str().c_str() );
            AddFailure( L"REQ_EP_046", explain );
            testPassed = false;
        }
    }
    
    return testPassed;
}

bool EPTrackContentsVisitor::EdgeVisit(AAFComponentReference& edge)
{
    return false;
}

bool EPTrackContentsVisitor::EdgeVisit(AAFSlotReference& edge)
{
    return false;
}
    
shared_ptr<DetailLevelTestResult> EPTrackContentsVisitor::GetResult()
{
    return _spResult;
}
   
void EPTrackContentsVisitor::AddFailure( const AxString& reqId, const AxString& explain )
{
    shared_ptr<const Requirement> failingReq = RequirementRegistry::GetInstance().GetRequirement( reqId );
    Requirement::RequirementMapSP reqMapSP(new Requirement::RequirementMap);
    (*reqMapSP)[reqId] = failingReq;
    
    shared_ptr<DetailLevelTestResult> spFailure( new DetailLevelTestResult( _spResult->GetName(),
                                L"-", // desc
                                explain,
                                L"-", // docref
                                TestResult::FAIL,
                                reqMapSP ) );
    spFailure->SetRequirementStatus( TestResult::FAIL, failingReq );
    
    _spResult->AppendSubtestResult( spFailure );
    _spResult->SetResult( _spResult->GetAggregateResult() );
    _spResult->SetRequirementStatus( TestResult::FAIL, failingReq );
}

unsigned int EPTrackContentsVisitor::CountSegments( AxMobSlot& track, aafUID_t segmentType )
{
    AxSegment axSegment( track.GetSegment() );
    AxClassDef clsDef( axSegment.GetDefinition() );
    if ( this->IsType( clsDef, segmentType, kAAFClassID_Segment ) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

} // end of namespace aafanalyzer