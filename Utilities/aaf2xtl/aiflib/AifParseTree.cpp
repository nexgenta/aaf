// Copyright 2003 BBC Technology

// $Id: AifParseTree.cpp,v 1.1 2004/11/20 21:14:38 jptrainor Exp $
// $Name:  $

#include <AifParseTree.h>

AifParseTree::AifParseTree(  std::auto_ptr<AifParseTreeNode> root )
: _root( root )
{}

AifParseTree::~AifParseTree()
{}

void AifParseTree::Traverse( AifParseTreeVisitor* visitor )
{
	_root->Visit( visitor );
}
