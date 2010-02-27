INCLUDES = -I${srcdir} -I${top_srcdir}/ref-impl/include/ref-api \
	-I${top_srcdir}/ref-impl/include \
	-I${top_srcdir}/ref-impl/include/platform \
	-I${top_srcdir}/ref-impl/include/OM \
	-I${srcdir}/../OM -I${top_srcdir}/ref-impl/aaflib

noinst_LTLIBRARIES = libimpl.la

libimpl_la_SOURCES = \
	AAFClassIDs.h AAFComponentVisitor.h AAFObjectModel.cpp AAFObjectModel.h \
	AAFObjectModelProcs.cpp AAFObjectModelProcs.h AAFUtils.cpp AAFUtils.h \
	ImplAAFAES3PCMDescriptor.cpp ImplAAFAES3PCMDescriptor.h \
	ImplAAFAIFCDescriptor.cpp ImplAAFAIFCDescriptor.h \
	ImplAAFAuxiliaryDescriptor.cpp ImplAAFAuxiliaryDescriptor.h \
	ImplAAFBWFImportDescriptor.cpp ImplAAFBWFImportDescriptor.h \
	ImplAAFBaseClassFactory.cpp ImplAAFBaseClassFactory.h \
	ImplAAFBuiltinClasses.cpp ImplAAFBuiltinClasses.h ImplAAFBuiltinDefs.h \
	ImplAAFBuiltinTypes.cpp ImplAAFBuiltinTypes.h ImplAAFCDCIDescriptor.cpp \
	ImplAAFCDCIDescriptor.h ImplAAFCachePageAllocator.cpp \
	ImplAAFCachePageAllocator.h ImplAAFClassDef.cpp ImplAAFClassDef.h \
	ImplAAFClientDiagnostics.cpp ImplAAFClientDiagnostics.h \
	ImplAAFCloneResolver.cpp ImplAAFCloneResolver.h ImplAAFCodecDef.cpp \
	ImplAAFCodecDef.h ImplAAFCollection.h ImplAAFCommentMarker.cpp \
	ImplAAFCommentMarker.h ImplAAFComponent.cpp ImplAAFComponent.h \
	ImplAAFCompositionMob.cpp ImplAAFCompositionMob.h \
	ImplAAFConstantValue.cpp ImplAAFConstantValue.h ImplAAFContainerDef.cpp \
	ImplAAFContainerDef.h ImplAAFContentStorage.cpp ImplAAFContentStorage.h \
	ImplAAFContext.cpp ImplAAFContext.h ImplAAFControlPoint.cpp \
	ImplAAFControlPoint.h ImplAAFDataDef.cpp ImplAAFDataDef.h \
	ImplAAFDataEssenceDescriptor.cpp ImplAAFDataEssenceDescriptor.h \
	ImplAAFDefObject.cpp ImplAAFDefObject.h ImplAAFDescriptiveClip.cpp \
	ImplAAFDescriptiveClip.h ImplAAFDescriptiveFramework.cpp \
	ImplAAFDescriptiveFramework.h ImplAAFDescriptiveMarker.cpp \
	ImplAAFDescriptiveMarker.h ImplAAFDescriptiveObject.cpp \
	ImplAAFDescriptiveObject.h ImplAAFDictionary.cpp ImplAAFDictionary.h \
	ImplAAFDigitalImageDescrip.cpp ImplAAFDigitalImageDescriptor.h \
	ImplAAFEdgecode.cpp ImplAAFEdgecode.h ImplAAFEnumerator.h \
	ImplAAFEssenceAccess.cpp ImplAAFEssenceAccess.h ImplAAFEssenceData.cpp \
	ImplAAFEssenceData.h ImplAAFEssenceDescriptor.cpp \
	ImplAAFEssenceDescriptor.h ImplAAFEssenceFormat.cpp \
	ImplAAFEssenceFormat.h ImplAAFEssenceGroup.cpp ImplAAFEssenceGroup.h \
	ImplAAFEssencePlugin.cpp ImplAAFEssencePlugin.h ImplAAFEvent.cpp \
	ImplAAFEvent.h ImplAAFEventMobSlot.cpp ImplAAFEventMobSlot.h \
	ImplAAFFile.cpp ImplAAFFile.h ImplAAFFileDescriptor.cpp \
	ImplAAFFileDescriptor.h ImplAAFFileEncoding.cpp ImplAAFFileEncoding.h \
	ImplAAFFiller.cpp ImplAAFFiller.h ImplAAFFilmDescriptor.cpp \
	ImplAAFFilmDescriptor.h ImplAAFFindSourceInfo.cpp ImplAAFFindSourceInfo.h \
	ImplAAFGPITrigger.cpp ImplAAFGPITrigger.h ImplAAFGetFileBits.cpp \
	ImplAAFGetFileBits.h ImplAAFHTMLClip.cpp ImplAAFHTMLClip.h \
	ImplAAFHTMLDescriptor.cpp ImplAAFHTMLDescriptor.h ImplAAFHeader.cpp \
	ImplAAFHeader.h ImplAAFIdentification.cpp ImplAAFIdentification.h \
	ImplAAFImportDescriptor.cpp ImplAAFImportDescriptor.h \
	ImplAAFInterpolationDef.cpp ImplAAFInterpolationDef.h ImplAAFKLVData.cpp \
	ImplAAFKLVData.h ImplAAFKLVDataDefinition.cpp ImplAAFKLVDataDefinition.h \
	ImplAAFLocator.cpp ImplAAFLocator.h ImplAAFMPEGVideoDescriptor.cpp \
	ImplAAFMPEGVideoDescriptor.h ImplAAFMasterMob.cpp ImplAAFMasterMob.h \
	ImplAAFMetaDefinition.cpp ImplAAFMetaDefinition.h \
	ImplAAFMetaDictionary.cpp ImplAAFMetaDictionary.h ImplAAFMob.cpp \
	ImplAAFMob.h ImplAAFMobSlot.cpp ImplAAFMobSlot.h ImplAAFModule.cpp \
	ImplAAFModule.h ImplAAFMultipleDescriptor.cpp ImplAAFMultipleDescriptor.h \
	ImplAAFNestedScope.cpp ImplAAFNestedScope.h ImplAAFNetworkLocator.cpp \
	ImplAAFNetworkLocator.h ImplAAFOMCachePageAllocator.cpp \
	ImplAAFOMCachePageAllocator.h ImplAAFOMRawStorage.cpp \
	ImplAAFOMRawStorage.h ImplAAFObject.cpp ImplAAFObject.h \
	ImplAAFObjectCreation.h ImplAAFOperationDef.cpp ImplAAFOperationDef.h \
	ImplAAFOperationGroup.cpp ImplAAFOperationGroup.h \
	ImplAAFPCMDescriptor.cpp ImplAAFPCMDescriptor.h ImplAAFParameter.cpp \
	ImplAAFParameter.h ImplAAFParameterDef.cpp ImplAAFParameterDef.h \
	ImplAAFPhysicalDescriptor.cpp ImplAAFPhysicalDescriptor.h \
	ImplAAFPlainEssenceData.cpp ImplAAFPlainEssenceData.h \
	ImplAAFPlainStreamData.cpp ImplAAFPlainStreamData.h ImplAAFPluginDef.cpp \
	ImplAAFPluginDef.h ImplAAFPluginFile.cpp ImplAAFPluginFile.h \
	ImplAAFPluginManager.cpp ImplAAFPluginManager.h	ImplAAFPropValData.cpp \
	ImplAAFPropValData.h ImplAAFProperty.cpp ImplAAFProperty.h \
	ImplAAFPropertyDef.cpp ImplAAFPropertyDef.h ImplAAFPropertyValue.cpp \
	ImplAAFPropertyValue.h ImplAAFPulldown.cpp ImplAAFPulldown.h \
	ImplAAFRGBADescriptor.cpp ImplAAFRGBADescriptor.h ImplAAFRIFFChunk.cpp \
	ImplAAFRIFFChunk.h ImplAAFRandomFile.cpp ImplAAFRandomFile.h \
	ImplAAFRandomRawStorage.cpp ImplAAFRandomRawStorage.h \
	ImplAAFRawStorage.cpp ImplAAFRawStorage.h ImplAAFRecordingDescriptor.cpp \
	ImplAAFRecordingDescriptor.h ImplAAFRefArrayValue.cpp \
	ImplAAFRefArrayValue.h ImplAAFRefContainerValue.cpp \
	ImplAAFRefContainerValue.h ImplAAFRefSetValue.cpp ImplAAFRefSetValue.h \
	ImplAAFRefValue.cpp	ImplAAFRefValue.h ImplAAFRoot.cpp ImplAAFRoot.h \
	ImplAAFScopeReference.cpp ImplAAFScopeReference.h \
	ImplAAFSearchableStack.h ImplAAFSegment.cpp ImplAAFSegment.h \
	ImplAAFSelector.cpp ImplAAFSelector.h ImplAAFSequence.cpp \
	ImplAAFSequence.h ImplAAFSetFileBits.cpp ImplAAFSetFileBits.h \
	ImplAAFSmartPointer.h ImplAAFSoundDescriptor.cpp \
	ImplAAFSoundDescriptor.h ImplAAFSourceClip.cpp ImplAAFSourceClip.h \
	ImplAAFSourceMob.cpp ImplAAFSourceMob.h ImplAAFSourceReference.cpp \
	ImplAAFSourceReference.h ImplAAFStaticMobSlot.cpp ImplAAFStaticMobSlot.h \
	ImplAAFStorable.cpp ImplAAFStorable.h ImplAAFStreamPropertyValue.cpp \
	ImplAAFStreamPropertyValue.h ImplAAFStrongRefArrayValue.cpp \
	ImplAAFStrongRefArrayValue.h ImplAAFStrongRefSetValue.cpp \
	ImplAAFStrongRefSetValue.h ImplAAFStrongRefValue.cpp \
	ImplAAFStrongRefValue.h ImplAAFTIFFDescriptor.cpp ImplAAFTIFFDescriptor.h \
	ImplAAFTaggedValue.cpp ImplAAFTaggedValue.h \
	ImplAAFTaggedValueDefinition.cpp ImplAAFTaggedValueDefinition.h \
	ImplAAFTaggedValueUtil.cpp ImplAAFTaggedValueUtil.h \
	ImplAAFTapeDescriptor.cpp ImplAAFTapeDescriptor.h ImplAAFTextClip.cpp \
	ImplAAFTextClip.h ImplAAFTextLocator.cpp ImplAAFTextLocator.h \
	ImplAAFTimecode.cpp ImplAAFTimecode.h ImplAAFTimecodeStream.cpp \
	ImplAAFTimecodeStream.h ImplAAFTimecodeStream12M.cpp \
	ImplAAFTimecodeStream12M.h ImplAAFTimelineMobSlot.cpp \
	ImplAAFTimelineMobSlot.h ImplAAFTransition.cpp ImplAAFTransition.h \
	ImplAAFTypeDef.cpp ImplAAFTypeDef.h ImplAAFTypeDefArray.cpp \
	ImplAAFTypeDefArray.h ImplAAFTypeDefCharacter.cpp \
	ImplAAFTypeDefCharacter.h ImplAAFTypeDefEnum.cpp ImplAAFTypeDefEnum.h \
	ImplAAFTypeDefExtEnum.cpp ImplAAFTypeDefExtEnum.h \
	ImplAAFTypeDefFixedArray.cpp ImplAAFTypeDefFixedArray.h \
	ImplAAFTypeDefIndirect.cpp ImplAAFTypeDefIndirect.h ImplAAFTypeDefInt.cpp \
	ImplAAFTypeDefInt.h ImplAAFTypeDefObjectRef.cpp ImplAAFTypeDefObjectRef.h \
	ImplAAFTypeDefOpaque.cpp ImplAAFTypeDefOpaque.h ImplAAFTypeDefRecord.cpp \
	ImplAAFTypeDefRecord.h ImplAAFTypeDefRename.cpp ImplAAFTypeDefRename.h \
	ImplAAFTypeDefSet.cpp ImplAAFTypeDefSet.h ImplAAFTypeDefStream.cpp \
	ImplAAFTypeDefStream.h ImplAAFTypeDefString.cpp ImplAAFTypeDefString.h \
	ImplAAFTypeDefStrongObjRef.cpp ImplAAFTypeDefStrongObjRef.h \
	ImplAAFTypeDefVariableArray.h ImplAAFTypeDefVariableArry.cpp \
	ImplAAFTypeDefWeakObjRef.cpp ImplAAFTypeDefWeakObjRef.h \
	ImplAAFTypeDefsGen.h ImplAAFUID.h ImplAAFVaryingValue.cpp \
	ImplAAFVaryingValue.h ImplAAFWAVEDescriptor.cpp ImplAAFWAVEDescriptor.h \
	ImplAAFWeakRefArrayValue.cpp ImplAAFWeakRefArrayValue.h \
	ImplAAFWeakRefSetValue.cpp ImplAAFWeakRefSetValue.h \
	ImplAAFWeakRefValue.cpp ImplAAFWeakRefValue.h ImplEnumAAFClassDefs.cpp \
	ImplEnumAAFClassDefs.h ImplEnumAAFCodecDefs.cpp ImplEnumAAFCodecDefs.h \
	ImplEnumAAFCodecFlavours.cpp ImplEnumAAFCodecFlavours.h \
	ImplEnumAAFComponents.cpp ImplEnumAAFComponents.h \
	ImplEnumAAFContainerDefs.cpp ImplEnumAAFContainerDefs.h \
	ImplEnumAAFControlPoints.cpp ImplEnumAAFControlPoints.h \
	ImplEnumAAFDataDefs.cpp ImplEnumAAFDataDefs.h ImplEnumAAFEssenceData.cpp \
	ImplEnumAAFEssenceData.h ImplEnumAAFFileDescriptors.h \
	ImplEnumAAFFileEncodings.cpp ImplEnumAAFFileEncodings.h \
	ImplEnumAAFIdentifications.cpp ImplEnumAAFIdentifications.h \
	ImplEnumAAFInterpolateDefs.cpp ImplEnumAAFInterpolationDefs.h \
	ImplEnumAAFKLVData.cpp ImplEnumAAFKLVData.h ImplEnumAAFKLVDataDefs.cpp \
	ImplEnumAAFKLVDataDefs.h ImplEnumAAFLoadedPlugins.cpp \
	ImplEnumAAFLoadedPlugins.h ImplEnumAAFLocators.cpp ImplEnumAAFLocators.h \
	ImplEnumAAFMobSlots.cpp ImplEnumAAFMobSlots.h ImplEnumAAFMobs.cpp \
	ImplEnumAAFMobs.h ImplEnumAAFOperationDefs.cpp \
	ImplEnumAAFOperationDefs.h ImplEnumAAFParameterDefs.cpp \
	ImplEnumAAFParameterDefs.h ImplEnumAAFParameters.cpp \
	ImplEnumAAFParameters.h ImplEnumAAFPluginDefs.cpp ImplEnumAAFPluginDefs.h \
	ImplEnumAAFPluginLocators.cpp ImplEnumAAFPluginLocators.h \
	ImplEnumAAFProperties.cpp ImplEnumAAFProperties.h \
	ImplEnumAAFPropertyDefs.cpp ImplEnumAAFPropertyDefs.h \
	ImplEnumAAFPropertyValues.cpp ImplEnumAAFPropertyValues.h \
	ImplEnumAAFRIFFChunks.h ImplEnumAAFSegments.cpp ImplEnumAAFSegments.h \
	ImplEnumAAFStorablePropVals.cpp ImplEnumAAFStorablePropVals.h \
	ImplEnumAAFTaggedValueDefs.cpp ImplEnumAAFTaggedValueDefs.h \
	ImplEnumAAFTaggedValues.cpp ImplEnumAAFTaggedValues.h \
	ImplEnumAAFTypeDefs.cpp ImplEnumAAFTypeDefs.h aafErr.cpp aafErr.h \
	aafTable.cpp aafTable.h
