This code is developed to serialize and deserialize data.

As per requirements, deserialization of buffer data from external file is done and the packet structure is populated and printed.

Additionally, serialization of the populated packet is done and stored in a packet buffer.

Serialization and Deserialization function and are included in the src folder.

The main.h file is included in the inc folder. 

Unit testing has been done using CUnit testing framework to confirm the functionality.
To install CUnit:
> sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev

COMPILATION STEPS:
For normal code compilation type in terminal:
> make build

To run the code:
> ./build

To clean .o and executable files:
> make clean

For UnitTest (make build must be done before this):
> make run

To run UnitTest:
> ./run

To clean unit test executable:
> make uclean


Functionality which are remaining:-
1) Reading the raw packet buffer data from the file is not complete. I was only able to load one raw packet buffer from the txt file.
The file reading was done using fgets. Even fscanf function was used to read multiple raw packet buffer and I tried to detect EOF but it was
not giving the correct results.
2) Unit testing which is done is using Cunit instead using pyhton. 