/***********************************************************************
*
*              Copyright (c) 1998-2000 Avid Technology, Inc.
*
* Permission to use, copy and modify this software and accompanying
* documentation, and to distribute and sublicense application software
* incorporating this software for any purpose is hereby granted,
* provided that (i) the above copyright notice and this permission
* notice appear in all copies of the software and related documentation,
* and (ii) the name Avid Technology, Inc. may not be used in any
* advertising or publicity relating to the software without the specific,
* prior written permission of Avid Technology, Inc.
*
* THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
* EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
* WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
* IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
* SPECIAL, INCIDENTAL, PUNITIVE, INDIRECT, ECONOMIC, CONSEQUENTIAL OR
* OTHER DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE AND
* ACCOMPANYING DOCUMENTATION, INCLUDING, WITHOUT LIMITATION, DAMAGES
* RESULTING FROM LOSS OF USE, DATA OR PROFITS, AND WHETHER OR NOT
* ADVISED OF THE POSSIBILITY OF DAMAGE, REGARDLESS OF THE THEORY OF
* LIABILITY.
*
************************************************************************/

// @doc OMINTERNAL
#ifndef OMPROPERTYTABLE_H
#define OMPROPERTYTABLE_H

#include "OMDataTypes.h"

#include "OMVector.h"

  // @class Persistent tables of property instance names.
class OMPropertyTable {
public:
  // @access Public members.

    // @cmember Constructor.
  OMPropertyTable(void);

    // @cmember Destructor.
  ~OMPropertyTable(void);

    // @cmember If <p propertyName> is not already present then insert
    //          it (by copying) into the table and return its tag,
    //          otherwise just return its tag. Tags are allocated
    //          sequentially.
  OMPropertyTag insert(const wchar_t* propertyName);

    // @cmember The property name corresponding to <p tag> in the table.
  const wchar_t* valueAt(OMPropertyTag tag) const;

    // @cmember The count of entries in the table.
  size_t count(void) const;

    // @cmember Is <p tag> valid ?
  bool isValid(OMPropertyTag tag) const;

private:

  OMVector<wchar_t*> _vector;

};

#endif
