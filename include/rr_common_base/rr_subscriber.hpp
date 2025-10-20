#ifndef RR_SUBSCRIBER_HPP
#define RR_SUBSCRIBER_HPP

#include <rclcpp/logger.hpp>
#include <rr_common_base/rr_state_maintainer.hpp>
#include <string>

namespace rrobot
{

    /**
     * @class RrSubscriber
     * @brief base class for Ryder Robot subscription services.
     */
    class RrSubscriber
    {
      public:
        virtual ~RrSubscriber() = default;

        /**
         * @fn get_topic_param
         * @brief returns ros args param for setting topic.
         */
        virtual std::string get_topic_param() = 0;


        /**
         * @fn get_topic_default
         * @brief return default topic
         */
        virtual std::string get_topic_default() = 0;


        /**
         * @fn set_logger
         * @brief set the logger for internal use of the subscriber
         * @param node logger
         */
        virtual void set_logger(rclcpp::Logger) = 0;

        /**
         * @fn set_state_handler
         * @brief set shared state handler
         * @param shared state handler pointer
         */
        virtual void set_state_handler(std::shared_ptr<RrStateMaintainer>) = 0;

      protected:
        RrSubscriber() {}
    };


    /**
     * @class RrSubscriberGps
     * 
     * Handles subscriptions for GPS.
     */
    class RrSubscriberGps : public RrSubscriber
    {
      public:
        /**
             * @fn callback
             * @brief callback for subscriptions to GPS service.
             */
        virtual void callback(const sensor_msgs::msg::NavSatFix::SharedPtr) = 0;
    };

    /**
     * @class RrSubscriberJoy
     */
    class RrSubscriberJoy : public RrSubscriber
    {
      public:
        virtual void callback(const sensor_msgs::msg::Joy::SharedPtr) = 0;
    };

    /**
     * @class RrSubscriberBattState
     * 
     * subscriber for battery state
     */
    class RrSubscriberBattState : public RrSubscriber
    {
      public:
        virtual void callback(const sensor_msgs::msg::BatteryState::SharedPtr) = 0;
    };

    class RrImageSubscriber : public RrSubscriber
    {
      public:
        virtual void callback(const sensor_msgs::msg::Image::SharedPtr) = 0;
    };

    class RrImuSubscriber : public RrSubscriber
    {
      public:
        virtual void callback(const sensor_msgs::msg::Imu::SharedPtr) = 0;
    };

    class RrRangesSubscriber : public RrSubscriber
    {
      public:
        virtual void callback(const sensor_msgs::msg::Range::SharedPtr) = 0;
    };

} // namespace rrobot

#endif