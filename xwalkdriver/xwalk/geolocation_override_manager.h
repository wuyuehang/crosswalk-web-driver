// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_TEST_XWALKDRIVER_XWALK_GEOLOCATION_OVERRIDE_MANAGER_H_
#define XWALK_TEST_XWALKDRIVER_XWALK_GEOLOCATION_OVERRIDE_MANAGER_H_

#include <string>

#include "base/basictypes.h"
#include "base/compiler_specific.h"
#include "base/memory/scoped_ptr.h"
#include "xwalk/test/xwalkdriver/xwalk/devtools_event_listener.h"

namespace base {
class DictionaryValue;
}

class DevToolsClient;
struct Geoposition;
class Status;

// Overrides the geolocation, if requested, for the duration of the
// given |DevToolsClient|'s lifetime.
class GeolocationOverrideManager : public DevToolsEventListener {
 public:
  explicit GeolocationOverrideManager(DevToolsClient* client);
  ~GeolocationOverrideManager() override;

  Status OverrideGeolocation(const Geoposition& geoposition);

  // Overridden from DevToolsEventListener:
  Status OnConnected(DevToolsClient* client) override;
  Status OnEvent(DevToolsClient* client,
                 const std::string& method,
                 const base::DictionaryValue& params) override;

 private:
  Status ApplyOverrideIfNeeded();

  DevToolsClient* client_;
  scoped_ptr<Geoposition> overridden_geoposition_;

  DISALLOW_COPY_AND_ASSIGN(GeolocationOverrideManager);
};

#endif  // XWALK_TEST_XWALKDRIVER_XWALK_GEOLOCATION_OVERRIDE_MANAGER_H_
