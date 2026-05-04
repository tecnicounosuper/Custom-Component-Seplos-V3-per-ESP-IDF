#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include <vector>

namespace esphome {
namespace seplos_v3 {

class SeplosV3Component : public Component, public uart::UARTDevice {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;

  void set_bms_count(uint8_t count) { bms_count_ = count; }

 protected:
  uint8_t bms_count_ = 1;
  std::vector<uint8_t> buffer_;

  void parse_packet(const std::vector<uint8_t> &packet);
};

}  // namespace seplos_v3
}  // namespace esphome
