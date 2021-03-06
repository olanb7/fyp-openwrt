// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "dist.pb.h"
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace DIDS {

namespace {

const ::google::protobuf::Descriptor* Station_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Station_reflection_ = NULL;
const ::google::protobuf::Descriptor* Instance_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Instance_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_dist_2eproto() {
  protobuf_AddDesc_dist_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "dist.proto");
  GOOGLE_CHECK(file != NULL);
  Station_descriptor_ = file->message_type(0);
  static const int Station_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Station, mac_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Station, beacons_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Station, rssi_),
  };
  Station_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Station_descriptor_,
      Station::default_instance_,
      Station_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Station, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Station, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Station));
  Instance_descriptor_ = file->message_type(1);
  static const int Instance_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Instance, station_),
  };
  Instance_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Instance_descriptor_,
      Instance::default_instance_,
      Instance_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Instance, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Instance, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Instance));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_dist_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Station_descriptor_, &Station::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Instance_descriptor_, &Instance::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_dist_2eproto() {
  delete Station::default_instance_;
  delete Station_reflection_;
  delete Instance::default_instance_;
  delete Instance_reflection_;
}

void protobuf_AddDesc_dist_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\ndist.proto\022\004DIDS\"5\n\007Station\022\013\n\003mac\030\002 \001"
    "(\t\022\017\n\007beacons\030\003 \001(\005\022\014\n\004rssi\030\004 \003(\005\"*\n\010Ins"
    "tance\022\036\n\007station\030\001 \003(\0132\r.DIDS.Station", 117);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "dist.proto", &protobuf_RegisterTypes);
  Station::default_instance_ = new Station();
  Instance::default_instance_ = new Instance();
  Station::default_instance_->InitAsDefaultInstance();
  Instance::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_dist_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_dist_2eproto {
  StaticDescriptorInitializer_dist_2eproto() {
    protobuf_AddDesc_dist_2eproto();
  }
} static_descriptor_initializer_dist_2eproto_;


// ===================================================================

const ::std::string Station::_default_mac_;
#ifndef _MSC_VER
const int Station::kMacFieldNumber;
const int Station::kBeaconsFieldNumber;
const int Station::kRssiFieldNumber;
#endif  // !_MSC_VER

Station::Station()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Station::InitAsDefaultInstance() {
}

Station::Station(const Station& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Station::SharedCtor() {
  _cached_size_ = 0;
  mac_ = const_cast< ::std::string*>(&_default_mac_);
  beacons_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Station::~Station() {
  SharedDtor();
}

void Station::SharedDtor() {
  if (mac_ != &_default_mac_) {
    delete mac_;
  }
  if (this != default_instance_) {
  }
}

void Station::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Station::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Station_descriptor_;
}

const Station& Station::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_dist_2eproto();  return *default_instance_;
}

Station* Station::default_instance_ = NULL;

Station* Station::New() const {
  return new Station;
}

void Station::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (_has_bit(0)) {
      if (mac_ != &_default_mac_) {
        mac_->clear();
      }
    }
    beacons_ = 0;
  }
  rssi_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Station::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string mac = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_mac()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->mac().data(), this->mac().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_beacons;
        break;
      }
      
      // optional int32 beacons = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_beacons:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &beacons_)));
          _set_bit(1);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_rssi;
        break;
      }
      
      // repeated int32 rssi = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_rssi:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 32, input, this->mutable_rssi())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_rssi())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_rssi;
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Station::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional string mac = 2;
  if (_has_bit(0)) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->mac().data(), this->mac().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->mac(), output);
  }
  
  // optional int32 beacons = 3;
  if (_has_bit(1)) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->beacons(), output);
  }
  
  // repeated int32 rssi = 4;
  for (int i = 0; i < this->rssi_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      4, this->rssi(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Station::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional string mac = 2;
  if (_has_bit(0)) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->mac().data(), this->mac().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->mac(), target);
  }
  
  // optional int32 beacons = 3;
  if (_has_bit(1)) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->beacons(), target);
  }
  
  // repeated int32 rssi = 4;
  for (int i = 0; i < this->rssi_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32ToArray(4, this->rssi(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Station::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string mac = 2;
    if (has_mac()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->mac());
    }
    
    // optional int32 beacons = 3;
    if (has_beacons()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->beacons());
    }
    
  }
  // repeated int32 rssi = 4;
  {
    int data_size = 0;
    for (int i = 0; i < this->rssi_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->rssi(i));
    }
    total_size += 1 * this->rssi_size() + data_size;
  }
  
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Station::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Station* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Station*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Station::MergeFrom(const Station& from) {
  GOOGLE_CHECK_NE(&from, this);
  rssi_.MergeFrom(from.rssi_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from._has_bit(0)) {
      set_mac(from.mac());
    }
    if (from._has_bit(1)) {
      set_beacons(from.beacons());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Station::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Station::CopyFrom(const Station& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Station::IsInitialized() const {
  
  return true;
}

void Station::Swap(Station* other) {
  if (other != this) {
    std::swap(mac_, other->mac_);
    std::swap(beacons_, other->beacons_);
    rssi_.Swap(&other->rssi_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Station::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Station_descriptor_;
  metadata.reflection = Station_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Instance::kStationFieldNumber;
#endif  // !_MSC_VER

Instance::Instance()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Instance::InitAsDefaultInstance() {
}

Instance::Instance(const Instance& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Instance::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Instance::~Instance() {
  SharedDtor();
}

void Instance::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Instance::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Instance::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Instance_descriptor_;
}

const Instance& Instance::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_dist_2eproto();  return *default_instance_;
}

Instance* Instance::default_instance_ = NULL;

Instance* Instance::New() const {
  return new Instance;
}

void Instance::Clear() {
  station_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Instance::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .DIDS.Station station = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_station:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_station()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_station;
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Instance::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .DIDS.Station station = 1;
  for (int i = 0; i < this->station_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->station(i), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Instance::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .DIDS.Station station = 1;
  for (int i = 0; i < this->station_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->station(i), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Instance::ByteSize() const {
  int total_size = 0;
  
  // repeated .DIDS.Station station = 1;
  total_size += 1 * this->station_size();
  for (int i = 0; i < this->station_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->station(i));
  }
  
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Instance::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Instance* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Instance*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Instance::MergeFrom(const Instance& from) {
  GOOGLE_CHECK_NE(&from, this);
  station_.MergeFrom(from.station_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Instance::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Instance::CopyFrom(const Instance& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Instance::IsInitialized() const {
  
  return true;
}

void Instance::Swap(Instance* other) {
  if (other != this) {
    station_.Swap(&other->station_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Instance::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Instance_descriptor_;
  metadata.reflection = Instance_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace DIDS

// @@protoc_insertion_point(global_scope)
