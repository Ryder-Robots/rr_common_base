#ifndef RR_STATE_MAINTAINER_HPP
#define RR_STATE_MAINTAINER_HPP

#include "rclcpp/logger.hpp"
#include "rr_interfaces/msg/buffer_response.hpp"
#include "rr_interfaces/msg/feature_set.hpp"
#include <list>
#include <mutex>
#include <shared_mutex>

namespace rrobot
{
    /**
     * @class RrStateMaintainer
     * @brief Shared object that maintains state variables accross different subscribers, and publisers.
     * 
     * when setter is activated, state remains until the setter is written to again.
     * 
     * Supported feature are:
     *   - GPS
     *   - Peripheral controllers (joysticks)
     *   - battery state (mangager) such BMS
     *   - camera streams
     *   - range detection devices, such as ultra sonic
     *   - IMU
     * 
     * State is used to send to normalization layer.
     * 
     * For image encoding refer to https://docs.ros.org/en/noetic/api/sensor_msgs/html/image__encodings_8h.html
     * Documenation on images can be found at https://docs.ros.org/en/noetic/api/sensor_msgs/html/msg/Image.html
     */
    class RrStateMaintainer
    {
      public:
        virtual ~RrStateMaintainer() = 0;
        /**
         * @fn set_gps has_gps get_gps
         * @brief setters and getters relating to gps
         */
        virtual void set_gps(const sensor_msgs::msg::NavSatFix gps) = 0;
        virtual bool has_gps() = 0;
        virtual const sensor_msgs::msg::NavSatFix get_gps() = 0;

        /**
         * @fn set_joystick has_joystick get_joystick
         * @brief setters and getters relating to joystick
         */
        virtual void set_joystick(const sensor_msgs::msg::Joy joystick) = 0;
        virtual bool has_joystick() = 0;
        virtual const sensor_msgs::msg::Joy get_joystick() = 0;

        /**
         * @fn set_batt_state get_batt_state has_batt_state
         * @brief setters and getters relating to battery state
         */
        virtual void set_batt_state(const sensor_msgs::msg::BatteryState) = 0;
        virtual bool has_batt_state() = 0;
        virtual const sensor_msgs::msg::BatteryState get_batt_state() = 0;

        /**
         * @fn set_image has_image get_image
         * @brief setters and getters relating to images (video stream)
         */
        virtual void set_image(const sensor_msgs::msg::Image) = 0;
        virtual bool has_image() = 0;
        virtual const sensor_msgs::msg::Image get_image() = 0;

        /**
         * @fn set_imu has_imu get_imu
         * @brief setters and getters relating to imu (video stream)
         */
        virtual void set_imu(const sensor_msgs::msg::Imu) = 0;
        virtual bool has_imu() = 0;
        virtual const sensor_msgs::msg::Imu get_imu() = 0;

        /**
         * @fn set_imu has_imu get_imu
         * @brief setters and getters relating to imu (video stream)
         */
        virtual void set_ranges(const std::list<sensor_msgs::msg::Range>) = 0;
        virtual bool has_ranges() = 0;
        virtual const std::list<sensor_msgs::msg::Range> get_ranges() = 0;

        virtual const rr_interfaces::msg::FeatureSet get_feature_set() = 0;

        virtual void init(rclcpp::Logger) = 0;

      protected:
        RrStateMaintainer() {}
    };
} // namespace rrobot

#endif