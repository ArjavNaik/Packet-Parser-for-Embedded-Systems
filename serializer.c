/*****************************************************//**
 * Author: Arjav Naik
 * Date: 5/19/19
 *
 * Serializer Code
 ********************************************************/

#include "main.h"

/*****************************************************//**
 * Functions required for Serialization
 ********************************************************/
void int32_to_buff(int32_t data, uint8_t offset)
{
  packet_buff[offset + 3] = data & 0xff;
  packet_buff[offset + 2] = (data >> 8) & 0xff;
  packet_buff[offset + 1] = (data >> 16) & 0xff;
  packet_buff[offset] = (data >> 24) & 0xff;
}

void uint32_to_buff(uint32_t data, uint8_t offset)
{
  packet_buff[offset + 3] = data & 0xff;
  packet_buff[offset + 2] = (data >> 8) & 0xff;
  packet_buff[offset + 1] = (data >> 16) & 0xff;
  packet_buff[offset] = (data >> 24) & 0xff;
}

void uint64_to_buff(uint64_t data, uint8_t offset)
{
  packet_buff[offset + 7] = data & 0xff;
  packet_buff[offset + 6] = (data >> 8) & 0xff;
  packet_buff[offset + 5] = (data >> 16) & 0xff;
  packet_buff[offset + 4] = (data >> 24) & 0xff;
  packet_buff[offset + 3] = (data >> 32) & 0xff;
  packet_buff[offset + 2] = (data >> 40) & 0xff;
  packet_buff[offset + 1] = (data >> 48) & 0xff;
  packet_buff[offset] = (data >> 56) & 0xff;
}

/*******************************************************************************
 * Function Name: serialize
 ********************************************************************************
 *
 * Summary:
 *  Serializes the packet structure in a uint8_t buffer
 *
 * Parameters:
 *  Pointer to struct header
 *
 * Return:
 *  EXIT_SUCCESS or EXIT_FAILURE
 *
 *******************************************************************************/
int serialize (struct header *packet_ptr) {
  // serialization
  uint8_t offset = 0;
  uint64_to_buff(packet_ptr -> SRC_ADDR, offset);
  
  offset += 8;
  uint64_to_buff(packet_ptr -> DST_ADDR, offset);
  
  offset += 8;
  uint32_to_buff(packet_ptr -> KEY, offset);
  
  offset += 4;
  int32_to_buff(packet_ptr -> VALUE, offset);

  // print serialized output
  printf("SERIALIZATION\n");
  printf("Packet Buffer = {%"PRIu8, packet_buff[0]);
  for (int i=1; i<24; i++)
    printf(", %"PRIu8, packet_buff[i]);
  printf("}\n\n");

  return EXIT_SUCCESS;
}