#pragma once
#include <stdint.h>

typedef enum {
	DEVICE_CMD_LOG_MESSAGE = 0x00U,
	DEVICE_CMD_START_TEST,
	DEVICE_CMD_STOP_TEST,
	DEVICE_CMD_TRIGGER_ENABLE,
	DEVICE_CMD_TRIGGER_DISABLE,
	DEVICE_CMD_DEBUG_LOG_ENABLE,
	DEVICE_CMD_DEBUG_LOG_DISABLE,
	DEVICE_CMD_PING,
	DEVICE_CMD_RESET_MCU,
	DEVICE_CMD_COUNT,
} DeviceCmd;

#pragma pack(push, 1)
typedef struct {
	DeviceCmd id;
	union {
		struct {
			uint32_t periodMs;
			uint32_t count;
		};
	};
} Command;
#pragma pack(pop)

void sendCommand(Command *cmd);
void parceInData(char* data);