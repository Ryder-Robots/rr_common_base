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

#ifndef RR_NODE_JOY_PLUGIN_IFACE_HPP
#define RR_NODE_JOY_PLUGIN_IFACE_HPP

#include "rr_common_base/rr_node_plugin_iface.hpp"
#include "sensor_msgs/msg/joy.hpp"

namespace rrobots
{
    namespace interfaces
    {
        /**
         * @class RrNodeJoyPluginIface
         * @brief extends InboundComT for ingress messages specific to joystick messages.
         * 
         * Interface is intended for plugins that hides the plumbing of a specific interface from a lifecycle node.
         * For instance drones may use ORB messages and interface with QGroundControl flight controllers, where as a 
         * rover or mousebot may interface with a custom client. However the joystick messages and consequent nodes
         * business logic is the same for both, the concrete implementation is expected to hide that detail so that
         * the node can implement business logic which is general to both types of implementations.
         */
        class RrNodeJoyPluginIface : public InboundComT<sensor_msgs::msg::Joy>
        {
          public:
            virtual ~RrNodeJoyPluginIface() = default;
        };
    } // namespace interfaces
} // namespace rrobots

#endif // RR_NODE_JOY_PLUGIN_IFACE_HPP