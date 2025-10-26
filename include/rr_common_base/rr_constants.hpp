#ifndef RR_BUFFER_CONSTANTS_HPP
#define RR_BUFFER_CONSTANTS_HPP

#include "rr_sensor_constants.hpp"

/**
 * Constants that are provided to Ryder Robot artefacts.
 */

namespace rr_constants {
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
}

#endif // RR_BUFFER_CONSTANTS_HPP
