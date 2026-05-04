#include "seplos_v3.h"
#include "esphome/core/log.h"

namespace esphome {
namespace seplos_v3 {

static const char *const TAG = "seplos_v3";

void SeplosV3Component::setup() {
  ESP_LOGI(TAG, "Seplos V3 Custom Component started on ESP-IDF");
}

void SeplosV3Component::loop() {
  while (available()) {
    uint8_t byte = read();
    buffer_.push_back(byte);

    // Seplos packets usually start with 0x7E and end with 0x7E
    if (byte == 0x7E && buffer_.size() > 10) {
      parse_packet(buffer_);
      buffer_.clear();
    }

    if (buffer_.size() > 300) buffer_.clear(); // safety
  }
}

void SeplosV3Component::parse_packet(const std::vector<uint8_t> &packet) {
  ESP_LOGI(TAG, "Received valid packet (%d bytes): %s", packet.size(), 
           format_hex_pretty(packet.data(), packet.size()).c_str());
  // Qui aggiungeremo in seguito il parsing vero e proprio dei valori
}

void SeplosV3Component::dump_config() {
  ESP_LOGCONFIG(TAG, "Seplos V3 Custom Component");
}

}  // namespace seplos_v3
}  // namespace esphome
