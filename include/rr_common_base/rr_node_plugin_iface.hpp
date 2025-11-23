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

#ifndef RR_NODE_PLUGIN_IFACE_HPP
#define RR_NODE_PLUGIN_IFACE_HPP

#include "lifecycle_msgs/msg/state.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "rclcpp/node_interfaces/node_base_interface.hpp"
#include <functional>
#include <memory>

namespace lc = rclcpp_lifecycle;
using LNI = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface;
using LNB = rclcpp::node_interfaces::NodeBaseInterface;

namespace rrobots
{
    namespace interfaces
    {
        /**
         * @class InboundComT
         * @brief interface for plugin subscription callback type.
         */
        template<typename MessageT>
        class InboundComT
        {
          public:
            using MessageType = MessageT;
            using CallbackType = std::function<void(const MessageT &)>;

            virtual ~InboundComT() = default;

            /**
             * @fn configure
             * @brief creates callback within plugin.
             * 
             * expected to be called during the configure section of a lifecycle node.
             * 
             * @param state nodes previous state when this method is called
             * @param callback to execute on subscription
             * @return CallbackReturn returns status result of method.
             */
            virtual LNI::CallbackReturn configure(const lc::State &state, CallbackType cb, LNB node) = 0;

            /**
             * @fn on_activate
             * @brief activates the subscription. callback will now be active
             * @param state nodes previous state when this method is called
             * @return CallbackReturn returns status result of method.
             */
            virtual LNI::CallbackReturn on_activate(const lc::State &state) = 0;

            /**
             * @fn on_deactivate
             * @brief deactivates the subscriber.
             * @param state nodes previous state when this method is called
             * @return CallbackReturn returns status result of method.
             */
            virtual LNI::CallbackReturn on_deactivate(const lc::State &state) = 0;

            /**
             * @fn on_cleanup
             * @brief performs cleanup
             * @param state nodes previous state when this method is called
             * @return CallbackReturn returns status result of method.
             */
            virtual LNI::CallbackReturn on_cleanup(const lc::State &state) = 0;
        };
    } // namespace interfaces
} // namespace rrobots

#endif // RR_NODE_PLUGIN_IFACE_HPP