// Copyright 2003 BBC Technology

// $Id: Aif2XtlSeqOffsetVisitor.h,v 1.1 2004/11/20 21:14:38 jptrainor Exp $
// $Name:  $

#ifndef _Aif2XtlSeqOffsetVisitor_h_
#define _Aif2XtlSeqOffsetVisitor_h_

#include <Aif2XtlParseTreeVisitor.h>
#include <Aif2XtlParseTreeNodes.h>

class Aif2XtlSeqOffsetVisitor : public Aif2XtlParseTreeVisitor {
public:
	Aif2XtlSeqOffsetVisitor( std::wostream& logStream );
	virtual ~Aif2XtlSeqOffsetVisitor();

	virtual void PreOrderVisit( Aif2XtlSourceClipNode& node );
	virtual void PostOrderVisit( Aif2XtlSourceClipNode& node );

private:

	void PreVisit( AifParseTreeNode& node );
	void PostVisit( AifParseTreeNode& node );

	aafLength_t _offset;	
};

#endif
