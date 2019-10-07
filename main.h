#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

// Packet structure
struct header {
	uint64_t SRC_ADDR;
	uint64_t DST_ADDR;
	uint32_t KEY;
	int32_t VALUE;
} packet;

// Packet buffer
uint8_t packet_buff[24];

// Serializer function declarations
int serialize (struct header *packet_ptr);

// Deserializer function declarations
int deserialize (uint8_t *packet_buff);