#pragma once

#include <cstdint>
// Generated from cross_call_worker.pplugin

namespace cross_call_worker {

  enum class Example : int32_t {
    First = 1,
    Second = 2,
    Third = 3,
    Forth = 4
  };


  /// Ownership type for RAII wrappers
  enum class Ownership : bool { Borrowed, Owned };

} // namespace cross_call_worker
