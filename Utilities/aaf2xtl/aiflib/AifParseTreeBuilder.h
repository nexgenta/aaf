// Copyright 2003 BBC Technology

// $Id: AifParseTreeBuilder.h,v 1.1 2004/11/20 21:14:38 jptrainor Exp $
// $Name:  $

#include <AxSmartPointer.h>

class AifParseTree;
class AifParseTreeNode;
class AifParseTreeNodeFactory;

class AifParseTreeBuilderAcceptFunc {
public:
	virtual bool operator()( IAAFObjectSP spObject ) = 0;
};

class AifParseTreeBuilderAcceptAll : public AifParseTreeBuilderAcceptFunc {
public:
	virtual ~AifParseTreeBuilderAcceptAll()
		{}
	virtual bool operator()( IAAFObjectSP spObject )
		{ return true; }
};

void
AifBuildParseTree( IAAFObjectSP spSubTreeRootObject, 
		   AifParseTreeNode* pParent,
		   AifParseTreeNodeFactory& nodeFactory,
		   AifParseTreeBuilderAcceptFunc& acceptFunc = AifParseTreeBuilderAcceptAll() );


std::auto_ptr<AifParseTreeNode> AifBuildParseTree( IAAFObjectSP spSubTreeRootObject,
						   AifParseTreeNodeFactory& nodeFactory,
						   AifParseTreeBuilderAcceptFunc& acceptFunc = AifParseTreeBuilderAcceptAll() );
