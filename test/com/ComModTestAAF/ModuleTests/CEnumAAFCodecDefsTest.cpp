//=---------------------------------------------------------------------=
//
// $Id: CEnumAAFCodecDefsTest.cpp,v 1.33 2009/06/01 11:47:14 stuart_hc Exp $ $Name:  $
//
// The contents of this file are subject to the AAF SDK Public Source
// License Agreement Version 2.0 (the "License"); You may not use this
// file except in compliance with the License.  The License is available
// in AAFSDKPSL.TXT, or you may obtain a copy of the License from the
// Advanced Media Workflow Association, Inc., or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.  Refer to Section 3.3 of the License for proper use
// of this Exhibit.
//
// WARNING:  Please contact the Advanced Media Workflow Association,
// Inc., for more information about any additional licenses to
// intellectual property covering the AAF Standard that may be required
// to create and distribute AAF compliant products.
// (http://www.amwa.tv/policies).
//
// Copyright Notices:
// The Original Code of this file is Copyright 1998-2009, licensor of the
// Advanced Media Workflow Association.  All rights reserved.
//
// The Initial Developer of the Original Code of this file and the
// licensor of the Advanced Media Workflow Association is
// Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

#include "AAF.h"

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <wchar.h>

#include "AAFStoredObjectIDs.h"
#include "AAFResult.h"
#include "ModuleTest.h"
#include "AAFDataDefs.h"
#include "AAFDefUIDs.h"
#include "AAFClassDefUIDs.h"
#include "AAFCodecDefs.h"
#include "AAFContainerDefs.h"

#include "CAAFBuiltinDefs.h"

// convenient error handlers.
inline void checkResult(HRESULT r)
{
  if (FAILED(r))
    throw r;
}
inline void checkExpression(bool expression, HRESULT r)
{
  if (!expression)
    throw r;
}

static const wchar_t *sName1 = L"Test Descriptor Name1";
static const wchar_t *sDescription1 = L"Test Descriptor Description1";
static const wchar_t *sName2 = L"Test Descriptor Name2";
static const wchar_t *sDescription2 = L"Test Descriptor Description2";
// {E4E190C9-EA4A-11d3-A352-009027DFCA6A}
static const aafUID_t TESTID_2 = 
{ 0xe4e190c9, 0xea4a, 0x11d3, { 0xa3, 0x52, 0x0, 0x90, 0x27, 0xdf, 0xca, 0x6a } };


static HRESULT CreateAAFFile(
    aafWChar * pFileName,
    aafUID_constref fileKind,
    testRawStorageType_t rawStorageType,
    aafProductIdentification_constref productID)
{
	IAAFFile*			pFile = NULL;
	IAAFHeader *		pHeader = NULL;
	IAAFDictionary*		pDictionary = NULL;
	IAAFCodecDef*	pCodecDef = NULL;
	IAAFClassDef*		pClass = NULL;
	bool				bFileOpen = false;
	HRESULT				hr = S_OK;
	aafUID_t			uid;
/*	long				test;
*/

  try
  {
    // Remove the previous test file if any.
    RemoveTestFile(pFileName);


	// Create the AAF file
	checkResult(CreateTestFile( pFileName, fileKind, rawStorageType, productID, &pFile ));
	bFileOpen = true;

	// We can't really do anthing in AAF without the header.
	checkResult(pFile->GetHeader(&pHeader));

    // Get the AAF Dictionary so that we can create valid AAF objects.
    checkResult(pHeader->GetDictionary(&pDictionary));
	CAAFBuiltinDefs defs (pDictionary);
    
	checkResult(defs.cdCodecDef()->
				CreateInstance(IID_IAAFCodecDef, 
							   (IUnknown **)&pCodecDef));
    
	checkResult(pCodecDef->AddEssenceKind (defs.ddkAAFMatte()));
	uid = kAAFNoCodec;
	checkResult(pCodecDef->Initialize (uid, sName1, sDescription1));
	checkResult(pDictionary->LookupClassDef(kAAFClassID_EssenceDescriptor, &pClass));
	checkResult(pCodecDef->SetFileDescriptorClass (pClass));
	checkResult(pDictionary->RegisterCodecDef(pCodecDef));
	pCodecDef->Release();
	pCodecDef = NULL;
	checkResult(defs.cdCodecDef()->
				CreateInstance(IID_IAAFCodecDef, 
							   (IUnknown **)&pCodecDef));
    
	checkResult(pCodecDef->AddEssenceKind (defs.ddkAAFMatte()));
	uid = TESTID_2;
	checkResult(pCodecDef->Initialize (uid, sName2, sDescription2));
	checkResult(pCodecDef->SetFileDescriptorClass (pClass));

	checkResult(pDictionary->RegisterCodecDef(pCodecDef));
  }
  catch (HRESULT& rResult)
  {
    hr = rResult;
  }


  // Cleanup and return
  if (pCodecDef)
    pCodecDef->Release();

  if (pDictionary)
    pDictionary->Release();

  if (pHeader)
    pHeader->Release();
      
  if (pClass)
    pClass->Release();
      
  if (pFile)
  {  // Close file
    if (bFileOpen)
	{
		pFile->Save();
		pFile->Close();
	}
     pFile->Release();
  }

  return hr;
}

static HRESULT ReadAAFFile(aafWChar* pFileName)
{
	IAAFFile*			pFile = NULL;
	IAAFHeader*			pHeader = NULL;
	IAAFDictionary*		pDictionary = NULL;
	IEnumAAFCodecDefs *pPlug = NULL;
	IEnumAAFCodecDefs *pClonePlug = NULL;
	IAAFDefObject*		pDef = NULL;
	IAAFCodecDef*	pCodecDef = NULL;
	IAAFCodecDef*	pArray[2] = { NULL, NULL };
	IAAFCodecDef**	pArrayDef = pArray;
	bool				bFileOpen = false;
	HRESULT				hr = S_OK;
	wchar_t				testString[256];
	aafUInt32			resultCount;

	try
	{
		// Open the AAF file
		checkResult(AAFFileOpenExistingRead(pFileName, 0, &pFile));
		bFileOpen = true;

		// Get the AAF file header.
		checkResult(pFile->GetHeader(&pHeader));

		checkResult(pHeader->GetDictionary(&pDictionary));
	
		checkResult(pDictionary->GetCodecDefs(&pPlug));
		/* Read and check the first element */
		checkResult(pPlug->NextOne(&pCodecDef));
		checkResult(pCodecDef->QueryInterface (IID_IAAFDefObject,
                                          (void **)&pDef));

		checkResult(pDef->GetName (testString, sizeof(testString)));
		checkExpression (wcscmp(testString, sName1) == 0, AAFRESULT_TEST_FAILED);
		pCodecDef->Release();
		pCodecDef = NULL;
		pDef->Release();
		pDef = NULL;

		/* Read and check the second element */
		checkResult(pPlug->NextOne(&pCodecDef));
		checkResult(pCodecDef->QueryInterface (IID_IAAFDefObject,
                                          (void **)&pDef));

		checkResult(pDef->GetName (testString, sizeof(testString)));
		checkExpression (wcscmp(testString, sName2) == 0, AAFRESULT_TEST_FAILED);
		pCodecDef->Release();
		pCodecDef = NULL;
		pDef->Release();
		pDef = NULL;
		/* Reset, and check the first element again*/
		checkResult(pPlug->Reset());
		checkResult(pPlug->NextOne(&pCodecDef));
		checkResult(pCodecDef->QueryInterface (IID_IAAFDefObject,
                                          (void **)&pDef));

		checkResult(pDef->GetName (testString, sizeof(testString)));
		checkExpression (wcscmp(testString, sName1) == 0, AAFRESULT_TEST_FAILED);
		pCodecDef->Release();
		pCodecDef = NULL;
		pDef->Release();
		pDef = NULL;
		/* Reset, Skip, and check the second element again*/
		checkResult(pPlug->Reset());
		checkResult(pPlug->Skip(1));
		checkResult(pPlug->NextOne(&pCodecDef));
		checkResult(pCodecDef->QueryInterface (IID_IAAFDefObject,
                                          (void **)&pDef));

		checkResult(pDef->GetName (testString, sizeof(testString)));
		checkExpression (wcscmp(testString, sName2) == 0, AAFRESULT_TEST_FAILED);
		pCodecDef->Release();
		pCodecDef = NULL;
		pDef->Release();
		pDef = NULL;
		/* Reset, and read both elements */
		checkResult(pPlug->Reset());
		checkResult(pPlug->Next (2, (IAAFCodecDef **)&pArray, &resultCount));
		checkExpression (resultCount == 2, AAFRESULT_TEST_FAILED);
		checkResult(pArrayDef[0]->QueryInterface (IID_IAAFDefObject,
                                          (void **)&pDef));

		checkResult(pDef->GetName (testString, sizeof(testString)));
		checkExpression (wcscmp(testString, sName1) == 0, AAFRESULT_TEST_FAILED);
		pDef->Release();
		pDef = NULL;
		checkResult(pArrayDef[1]->QueryInterface (IID_IAAFDefObject,
                                          (void **)&pDef));

		checkResult(pDef->GetName (testString, sizeof(testString)));
		checkExpression (wcscmp(testString, sName2) == 0, AAFRESULT_TEST_FAILED);
		pDef->Release();
		pDef = NULL;
		pArrayDef[0]->Release();
		pArrayDef[0] = NULL;
		pArrayDef[1]->Release();
		pArrayDef[1] = NULL;
		/* Read one past to make sure that it fails */
		checkExpression(pPlug->NextOne(&pCodecDef) != AAFRESULT_SUCCESS, AAFRESULT_TEST_FAILED);
		/* Clone the enumerator, and read one element */
		checkResult(pPlug->Clone(&pClonePlug));
		checkResult(pClonePlug->Reset());
		checkResult(pClonePlug->NextOne(&pCodecDef));
		checkResult(pCodecDef->QueryInterface (IID_IAAFDefObject,
                                          (void **)&pDef));

		checkResult(pDef->GetName (testString, sizeof(testString)));
		checkExpression (wcscmp(testString, sName1) == 0, AAFRESULT_TEST_FAILED);
		pCodecDef->Release();
		pCodecDef = NULL;
		pDef->Release();
		pDef = NULL;
	}
	catch (HRESULT& rResult)
	{
		hr = rResult;
	}

	// Cleanup and return
	if (pHeader)
		pHeader->Release();
      
	if (pDictionary)
		pDictionary->Release();
      
	if (pPlug)
		pPlug->Release();

	if (pClonePlug)
		pClonePlug->Release();

	if (pDef)
		pDef->Release();
      
	if (pCodecDef)
		pCodecDef->Release();
            
	if (pArray[0])
		pArray[0]->Release();
	if (pArray[1])
		pArray[1]->Release();
            
	if (pFile)
	{  // Close file
		if (bFileOpen)
			pFile->Close();
		pFile->Release();
	}

	return hr;
}
 

extern "C" HRESULT CEnumAAFCodecDefs_test(
    testMode_t mode,
    aafUID_t fileKind,
    testRawStorageType_t rawStorageType,
    aafProductIdentification_t productID);
extern "C" HRESULT CEnumAAFCodecDefs_test(
    testMode_t mode,
    aafUID_t fileKind,
    testRawStorageType_t rawStorageType,
    aafProductIdentification_t productID)
{
	HRESULT hr = AAFRESULT_NOT_IMPLEMENTED;
	const size_t fileNameBufLen = 128;
	aafWChar pFileName[ fileNameBufLen ] = L"";
	GenerateTestFileName( productID.productName, fileKind, fileNameBufLen, pFileName );

	try
	{
		if(mode == kAAFUnitTestReadWrite)
			hr = CreateAAFFile(pFileName, fileKind, rawStorageType, productID);
		else
			hr = AAFRESULT_SUCCESS;
		if (SUCCEEDED(hr))
			hr = ReadAAFFile(pFileName);
	}
	catch (...)
	{
		cerr << "CEnumAAFCodecDefs_test..."
			 << "Caught general C++ exception!" << endl; 
		hr = AAFRESULT_TEST_FAILED;
	}

	return hr;
}
