INCLUDES = -I${srcdir}/../../include/ref-api \
	-I${srcdir}/../../include/OM \
	-I${srcdir}/../OM \
	-I${srcdir}/../../include \
	-I${srcdir}/com-dll \
	-I${srcdir}/../impl \
	-I${srcdir}/../../aaflib

lib_LTLIBRARIES = libcom-api.la

libcom_api_la_SOURCES = AAFCLSIDs.h AAFObjectTable.h AAFObjectTable_i.cpp \
	CAAFAES3PCMDescriptor.cpp CAAFAES3PCMDescriptor.h CAAFAIFCDescriptor.cpp \
	CAAFAIFCDescriptor.h CAAFAuxiliaryDescriptor.cpp \
	CAAFAuxiliaryDescriptor.h CAAFBWFImportDescriptor.cpp \
	CAAFBWFImportDescriptor.h CAAFCDCIDescriptor.cpp CAAFCDCIDescriptor.h \
	CAAFCachePageAllocator.cpp CAAFCachePageAllocator.h CAAFClassDef.cpp \
	CAAFClassDef.h CAAFCodecDef.cpp CAAFCodecDef.h CAAFCommentMarker.cpp \
	CAAFCommentMarker.h CAAFComponent.cpp CAAFComponent.h \
	CAAFCompositionMob.cpp CAAFCompositionMob.h CAAFConstantValue.cpp \
	CAAFConstantValue.h CAAFContainerDef.cpp CAAFContainerDef.h \
	CAAFContentStorage.cpp CAAFContentStorage.h CAAFControlPoint.cpp \
	CAAFControlPoint.h CAAFDataDef.cpp CAAFDataDef.h \
	CAAFDataEssenceDescriptor.cpp CAAFDataEssenceDescriptor.h \
	CAAFDefObject.cpp CAAFDefObject.h CAAFDescriptiveClip.cpp \
	CAAFDescriptiveClip.h CAAFDescriptiveFramework.cpp \
	CAAFDescriptiveFramework.h CAAFDescriptiveMarker.cpp \
	CAAFDescriptiveMarker.h CAAFDescriptiveObject.cpp CAAFDescriptiveObject.h \
	CAAFDictionary.cpp CAAFDictionary.h CAAFDigitalImageDescriptor.cpp \
	CAAFDigitalImageDescriptor.h CAAFEdgecode.cpp CAAFEdgecode.h \
	CAAFEnumValidation.cpp CAAFEnumValidation.h CAAFEssenceAccess.cpp \
	CAAFEssenceAccess.h CAAFEssenceData.cpp CAAFEssenceData.h \
	CAAFEssenceDescriptor.cpp CAAFEssenceDescriptor.h CAAFEssenceFormat.cpp \
	CAAFEssenceFormat.h CAAFEssenceGroup.cpp CAAFEssenceGroup.h CAAFEvent.cpp \
	CAAFEvent.h CAAFEventMobSlot.cpp CAAFEventMobSlot.h CAAFFile.cpp \
	CAAFFile.h CAAFFileDescriptor.cpp CAAFFileDescriptor.h \
	CAAFFileEncoding.cpp CAAFFileEncoding.h CAAFFiller.cpp CAAFFiller.h \
	CAAFFilmDescriptor.cpp CAAFFilmDescriptor.h CAAFFindSourceInfo.cpp \
	CAAFFindSourceInfo.h CAAFGPITrigger.cpp CAAFGPITrigger.h \
	CAAFGetFileBits.cpp CAAFGetFileBits.h CAAFHTMLClip.cpp CAAFHTMLClip.h \
	CAAFHTMLDescriptor.cpp CAAFHTMLDescriptor.h CAAFHeader.cpp CAAFHeader.h \
	CAAFIdentification.cpp CAAFIdentification.h CAAFImportDescriptor.cpp \
	CAAFImportDescriptor.h CAAFInterpolationDef.cpp CAAFInterpolationDef.h \
	CAAFKLVData.cpp CAAFKLVData.h CAAFKLVDataDefinition.cpp \
	CAAFKLVDataDefinition.h CAAFLocator.cpp CAAFLocator.h \
	CAAFMPEGVideoDescriptor.cpp CAAFMPEGVideoDescriptor.h CAAFMasterMob.cpp \
	CAAFMasterMob.h CAAFMetaDefinition.cpp CAAFMetaDefinition.h \
	CAAFMetaDictionary.cpp CAAFMetaDictionary.h CAAFMob.cpp CAAFMob.h \
	CAAFMobSlot.cpp CAAFMobSlot.h CAAFModule.cpp CAAFMultipleDescriptor.cpp \
	CAAFMultipleDescriptor.h CAAFNestedScope.cpp CAAFNestedScope.h \
	CAAFNetworkLocator.cpp CAAFNetworkLocator.h CAAFObject.cpp CAAFObject.h \
	CAAFOperationDef.cpp CAAFOperationDef.h CAAFOperationGroup.cpp \
	CAAFOperationGroup.h CAAFPCMDescriptor.cpp CAAFPCMDescriptor.h \
	CAAFParameter.cpp CAAFParameter.h CAAFParameterDef.cpp CAAFParameterDef.h \
	CAAFPhysicalDescriptor.cpp CAAFPhysicalDescriptor.h \
	CAAFPlainEssenceData.cpp CAAFPlainEssenceData.h CAAFPlainStreamData.cpp \
	CAAFPlainStreamData.h CAAFPluginDef.cpp CAAFPluginDef.h \
	CAAFPluginManager.cpp CAAFPluginManager.h CAAFPropValData.cpp \
	CAAFPropValData.h CAAFProperty.cpp CAAFProperty.h CAAFPropertyDef.cpp \
	CAAFPropertyDef.h CAAFPropertyValue.cpp CAAFPropertyValue.h \
	CAAFPulldown.cpp CAAFPulldown.h CAAFRGBADescriptor.cpp \
	CAAFRGBADescriptor.h CAAFRIFFChunk.cpp CAAFRIFFChunk.h CAAFRandomFile.cpp \
	CAAFRandomFile.h CAAFRandomRawStorage.cpp CAAFRandomRawStorage.h \
	CAAFRawStorage.cpp CAAFRawStorage.h CAAFRecordingDescriptor.cpp \
	CAAFRecordingDescriptor.h CAAFRoot.cpp CAAFRoot.h CAAFScopeReference.cpp \
	CAAFScopeReference.h CAAFSegment.cpp CAAFSegment.h CAAFSelector.cpp \
	CAAFSelector.h CAAFSequence.cpp CAAFSequence.h CAAFSetFileBits.cpp \
	CAAFSetFileBits.h CAAFSoundDescriptor.cpp CAAFSoundDescriptor.h \
	CAAFSourceClip.cpp CAAFSourceClip.h CAAFSourceMob.cpp CAAFSourceMob.h \
	CAAFSourceReference.cpp CAAFSourceReference.h CAAFStaticMobSlot.cpp \
	CAAFStaticMobSlot.h CAAFStreamPropertyValue.cpp CAAFStreamPropertyValue.h \
	CAAFStrongRefArrayValue.cpp CAAFStrongRefArrayValue.h \
	CAAFStrongRefSetValue.cpp CAAFStrongRefSetValue.h CAAFStrongRefValue.cpp \
	CAAFStrongRefValue.h CAAFTIFFDescriptor.cpp CAAFTIFFDescriptor.h \
	CAAFTaggedValue.cpp CAAFTaggedValue.h CAAFTaggedValueDefinition.cpp \
	CAAFTaggedValueDefinition.h CAAFTapeDescriptor.cpp CAAFTapeDescriptor.h \
	CAAFTextClip.cpp CAAFTextClip.h CAAFTextLocator.cpp CAAFTextLocator.h \
	CAAFTimecode.cpp CAAFTimecode.h CAAFTimecodeStream.cpp \
	CAAFTimecodeStream.h CAAFTimecodeStream12M.cpp CAAFTimecodeStream12M.h \
	CAAFTimelineMobSlot.cpp CAAFTimelineMobSlot.h CAAFTransition.cpp \
	CAAFTransition.h CAAFTypeDef.cpp CAAFTypeDef.h CAAFTypeDefCharacter.cpp \
	CAAFTypeDefCharacter.h CAAFTypeDefEnum.cpp CAAFTypeDefEnum.h \
	CAAFTypeDefExtEnum.cpp CAAFTypeDefExtEnum.h CAAFTypeDefFixedArray.cpp \
	CAAFTypeDefFixedArray.h CAAFTypeDefIndirect.cpp CAAFTypeDefIndirect.h \
	CAAFTypeDefInt.cpp CAAFTypeDefInt.h CAAFTypeDefObjectRef.cpp \
	CAAFTypeDefObjectRef.h CAAFTypeDefOpaque.cpp CAAFTypeDefOpaque.h \
	CAAFTypeDefRecord.cpp CAAFTypeDefRecord.h CAAFTypeDefRename.cpp \
	CAAFTypeDefRename.h CAAFTypeDefSet.cpp CAAFTypeDefSet.h \
	CAAFTypeDefStream.cpp CAAFTypeDefStream.h CAAFTypeDefString.cpp \
	CAAFTypeDefString.h CAAFTypeDefStrongObjRef.cpp CAAFTypeDefStrongObjRef.h \
	CAAFTypeDefVariableArray.cpp CAAFTypeDefVariableArray.h \
	CAAFTypeDefWeakObjRef.cpp CAAFTypeDefWeakObjRef.h CAAFVaryingValue.cpp \
	CAAFVaryingValue.h CAAFWAVEDescriptor.cpp CAAFWAVEDescriptor.h \
	CAAFWeakRefArrayValue.cpp CAAFWeakRefArrayValue.h CAAFWeakRefSetValue.cpp \
	CAAFWeakRefSetValue.h CAAFWeakRefValue.cpp CAAFWeakRefValue.h \
	CEnumAAFClassDefs.cpp CEnumAAFClassDefs.h CEnumAAFCodecDefs.cpp \
	CEnumAAFCodecDefs.h CEnumAAFCodecFlavours.cpp CEnumAAFCodecFlavours.h \
	CEnumAAFComponents.cpp CEnumAAFComponents.h CEnumAAFContainerDefs.cpp \
	CEnumAAFContainerDefs.h CEnumAAFControlPoints.cpp CEnumAAFControlPoints.h \
	CEnumAAFDataDefs.cpp CEnumAAFDataDefs.h CEnumAAFEssenceData.cpp \
	CEnumAAFEssenceData.h CEnumAAFFileDescriptors.cpp \
	CEnumAAFFileDescriptors.h CEnumAAFFileEncodings.cpp \
	CEnumAAFFileEncodings.h CEnumAAFIdentifications.cpp \
	CEnumAAFIdentifications.h CEnumAAFInterpolationDefs.cpp \
	CEnumAAFInterpolationDefs.h CEnumAAFKLVData.cpp CEnumAAFKLVData.h \
	CEnumAAFKLVDataDefs.cpp CEnumAAFKLVDataDefs.h CEnumAAFLoadedPlugins.cpp \
	CEnumAAFLoadedPlugins.h CEnumAAFLocators.cpp CEnumAAFLocators.h \
	CEnumAAFMobSlots.cpp CEnumAAFMobSlots.h CEnumAAFMobs.cpp CEnumAAFMobs.h \
	CEnumAAFOperationDefs.cpp CEnumAAFOperationDefs.h \
	CEnumAAFParameterDefs.cpp CEnumAAFParameterDefs.h CEnumAAFParameters.cpp \
	CEnumAAFParameters.h CEnumAAFPluginDefs.cpp CEnumAAFPluginDefs.h \
	CEnumAAFPluginLocators.cpp CEnumAAFPluginLocators.h \
	CEnumAAFProperties.cpp CEnumAAFProperties.h CEnumAAFPropertyDefs.cpp \
	CEnumAAFPropertyDefs.h CEnumAAFPropertyValues.cpp \
	CEnumAAFPropertyValues.h CEnumAAFRIFFChunks.cpp CEnumAAFRIFFChunks.h \
	CEnumAAFSegments.cpp CEnumAAFSegments.h CEnumAAFStorablePropVals.cpp \
	CEnumAAFStorablePropVals.h CEnumAAFTaggedValueDefs.cpp \
	CEnumAAFTaggedValueDefs.h CEnumAAFTaggedValues.cpp \
	CEnumAAFTaggedValues.h CEnumAAFTypeDefs.cpp CEnumAAFTypeDefs.h
	\
	com-dll/AAFCOM.cpp com-dll/AAFObjectCreation.cpp \
	com-dll/CAAFClassFactory.cpp com-dll/CAAFClassFactory.h \
	com-dll/CAAFInProcServer.cpp com-dll/CAAFInProcServer.h \
	com-dll/CAAFServer.cpp com-dll/CAAFServer.h com-dll/CAAFUnknown.cpp \
	com-dll/CAAFUnknown.h com-dll/utf8.cpp

libcom_api_la_LDFLAGS = -avoid-version
