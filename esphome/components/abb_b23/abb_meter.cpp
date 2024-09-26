#include "abb_meter.h"
#include "abb_meter_registers.h"
#include "esphome/core/log.h"

namespace esphome {
namespace abb_meter {

static const char *const TAG = "abb_meter";

static const uint8_t MODBUS_CMD_READ_IN_REGISTERS = 0x04;
static const uint8_t MODBUS_REGISTER_COUNT = 80;  // 74 x 16-bit registers

void SDMMeter::on_modbus_data(const std::vector<uint8_t> &data) {
  if (data.size() < MODBUS_REGISTER_COUNT * 2) {
    ESP_LOGW(TAG, "Invalid size for SDMMeter!");
    return;
  }

  auto abb_meter_get_float = [&](size_t i) -> float {
    uint32_t temp = encode_uint32(data[i], data[i + 1], data[i + 2], data[i + 3]);
    float f;
    memcpy(&f, &temp, sizeof(f));
    return f;
  };

  for (uint8_t i = 0; i < 3; i++) {
    auto phase = this->phases_[i];
    if (!phase.setup)
      continue;

    float voltage = abb_meter_get_float(ABB_PHASE_1_VOLTAGE * 2 + (i * 4));
    float current = abb_meter_get_float(ABB_PHASE_1_CURRENT * 2 + (i * 4));
    float active_power = abb_meter_get_float(ABB_PHASE_1_ACTIVE_POWER * 2 + (i * 4));
    float apparent_power = abb_meter_get_float(ABB_PHASE_1_APPARENT_POWER * 2 + (i * 4));
    float reactive_power = abb_meter_get_float(ABB_PHASE_1_REACTIVE_POWER * 2 + (i * 4));
    float power_factor = abb_meter_get_float(ABB_PHASE_1_POWER_FACTOR * 2 + (i * 4));

    ESP_LOGD(
        TAG,
        "SDMMeter Phase %c: V=%.3f V, I=%.3f A, Active P=%.3f W, Apparent P=%.3f VA, Reactive P=%.3f VAR, PF=%.3f, ",
        i + 'A', voltage, current, active_power, apparent_power, reactive_power, power_factor, phase_angle);
    if (phase.voltage_sensor_ != nullptr)
      phase.voltage_sensor_->publish_state(voltage);
    if (phase.current_sensor_ != nullptr)
      phase.current_sensor_->publish_state(current);
    if (phase.active_power_sensor_ != nullptr)
      phase.active_power_sensor_->publish_state(active_power);
    if (phase.apparent_power_sensor_ != nullptr)
      phase.apparent_power_sensor_->publish_state(apparent_power);
    if (phase.reactive_power_sensor_ != nullptr)
      phase.reactive_power_sensor_->publish_state(reactive_power);
    if (phase.power_factor_sensor_ != nullptr)
      phase.power_factor_sensor_->publish_state(power_factor);
  }

  float total_power = abb_meter_get_float(ABB_TOTAL_SYSTEM_POWER * 2);
  float frequency = abb_meter_get_float(ABB_FREQUENCY * 2);
  float import_active_energy = abb_meter_get_float(ABB_IMPORT_ACTIVE_ENERGY * 2);
  float export_active_energy = abb_meter_get_float(ABB_EXPORT_ACTIVE_ENERGY * 2);
  float import_reactive_energy = abb_meter_get_float(ABB_IMPORT_REACTIVE_ENERGY * 2);
  float export_reactive_energy = abb_meter_get_float(ABB_EXPORT_REACTIVE_ENERGY * 2);

  ESP_LOGD(TAG, "ABBMeter: F=%.3f Hz, Im.A.E=%.3f Wh, Ex.A.E=%.3f Wh, Im.R.E=%.3f VARh, Ex.R.E=%.3f VARh, T.P=%.3f W",
           frequency, import_active_energy, export_active_energy, import_reactive_energy, export_reactive_energy,
           total_power);

  if (this->total_power_sensor_ != nullptr)
    this->total_power_sensor_->publish_state(total_power);
  if (this->frequency_sensor_ != nullptr)
    this->frequency_sensor_->publish_state(frequency);
  if (this->import_active_energy_sensor_ != nullptr)
    this->import_active_energy_sensor_->publish_state(import_active_energy);
  if (this->export_active_energy_sensor_ != nullptr)
    this->export_active_energy_sensor_->publish_state(export_active_energy);
  if (this->import_reactive_energy_sensor_ != nullptr)
    this->import_reactive_energy_sensor_->publish_state(import_reactive_energy);
  if (this->export_reactive_energy_sensor_ != nullptr)
    this->export_reactive_energy_sensor_->publish_state(export_reactive_energy);
}

void SDMMeter::update() { this->send(MODBUS_CMD_READ_IN_REGISTERS, 0, MODBUS_REGISTER_COUNT); }
void SDMMeter::dump_config() {
  ESP_LOGCONFIG(TAG, "ABB Meter:");
  ESP_LOGCONFIG(TAG, "  Address: 0x%02X", this->address_);
  for (uint8_t i = 0; i < 3; i++) {
    auto phase = this->phases_[i];
    if (!phase.setup)
      continue;
    ESP_LOGCONFIG(TAG, "  Phase %c", i + 'A');
    LOG_SENSOR("    ", "Voltage", phase.voltage_sensor_);
    LOG_SENSOR("    ", "Current", phase.current_sensor_);
    LOG_SENSOR("    ", "Active Power", phase.active_power_sensor_);
    LOG_SENSOR("    ", "Apparent Power", phase.apparent_power_sensor_);
    LOG_SENSOR("    ", "Reactive Power", phase.reactive_power_sensor_);
    LOG_SENSOR("    ", "Power Factor", phase.power_factor_sensor_);
  }
  LOG_SENSOR("  ", "Total Power", this->total_power_sensor_);
  LOG_SENSOR("  ", "Frequency", this->frequency_sensor_);
  LOG_SENSOR("  ", "Import Active Energy", this->import_active_energy_sensor_);
  LOG_SENSOR("  ", "Export Active Energy", this->export_active_energy_sensor_);
  LOG_SENSOR("  ", "Import Reactive Energy", this->import_reactive_energy_sensor_);
  LOG_SENSOR("  ", "Export Reactive Energy", this->export_reactive_energy_sensor_);
}

}  // namespace abb_meter
}  // namespace esphome
