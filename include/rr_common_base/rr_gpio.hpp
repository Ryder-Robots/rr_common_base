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

/*
 * This interface can be used by GPIO plugins, note that while this header attempts to be generic. The implementations
 * are not. For example the GPIO implementation for Pi 4B MUST not be used on a Jetson, or Pi5. This will
 * risk damage to hardware. For development purposes non working implementations will be supplied these can
 * act as interfaces for Gazebo simulation and testing on unsupported hardware, or test generic logic
 * that is not hardware specific.
 *
 * This header assumes that direct headers to the SBCs GPIO interface is required.
 */

#pragma once

#include <string>
#include <map>
#include <variant>
#include <cstdint>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"

namespace rrobots
{
namespace interfaces
{
/**
 * @class RRGPIOInterface
 * @brief interface for GPIO plugins.
 */
class RRGPIOInterface
{
public:
  using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;
  using ValueType = std::variant<int, std::string>;

  RRGPIOInterface() = default;
  virtual ~RRGPIOInterface() = default;

  /**
   * callback for that is used for GPIO interrupts, this is used for both testing and real hardware, but the
   * implementation will differ. Note that it is uses some very traditional syntax, this is because it will need to be
   * used within very low level C libraries, and this is the most compatible way to do so.
   *
   * @param gpio the GPIO pin that triggered the interrupt.
   * @param level the level of the pin when the interrupt was triggered, 0 = LOW, 1 = HIGH.
   * @param tick the system tick when the interrupt was triggered, this is the number of microseconds since system boot.
   * @param userdata a pointer to user data that can be passed to the callback, this can be used to pass a pointer to
   * the GPIO interface object, or any other data that is required within the callback.
   * Note that this callback is expected to be called within an interrupt service routine, so it should be designed to
   * be as efficient as possible, and should not perform any blocking operations. It is the responsibility of the
   * implementer to ensure that the callback is thread safe, and does not cause any race conditions.
   */
  using gpio_isr_func_ex_t = void (*)(int gpio, int level, uint32_t tick, void* userdata);

  /**
   * @fn configure
   * @brief Updates internal variables and prepares for activation, but does not engage hardware. This is expected to be
   * called during the configure section of a lifecycle node.
   *
   * At this stage hardware is not engaged, only configuration is supplied, if it is required.
   *
   * @param state nodes previous state when this method is called.
   * @param node parent that owns subscription.
   * @return CallbackReturn returns status result of method.
   */
  virtual CallbackReturn configure(const rclcpp_lifecycle::State& state,
                                   rclcpp_lifecycle::LifecycleNode::SharedPtr node) = 0;

  /**
   * @fn on_activate
   * @brief engages hardware and makes the GPIO interface active. This is expected to be called during the activate
   * section of a lifecycle node.
   * @param state nodes previous state when this method is called
   * @return CallbackReturn returns status result of method.
   */
  virtual CallbackReturn on_activate(const rclcpp_lifecycle::State& state) = 0;

  /**
   * @fn on_deactivate
   * @brief Disengages hardware, and leaves GPIO in a clean state.
   * @param state nodes previous state when this method is called
   * @return CallbackReturn returns status result of method.
   */
  virtual CallbackReturn on_deactivate(const rclcpp_lifecycle::State& state) = 0;

  /**
   * @fn on_cleanup
   * @brief deletes any temporary files, or state files, that are required for the GPIO interface to operate. This is
   * expected to be called during the cleanup section of a lifecycle node.
   * @param state nodes previous state when this method is called
   * @return CallbackReturn returns status result of method.
   */
  virtual CallbackReturn on_cleanup(const rclcpp_lifecycle::State& state) = 0;

  // Below are commands provided by this interface, note that object should be available
  // by calling node so hardware operations can be performed if needed.

  /**
   * @fn hardware_report
   * @brief returns a map reporting the current hardware that the plugin believes it is controlling, this can be
   * used for debugging and verification purposes. For example a GPIO plugin for a Pi 4B should report that it is
   * controlling a Pi 4B, and not a Jetson or Pi 5. this should include the software version.
   *
   * expected map keys:
   * hardware_revision: integer that represents the hardware revision. For instance 17 for 4B
   * hardware_name: string that represents the hardware name. For instance "Raspberry Pi 4B"
   * software_version: string that represents the software version of the GPIO plugin.
   */
  virtual std::map<std::string, ValueType> hardware_report() const = 0;

  /**
   * @fn initialise
   * @brief performs any hardware initialisation that is required before GPIO pins can be used.
   *
   * This method is expected to be called once after the plugin is constructed, but before configure is called. it
   * should be noted that this method MUST only be called under testing conditions, and should be implemented as part of
   * on_activate().
   *
   * @return int returns 0 on success, negative values on failure.
   */
  virtual int initialise() = 0;

  /**
   * @fn terminate
   * @brief performs any hardware termination that is required before the plugin is destroyed.
   *
   * Note that this method MUST only be called under testing conditions, and should be
   * implemented as part of on_deactivate().
   */
  virtual int terminate() = 0;

  /**
   * @fn set_pin_mode
   * @brief sets the pin mode for a specific pin. Use the PI_INPUT, PI_OUTPUT, and PI_ALTx
   * constants defined in this class. Mode values follow the pigpio convention:
   * 0 = INPUT (PI_INPUT)
   * 1 = OUTPUT (PI_OUTPUT)
   * 2 = ALT5 (PI_ALT5)
   * 3 = ALT4 (PI_ALT4)
   * 4 = ALT0 (PI_ALT0)
   * 5 = ALT1 (PI_ALT1)
   * 6 = ALT2 (PI_ALT2)
   * 7 = ALT3 (PI_ALT3)
   *
   * @param pin GPIO pin number to set mode for.
   * @param mode mode to set pin to.
   * @return int returns 0 on success, negative values on failure.
   */
  virtual int set_pin_mode(unsigned pin, int mode) = 0;

  /**
   * @fn set_pull_up_down
   * @brief sets the pull up/down resistors for a specific pin.  Modes are
   * 0 = OFF
   * 1 = PULL UP
   * 2 = PULL DOWN
   */
  virtual int set_pull_up_down(unsigned pin, unsigned pud) = 0;

  /**
   * @fn tick
   * @brief Returns the current system tick.
   *
   * Tick is the number of microseconds since system boot.
   *
   * As tick is an unsigned 32 bit quantity it wraps around after
   * 2^32 microseconds, which is approximately 1 hour 12 minutes.
   *
   * You don't need to worry about the wrap around as long as you
   * take a tick (uint32_t) from another tick, i.e. the following
   * code will always provide the correct difference.
   * uint32_t start = gpio->tick();
   * @return uint32_t
   *
   */
  virtual uint32_t tick(void) = 0;

  /**
   * @fn set_isr_func_ex
   * @brief sets an interrupt service routine for a specific pin and edge.
   *
   * @param gpio GPIO pin number to set ISR for.
   * @param edge edge to trigger on, 0 = LOW, 1 = HIGH, 2 = BOTH.
   * @param timeout timeout in milliseconds for the ISR to be called after the edge is detected, if the edge is not
   * detected within the timeout period, the ISR will be called with level = -1. If timeout is 0, the ISR will be called
   * immediately after the edge is detected.
   * @param func function pointer to the ISR callback function.
   * @param userdata pointer to user data that will be passed to the ISR callback function.
   * @return int returns 0 on success, negative values on failure.
   */
  virtual int set_isr_func_ex(unsigned gpio, unsigned edge, int timeout, gpio_isr_func_ex_t func, void* userdata) = 0;

  /**
   * @fn gpio_write
   * @brief writes a value to a specific GPIO pin.
   * @param gpio GPIO pin number to write to.
   * @param level value to write to pin, 0 = LOW, 1 =
   * HIGH.
   * @return int returns 0 on success, negative values on failure.
   * Note that this method is provided as a more direct way to write to GPIO pins,
   * and may be used within ISR callbacks.
   */
  virtual int gpio_write(unsigned gpio, unsigned level) = 0;

  /**
   * @fn gpio_hardware_pwm
   * @brief sets a hardware PWM signal on a specific GPIO pin.
   * @param pin GPIO pin number to set PWM on.
   * @param pwm_freq frequency of the PWM signal in Hz.
   * @param pwm_duty_cycle duty cycle of the PWM signal in range [0, 100], where 0 means the signal is always LOW, and
   * 100 means the signal is always HIGH.
   * @return int returns 0 on success, negative values on failure.
   * Note that this method is provided as a more direct way to set hardware PWM on GPIO pins, and may be used within ISR
   * callbacks. Not all GPIO pins may support hardware PWM.
   */
  virtual int gpio_hardware_pwm(unsigned pin, unsigned pwm_freq, unsigned pwm_duty_cycle) = 0;

  static constexpr int PI_OFF = 0;
  static constexpr int PI_ON = 1;

  static constexpr int PI_LOW = 0;
  static constexpr int PI_HIGH = 1;

  /* mode: 0-7 */

  static constexpr int PI_INPUT = 0;
  static constexpr int PI_OUTPUT = 1;
  static constexpr int PI_ALT0 = 4;
  static constexpr int PI_ALT1 = 5;
  static constexpr int PI_ALT2 = 6;
  static constexpr int PI_ALT3 = 7;
  static constexpr int PI_ALT4 = 3;
  static constexpr int PI_ALT5 = 2;

  /* pud: 0-2 */

  static constexpr int PI_PUD_OFF = 0;
  static constexpr int PI_PUD_DOWN = 1;
  static constexpr int PI_PUD_UP = 2;
};
}  // namespace interfaces
}  // namespace rrobots