// Copyright 2003 BBC Technology

// $Id: Aif2XtlSourceClipVisitor.h,v 1.1 2004/11/20 21:14:38 jptrainor Exp $
// $Name:  $

#ifndef _Aif2XtlSourceClipVisitor_h_
#define _Aif2XtlSourceClipVisitor_h_

#include <Aif2XtlParseTreeVisitor.h>
#include <Aif2XtlParseTreeNodes.h>

#include <AifParseTreeVisitor.h>

class AifParseTreeNodeFactory;

class Aif2XtlSourceClipVisitor : public Aif2XtlParseTreeVisitor {
public:
	Aif2XtlSourceClipVisitor( AifParseTreeNodeFactory& nodeFactory,
							  std::wostream& logStream );

	virtual ~Aif2XtlSourceClipVisitor();

	virtual void PreOrderVisit( Aif2XtlSourceClipNode& node );

	virtual void PostOrderVisit( Aif2XtlSourceClipNode& node );

private:

	AifParseTreeNodeFactory& _nodeFactory;
};

#endif

