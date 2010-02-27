INCLUDES = -I${srcdir} -I${top_srcdir}/ref-impl/include/OM \
	-I${top_srcdir}/ss-impl/ref -I${top_srcdir}/ref-impl/include \
	-I${top_srcdir}/sss-impl/include

CPPFLAGS = @CPPFLAGS@ -DOM_STACK_TRACE_ON_ASSERT -DXML_STATIC

noinst_LTLIBRARIES = libom.la

libom_la_SOURCES = OMAVLTreeT.h OMArrayPropertyIteratorT.h OMArrayPropertyT.h \
	OMArrayType.cpp OMAssertions.cpp OMAssertions.h OMBufferedIStream.cpp \
	OMBufferedStream.cpp OMByteArray.cpp OMByteArray.h \
	OMCachePageAllocator.cpp OMCachedDiskRawStorage.cpp \
	OMCachedRawStorage.cpp OMCharacterStringPropertyT.h OMCharacterType.cpp \
	OMClassDefinition.cpp OMClassFactory.h OMContainerElement.cpp \
	OMContainerElementT.h OMContainerProperty.cpp OMDataSet.cpp \
	OMDataStream.cpp OMDataStreamAccess.cpp OMDataStreamProperty.cpp \
	OMDataStreamPropertyFilter.cpp OMDataTypes.cpp OMDataVector.cpp \
	OMDefinition.cpp OMDictionary.cpp OMDiskRawStorage.cpp \
	OMDynamicLibrary.cpp OMEnumeratedType.cpp OMExceptions.cpp \
	OMExtendibleEnumeratedType.cpp OMFile.cpp OMFile.h OMFixedSizePropertyT.h \
	OMIOStream.cpp OMIdentitySetIterT.h OMIdentitySetT.h OMIndirectType.cpp \
	OMIntegerType.cpp OMKLVStoredObject.cpp OMKLVStoredObjectFactory.cpp \
	OMKLVStoredStream.cpp OMKLVStoredStreamFilter.cpp OMListIteratorT.h \
	OMListT.h OMMSStructuredStorage.cpp OMMSStructuredStorage.h \
	OMMS_SSStoredObjectFactory.cpp OMMXFStorage.cpp \
	OMMappedFileRawStorage.cpp OMMemoryRawStorage.cpp OMOStream.cpp \
	OMObjectManager.cpp OMObjectReference.cpp OMObjectReferenceT.h \
	OMObjectReferenceType.cpp OMOpaqueType.cpp OMPageCache.cpp \
	OMPortability.h OMProperty.cpp OMPropertyDefinition.cpp \
	OMPropertySet.cpp OMPropertySetIterator.cpp OMPropertyTable.cpp \
	OMRawStorageLockBytes.cpp OMRecordType.cpp OMRedBlackTreeIteratorT.h \
	OMRedBlackTreeT.h OMRefProperty.cpp OMRefSetProperty.cpp \
	OMRefVectorProperty.cpp OMReferenceSetIterT.h OMReferenceSetT.h \
	OMReferenceVectorIterT.h OMReferenceVectorT.h OMRenamedType.cpp \
	OMRootStorable.cpp OMRootStorable.h OMSSSStorageRWInputSource.cpp \
	OMSSSStorageRWInputSource.h OMSSStoredObject.cpp \
	OMSSStoredObjectFactory.cpp OMSSStoredStream.cpp \
	OMSSStructuredStorage.cpp OMSSStructuredStorage.h \
	OMSS_SSStoredObjectFactory.cpp OMSetIteratorT.h OMSetPropertyIteratorT.h \
	OMSetPropertyT.h OMSetT.h OMSetType.cpp OMSingletonT.h OMStackTrace.cpp \
	OMStorable.cpp OMStorable.h OMStoredObject.cpp OMStoredObject.h \
	OMStoredObjectFactory.cpp OMStoredObjectFactory.h \
	OMStoredPropertySetIndex.cpp OMStoredPropertySetIndex.h \
	OMStoredSetIndex.cpp OMStoredSetIndex.h OMStoredVectorIndex.cpp \
	OMStoredVectorIndex.h OMStream.cpp OMStreamPropertyT.h \
	OMStreamType.cpp OMStringType.cpp OMStrongRefPropertyT.h \
	OMStrongRefSetPropertyT.h OMStrongRefVectorPropertyT.h \
	OMStrongReference.cpp OMStrongReferenceSet.cpp \
	OMStrongReferenceSetIterT.h OMStrongReferenceVector.cpp \
	OMStrongReferenceVectorIterT.h OMSymbolspace.cpp OMSymbolspace.h \
	OMType.cpp OMTypeDefinition.cpp OMTypeVisitor.cpp \
	OMUniqueObjectIdentType.cpp OMUtilities.cpp OMUtilities.h \
	OMVariableSizePropertyT.h OMVectorIteratorT.h OMVectorT.h \
	OMWString.cpp OMWString.h OMWeakRefPropertyT.h OMWeakRefSetPropertyT.h \
	OMWeakRefVectorPropertyT.h OMWeakReference.cpp OMWeakReferenceSet.cpp \
	OMWeakReferenceSetIterT.h OMWeakReferenceVector.cpp \
	OMWeakReferenceVectorIterT.h OMWideStringProperty.cpp \
	OMWrappedRawStorage.cpp OMXMLReader.cpp OMXMLReader.h OMXMLStorage.cpp \
	OMXMLStorage.h OMXMLStoredObject.cpp OMXMLStoredObjectFactory.cpp \
	OMXMLStoredStream.cpp OMXMLUtilities.cpp OMXMLUtilities.h OMXMLWriter.cpp \
	OMXMLWriter.h utf8.cpp

if OM_USE_GSF_SS

libom_la_SOURCES += OMGSFStructuredStorage.cpp OMGSFStructuredStorage.h \
	OMGSF_SSStoredObjectFactory.cpp

endif

libom_la_LDFLAGS = -static
