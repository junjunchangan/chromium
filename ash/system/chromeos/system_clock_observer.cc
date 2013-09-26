// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ash/system/chromeos/system_clock_observer.h"

#include "ash/system/tray/system_tray_notifier.h"
#include "chromeos/dbus/dbus_thread_manager.h"

namespace ash {
namespace internal {

SystemClockObserver::SystemClockObserver() {
  chromeos::DBusThreadManager::Get()->GetSystemClockClient()
      ->AddObserver(this);
}

SystemClockObserver::~SystemClockObserver() {
  chromeos::DBusThreadManager::Get()->GetSystemClockClient()
      ->RemoveObserver(this);
}

void SystemClockObserver::SystemClockUpdated() {
  Shell::GetInstance()->system_tray_notifier()
      ->NotifySystemClockTimeUpdated();
}

}  // namespace internal
}  // namespace ash
