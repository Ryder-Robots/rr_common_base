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

    // topic that is used for verifying heartbeats for various services.
    const std::string TOPIC_HEARTBEAT = "/rr/heartbeat";

    // sends current state this topic.
    const std::string TOPIC_STATE_FRAME = "/rr/state_frame";

    // frame_ids
    // frame id for buffer service
    const std::string LINK_BUFF_SVR = "buf_svc";

    // Used in multi-sensor robot setups where GPS provides absolute position data.
    const std::string LINK_GPS = "gps_link";
    // Used when the GPS antenna is rigidly offset from base_link.
    const std::string LINK_GPS_ANTENNA = "gps_antenna_link";

    // Used when GPS is located at or near the robot’s geometric center.
    const std::string LINK_GPS_BASE_LINK = "base_link";

    // no offical frame ID for joysticks, so matching the controller type
    const std::string LINK_JOY_PS4 = "joy_ps4";

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

    // Link Ids for heartbeat frames
    const std::string LINK_HB = "heartbeat_link";

    // Link for state
    const std::string LINK_STATE = "state_link";

} // namespace rr_constants

#endif