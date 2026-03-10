#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from cross_call_master.pplugin (group: resource)

namespace cross_call_master {

  using _ResourceHandleCreate = void* (*)(int32_t, const plg::string&);
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleCreate __cross_call_master_ResourceHandleCreate;
namespace cross_call_master {
  /**
   * @param id (int32)
   * @param name (string)
   * @return ptr64
   */
  inline void* ResourceHandleCreate(int32_t id, const plg::string& name, plg::source_location __location = plg::source_location::current()) {
    plg::Log("cross_call_master::ResourceHandleCreate", plg::Severity::Trace, __location);
    return __cross_call_master_ResourceHandleCreate(id, name);
  }

  using _ResourceHandleCreateDefault = void* (*)();
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleCreateDefault __cross_call_master_ResourceHandleCreateDefault;
namespace cross_call_master {
  /**
   * @return ptr64
   */
  inline void* ResourceHandleCreateDefault(plg::source_location __location = plg::source_location::current()) {
    plg::Log("cross_call_master::ResourceHandleCreateDefault", plg::Severity::Trace, __location);
    return __cross_call_master_ResourceHandleCreateDefault();
  }

  using _ResourceHandleDestroy = void (*)(void*);
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleDestroy __cross_call_master_ResourceHandleDestroy;
namespace cross_call_master {
  /**
   * @param handle (ptr64)
   */
  inline void ResourceHandleDestroy(void* handle, plg::source_location __location = plg::source_location::current()) {
    plg::Log("cross_call_master::ResourceHandleDestroy", plg::Severity::Trace, __location);
    return __cross_call_master_ResourceHandleDestroy(handle);
  }

  using _ResourceHandleGetId = int32_t (*)(void*);
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleGetId __cross_call_master_ResourceHandleGetId;
namespace cross_call_master {
  /**
   * @param handle (ptr64)
   * @return int32
   */
  inline int32_t ResourceHandleGetId(void* handle, plg::source_location __location = plg::source_location::current()) {
    plg::Log("cross_call_master::ResourceHandleGetId", plg::Severity::Trace, __location);
    return __cross_call_master_ResourceHandleGetId(handle);
  }

  using _ResourceHandleGetName = plg::string (*)(void*);
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleGetName __cross_call_master_ResourceHandleGetName;
namespace cross_call_master {
  /**
   * @param handle (ptr64)
   * @return string
   */
  inline plg::string ResourceHandleGetName(void* handle, plg::source_location __location = plg::source_location::current()) {
    plg::Log("cross_call_master::ResourceHandleGetName", plg::Severity::Trace, __location);
    return __cross_call_master_ResourceHandleGetName(handle);
  }

  using _ResourceHandleSetName = void (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleSetName __cross_call_master_ResourceHandleSetName;
namespace cross_call_master {
  /**
   * @param handle (ptr64)
   * @param name (string)
   */
  inline void ResourceHandleSetName(void* handle, const plg::string& name, plg::source_location __location = plg::source_location::current()) {
    plg::Log("cross_call_master::ResourceHandleSetName", plg::Severity::Trace, __location);
    return __cross_call_master_ResourceHandleSetName(handle, name);
  }

  using _ResourceHandleIncrementCounter = void (*)(void*);
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleIncrementCounter __cross_call_master_ResourceHandleIncrementCounter;
namespace cross_call_master {
  /**
   * @param handle (ptr64)
   */
  inline void ResourceHandleIncrementCounter(void* handle, plg::source_location __location = plg::source_location::current()) {
    plg::Log("cross_call_master::ResourceHandleIncrementCounter", plg::Severity::Trace, __location);
    return __cross_call_master_ResourceHandleIncrementCounter(handle);
  }

  using _ResourceHandleGetCounter = int32_t (*)(void*);
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleGetCounter __cross_call_master_ResourceHandleGetCounter;
namespace cross_call_master {
  /**
   * @param handle (ptr64)
   * @return int32
   */
  inline int32_t ResourceHandleGetCounter(void* handle, plg::source_location __location = plg::source_location::current()) {
    plg::Log("cross_call_master::ResourceHandleGetCounter", plg::Severity::Trace, __location);
    return __cross_call_master_ResourceHandleGetCounter(handle);
  }

  using _ResourceHandleAddData = void (*)(void*, float);
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleAddData __cross_call_master_ResourceHandleAddData;
namespace cross_call_master {
  /**
   * @param handle (ptr64)
   * @param value (float)
   */
  inline void ResourceHandleAddData(void* handle, float value, plg::source_location __location = plg::source_location::current()) {
    plg::Log("cross_call_master::ResourceHandleAddData", plg::Severity::Trace, __location);
    return __cross_call_master_ResourceHandleAddData(handle, value);
  }

  using _ResourceHandleGetData = plg::vector<float> (*)(void*);
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleGetData __cross_call_master_ResourceHandleGetData;
namespace cross_call_master {
  /**
   * @param handle (ptr64)
   * @return float[]
   */
  inline plg::vector<float> ResourceHandleGetData(void* handle, plg::source_location __location = plg::source_location::current()) {
    plg::Log("cross_call_master::ResourceHandleGetData", plg::Severity::Trace, __location);
    return __cross_call_master_ResourceHandleGetData(handle);
  }

  using _ResourceHandleGetAliveCount = int32_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleGetAliveCount __cross_call_master_ResourceHandleGetAliveCount;
namespace cross_call_master {
  /**
   * @return int32
   */
  inline int32_t ResourceHandleGetAliveCount(plg::source_location __location = plg::source_location::current()) {
    plg::Log("cross_call_master::ResourceHandleGetAliveCount", plg::Severity::Trace, __location);
    return __cross_call_master_ResourceHandleGetAliveCount();
  }

  using _ResourceHandleGetTotalCreated = int32_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleGetTotalCreated __cross_call_master_ResourceHandleGetTotalCreated;
namespace cross_call_master {
  /**
   * @return int32
   */
  inline int32_t ResourceHandleGetTotalCreated(plg::source_location __location = plg::source_location::current()) {
    plg::Log("cross_call_master::ResourceHandleGetTotalCreated", plg::Severity::Trace, __location);
    return __cross_call_master_ResourceHandleGetTotalCreated();
  }

  using _ResourceHandleGetTotalDestroyed = int32_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleGetTotalDestroyed __cross_call_master_ResourceHandleGetTotalDestroyed;
namespace cross_call_master {
  /**
   * @return int32
   */
  inline int32_t ResourceHandleGetTotalDestroyed(plg::source_location __location = plg::source_location::current()) {
    plg::Log("cross_call_master::ResourceHandleGetTotalDestroyed", plg::Severity::Trace, __location);
    return __cross_call_master_ResourceHandleGetTotalDestroyed();
  }

} // namespace cross_call_master
