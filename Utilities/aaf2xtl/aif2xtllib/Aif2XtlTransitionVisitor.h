// Copyright 2003 BBC Technology

// $Id: Aif2XtlTransitionVisitor.h,v 1.1 2004/11/20 21:14:38 jptrainor Exp $
// $Name:  $

#ifndef _Aif2XtlTransitionVisitor_h_
#define _Aif2XtlTransitionVisitor_h_

#include <Aif2XtlParseTreeVisitor.h>
#include <Aif2XtlParseTreeNodes.h>

class Aif2XtlTransitionVisitor : public Aif2XtlParseTreeVisitor {
public:
	Aif2XtlTransitionVisitor( bool cutsOnly, std::wostream& logStream );
	virtual ~Aif2XtlTransitionVisitor();

	virtual void PreOrderVisit( Aif2XtlTransition& node );
	virtual void PostOrderVisit( Aif2XtlTransition& node );

private:
	bool _cutsOnly;
};

#endif
