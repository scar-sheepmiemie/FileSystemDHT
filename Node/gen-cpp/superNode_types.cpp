/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "superNode_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace csci_5105 { namespace PA1 {

int _kStateValues[] = {
  State::INIT,
  State::ADDING,
  State::WORKING,
  State::BUSY
};
const char* _kStateNames[] = {
  "INIT",
  "ADDING",
  "WORKING",
  "BUSY"
};
const std::map<int, const char*> _State_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kStateValues, _kStateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

}} // namespace