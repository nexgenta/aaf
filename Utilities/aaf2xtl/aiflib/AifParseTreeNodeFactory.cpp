// Copyright 2003 BBC Technology

// $Id: AifParseTreeNodeFactory.cpp,v 1.1 2004/11/20 21:14:38 jptrainor Exp $
// $Name:  $

#include <AifParseTreeNodeFactory.h>

AifParseTreeNodeFactory::AifParseTreeNodeFactory()
{}

AifParseTreeNodeFactory::~AifParseTreeNodeFactory()
{}

std::auto_ptr<AifParseTreeNode> AifParseTreeNodeFactory::CreateNode( IAAFObjectSP sp )
{
	std::auto_ptr<AifParseTreeNode> pNode( new AifParseTreeNode(sp) );
	return pNode;
}
