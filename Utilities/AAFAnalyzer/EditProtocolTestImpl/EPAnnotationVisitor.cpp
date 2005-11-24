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
#include "EPAnnotationVisitor.h"
#include "EPAnnotationTest.h"

//Test/Result files
#include <DetailLevelTestResult.h>
#include <TestRegistry.h>

//Ax files
#include <AxComponent.h>
#include <AxEx.h>

//AAF files
#include <AAFResult.h>

namespace {

} // end of namespace

//======================================================================

namespace aafanalyzer {

using namespace boost;
 
EPAnnotationVisitor::EPAnnotationVisitor( wostream& log, shared_ptr<EdgeMap> spEdgeMap )
    : _log(log),
      _spEdgeMap( spEdgeMap ),
      _spResult( new DetailLevelTestResult( L"Edit Protocol Annotation Visitor",
                                            L"Visit components to make sure they do not have illegal annotations.",
                                            L"", // explain
                                            L"", // DOCREF REQUIRED
                                            TestResult::PASS,
                                            TestRegistry::GetInstance().GetRequirementsForTest( EPAnnotationTest::GetTestInfo().GetName() )
               )                          ),
      _isAncestorEssenceTrack( false ),
      _isAncestorEventMobSlot( false )
{
    _isParentMobSlot.push( false );
}
    
EPAnnotationVisitor::~EPAnnotationVisitor()
{}

/*
 * 
 * Components
 * 
 */
 
bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFTransition>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFSegment>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFSequence>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFFiller>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFSourceReference>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFSourceClip>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFEvent>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFGPITrigger>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFEdgecode>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFTimecode>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFTimecodeStream>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFTimecodeStream12M>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFPulldown>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFOperationGroup>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFNestedScope>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFScopeReference>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFEssenceGroup>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFSelector>& node )
{
    shared_ptr<AAFTypedObjNode<IAAFComponent> > spGeneric( node.DownCast<IAAFComponent>() );
    return this->PreOrderVisit( *spGeneric );
}

//Base Cases:

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFDescriptiveMarker>& node )
{
    //This is a comment marker subclass, there is nothing that needs to be
    //checked, but state must be updated.
    _isParentMobSlot.push( false );
    return true;
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFCommentMarker>& node )
{
    
    bool testPassed = true;
    
    if ( _isAncestorEssenceTrack )
    {
        //Ancestor is an essence track
        _spResult->AddInformationResult( L"REQ_EP_149", this->GetMobSlotName( _spEdgeMap, node) + L" is an essence track and uses CommentMarkers for annotations.", TestResult::FAIL );
        testPassed = false;
    }
    
    //Need to ensure that parent is event mob slot
    if ( !_isAncestorEventMobSlot )
    {
        _spResult->AddInformationResult( L"REQ_EP_150", this->GetMobSlotName( _spEdgeMap, node) + L" is not an Event Mob Slot but contains a CommentMarker.", TestResult::FAIL );
        testPassed = false;
    }
    
    //Update State
    _isParentMobSlot.push( false );
    
    return testPassed;
}

bool EPAnnotationVisitor::PreOrderVisit( AAFTypedObjNode<IAAFComponent>& node )
{
    
    AxComponent axComponent( node.GetAAFObjectOfType() );
    
    //Need to ensure that parent is a comment marker or mob slot
    if ( axComponent.CountComments() != 0 )
    {
        //Component::UserComments is being used
        if ( !_isParentMobSlot.top() )
        {
            //Parent is not a MobSlot and this is not a CommentMarker so fail
            //the test.
            _spResult->AddInformationResult( L"REQ_EP_147", this->GetMobSlotName( _spEdgeMap, node ) + L" contains a Component that illegally uses the Component::UserComments property.", TestResult::FAIL );
            return false;
        }
    }

    //Update state
    _isParentMobSlot.push( false );
    return true;
}

/*
 * 
 * Mob Slot/Tracks
 * 
 */

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFTimelineMobSlot, EPAudioTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFTimelineMobSlot, EPVideoTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFTimelineMobSlot, EPEssenceTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFTimelineMobSlot, EPTimecodeTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPNonEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPNonEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFTimelineMobSlot, EPEdgecodeTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPNonEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPNonEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFTimelineMobSlot, EPNonEssenceTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPNonEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPNonEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFStaticMobSlot, EPAudioTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFStaticMobSlot, EPVideoTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFStaticMobSlot, EPEssenceTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFStaticMobSlot, EPTimecodeTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPNonEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPNonEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFStaticMobSlot, EPEdgecodeTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPNonEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPNonEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFStaticMobSlot, EPNonEssenceTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPNonEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPNonEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFEventMobSlot, EPAudioTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFEventMobSlot, EPEssenceTrack> > spGeneric( node.DownCast<IAAFEventMobSlot, EPEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFEventMobSlot, EPVideoTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFEventMobSlot, EPEssenceTrack> > spGeneric( node.DownCast<IAAFEventMobSlot, EPEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFEventMobSlot, EPTimecodeTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFEventMobSlot, EPNonEssenceTrack> > spGeneric( node.DownCast<IAAFEventMobSlot, EPNonEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFEventMobSlot, EPEdgecodeTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFEventMobSlot, EPNonEssenceTrack> > spGeneric( node.DownCast<IAAFEventMobSlot, EPNonEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFMobSlot, EPAudioTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFMobSlot, EPVideoTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFMobSlot, EPTimecodeTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPNonEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPNonEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFMobSlot, EPEdgecodeTrack>& node )
{
    shared_ptr<EPTypedObjNode<IAAFMobSlot, EPNonEssenceTrack> > spGeneric( node.DownCast<IAAFMobSlot, EPNonEssenceTrack>() );
    return this->PreOrderVisit( *spGeneric );
}

//Base cases:
bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFEventMobSlot, EPEssenceTrack>& node )
{
    _isAncestorEventMobSlot = true;
    _isParentMobSlot.push( true );
    _isAncestorEssenceTrack = true;
    return true;
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFEventMobSlot, EPNonEssenceTrack>& node )
{
    _isAncestorEventMobSlot = true;
    _isParentMobSlot.push( true );
    _isAncestorEssenceTrack = false;
    return true;
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFMobSlot, EPEssenceTrack>& node )
{
    _isAncestorEventMobSlot = false;
    _isParentMobSlot.push( true );
    _isAncestorEssenceTrack = true;
    return true;
}

bool EPAnnotationVisitor::PreOrderVisit( EPTypedObjNode<IAAFMobSlot, EPNonEssenceTrack>& node )
{
    _isAncestorEventMobSlot = false;
    _isParentMobSlot.push( true );
    _isAncestorEssenceTrack = false;
    return true;
}

/*
 * 
 * Post-Order Visits
 * 
 */
 
bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFComponent>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFTransition>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFSegment>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFSequence>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFFiller>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFSourceReference>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFSourceClip>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFEvent>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFGPITrigger>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFCommentMarker>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFDescriptiveMarker>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFEdgecode>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFTimecode>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFTimecodeStream>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFTimecodeStream12M>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFPulldown>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFOperationGroup>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFNestedScope>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFScopeReference>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFEssenceGroup>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFSelector>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFTimelineMobSlot>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFStaticMobSlot>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFEventMobSlot>& node )
{
    return PopStacks();
}

bool EPAnnotationVisitor::PostOrderVisit( AAFTypedObjNode<IAAFMobSlot>& node )
{
    return PopStacks();
}

    
bool EPAnnotationVisitor::PopStacks()
{
    _isParentMobSlot.pop();
    return true;
}

shared_ptr<DetailLevelTestResult> EPAnnotationVisitor::GetResult()
{
    return _spResult;
}
   
} // end of namespace aafanalyzer