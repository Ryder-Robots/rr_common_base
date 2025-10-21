#ifndef RR_SENSOR_CONSTANTS
#define RR_SENSOR_CONSTANTS

#include <string>

/**
 * List of constants, mostly supported, or expected to be supported.
 */

namespace rr_constants
{
    // Main topic publishing latitude, longitude, altitude, and covariance. Represents the current GNSS position fix.
    const std::string TOPIC_GPS_FIXED = "/gps/fix";     // sensor_msgs::msg::NavSatFix
    const std::string TOPIC_GPS_STATUS = "/gps/status"; // sensor_msgs::msg::NavSatStatus

    // Joystick topic
    const std::string TOPIC_JOY = "/joy"; // sensor_msgs::msg::Joy

    // battery status
    const std::string TOPIC_BATT_STATE = "/battery_state"; // sensor_msgs::msg::BatteryState

    // Image (video stream topics)
    const std::string TOPIC_IMAGE_RAW = "/camera/image_raw";
    const std::string TOPIC_IMAGE_INFO = "/camera/camera_info";
    const std::string TOPIC_IMAGE_RAW_COMPRESSED = "/camera/image_raw/compressed";

    // IMU
    const std::string TOPIC_IMU = "/imu/data"; // sensor_msgs::msg::Imu

    // Topics that sensors are published too, for ulatra sonics.
    const std::string TOPIC_ULTRA_SONIC_LEFT = "/ultrasonic_front_left";     // sensor_msgs::msg::Range
    const std::string TOPIC_ULTRA_SONIC_CENTER = "/ultrasonic_front_center"; // sensor_msgs::msg::Range
    const std::string TOPIC_ULTRA_SONIC_RIGHT = "/ultrasonic_front_right";   // sensor_msgs::msg::Range

    // frame_id for GPS
    // Used in multi-sensor robot setups where GPS provides absolute position data.
    const std::string LINK_GPS = "gps_link";
    // Used when the GPS antenna is rigidly offset from base_link.
    const std::string LINK_GPS_ANTENNA = "gps_antenna_link";

    // Used when GPS is located at or near the robot’s geometric center.
    const std::string LINK_GPS_BASE_LINK = "base_link";

    // no offical frame ID for joysticks, so matching the controller type
    const std::string LINK_JOY_PS4 = "joy-ps4";

    const std::string LINK_BATT_STATE = "power_supply";

    // frame_id for camera sensors
    const std::string LINK_CAM = "camera_link"; // generic raw image
    const std::string LINK_CAM_OPT = "camera_optical_frame";

    // Imu sensor
    const std::string LINK_IMU = "imu_link";

    // frame_links for ultra sonics
    const std::string LINK_ULTRA_SONIC_LEFT = "ultrasonic_front_left_link";
    const std::string LINK_ULTRA_SONIC_CENTER = "ultrasonic_front_center_link";
    const std::string LINK_ULTRA_SONIC_RIGHT = "ultrasonic_front_center_link";
} // namespace rrobot

#endif