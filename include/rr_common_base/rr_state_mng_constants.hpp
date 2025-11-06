#ifndef RR_STATE_MNG_CONSTANTS_HPP
#define RR_STATE_MNG_CONSTANTS_HPP

#include <string>
/**
 * The following constants are used for communication with the state manager service.
 */
namespace rr_constants
{
    // define state battery request
    const std::string STATE_BAT_REQ = "state_bat_req";

    // define state GPS request
    const std::string STATE_GPS_REQ = "state_gps_req";

    // define state image request
    const std::string STATE_IMG_REQ = "state_img_req";

    // define state IMU request
    const std::string STATE_IMU_REQ = "state_imu_req";

    // define state joystick request
    const std::string STATE_JOY_REQ = "state_joy_req";

    // define state range request
    const std::string STATE_RNG_REQ = "state_rng_req";

    // define state response
    const std::string STATE_RESPONSE = "state_response";
} // namespace rr_constants

#endif