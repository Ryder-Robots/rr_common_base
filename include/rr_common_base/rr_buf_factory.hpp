#ifndef RR_BUF_FACTORY
#define RR_BUF_FACTORY

#include "rclcpp/rclcpp.hpp"
#include "rr_common_base/rr_state_maintainer.hpp"

namespace rrobot
{
    class RrBufFactory
    {
      public:
        /**
         * @fn initialize
         * @brief initialize each subscriber, injects logger and state_manager in each
         * subscriber, and links them to ctl.
         * 
         * @param ctl controlling node
         * @param state_manager common state managed by calling node
         */
        virtual void initialize(rclcpp::Node::SharedPtr ctl, std::shared_ptr<RrStateMaintainer> state_manager) = 0;

        /**
         * @fn tear_down
         * @brief perform any tear down activities.
         */
        virtual void tear_down() = 0;

        /**
         * @fn ~RrBufFactory
         * @brief perform any clean up operations.
         */
        virtual ~RrBufFactory() = default;

        /**
         * @fn sub_img_group
         * @brief returns subscription group for image collection.
         */
        virtual rclcpp::CallbackGroup::SharedPtr sub_img_group() = 0;

        /**
         * @fn sub_sensor_group
         * @brief returns subscription group for sensors.
         * 
         * Sensors are on the same callback group, this means they run in the same thread.
         */
        virtual rclcpp::CallbackGroup::SharedPtr sub_sensor_group() = 0;

      protected:
        RrBufFactory() {}
    };
} // namespace rrobot

#endif