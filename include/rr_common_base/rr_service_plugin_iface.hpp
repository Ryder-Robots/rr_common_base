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

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include <memory>


// reference https://docs.ros.org/en/kilted/Tutorials/Intermediate/Writing-an-Action-Server-Client/Cpp.html

namespace rrobots
{
    namespace interfaces
    {
        /**
         * @class RRServicePluginIface
         * @brief plugin that abstracts service implementation for service nodes.
         * 
         * As part of the request/response lifecycle of Ryder Robot service node, sensor will have services
         * that communicate with lower level drivers such as serial drivers. RRServicePluginIface abstracts
         * plumbing of lower service, by allow the concrete service node implementation to either override 
         * the methods, or use them as part of its 'configure' method.
         */
        template<typename ActionT>
        class RRServicePluginIface
        {
          public:
            using GoalHandle = rclcpp_action::ServerGoalHandle<ActionT>;

            virtual ~RRServicePluginIface() = default;

            /**
             * @fn configure
             * @brief last call from concrete implementations configure() method.
             * 
             * Performs any initialization of plugin that is necessary.
             * 
             * @param state - current life cycle transition state, if this state has changed prior to calling on_srv_configure method then the changed state
             * should be used.
             * @param node - actio node 
             * @return state after on_srv_configure has completed.
             */
            virtual rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_srv_configure(const rclcpp_lifecycle::State &state, rclcpp_lifecycle::LifecycleNode::SharedPtr node) = 0;

            /**
             * @fn handle_goal
             * @brief performs any checks to see if the goal can be accepted, this involves verifying that goal has completed data.
             * @param uuid UUID provided by ROS2 that represents this transaction.
             * @param goal Raw goal
             * @return on success ACCEPT_AND_EXECUTE, any other return type should be considered erroneous.
             */
            virtual rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const typename ActionT::Goal> goal) = 0;

            /**
             * @fn handle_cancel
             * @brief handles cancel request.
             * @param goal_handle reference to goal object.
             * @return will return ACCEPT if goal can be cancelled.
             */
            virtual rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandle> goal_handle) = 0;

            /**
             * @fn handle_accepted
             * @brief executes goal. This sets the final response.
             * @param goal_handle reference to goal object.
             */
            virtual void handle_accepted(const std::shared_ptr<GoalHandle> goal_handle) = 0;
        };
    } // namespace interfaces
} // namespace rrobots
