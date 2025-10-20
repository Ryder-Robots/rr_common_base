#ifndef RR_RANGE_SENSOR_CONSTANTS
#define RR_RANGE_SENSOR_CONSTANTS

#include <string>

namespace rrobot {
    
    // Topics that sensors are published too, for ulatra sonics.
    const std::string ULTRA_SONIC_LEFT_TOPIC = "/ultrasonic_front_left";
    const std::string ULTRA_SONIC_CENTER_TOPIC = "/ultrasonic_front_center";
    const std::string ULTRA_SONIC_RIGHT_TOPIC = "/ultrasonic_front_right";

    // frame_links for ultra sonics
    const std::string  ULTRA_SONIC_LEFT_LINK = "ultrasonic_front_left_link";
    const std::string  ULTRA_SONIC_CENTER_LINK = "ultrasonic_front_center_link";
    const std::string  ULTRA_SONIC_RIGHT_LINK = "ultrasonic_front_center_link";
}

#endif