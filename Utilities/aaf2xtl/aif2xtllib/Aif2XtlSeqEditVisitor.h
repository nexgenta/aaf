// Copyright 2003 BBC Technology

// $Id: Aif2XtlSeqEditVisitor.h,v 1.1 2004/11/20 21:14:38 jptrainor Exp $
// $Name:  $

#ifndef _Aif2XtlSeqEditVisitor_h_
#define _Aif2XtlSeqEditVisitor_h_

#include <Aif2XtlParseTreeVisitor.h>
#include <Aif2XtlParseTreeNodes.h>

class Aif2XtlSeqEditVisitor : public Aif2XtlParseTreeVisitor {
public:
	Aif2XtlSeqEditVisitor( std::wostream& logStream );
	virtual ~Aif2XtlSeqEditVisitor();

	virtual void PreOrderVisit( Aif2XtlSequence& node );
	virtual void PostOrderVisit( Aif2XtlSequence& node );

	virtual void PreOrderVisit( Aif2XtlSourceClipNode& node );
	virtual void PostOrderVisit( Aif2XtlSourceClipNode& node );

private:
	
	void ProcessTransition( AifParseTreeNode& nodeA, IAAFSegmentSP spSegmentA,
				AifParseTreeNode& nodeB, IAAFTransitionSP spTransitionB,
				AifParseTreeNode& nodeC, IAAFSegmentSP spSegmentC );

	void ProcessCut( AifParseTreeNode& nodeA, IAAFSegmentSP spSegmentA,
			 AifParseTreeNode& nodeB, IAAFSegmentSP spSegmentB );

	void ProcessSingle( AifParseTreeNode& node, IAAFSegmentSP spSegment );

	// This is the position of a single segment in a sequence.
	// It is used as a temporary variable when processing the segments
	// in a single sequence.
	aafPosition_t _position;
};

#endif
