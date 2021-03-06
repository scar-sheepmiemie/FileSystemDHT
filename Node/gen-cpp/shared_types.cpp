/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "shared_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace csci_5105 { namespace PA1 {


SingleNode::~SingleNode() throw() {
}


void SingleNode::__set_id(const int32_t val) {
  this->id = val;
}

void SingleNode::__set_ip(const std::string& val) {
  this->ip = val;
}

void SingleNode::__set_port(const int32_t val) {
  this->port = val;
}

uint32_t SingleNode::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->id);
          this->__isset.id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->ip);
          this->__isset.ip = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->port);
          this->__isset.port = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t SingleNode::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("SingleNode");

  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("ip", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->ip);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("port", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->port);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SingleNode &a, SingleNode &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.ip, b.ip);
  swap(a.port, b.port);
  swap(a.__isset, b.__isset);
}

SingleNode::SingleNode(const SingleNode& other0) {
  id = other0.id;
  ip = other0.ip;
  port = other0.port;
  __isset = other0.__isset;
}
SingleNode& SingleNode::operator=(const SingleNode& other1) {
  id = other1.id;
  ip = other1.ip;
  port = other1.port;
  __isset = other1.__isset;
  return *this;
}
void SingleNode::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "SingleNode(";
  out << "id=" << to_string(id);
  out << ", " << "ip=" << to_string(ip);
  out << ", " << "port=" << to_string(port);
  out << ")";
}


NodeList::~NodeList() throw() {
}


void NodeList::__set_maxSize(const int32_t val) {
  this->maxSize = val;
}

void NodeList::__set_id2node(const std::map<int32_t, SingleNode> & val) {
  this->id2node = val;
}

uint32_t NodeList::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->maxSize);
          this->__isset.maxSize = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->id2node.clear();
            uint32_t _size2;
            ::apache::thrift::protocol::TType _ktype3;
            ::apache::thrift::protocol::TType _vtype4;
            xfer += iprot->readMapBegin(_ktype3, _vtype4, _size2);
            uint32_t _i6;
            for (_i6 = 0; _i6 < _size2; ++_i6)
            {
              int32_t _key7;
              xfer += iprot->readI32(_key7);
              SingleNode& _val8 = this->id2node[_key7];
              xfer += _val8.read(iprot);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.id2node = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t NodeList::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("NodeList");

  xfer += oprot->writeFieldBegin("maxSize", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->maxSize);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("id2node", ::apache::thrift::protocol::T_MAP, 2);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->id2node.size()));
    std::map<int32_t, SingleNode> ::const_iterator _iter9;
    for (_iter9 = this->id2node.begin(); _iter9 != this->id2node.end(); ++_iter9)
    {
      xfer += oprot->writeI32(_iter9->first);
      xfer += _iter9->second.write(oprot);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(NodeList &a, NodeList &b) {
  using ::std::swap;
  swap(a.maxSize, b.maxSize);
  swap(a.id2node, b.id2node);
  swap(a.__isset, b.__isset);
}

NodeList::NodeList(const NodeList& other10) {
  maxSize = other10.maxSize;
  id2node = other10.id2node;
  __isset = other10.__isset;
}
NodeList& NodeList::operator=(const NodeList& other11) {
  maxSize = other11.maxSize;
  id2node = other11.id2node;
  __isset = other11.__isset;
  return *this;
}
void NodeList::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "NodeList(";
  out << "maxSize=" << to_string(maxSize);
  out << ", " << "id2node=" << to_string(id2node);
  out << ")";
}


File::~File() throw() {
}


void File::__set_fileName(const std::string& val) {
  this->fileName = val;
}

void File::__set_data(const std::string& val) {
  this->data = val;
}

uint32_t File::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->fileName);
          this->__isset.fileName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->data);
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t File::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("File");

  xfer += oprot->writeFieldBegin("fileName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->fileName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->data);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(File &a, File &b) {
  using ::std::swap;
  swap(a.fileName, b.fileName);
  swap(a.data, b.data);
  swap(a.__isset, b.__isset);
}

File::File(const File& other12) {
  fileName = other12.fileName;
  data = other12.data;
  __isset = other12.__isset;
}
File& File::operator=(const File& other13) {
  fileName = other13.fileName;
  data = other13.data;
  __isset = other13.__isset;
  return *this;
}
void File::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "File(";
  out << "fileName=" << to_string(fileName);
  out << ", " << "data=" << to_string(data);
  out << ")";
}

}} // namespace
