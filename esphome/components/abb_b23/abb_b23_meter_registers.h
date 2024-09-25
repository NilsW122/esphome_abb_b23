#pragma once

namespace esphome {
namespace abb_meter {

/* PHASE STATUS REGISTERS */
static const uint16_t ABB_PHASE_1_VOLTAGE = 0x5B00;
static const uint16_t ABB_PHASE_2_VOLTAGE = 0x5B02;
static const uint16_t ABB_PHASE_3_VOLTAGE = 0x5B04;
static const uint16_t ABB_PHASE_1_TO_PHASE_2_VOLTAGE = 0x5B06;
static const uint16_t ABB_PHASE_2_TO_PHASE_3_VOLTAGE = 0x5B08;
static const uint16_t ABB_PHASE_3_TO_PHASE_1_VOLTAGE = 0x5B0A;
static const uint16_t ABB_PHASE_1_CURRENT = 0x5B0C;
static const uint16_t ABB_PHASE_2_CURRENT = 0x5B0E;
static const uint16_t ABB_PHASE_3_CURRENT = 0x5B10;
static const uint16_t ABB_NEUTRAL_CURRENT = 0x5B12;

static const uint16_t ABB_TOTAL_ACTIVE_POWER = 0x5B14;
static const uint16_t ABB_PHASE_1_ACTIVE_POWER = 0x5B16;
static const uint16_t ABB_PHASE_2_ACTIVE_POWER = 0x5B18;
static const uint16_t ABB_PHASE_3_ACTIVE_POWER = 0x5B1A;
static const uint16_t ABB_TOTAL_REACTIVE_POWER = 0x5B1C;
static const uint16_t ABB_PHASE_1_REACTIVE_POWER = 0x5B1E;
static const uint16_t ABB_PHASE_2_REACTIVE_POWER = 0x5B20;
static const uint16_t ABB_PHASE_3_REACTIVE_POWER = 0x5B22;
static const uint16_t ABB_TOTAL_APPARENT_POWER = 0x5B24;
static const uint16_t ABB_PHASE_1_APPARENT_POWER = 0x5B26;
static const uint16_t ABB_PHASE_2_APPARENT_POWER = 0x5B28;
static const uint16_t ABB_PHASE_3_APPARENT_POWER = 0x5B2A;
static const uint16_t ABB_FREQUENCY = 0x5D2C;
static const uint16_t ABB_TOTAL_POWER_FACTOR = 0x5B3A;
static const uint16_t ABB_PHASE_1_POWER_FACTOR = 0x5B3B;
static const uint16_t ABB_PHASE_2_POWER_FACTOR = 0x5B3C;
static const uint16_t ABB_PHASE_3_POWER_FACTOR = 0x5B3D;

static const uint16_t ABB_IMPORT_ACTIVE_ENERGY = 0x5000;
static const uint16_t ABB_EXPORT_ACTIVE_ENERGY = 0x5004;
static const uint16_t ABB_NET_ACTIVE_ENERGY = 0x5008;
static const uint16_t ABB_IMPORT_REACTIVE_ENERGY = 0x500C;
static const uint16_t ABB_EXPORT_REACTIVE_ENERGY = 0x5010;
static const uint16_t ABB_NET_REACTIVE_ENERGY = 0x5014;
static const uint16_t ABB_IMPORT_APPARENT_ENERGY = 0x5018;
static const uint16_t ABB_EXPORT_APPARENT_ENERGY = 0x501C;
static const uint16_t ABB_NET_APPARENT_ENERGY = 0x5020;

static const uint16_t ABB_L1_IMPORT_ACTIVE_ENERGY = 0x5460;
static const uint16_t ABB_L2_IMPORT_ACTIVE_ENERGY = 0x5464;
static const uint16_t ABB_L3_IMPORT_ACTIVE_ENERGY = 0x5468;
static const uint16_t ABB_L1_EXPORT_ACTIVE_ENERGY = 0x546C;
static const uint16_t ABB_L2_EXPORT_ACTIVE_ENERGY = 0x5470;
static const uint16_t ABB_L3_EXPORT_ACTIVE_ENERGY = 0x5474;
static const uint16_t ABB_L1_NET_ACTIVE_ENERGY = 0x5478;
static const uint16_t ABB_L2_NET_ACTIVE_ENERGY = 0x547C;
static const uint16_t ABB_L3_NET_ACTIVE_ENERGY = 0x5480;

static const uint16_t ABB_L1_IMPORT_REACTIVE_ENERGY = 0x5484;
static const uint16_t ABB_L2_IMPORT_REACTIVE_ENERGY = 0x5488;
static const uint16_t ABB_L3_IMPORT_REACTIVE_ENERGY = 0x548C;
static const uint16_t ABB_L1_EXPORT_REACTIVE_ENERGY = 0x5490;
static const uint16_t ABB_L2_EXPORT_REACTIVE_ENERGY = 0x5494;
static const uint16_t ABB_L3_EXPORT_REACTIVE_ENERGY = 0x5498;
static const uint16_t ABB_L1_NET_REACTIVE_ENERGY = 0x549C;
static const uint16_t ABB_L2_NET_REACTIVE_ENERGY = 0x54A0;
static const uint16_t ABB_L3_NET_REACTIVE_ENERGY = 0x54A4;

static const uint16_t ABB_L1_IMPORT_APPARENT_ENERGY = 0x54A8;
static const uint16_t ABB_L2_IMPORT_APPARENT_ENERGY = 0x54AC;
static const uint16_t ABB_L3_IMPORT_APPARENT_ENERGY = 0x54B0;
static const uint16_t ABB_L1_EXPORT_APPARENT_ENERGY = 0x54B4;
static const uint16_t ABB_L2_EXPORT_APPARENT_ENERGY = 0x54B8;
static const uint16_t ABB_L3_EXPORT_APPARENT_ENERGY = 0x54BC;
static const uint16_t ABB_L1_NET_APPARENT_ENERGY = 0x54C0;
static const uint16_t ABB_L2_NET_APPARENT_ENERGY = 0x54C4;
static const uint16_t ABB_L3_NET_APPARENT_ENERGY = 0x54C8;

}  // namespace abb_meter
}  // namespace esphome
