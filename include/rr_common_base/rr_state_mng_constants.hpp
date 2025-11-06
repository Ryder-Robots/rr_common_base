#ifndef RR_STATE_MNG_CONSTANTS_HPP
#define RR_STATE_MNG_CONSTANTS_HPP

/**
 * The following constants are used for communication with the state manager service.
 */
namespace rr_constants
{
    // define state battery request
    #define STATE_BAT_REQ "state_bat_req"

    // define state GPS request
    #define STATE_GPS_REQ "state_gps_req"

    // define state image request
    #define STATE_IMG_REQ "state_img_req"

    // define state IMU request
    #define STATE_IMU_REQ "state_imu_req"

    // define state joystick request
    #define STATE_JOY_REQ "state_joy_req"

    // define state range request
    #define STATE_RNG_REQ "state_rng_req"

    // define state response
    #define STATE_RESPONSE "state_response"
}

#endif