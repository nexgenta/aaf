// Copyright 2003 BBC Technology

// $Id: AifParseTreeVisitor.h,v 1.1 2004/11/20 21:14:38 jptrainor Exp $
// $Name:  $

#ifndef _AifParseTreeVisitor_h_
#define _AifParseTreeVisitor_h_

class AifParseTreeNode;

class AifParseTreeVisitor {
public:
	AifParseTreeVisitor();
	virtual ~AifParseTreeVisitor();
	virtual void PreOrderVisit( AifParseTreeNode& node );
	virtual void PostOrderVisit( AifParseTreeNode& node );
};

#endif
