/*****************************************************//**
 * Author: Arjav Naik
 * Date: 5/19/19
 *
 * This code demonstrates the deserialization of the input
 * packet data from a file.
 *
 * For demonstrational purposes, serialization of the 
 * deserialized data is also done to get the original
 * input.
 ********************************************************/

#include "main.h"

int main() {
	FILE * pRead = fopen("raw_data_file.txt", "r");

	uint8_t raw_packet_buff[24];

	// to store data from file in a string line
	char line[100] = {0};
	char *ptr;

	if (!pRead)	{
		printf("File cannot be opened\n");
		return EXIT_FAILURE;
	}

	// read data and store in line string
	fgets(line, 100, pRead);

	// extract values from string and store in packet buffer
    for (int i=0; i<24; i++) {
    	raw_packet_buff[i] = (uint8_t)strtol(line, &ptr, 10);
    	//printf("%d ", raw_packet_buff[i]);
    	strcpy(line, ptr);
    }

    //printf("\n");
	
	// to check error response
	uint8_t response;

	// deserialize
	response = deserialize(raw_packet_buff);
	if(response == EXIT_FAILURE)
		return EXIT_FAILURE;
	
	// serialize after packet struct is populated
	response = serialize(&packet);
	if(response == EXIT_FAILURE)
		return EXIT_FAILURE;

	fclose(pRead);
	
	return EXIT_SUCCESS;
}
