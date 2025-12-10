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


#ifndef RR_BUFFER_CONSTANTS_HPP
#define RR_BUFFER_CONSTANTS_HPP

#include <cstdint>
#include "rr_sensor_constants.hpp"

/**
 * Constants that are provided to Ryder Robot artefacts.
 */

namespace rr_constants
{
    const std::string TOPIC_BUFFER_SERVICE = "/rr/buffer";

    /**
     * Constants relating to battery status.
     * 
     * Battery Status attributes:
     * 
     * * voltage (float32): Battery voltage in volts (V).
     * * temperature (float32): Battery temperature in degrees Celsius (C).
     * * current (float32): Battery current, positive when discharging, negative when charging (amperes).
     * * charge (float32): Charge remaining in ampere-hours (Ah).
     * * capacity (float32): Battery capacity in ampere-hours. For a 3200 mAh battery this would be 3.2, Indicating
     *   3.2 Amp hours.
     * * design_capacity (float32): Original design capacity (Ah).
     * * percentage (float32): State of charge in range [0.0, 1.0].
     * --- 0.0 means the battery is fully discharged (empty).
     * --- 1.0 means the battery is fully charged (100% full).
     * --- Each cell is represented within this task.
     * * power_supply_status (uint8): Status enum (charging, discharging, full, etc.) matching Linux kernel power supply states.
     * * power_supply_health (uint8): Health enum (good, overheat, dead, etc.).
     * * power_supply_technology (uint8): Battery chemistry type (Li-ion, NiMH, etc.).
     * * present (bool): Whether battery is physically present.
     * * cell_voltage (float32[]): Voltage of individual battery cells.
     * * cell_temperature (float32[]): Temperature of individual battery cells.
     * * location (string): Physical location of battery (optional).
     * * serial_number (string): Battery serial number (optional).
     * 
     * Reference: https://docs.ros2.org/foxy/api/sensor_msgs/msg/BatteryState.html
     * 
     */

    const std::string BATT_LOC_BASE = "base";
    const std::string BATT_LOC_LEFT = "left_battery";
    const std::string BATT_LOC_RIGHT = "right_battery";

    /**
   * The following constants are true for PS4 joysticks not sure if it is true about all controllers.
   * 
   * Note lists for games controllers are split into two parts, sticks which are an anolog component which 
   * gives a value between -1 to 1,  where 0 is centered. 
   * 
   * Buttons which are the various button values on the game controller, these are generally boolean values
   * that can be represented as 1 or 0. Not all buttons are mapped out below.
   * 
   * Note that mapping are referenced from https://docs.ros.org/en/ros2_packages/jazzy/api/joy/index.html
   */

    const size_t JOY_A_CROSS = 0;
    const size_t JOY_B_CIRCLE = 1;
    const size_t JOY_X_SQUARE = 2;
    const size_t JOY_Y_TRIANGLE = 3;
    const size_t JOY_BACK_SELECT = 4;
    const size_t JOY_GUIDE = 5;
    const size_t JOY_START = 6;
    const size_t JOY_LEFTSTICK = 7;
    const size_t JOY_RIGHTSTICK = 8;
    const size_t JOY_LEFTSHOULDER = 9;
    const size_t JOY_RIGHTSHOULDER = 10;
    const size_t JOY_DPAD_UP = 11;
    const size_t JOY_DPAD_DOWN = 12;
    const size_t JOY_DPAD_LEFT = 13;
    const size_t JOY_DPAD_RIGHT = 14;
    const size_t JOY_MISC1 = 15;    // Depends on the controller manufacturer, but is usually at a similar location on the controller as back/start
    const size_t JOY_PADDLE1 = 16;  //Upper left, facing the back of the controller if present
    const size_t JOY_PADDLE2 = 17;  // Upper right, facing the back of the controller if present
    const size_t JOY_PADDLE3 = 18;  // Lower left, facing the back of the controller if present
    const size_t JOY_PADDLE4 = 19;  // Lower right, facing the back of the controller if present
    const size_t JOY_TOUCHPAD = 20; // If present. Button status only

    const size_t JOY_AXES_LEFTX = 0;
    const size_t JOY_AXES_LEFTY = 1;
    const size_t JOY_AXES_RIGHTX = 2;
    const size_t JOY_AXES_RIGHTY = 3;
    const size_t JOY_AXES_TRIGGERLEFT = 4;
    const size_t JOY_AXES_TRIGGERRIGHT = 5;

    const int8_t ACTION_STATE_PREPARING = 0;
    const int8_t ACTION_STATE_SENT = 1;
    const int8_t ACTION_STATE_PROCESSING = 2;
    const int8_t ACTION_STATE_SUCCESS = 3;
    const int8_t ACTION_STATE_FAIL= 4;
    const int8_t ACTION_STATE_TIMEOUT = 5;

} // namespace rr_constants

#endif // RR_BUFFER_CONSTANTS_HPP
