# RR Common Base

A common base repository for Ryder Robots ROS2 packages. This package provides shared headers and interfaces used across Ryder Robots software.

## Installation

### From APT Repository

```bash
# One-time setup (if not already done)
curl -fsSL https://ryder-robots.github.io/rr-apt/public.gpg | sudo gpg --dearmor -o /usr/share/keyrings/rr-apt.gpg
echo "deb [signed-by=/usr/share/keyrings/rr-apt.gpg] https://ryder-robots.github.io/rr-apt noble main" | sudo tee /etc/apt/sources.list.d/rr-apt.list

# Install
sudo apt update
sudo apt install ros-kilted-rr-common-base
```
