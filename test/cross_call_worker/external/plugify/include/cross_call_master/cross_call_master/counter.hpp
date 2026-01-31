#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from cross_call_master.pplugin (group: counter)

namespace cross_call_master {

  using _CounterCreate = void* (*)(int64_t);
}
extern "C" PLUGIN_API cross_call_master::_CounterCreate __cross_call_master_CounterCreate;
namespace cross_call_master {
  /**
   * @param initialValue (int64)
   * @return ptr64
   */
  inline void* CounterCreate(int64_t initialValue) {
    return __cross_call_master_CounterCreate(initialValue);
  }

  using _CounterCreateZero = void* (*)();
}
extern "C" PLUGIN_API cross_call_master::_CounterCreateZero __cross_call_master_CounterCreateZero;
namespace cross_call_master {
  /**
   * @return ptr64
   */
  inline void* CounterCreateZero() {
    return __cross_call_master_CounterCreateZero();
  }

  using _CounterGetValue = int64_t (*)(void*);
}
extern "C" PLUGIN_API cross_call_master::_CounterGetValue __cross_call_master_CounterGetValue;
namespace cross_call_master {
  /**
   * @param counter (ptr64)
   * @return int64
   */
  inline int64_t CounterGetValue(void* counter) {
    return __cross_call_master_CounterGetValue(counter);
  }

  using _CounterSetValue = void (*)(void*, int64_t);
}
extern "C" PLUGIN_API cross_call_master::_CounterSetValue __cross_call_master_CounterSetValue;
namespace cross_call_master {
  /**
   * @param counter (ptr64)
   * @param value (int64)
   */
  inline void CounterSetValue(void* counter, int64_t value) {
    return __cross_call_master_CounterSetValue(counter, value);
  }

  using _CounterIncrement = void (*)(void*);
}
extern "C" PLUGIN_API cross_call_master::_CounterIncrement __cross_call_master_CounterIncrement;
namespace cross_call_master {
  /**
   * @param counter (ptr64)
   */
  inline void CounterIncrement(void* counter) {
    return __cross_call_master_CounterIncrement(counter);
  }

  using _CounterDecrement = void (*)(void*);
}
extern "C" PLUGIN_API cross_call_master::_CounterDecrement __cross_call_master_CounterDecrement;
namespace cross_call_master {
  /**
   * @param counter (ptr64)
   */
  inline void CounterDecrement(void* counter) {
    return __cross_call_master_CounterDecrement(counter);
  }

  using _CounterAdd = void (*)(void*, int64_t);
}
extern "C" PLUGIN_API cross_call_master::_CounterAdd __cross_call_master_CounterAdd;
namespace cross_call_master {
  /**
   * @param counter (ptr64)
   * @param amount (int64)
   */
  inline void CounterAdd(void* counter, int64_t amount) {
    return __cross_call_master_CounterAdd(counter, amount);
  }

  using _CounterReset = void (*)(void*);
}
extern "C" PLUGIN_API cross_call_master::_CounterReset __cross_call_master_CounterReset;
namespace cross_call_master {
  /**
   * @param counter (ptr64)
   */
  inline void CounterReset(void* counter) {
    return __cross_call_master_CounterReset(counter);
  }

  using _CounterIsPositive = bool (*)(void*);
}
extern "C" PLUGIN_API cross_call_master::_CounterIsPositive __cross_call_master_CounterIsPositive;
namespace cross_call_master {
  /**
   * @param counter (ptr64)
   * @return bool
   */
  inline bool CounterIsPositive(void* counter) {
    return __cross_call_master_CounterIsPositive(counter);
  }

  using _CounterCompare = int32_t (*)(int64_t, int64_t);
}
extern "C" PLUGIN_API cross_call_master::_CounterCompare __cross_call_master_CounterCompare;
namespace cross_call_master {
  /**
   * @param value1 (int64)
   * @param value2 (int64)
   * @return int32
   */
  inline int32_t CounterCompare(int64_t value1, int64_t value2) {
    return __cross_call_master_CounterCompare(value1, value2);
  }

  using _CounterSum = int64_t (*)(const plg::vector<int64_t>&);
}
extern "C" PLUGIN_API cross_call_master::_CounterSum __cross_call_master_CounterSum;
namespace cross_call_master {
  /**
   * @param values (int64[])
   * @return int64
   */
  inline int64_t CounterSum(const plg::vector<int64_t>& values) {
    return __cross_call_master_CounterSum(values);
  }

} // namespace cross_call_master
