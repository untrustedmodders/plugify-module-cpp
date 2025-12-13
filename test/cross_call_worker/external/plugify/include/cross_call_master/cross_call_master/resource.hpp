#pragma once

#include <plugin_export.h>

#include "enums.hpp"
#include "delegates.hpp"
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
  inline void* ResourceHandleCreate(int32_t id, const plg::string& name) {
    return __cross_call_master_ResourceHandleCreate(id, name);
  }

  using _ResourceHandleCreateDefault = void* (*)();
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleCreateDefault __cross_call_master_ResourceHandleCreateDefault;
namespace cross_call_master {
  /**
   * @return ptr64
   */
  inline void* ResourceHandleCreateDefault() {
    return __cross_call_master_ResourceHandleCreateDefault();
  }

  using _ResourceHandleDestroy = void (*)(void*);
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleDestroy __cross_call_master_ResourceHandleDestroy;
namespace cross_call_master {
  /**
   * @param handle (ptr64)
   */
  inline void ResourceHandleDestroy(void* handle) {
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
  inline int32_t ResourceHandleGetId(void* handle) {
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
  inline plg::string ResourceHandleGetName(void* handle) {
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
  inline void ResourceHandleSetName(void* handle, const plg::string& name) {
    return __cross_call_master_ResourceHandleSetName(handle, name);
  }

  using _ResourceHandleIncrementCounter = void (*)(void*);
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleIncrementCounter __cross_call_master_ResourceHandleIncrementCounter;
namespace cross_call_master {
  /**
   * @param handle (ptr64)
   */
  inline void ResourceHandleIncrementCounter(void* handle) {
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
  inline int32_t ResourceHandleGetCounter(void* handle) {
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
  inline void ResourceHandleAddData(void* handle, float value) {
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
  inline plg::vector<float> ResourceHandleGetData(void* handle) {
    return __cross_call_master_ResourceHandleGetData(handle);
  }

  using _ResourceHandleGetAliveCount = int32_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleGetAliveCount __cross_call_master_ResourceHandleGetAliveCount;
namespace cross_call_master {
  /**
   * @return int32
   */
  inline int32_t ResourceHandleGetAliveCount() {
    return __cross_call_master_ResourceHandleGetAliveCount();
  }

  using _ResourceHandleGetTotalCreated = int32_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleGetTotalCreated __cross_call_master_ResourceHandleGetTotalCreated;
namespace cross_call_master {
  /**
   * @return int32
   */
  inline int32_t ResourceHandleGetTotalCreated() {
    return __cross_call_master_ResourceHandleGetTotalCreated();
  }

  using _ResourceHandleGetTotalDestroyed = int32_t (*)();
}
extern "C" PLUGIN_API cross_call_master::_ResourceHandleGetTotalDestroyed __cross_call_master_ResourceHandleGetTotalDestroyed;
namespace cross_call_master {
  /**
   * @return int32
   */
  inline int32_t ResourceHandleGetTotalDestroyed() {
    return __cross_call_master_ResourceHandleGetTotalDestroyed();
  }

} // namespace cross_call_master
