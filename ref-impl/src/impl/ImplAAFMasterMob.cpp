/***********************************************************************
 *
 *              Copyright (c) 1998-1999 Avid Technology, Inc.
 *
 * Permission to use, copy and modify this software and accompanying 
 * documentation, and to distribute and sublicense application software
 * incorporating this software for any purpose is hereby granted, 
 * provided that (i) the above copyright notice and this permission
 * notice appear in all copies of the software and related documentation,
 * and (ii) the name Avid Technology, Inc. may not be used in any
 * advertising or publicity relating to the software without the specific,
 *  prior written permission of Avid Technology, Inc.
 *
 * THE SOFTWARE IS PROVIDED AS-IS AND WITHOUT WARRANTY OF ANY KIND,
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

#include "ImplAAFSourceClip.h"
#include "ImplAAFSourceMob.h"
#include "ImplAAFComponent.h"
#include "ImplAAFDataDef.h"
#include "ImplAAFFindSourceInfo.h"
#include "ImplAAFMasterMob.h"
#include "ImplAAFHeader.h"
#include "ImplAAFContentStorage.h"
#include "ImplAAFObjectCreation.h"
#include "ImplEnumAAFMobSlots.h"
#include "ImplAAFEssenceAccess.h"
#include <assert.h>
#include "AAFResult.h"
#include "aafCvt.h"
#include "aafUtils.h"

#include "AAFStoredObjectIDs.h"
#include "AAFPropertyIDs.h"
#include "ImplAAFEssenceGroup.h"

extern "C" const aafClassID_t CLSID_AAFEssenceAccess;

ImplAAFMasterMob::ImplAAFMasterMob ()
{}


ImplAAFMasterMob::~ImplAAFMasterMob ()
{}


AAFRESULT STDMETHODCALLTYPE
ImplAAFMasterMob::Initialize ()
{
  return AAFRESULT_SUCCESS;
}


//***********************************************************
//
// AddMasterSlot()
//
// This function adds a slot to the specified Master Mob that
// references the specified a slot in the specified Source Mob. The
// new slot in the Master Mob contains a Source Clip that specifies
// the Source Mob in its source reference properties.
//
// The dataDef parameter requires a data kind valid for a media
// stream. Valid data kinds are:
//
// - DDEF_Picture
// - DDEF_Sound
//
// Note: If pSlotName is passed in with zero length, then the
// slot is not assigned a name.  Slot names are not used by the
// SDK, and exist only so the user can name slots.
// 
// Succeeds if all of the following are true:
// (more conditions here)
// 
// If this method fails no state is changed.
// 
// This method will return the following codes.  If more than one of
// the listed errors is in effect, it will return the first one
// encountered in the order given below:
// 
// AAFRESULT_SUCCESS
//   - succeeded.  (This is the only code indicating success.)
//
// AAFRESULT_NULL_PARAM
//   - One or more of the following parameters are NULL pSourceMob,
//     pDataDef, and pSlotName.
//
// AAFRESULT_INVALID_DATADEF
//   - The data kind of the source MOB slot to be added to the Master
//     Mob does not match what is specfied in pDataDef.
//
// AAFRESULT_SLOT_NOTFOUND
//   - The specified Source Mob slot was not found.
//
// AAFRESULT_SLOT_EXISTS
//   - The specified Master slot ID already exists.
//
// 
AAFRESULT STDMETHODCALLTYPE
    ImplAAFMasterMob::AddMasterSlot (const aafUID_t &	dataDef,
									 aafSlotID_t		sourceSlotID,
									 ImplAAFSourceMob*	pSourceMob,
									 aafSlotID_t		masterSlotID,
									 const aafWChar*	pSlotName)
{
	aafLength_t	slotLength;
	aafUID_t	sourceMobID;
	HRESULT		hr = AAFRESULT_SUCCESS;
	ImplAAFMobSlot*	pMobSlot;
	ImplAAFTimelineMobSlot* pTimelineMobSlot = NULL;
	aafUID_t	segDataDef;
	ImplAAFSegment*	pSegment = NULL;
	ImplAAFSourceClip*	pSrcClip = NULL;
	aafSourceRef_t		ref;
	aafPosition_t		zeroPos;
	ImplAAFTimelineMobSlot	*pNewTimelineSlot = NULL;
	aafRational_t  editRate;
  ImplAAFDictionary *pDictionary = NULL;


	if (!pSourceMob || !pSlotName)
		return AAFRESULT_NULL_PARAM;

	XPROTECT()
	{
		// Get the slot length and mob id.  Verify that data kind
		// of the slot is the same as dataDef
		CHECK(pSourceMob->GetMobID(&sourceMobID));

		CHECK(pSourceMob->FindSlotBySlotID(sourceSlotID, &pMobSlot));
		pTimelineMobSlot = dynamic_cast<ImplAAFTimelineMobSlot *>(pMobSlot);
		if (NULL == pTimelineMobSlot)
			RAISE(AAFRESULT_SLOT_NOT_FOUND); // please use the correct error code!
//		CHECK(pMobSlot->QueryInterface(IID_IAAFTimelineMobSlot,(void **) &pTimelineMobSlot));
		CHECK(pTimelineMobSlot->GetEditRate(&editRate));

		CHECK(pMobSlot->GetSegment(&pSegment));

		pSegment->GetLength(&slotLength);
		pSegment->GetDataDef(&segDataDef);
		pSegment->ReleaseReference();
		pSegment = NULL;

		// Make sure the slot contains the expected media type.
		if (!EqualAUID(&segDataDef, &dataDef))
			RAISE(AAFRESULT_INVALID_DATADEF);

		pMobSlot->ReleaseReference();
		pMobSlot = NULL;

	// Add the master slot

		CvtInt32toPosition(0, zeroPos);
		ref.sourceID = sourceMobID;
		ref.sourceSlotID = sourceSlotID;
		ref.startTime = zeroPos;
		CHECK(GetDictionary(&pDictionary));
		pSrcClip = (ImplAAFSourceClip *)pDictionary->CreateImplObject(AUID_AAFSourceClip);
		if(pSrcClip == NULL)
			RAISE(E_FAIL);
		pDictionary->ReleaseReference();
		pDictionary = NULL;

		CHECK(pSrcClip->Initialize(dataDef, slotLength, ref));
		CHECK(AppendNewTimelineSlot(editRate,pSrcClip, masterSlotID, pSlotName, 
									zeroPos,&pNewTimelineSlot));

		pNewTimelineSlot->ReleaseReference();
		pNewTimelineSlot = NULL;

		pSrcClip->ReleaseReference();
		pSrcClip = NULL;
	}
	XEXCEPT
	{
		if(pNewTimelineSlot != NULL)
			pNewTimelineSlot->ReleaseReference();
		if(pSegment != NULL)
			pSegment->ReleaseReference();
		if(pMobSlot != NULL)
			pMobSlot->ReleaseReference();
		if(pSrcClip != NULL)
			pSrcClip->ReleaseReference();
		if(pDictionary != NULL)
			pDictionary->ReleaseReference();
	}
	XEND;
	return hr;
}

//***********************************************************
//
// GetTapeName()
//
// Finds the videotape Source Mob associated with a Master Mob slot
// and writes the name of the videotape, which is stored in the
// Mobs Name property, into the pTapeName buffer.  The buffer is
// allocated by the caller.  The size of the buffer is given by
// bufSize.  If the property name has not yet been set, a
// zero-length string will be written (that is, only the trailing
// null character).
// 
// Caller may call GetTapeNameBufLen() to determine the required
// buffer size.
// 
// Succeeds if all of the following are true:
// - the pTapeName pointer is valid.
// - bufSize indicates the buffer is large enough to hold the name.
// 
// If this method fails nothing will be written to *pTapeName.
// 
// This method will return the following codes.  If more than one of
// the listed errors is in effect, it will return the first one
// encountered in the order given below:
// 
// AAFRESULT_SUCCESS
//   - succeeded.  (This is the only code indicating success.)
//
// AAFRESULT_NULL_PARAM
//   - pTapeName arg is NULL.
//
// AAFRESULT_SLOT_NOTFOUND
//   - The specified Master Slot was not found.
//
// AAFRESULT_NOT_TAPEMOB
//   - The specified Master Slot does not contain a Tape MOB.
//
// AAFRESULT_SMALLBUF
//   - bufSize indicates the buffer is too small to hold the string.
//
// 
AAFRESULT STDMETHODCALLTYPE
    ImplAAFMasterMob::GetTapeName (aafInt32		masterSlotID,
								   aafWChar*	pTapeName,
								   aafInt32		bufSize)
{
	ImplAAFFindSourceInfo	*info = NULL;
	ImplAAFMob				*mob = NULL;

	XPROTECT()
	{
		CHECK(SearchSource (masterSlotID, 0, kTapeMob, NULL, NULL,
									&info));
		CHECK(info->GetMob(&mob));
		CHECK(mob->GetName(pTapeName, bufSize));
		info->ReleaseReference();
		info = NULL;
		mob->ReleaseReference();
		mob = NULL;
	}
	XEXCEPT
	{
		if(info != NULL)
			info->ReleaseReference();
		if(mob != NULL)
			mob->ReleaseReference();
	}
	XEND;

	return AAFRESULT_SUCCESS;
}


//***********************************************************
//
// GetTapeNameBufLen()
//
// Returns the length of buffer required for the GetTapeName()
// method.  The value is placed into the location specified by pLen.
// The value will include space required for the trailing null
// character.
//
// Succeeds if all of the following are true:
// - the pLen pointer is valid.
//
// If this method fails nothing will be written to *pLen.
//
// This method will return the following codes.  If more than one of
// the listed errors is in effect, it will return the first one
// encountered in the order given below:
// 
// AAFRESULT_SUCCESS
//   - succeeded.  (This is the only code indicating success.)
//
// AAFRESULT_NULL_PARAM
//   - pLen arg is NULL.
//
// AAFRESULT_SLOT_NOTFOUND
//   - The specified Master Slot was not found.
//
// AAFRESULT_NOT_TAPEMOB
//   - The specified Master Slot does not contain a Tape MOB.
//
// 
AAFRESULT STDMETHODCALLTYPE
    ImplAAFMasterMob::GetTapeNameBufLen (aafInt32	masterSlotID,
										 aafInt32*  pLen)
{
	ImplAAFFindSourceInfo	*info = NULL;
	ImplAAFMob				*mob = NULL;

	if(pLen == NULL)
		return AAFRESULT_NULL_PARAM;
	
	XPROTECT()
	{
		CHECK(SearchSource (masterSlotID, 0, kTapeMob, NULL, NULL,
									&info));
		CHECK(info->GetMob(&mob));
		CHECK(mob->GetNameBufLen(pLen));
		info->ReleaseReference();
		info = NULL;
		mob->ReleaseReference();
		mob = NULL;
	}
	XEXCEPT
	{
		if(info != NULL)
			info->ReleaseReference();
		if(mob != NULL)
			mob->ReleaseReference();
	}
	XEND;

	return AAFRESULT_SUCCESS;
}

//***********************************************************
//
// GetNumRepresentations()
//
// This function returns the number of media representations
// available for the specified SlotID on a specified Master
// Mob.
//
// Succeeds if all of the following are true:
// - the pNumReps pointer is valid.
//
// If this method fails nothing will be written to *pLen.
//
// This method will return the following codes.  If more than one of
// the listed errors is in effect, it will return the first one
// encountered in the order given below:
// 
// AAFRESULT_SUCCESS
//   - succeeded.  (This is the only code indicating success.)
//
// AAFRESULT_NULL_PARAM
//   - pNumReps arg is NULL.
//
// AAFRESULT_SLOT_NOTFOUND
//   - The specified Master Slot was not found.
//
// 
AAFRESULT STDMETHODCALLTYPE
    ImplAAFMasterMob::GetNumRepresentations (aafSlotID_t	slotID,
											 aafNumSlots_t*	pNumReps)
{
	ImplAAFMobSlot	*pSlot = NULL;
  ImplAAFSegment	*pSegment = NULL;
	HRESULT			hr;
	
	if (!pNumReps)
		return AAFRESULT_NULL_PARAM;

	*pNumReps = 0;
	
	hr = FindSlotBySlotID(slotID, &pSlot);
	if (SUCCEEDED(hr))
	{
		hr = pSlot->GetSegment(&pSegment);
		if (SUCCEEDED(hr))
		{
			hr = pSegment->NumRepresentations(pNumReps);
			pSegment->ReleaseReference();
			pSegment = NULL;
		}
		pSlot->ReleaseReference();
		pSlot = NULL;
	}

	return hr;
}

//***********************************************************
//
// GetRepresentationSourceClip()
//
// This method returns the indexed media representation for the specified
// Master Mob, SlotID, and index.  This call is meant to work
// with GetNumRepresentations, so that you can iterate through all
// of the choices yourself.  This method uses an integer index, not
// an iterator.  The function GetRepresentationSourceClip takes an
// index between 1 and the number of representations [inclusive],
// and returns the indexed Source Mob.
//
// Succeeds if all of the following are true:
// - the ppSourceClip pointer is valid.
//
// If this method fails nothing will be written to *ppSourceClip.
//
// This method will return the following codes.  If more than one of
// the listed errors is in effect, it will return the first one
// encountered in the order given below:
// 
// AAFRESULT_SUCCESS
//   - succeeded.  (This is the only code indicating success.)
//
// AAFRESULT_NULL_PARAM
//   - ppSourceClip arg is NULL.
//
// AAFRESULT_SLOT_NOTFOUND
//   - The specified Master Slot was not found.
//
// AAFRESULT_BADINDEX
//   - No Source Mob at specified index.
//
// AAFRESULT_MISSING_MEDIA_REP
//   - TODO: add this to idl
//
AAFRESULT STDMETHODCALLTYPE
    ImplAAFMasterMob::GetRepresentationSourceClip (aafSlotID_t			slotID,
												   aafUInt32				index,
												   ImplAAFSourceClip**	ppSourceClip)
{
	ImplAAFMobSlot	*pSlot = NULL;
	ImplAAFSegment	*pSegment = NULL;
	ImplAAFEssenceGroup	*pGroup = NULL;
	HRESULT			hr;
	aafNumSlots_t	numReps;

	if (!ppSourceClip)
		return AAFRESULT_NULL_PARAM;

	numReps = 0;
	
	hr = FindSlotBySlotID(slotID, &pSlot);
	if (SUCCEEDED(hr))
	{
		hr = pSlot->GetSegment(&pSegment);
		if (SUCCEEDED(hr))
		{
			hr = pSegment->NumRepresentations(&numReps);
			if(index < 0 || index >= numReps)
				return(AAFRESULT_BADINDEX);
			pGroup = dynamic_cast<ImplAAFEssenceGroup*>(pSegment);
			if(pGroup == NULL)
				return(AAFRESULT_INCONSISTANCY);
			hr = pGroup->GetIndexedChoice (index, ppSourceClip);
			pGroup->ReleaseReference();
			pGroup = NULL;
			pSegment->ReleaseReference();
			pSegment = NULL;
		}
		pSlot->ReleaseReference();
		pSlot = NULL;
	}

	return hr;
}

//***********************************************************
//
// GetCriteriaSourceClip()
//
// Returns the Source Clip on the specified slot of a Master Mob
// that references the Source Mob that best meets the specified
// criteria.  This function will work whether multiple media
// representations exist or not.
//
// Note:
// The aafMediaCriteria_t is defined as the following structure:
// typedef struct
// {
//	aafCriteriaType_t type;
//	aafCriteriaProc_t proc;
// } aafMediaCriteria_t;
// 
// Note:
// The type field can have one of the following values: |
// typedef enum
// {
//	kAAFAnyRepresentation = 0,
//	kAAFFastestRepresentation,
//	kAAFBestFidelityRepresentation,
//	kAAFSmallestRepresentation,
//	kAAFUseRepresentationProc
// } aafCriteriaType_t;
//
// Succeeds if all of the following are true:
// - the ppSourceClip pointer is valid.
//
// If this method fails nothing will be written to *ppSourceClip.
//
// This method will return the following codes.  If more than one of
// the listed errors is in effect, it will return the first one
// encountered in the order given below:
// 
// AAFRESULT_SUCCESS
//   - succeeded.  (This is the only code indicating success.)
//
// AAFRESULT_NULL_PARAM
//   - ppSourceClip arg is NULL.
//
// AAFRESULT_SLOT_NOTFOUND
//   - The specified Master Slot was not found.
//
// 
AAFRESULT STDMETHODCALLTYPE
    ImplAAFMasterMob::GetCriteriaSourceClip (aafSlotID_t			slotID,
											 aafMediaCriteria_t*	pCriteria,
											 ImplAAFSourceClip**	ppSourceClip)
{
	ImplAAFMobSlot	*pSlot = NULL;
	ImplAAFSegment	*pSegment = NULL;
	ImplAAFEssenceGroup	*pGroup = NULL;
	HRESULT			hr;
	aafNumSlots_t	numReps;

	if (!ppSourceClip || !pCriteria)
		return AAFRESULT_NULL_PARAM;

	numReps = 0;
	
	hr = FindSlotBySlotID(slotID, &pSlot);
	if (SUCCEEDED(hr))
	{
		hr = pSlot->GetSegment(&pSegment);
		if (SUCCEEDED(hr))
		{
			hr = pSegment->NumRepresentations(&numReps);
			pGroup = dynamic_cast<ImplAAFEssenceGroup*>(pSegment);
			if(pGroup == NULL)
				return(AAFRESULT_INCONSISTANCY);
			hr = pGroup->GetCriteriaSourceClip (pCriteria, ppSourceClip);
			pGroup->ReleaseReference();
			pGroup = NULL;
			pSegment->ReleaseReference();
			pSegment = NULL;
		}
		pSlot->ReleaseReference();
		pSlot = NULL;
	}

	return hr;
}



//***********************************************************
//
// SearchSource()
//
// AAFRESULT_SUCCESS
//   - succeeded.  (This is the only code indicating success.)
//
// AAFRESULT_NULL_PARAM
//   - ppSourceClip arg is NULL.
//
// 
AAFRESULT STDMETHODCALLTYPE
    ImplAAFMasterMob::SearchSource (aafSlotID_t				slotID,
									aafPosition_t			offset,
									aafMobKind_t			mobKind,
									aafMediaCriteria_t*		pMediaCrit,
									aafOperationChoice_t*	pOperationChoice,
									ImplAAFFindSourceInfo**	ppSourceInfo)
{
	return(InternalSearchSource(slotID, offset, mobKind, pMediaCrit, pOperationChoice,
										   ppSourceInfo));
}

//***********************************************************
//
// GetMobKind()
//
// Returns kMasterMob in *pMobKind.
// 
// AAFRESULT_SUCCESS
//   - succeeded.  (This is the only code indicating success.)
//
// AAFRESULT_NULL_PARAM
//   - ppSourceClip arg is NULL.
//
// 
AAFRESULT STDMETHODCALLTYPE
    ImplAAFMasterMob::GetMobKind (aafMobKind_t *pMobKind)
{
	if(pMobKind == NULL)
		return(AAFRESULT_NULL_PARAM);
	*pMobKind = kMasterMob;

	return AAFRESULT_SUCCESS;
}

//****************
// NewPhysSourceRef()
//
AAFRESULT STDMETHODCALLTYPE
    ImplAAFMasterMob::NewPhysSourceRef (const aafRational_t & editrate,
										aafSlotID_t  aMobSlot,
										const aafUID_t & essenceKind,
										aafSourceRef_t  ref,
										aafLength_t  srcRefLength)
{
	return(ImplAAFMob::AddPhysSourceRef(kAAFForceOverwrite,
										editrate,
										aMobSlot,
										essenceKind,
										ref,
										srcRefLength));
}

//****************
// AppendPhysSourceRef()
//
AAFRESULT STDMETHODCALLTYPE
    ImplAAFMasterMob::AppendPhysSourceRef (const aafRational_t & editrate,
										   aafSlotID_t  aMobSlot,
										   const aafUID_t & essenceKind,
										   aafSourceRef_t  ref,
										   aafLength_t  srcRefLength)
{
	return(ImplAAFMob::AddPhysSourceRef(kAAFAppend,
										editrate,
										aMobSlot,
										essenceKind,
										ref,
										srcRefLength));
}




/************************
 * Function: omfsReconcileMasterMobLength (INTERNAL)
 *
 * 	Called from omfsReconcileMobLength to handle the master mob case.
 *		Given a master mob, make sure that all fields which contain the
 *		length of the mob are in agreement.  Currently only makes sure
 *		that mob length references are >= each of the track lengths.
 *
 *		Since 2.0 does not contain a redundant mob length field, this
 *		function simply returns on 2.x era files.
 *
 * Argument Notes:
 *		<none>.
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard errors (see top of file).
 */
AAFRESULT ImplAAFMasterMob::ReconcileMobLength(void)
{
	ImplAAFMob			*fileMob = NULL;
	ImplEnumAAFMobSlots	*slotIter = NULL, *fileSlotIter = NULL;
	ImplAAFMobSlot		*fileSlot = NULL, *slot = NULL;
	ImplAAFSegment		*fileSeg = NULL, *seg = NULL;
	aafUInt32			loop;
	aafNumSlots_t		numSlots, fileNumSlots;
	aafPosition_t		endPos;

	XPROTECT()
	{
		/* Adjust the SCLP length from the master mob to the length of
		 * the file mob, in the units of the master mob
		 */
		CHECK(EnumAAFAllMobSlots (&slotIter));
		CHECK(GetNumSlots(&numSlots));
		for (loop = 1; loop <= numSlots; loop++)
		{
			CHECK(slotIter->NextOne(&slot));
			CHECK(slot->GetSegment(&seg));
			CHECK(((ImplAAFSourceClip *)seg)->ResolveRef( &fileMob));
			CHECK(fileMob->GetNumSlots(&fileNumSlots));
			if(fileNumSlots >= 1)
			{
				CHECK(fileMob->EnumAAFAllMobSlots (&fileSlotIter));
				CHECK(fileSlotIter->NextOne(&fileSlot));
				CHECK(fileSlot->GetSegment(&fileSeg));
				CHECK(fileSeg->GetLength(&endPos));
				fileSeg->ReleaseReference();
				fileSeg = NULL;
				fileSlotIter->ReleaseReference();
				fileSlotIter = NULL;
			}
			else
				fileSlot = NULL;
			fileMob->ReleaseReference();
			fileMob = NULL;
			CHECK(slot->ConvertToMyRate(endPos, fileSlot, &endPos));
			if(fileSlot != NULL)
			{
				fileSlot->ReleaseReference();
				fileSlot = NULL;
			}
			slot->ReleaseReference();
			slot = NULL;
			CHECK(seg->SetLength(endPos));
			seg->ReleaseReference();
			seg = NULL;
		}			
		slotIter->ReleaseReference();
		slotIter = NULL;
	}
	XEXCEPT
	{
		if(slotIter != NULL)
			slotIter->ReleaseReference();
		if(fileSlotIter != NULL)
			fileSlotIter->ReleaseReference();
		if(fileSlot != NULL)
			fileSlot->ReleaseReference();
		if(slot != NULL)
			slot->ReleaseReference();
		if(fileSeg != NULL)
			fileSeg->ReleaseReference();
		if(seg != NULL)
			seg->ReleaseReference();
		if(fileMob != NULL)
			fileMob->ReleaseReference();
	}
	XEND
		
	return (AAFRESULT_SUCCESS);
}


/****/
AAFRESULT STDMETHODCALLTYPE
ImplAAFMasterMob::CreateEssence (aafSlotID_t		masterSlotID,
								aafUID_t			mediaKind,
								aafUID_t			codecID,
								aafRational_t	editRate,
								aafRational_t	sampleRate,
								aafCompressEnable_t  enable,
								ImplAAFLocator		*destination,
								aafUID_t			fileFormat,
								ImplAAFEssenceAccess **result)
{
	ImplAAFEssenceAccess	*access;

	access = (ImplAAFEssenceAccess *)CreateImpl (CLSID_AAFEssenceAccess);
	*result = access;

	XPROTECT()
	{
		if(destination != NULL)
		{
			CHECK(access->SetEssenceDestination(destination, fileFormat));
		}
		
		CHECK(access->Create(this, masterSlotID, mediaKind, codecID, editRate, sampleRate, enable));
	}
	XEXCEPT
	XEND;

	return(AAFRESULT_SUCCESS);
}

	//@comm Creates a single channel stream of essence.  Convenience functions
	// exist to create audio or video essence, and a separate call
	// (MultiCreate) exists to create interleaved audio and
	// video data.
	//@comm The essence handle from this call can be used with
	// WriteDataSamples  and possibly WriteDataLines, but NOT with
	// WriteMultiSamples.
	//@comm If you are creating the essence, and then attaching it to a master
	// mob, then the "masterMob" field may be left NULL.
	// For video, the sampleRate should be the edit rate of the file mob.
	// For audio, the sample rate should be the actual samples per second.
	//@comm Replaces omfmMediaCreate
	
/****/
AAFRESULT STDMETHODCALLTYPE
   ImplAAFMasterMob::CreateMultiEssence (aafUID_t codecID,
							aafInt16  arrayElemCount,
							aafmMultiCreate_t *mediaArray,
							aafCompressEnable_t Enable,
							ImplAAFLocator		*destination,
							aafUID_t			fileFormat,
							IAAFEssenceMultiAccess **result)
{
	ImplAAFEssenceAccess	*access;
	IUnknown				*iUnk = NULL;
	AAFRESULT				hr;

	access = (ImplAAFEssenceAccess *)CreateImpl (CLSID_AAFEssenceAccess);
	iUnk = static_cast<IUnknown *> (access->GetContainer());
	hr = iUnk->QueryInterface(IID_IAAFEssenceMultiAccess, (void **)result);
	if(hr != AAFRESULT_SUCCESS)
		return hr;

	iUnk->Release();
	iUnk = NULL;
	return access->MultiCreate(this, codecID, arrayElemCount, mediaArray, Enable);
}

/****/
AAFRESULT STDMETHODCALLTYPE
    ImplAAFMasterMob::GetNumChannels (
                           aafSlotID_t  slotID,
                           aafMediaCriteria_t *essenceCrit,
                           aafUID_t essenceKind,
                           aafInt16 *numCh)
{
	ImplAAFEssenceAccess	*access;

	access = (ImplAAFEssenceAccess *)CreateImpl (CLSID_AAFEssenceAccess);
	return access->GetNumChannels(this, slotID, essenceCrit, essenceKind, numCh);
}

/****/
AAFRESULT STDMETHODCALLTYPE
    ImplAAFMasterMob::OpenEssence (aafSlotID_t  slotID,
                           aafMediaCriteria_t*mediaCrit,
                           aafMediaOpenMode_t  openMode,
                           aafCompressEnable_t  compEnable,
							ImplAAFEssenceAccess **result)
{
	ImplAAFEssenceAccess	*access;

	access = (ImplAAFEssenceAccess *)CreateImpl (CLSID_AAFEssenceAccess);
	*result = access;
	return access->Open(this, slotID, mediaCrit, openMode, compEnable);
}

	//@comm If the essence is interleaved,
	// then it will be di-interleaved when samples are read.  This routine
	// follows the locator, and may call the locator failure callback if
	// the essence can not be found.  If the failure callback finds the essence,
	// then this routine will return normally.
	//@comm The essence handle from this call can be used with
	// ReadDataSamples  and possibly ReadDataLines, but NOT with
	// ReadMultiSamples.
	//@comm Possible Errors:
	// 	Standard errors (see top of file).
	// 	AAFRESULT_NOMEMORY -- couldn't allocate memory for the essence handle
	//@comm NOTE: If a locator is followed, then essencePtr may reference ANOTHER file
	// object, which must be closed on file close.
	//@comm Replaces omfmMediaOpen*/
	
/****/
AAFRESULT STDMETHODCALLTYPE
    ImplAAFMasterMob::OpenMultiEssence (aafSlotID_t slotID,
                           aafMediaCriteria_t*  mediaCrit,
                           aafMediaOpenMode_t  openMode,
                           aafCompressEnable_t  compEnable,
							IAAFEssenceMultiAccess **result)
{
	ImplAAFEssenceAccess	*access;
	IUnknown				*iUnk = NULL;
	AAFRESULT				hr;

	access = (ImplAAFEssenceAccess *)CreateImpl (CLSID_AAFEssenceAccess);
	iUnk = static_cast<IUnknown *> (access->GetContainer());
	hr = iUnk->QueryInterface(IID_IAAFEssenceMultiAccess, (void **)result);
	if(hr != AAFRESULT_SUCCESS)
		return hr;
	iUnk->Release();
	iUnk = NULL;
	return access->MultiOpen(this, slotID, mediaCrit, openMode, compEnable);
}

	//@comm This routine
	// follows the locator, and may call the locator failure callback if
	// the essence can not be found.  If the failure callback finds the essence,
	// then this routine will return normally.
	//@comm The essence handle from this call can be used with
	// WriteDataSamples or WriteMultiSamples but NOT with 
	//  WriteDataLines.
	//@comm Possible Errors:
	// 	Standard errors (see top of file).
	// 	AAFRESULT_NOMEMORY -- couldn't allocate memory for the essence handle
	//@comm Replaces omfmMediaMultiOpen*/
