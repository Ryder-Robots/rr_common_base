#ifndef RR_BUFFER_CONSTANTS_HPP
#define RR_BUFFER_CONSTANTS_HPP

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
   */

    // Left stick X and Y axis
    const size_t CTRL_AXIS_XL = 0;
    const size_t CTRL_AXIS_YL = 1;

    // Right stick X and Y axis
    const size_t CTRL_AXIS_XR = 2;
    const size_t CTRL_AXIS_YR= 2;

    // buttons
    const size_t CTRL_X_BUTTON = 0;
    const size_t CTRL_SCROLL_DOWN = 11;
    const size_t CTRL_SCROLL_UP = 12;
    const size_t CTRL_SCROLL_LEFT = 13;
    const size_t CTRL_SCROLL_RIGHT = 14;

} // namespace rr_constants

#endif // RR_BUFFER_CONSTANTS_HPP
