/*****************************************************//**
 * Author: Arjav Naik
 * Date: 5/19/19
 *
 * Deserializer Code
 ********************************************************/

#include "main.h"

/*****************************************************//**
 * Functions required for Deserialization
 ********************************************************/
int32_t int32_from_buff(const uint8_t *ptr)
{
  return
    ((int32_t)ptr[3])
    | ((int32_t)ptr[2] << 8)
    | ((int32_t)ptr[1] << 16)
    | ((int32_t)ptr[0] << 24)
  ;
}

uint32_t uint32_from_buff(const uint8_t *ptr)
{
  return
    ((uint32_t)ptr[3])
    | ((uint32_t)ptr[2] << 8)
    | ((uint32_t)ptr[1] << 16)
    | ((uint32_t)ptr[0] << 24)
  ;
}

uint64_t uint64_from_buff(const uint8_t *ptr)
{
  return
    ((uint64_t)ptr[7])
    | ((uint64_t)ptr[6] << 8)
    | ((uint64_t)ptr[5] << 16)
    | ((uint64_t)ptr[4] << 24)
	  | ((uint64_t)ptr[3] << 32)
	  | ((uint64_t)ptr[2] << 40)
	  | ((uint64_t)ptr[1] << 48)
	  | ((uint64_t)ptr[0] << 56)
  ;
}

/*******************************************************************************
 * Function Name: deserialize
 ********************************************************************************
 *
 * Summary:
 *  Deserializes the packet buffer into the packet structure
 *
 * Parameters:
 *  Pointer to packet buffer
 *
 * Return:
 *  EXIT_SUCCESS or EXIT_FAILURE
 *
 *******************************************************************************/
int deserialize (uint8_t *packet_buff) {
	// deserialize packet_buff and store data in packet struct
	packet.SRC_ADDR = uint64_from_buff ( packet_buff );
	packet.DST_ADDR = uint64_from_buff ( &packet_buff[8] );
	packet.KEY 		  = uint32_from_buff ( &packet_buff[16] );
	packet.VALUE 	  = int32_from_buff  ( &packet_buff[20] );

	// print deserialized output
  printf("DESERIALIZATION\n");
	printf("SRC_ADDR = %"PRIu64"\n", packet.SRC_ADDR);
	printf("DST_ADDR = %"PRIu64"\n", packet.DST_ADDR);
	printf("KEY = %"PRIu32"\n", packet.KEY);
	printf("VALUE = %"PRId32"\n\n", packet.VALUE);

	return EXIT_SUCCESS;
}