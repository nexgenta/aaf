
MXF_DEFINE_PACK_KEY(OpenHeaderPartition,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x05, 0x01, 0x01,
            0x0d, 0x01, 0x02, 0x01, 0x01, 0x02, 0x01, 0x00))

MXF_DEFINE_PACK_KEY(ClosedHeaderPartition,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x05, 0x01, 0x01,
            0x0d, 0x01, 0x02, 0x01, 0x01, 0x02, 0x02, 0x00))

MXF_DEFINE_PACK_KEY(OpenBodyPartition,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x05, 0x01, 0x01,
            0x0d, 0x01, 0x02, 0x01, 0x01, 0x03, 0x01, 0x00))

MXF_DEFINE_PACK_KEY(ClosedBodyPartition,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x05, 0x01, 0x01,
            0x0d, 0x01, 0x02, 0x01, 0x01, 0x03, 0x02, 0x00))

MXF_DEFINE_PACK_KEY(ClosedFooterPartition,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x05, 0x01, 0x01,
            0x0d, 0x01, 0x02, 0x01, 0x01, 0x04, 0x02, 0x00))

MXF_DEFINE_PACK_KEY(Primer,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x05, 0x01, 0x01,
            0x0d, 0x01, 0x02, 0x01, 0x01, 0x05, 0x01, 0x00))

MXF_DEFINE_SET_KEY(Preface,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x2f, 0x00))

MXF_DEFINE_SET_KEY(Identification,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x30, 0x00))

MXF_DEFINE_SET_KEY(ContentStorage,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x18, 0x00))

MXF_DEFINE_SET_KEY(EssenceContainerData,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x23, 0x00))

MXF_DEFINE_SET_KEY(MaterialPackage,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x36, 0x00))

MXF_DEFINE_SET_KEY(SourcePackage,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x37, 0x00))

MXF_DEFINE_SET_KEY(Track,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x3b, 0x00))

MXF_DEFINE_SET_KEY(Sequence,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x0f, 0x00))

MXF_DEFINE_SET_KEY(SourceClip,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x00))

MXF_DEFINE_SET_KEY(Timecode12MComponent,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x14, 0x00))

MXF_DEFINE_SET_KEY(TimecodeStream12MComponent,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x16, 0x00))

MXF_DEFINE_SET_KEY(DMSegment,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x41, 0x00))

MXF_DEFINE_SET_KEY(DMSourceClip,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x45, 0x00))

MXF_DEFINE_SET_KEY(FileDescriptor,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x25, 0x00))

MXF_DEFINE_SET_KEY(GenPictureEssenceDesc,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x27, 0x00))

MXF_DEFINE_SET_KEY(CDCIEssenceDescriptor,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x28, 0x00))

MXF_DEFINE_SET_KEY(RGBAEssenceDescriptor,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x29, 0x00))

MXF_DEFINE_SET_KEY(GenSoundEssenceDesc,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x42, 0x00))

MXF_DEFINE_SET_KEY(GenDataEssenceDesc,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x43, 0x00))

MXF_DEFINE_SET_KEY(MultipleDescriptor,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x44, 0x00))

MXF_DEFINE_SET_KEY(NetworkLocator,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x32, 0x00))

MXF_DEFINE_SET_KEY(TextLocator,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x33, 0x00))

MXF_DEFINE_SEGEMENT_KEY(IndexTable,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x02, 0x53, 0x01, 0x01,
            0x0d, 0x01, 0x02, 0x01, 0x01, 0x01, 0x10, 0x00))

MXF_DEFINE_KEY(Filler,
  MXF_LABEL(0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01,
            0x03, 0x01, 0x02, 0x10, 0x01, 0x00, 0x00, 0x00))

