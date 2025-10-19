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
         */
        virtual void initialize(rclcpp::Node::SharedPtr ctl, RrStateMaintainer state_manager) = 0;

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

      protected:
        RrBufFactory() {}
    };
} // namespace rrobot

#endif