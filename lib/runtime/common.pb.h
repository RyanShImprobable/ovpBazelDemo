// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: runtime/common.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_runtime_2fcommon_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_runtime_2fcommon_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_runtime_2fcommon_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_runtime_2fcommon_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_runtime_2fcommon_2eproto;
namespace improbable {
namespace platform {
namespace runtime {
class EntityId;
class EntityIdDefaultTypeInternal;
extern EntityIdDefaultTypeInternal _EntityId_default_instance_;
class Point;
class PointDefaultTypeInternal;
extern PointDefaultTypeInternal _Point_default_instance_;
class Rectangle;
class RectangleDefaultTypeInternal;
extern RectangleDefaultTypeInternal _Rectangle_default_instance_;
}  // namespace runtime
}  // namespace platform
}  // namespace improbable
PROTOBUF_NAMESPACE_OPEN
template<> ::improbable::platform::runtime::EntityId* Arena::CreateMaybeMessage<::improbable::platform::runtime::EntityId>(Arena*);
template<> ::improbable::platform::runtime::Point* Arena::CreateMaybeMessage<::improbable::platform::runtime::Point>(Arena*);
template<> ::improbable::platform::runtime::Rectangle* Arena::CreateMaybeMessage<::improbable::platform::runtime::Rectangle>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace improbable {
namespace platform {
namespace runtime {

// ===================================================================

class EntityId PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:improbable.platform.runtime.EntityId) */ {
 public:
  inline EntityId() : EntityId(nullptr) {}
  virtual ~EntityId();

  EntityId(const EntityId& from);
  EntityId(EntityId&& from) noexcept
    : EntityId() {
    *this = ::std::move(from);
  }

  inline EntityId& operator=(const EntityId& from) {
    CopyFrom(from);
    return *this;
  }
  inline EntityId& operator=(EntityId&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const EntityId& default_instance();

  static inline const EntityId* internal_default_instance() {
    return reinterpret_cast<const EntityId*>(
               &_EntityId_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(EntityId& a, EntityId& b) {
    a.Swap(&b);
  }
  inline void Swap(EntityId* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(EntityId* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline EntityId* New() const final {
    return CreateMaybeMessage<EntityId>(nullptr);
  }

  EntityId* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<EntityId>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const EntityId& from);
  void MergeFrom(const EntityId& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(EntityId* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "improbable.platform.runtime.EntityId";
  }
  protected:
  explicit EntityId(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_runtime_2fcommon_2eproto);
    return ::descriptor_table_runtime_2fcommon_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIdFieldNumber = 1,
  };
  // int64 id = 1;
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::int64 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // @@protoc_insertion_point(class_scope:improbable.platform.runtime.EntityId)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int64 id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_runtime_2fcommon_2eproto;
};
// -------------------------------------------------------------------

class Point PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:improbable.platform.runtime.Point) */ {
 public:
  inline Point() : Point(nullptr) {}
  virtual ~Point();

  Point(const Point& from);
  Point(Point&& from) noexcept
    : Point() {
    *this = ::std::move(from);
  }

  inline Point& operator=(const Point& from) {
    CopyFrom(from);
    return *this;
  }
  inline Point& operator=(Point&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Point& default_instance();

  static inline const Point* internal_default_instance() {
    return reinterpret_cast<const Point*>(
               &_Point_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Point& a, Point& b) {
    a.Swap(&b);
  }
  inline void Swap(Point* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Point* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Point* New() const final {
    return CreateMaybeMessage<Point>(nullptr);
  }

  Point* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Point>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Point& from);
  void MergeFrom(const Point& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Point* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "improbable.platform.runtime.Point";
  }
  protected:
  explicit Point(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_runtime_2fcommon_2eproto);
    return ::descriptor_table_runtime_2fcommon_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kZFieldNumber = 2,
  };
  // double x = 1;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double z = 2;
  void clear_z();
  double z() const;
  void set_z(double value);
  private:
  double _internal_z() const;
  void _internal_set_z(double value);
  public:

  // @@protoc_insertion_point(class_scope:improbable.platform.runtime.Point)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double x_;
  double z_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_runtime_2fcommon_2eproto;
};
// -------------------------------------------------------------------

class Rectangle PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:improbable.platform.runtime.Rectangle) */ {
 public:
  inline Rectangle() : Rectangle(nullptr) {}
  virtual ~Rectangle();

  Rectangle(const Rectangle& from);
  Rectangle(Rectangle&& from) noexcept
    : Rectangle() {
    *this = ::std::move(from);
  }

  inline Rectangle& operator=(const Rectangle& from) {
    CopyFrom(from);
    return *this;
  }
  inline Rectangle& operator=(Rectangle&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Rectangle& default_instance();

  static inline const Rectangle* internal_default_instance() {
    return reinterpret_cast<const Rectangle*>(
               &_Rectangle_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Rectangle& a, Rectangle& b) {
    a.Swap(&b);
  }
  inline void Swap(Rectangle* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Rectangle* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Rectangle* New() const final {
    return CreateMaybeMessage<Rectangle>(nullptr);
  }

  Rectangle* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Rectangle>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Rectangle& from);
  void MergeFrom(const Rectangle& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Rectangle* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "improbable.platform.runtime.Rectangle";
  }
  protected:
  explicit Rectangle(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_runtime_2fcommon_2eproto);
    return ::descriptor_table_runtime_2fcommon_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBottomLeftFieldNumber = 1,
    kTopRightFieldNumber = 2,
  };
  // .improbable.platform.runtime.Point bottom_left = 1;
  bool has_bottom_left() const;
  private:
  bool _internal_has_bottom_left() const;
  public:
  void clear_bottom_left();
  const ::improbable::platform::runtime::Point& bottom_left() const;
  ::improbable::platform::runtime::Point* release_bottom_left();
  ::improbable::platform::runtime::Point* mutable_bottom_left();
  void set_allocated_bottom_left(::improbable::platform::runtime::Point* bottom_left);
  private:
  const ::improbable::platform::runtime::Point& _internal_bottom_left() const;
  ::improbable::platform::runtime::Point* _internal_mutable_bottom_left();
  public:
  void unsafe_arena_set_allocated_bottom_left(
      ::improbable::platform::runtime::Point* bottom_left);
  ::improbable::platform::runtime::Point* unsafe_arena_release_bottom_left();

  // .improbable.platform.runtime.Point top_right = 2;
  bool has_top_right() const;
  private:
  bool _internal_has_top_right() const;
  public:
  void clear_top_right();
  const ::improbable::platform::runtime::Point& top_right() const;
  ::improbable::platform::runtime::Point* release_top_right();
  ::improbable::platform::runtime::Point* mutable_top_right();
  void set_allocated_top_right(::improbable::platform::runtime::Point* top_right);
  private:
  const ::improbable::platform::runtime::Point& _internal_top_right() const;
  ::improbable::platform::runtime::Point* _internal_mutable_top_right();
  public:
  void unsafe_arena_set_allocated_top_right(
      ::improbable::platform::runtime::Point* top_right);
  ::improbable::platform::runtime::Point* unsafe_arena_release_top_right();

  // @@protoc_insertion_point(class_scope:improbable.platform.runtime.Rectangle)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::improbable::platform::runtime::Point* bottom_left_;
  ::improbable::platform::runtime::Point* top_right_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_runtime_2fcommon_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// EntityId

// int64 id = 1;
inline void EntityId::clear_id() {
  id_ = PROTOBUF_LONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::int64 EntityId::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 EntityId::id() const {
  // @@protoc_insertion_point(field_get:improbable.platform.runtime.EntityId.id)
  return _internal_id();
}
inline void EntityId::_internal_set_id(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  id_ = value;
}
inline void EntityId::set_id(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:improbable.platform.runtime.EntityId.id)
}

// -------------------------------------------------------------------

// Point

// double x = 1;
inline void Point::clear_x() {
  x_ = 0;
}
inline double Point::_internal_x() const {
  return x_;
}
inline double Point::x() const {
  // @@protoc_insertion_point(field_get:improbable.platform.runtime.Point.x)
  return _internal_x();
}
inline void Point::_internal_set_x(double value) {
  
  x_ = value;
}
inline void Point::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:improbable.platform.runtime.Point.x)
}

// double z = 2;
inline void Point::clear_z() {
  z_ = 0;
}
inline double Point::_internal_z() const {
  return z_;
}
inline double Point::z() const {
  // @@protoc_insertion_point(field_get:improbable.platform.runtime.Point.z)
  return _internal_z();
}
inline void Point::_internal_set_z(double value) {
  
  z_ = value;
}
inline void Point::set_z(double value) {
  _internal_set_z(value);
  // @@protoc_insertion_point(field_set:improbable.platform.runtime.Point.z)
}

// -------------------------------------------------------------------

// Rectangle

// .improbable.platform.runtime.Point bottom_left = 1;
inline bool Rectangle::_internal_has_bottom_left() const {
  return this != internal_default_instance() && bottom_left_ != nullptr;
}
inline bool Rectangle::has_bottom_left() const {
  return _internal_has_bottom_left();
}
inline void Rectangle::clear_bottom_left() {
  if (GetArena() == nullptr && bottom_left_ != nullptr) {
    delete bottom_left_;
  }
  bottom_left_ = nullptr;
}
inline const ::improbable::platform::runtime::Point& Rectangle::_internal_bottom_left() const {
  const ::improbable::platform::runtime::Point* p = bottom_left_;
  return p != nullptr ? *p : reinterpret_cast<const ::improbable::platform::runtime::Point&>(
      ::improbable::platform::runtime::_Point_default_instance_);
}
inline const ::improbable::platform::runtime::Point& Rectangle::bottom_left() const {
  // @@protoc_insertion_point(field_get:improbable.platform.runtime.Rectangle.bottom_left)
  return _internal_bottom_left();
}
inline void Rectangle::unsafe_arena_set_allocated_bottom_left(
    ::improbable::platform::runtime::Point* bottom_left) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(bottom_left_);
  }
  bottom_left_ = bottom_left;
  if (bottom_left) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:improbable.platform.runtime.Rectangle.bottom_left)
}
inline ::improbable::platform::runtime::Point* Rectangle::release_bottom_left() {
  
  ::improbable::platform::runtime::Point* temp = bottom_left_;
  bottom_left_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::improbable::platform::runtime::Point* Rectangle::unsafe_arena_release_bottom_left() {
  // @@protoc_insertion_point(field_release:improbable.platform.runtime.Rectangle.bottom_left)
  
  ::improbable::platform::runtime::Point* temp = bottom_left_;
  bottom_left_ = nullptr;
  return temp;
}
inline ::improbable::platform::runtime::Point* Rectangle::_internal_mutable_bottom_left() {
  
  if (bottom_left_ == nullptr) {
    auto* p = CreateMaybeMessage<::improbable::platform::runtime::Point>(GetArena());
    bottom_left_ = p;
  }
  return bottom_left_;
}
inline ::improbable::platform::runtime::Point* Rectangle::mutable_bottom_left() {
  // @@protoc_insertion_point(field_mutable:improbable.platform.runtime.Rectangle.bottom_left)
  return _internal_mutable_bottom_left();
}
inline void Rectangle::set_allocated_bottom_left(::improbable::platform::runtime::Point* bottom_left) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete bottom_left_;
  }
  if (bottom_left) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(bottom_left);
    if (message_arena != submessage_arena) {
      bottom_left = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, bottom_left, submessage_arena);
    }
    
  } else {
    
  }
  bottom_left_ = bottom_left;
  // @@protoc_insertion_point(field_set_allocated:improbable.platform.runtime.Rectangle.bottom_left)
}

// .improbable.platform.runtime.Point top_right = 2;
inline bool Rectangle::_internal_has_top_right() const {
  return this != internal_default_instance() && top_right_ != nullptr;
}
inline bool Rectangle::has_top_right() const {
  return _internal_has_top_right();
}
inline void Rectangle::clear_top_right() {
  if (GetArena() == nullptr && top_right_ != nullptr) {
    delete top_right_;
  }
  top_right_ = nullptr;
}
inline const ::improbable::platform::runtime::Point& Rectangle::_internal_top_right() const {
  const ::improbable::platform::runtime::Point* p = top_right_;
  return p != nullptr ? *p : reinterpret_cast<const ::improbable::platform::runtime::Point&>(
      ::improbable::platform::runtime::_Point_default_instance_);
}
inline const ::improbable::platform::runtime::Point& Rectangle::top_right() const {
  // @@protoc_insertion_point(field_get:improbable.platform.runtime.Rectangle.top_right)
  return _internal_top_right();
}
inline void Rectangle::unsafe_arena_set_allocated_top_right(
    ::improbable::platform::runtime::Point* top_right) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(top_right_);
  }
  top_right_ = top_right;
  if (top_right) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:improbable.platform.runtime.Rectangle.top_right)
}
inline ::improbable::platform::runtime::Point* Rectangle::release_top_right() {
  
  ::improbable::platform::runtime::Point* temp = top_right_;
  top_right_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::improbable::platform::runtime::Point* Rectangle::unsafe_arena_release_top_right() {
  // @@protoc_insertion_point(field_release:improbable.platform.runtime.Rectangle.top_right)
  
  ::improbable::platform::runtime::Point* temp = top_right_;
  top_right_ = nullptr;
  return temp;
}
inline ::improbable::platform::runtime::Point* Rectangle::_internal_mutable_top_right() {
  
  if (top_right_ == nullptr) {
    auto* p = CreateMaybeMessage<::improbable::platform::runtime::Point>(GetArena());
    top_right_ = p;
  }
  return top_right_;
}
inline ::improbable::platform::runtime::Point* Rectangle::mutable_top_right() {
  // @@protoc_insertion_point(field_mutable:improbable.platform.runtime.Rectangle.top_right)
  return _internal_mutable_top_right();
}
inline void Rectangle::set_allocated_top_right(::improbable::platform::runtime::Point* top_right) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete top_right_;
  }
  if (top_right) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(top_right);
    if (message_arena != submessage_arena) {
      top_right = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, top_right, submessage_arena);
    }
    
  } else {
    
  }
  top_right_ = top_right;
  // @@protoc_insertion_point(field_set_allocated:improbable.platform.runtime.Rectangle.top_right)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace runtime
}  // namespace platform
}  // namespace improbable

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_runtime_2fcommon_2eproto
