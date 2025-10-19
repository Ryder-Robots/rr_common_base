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
        virtual ~RrSubscriber() = 0;

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

        /**
         * @fn callback
         * @brief method that will be called when messages are recieved
         * @param event message.
         * 
         * Void should be cast to the specific message that is getting used. This called
         * be done by using the callback to cast the message to the appropriate type
         * then use a further internal private method to perform the processing.
         */
        virtual void callback(std::shared_ptr<void>) = 0;

      protected:
        RrSubscriber() {}
    };
} // namespace rrobot

#endif