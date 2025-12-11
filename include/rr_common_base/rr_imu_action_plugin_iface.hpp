// Copyright (c) 2025 Ryder Robots
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "rr_common_base/rr_action_plugin_iface.hpp"
#include "rr_interfaces/action/monitor_imu_action.hpp"

namespace rrobots
{
    namespace interfaces
    {
        /**
         * @class RRImuServicePluginIface
         * @brief provides plugin interface for IMU events.
         * 
         * Strictly an interface for IMUs. Concrete classs are expected to use this 
         * interface as their base, and implement virtual methods contained in
         * RRActionPluginIface. The plugin may extend upon, but only methods that are
         * in RRActionPluginIface will be used by nodes.
         */
        class RRImuActionPluginIface : public RRActionPluginIface<rr_interfaces::action::MonitorImuAction>
        {
          public:
            virtual ~RRImuActionPluginIface() = default;
        };
    } // namespace interfaces
} // namespace rrobots