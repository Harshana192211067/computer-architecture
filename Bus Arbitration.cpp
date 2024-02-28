#include <stdio.h>
 
#define NUM_DEVICES 3
 
// Function to simulate bus arbitration using round-robin
int busArbitrationRoundRobin(int currentDevice) {
	return (currentDevice + 1) % NUM_DEVICES;
}
 
int main() {
	int currentDevice = 0;  // Start with the first device
 
	printf("Bus Arbitration Simulation\n");
 
	// Simulate 10 cycles of bus access
	for (int cycle = 1; cycle <= 10; cycle++) {
        printf("Cycle %d: Device %d accesses the bus\n", cycle, currentDevice);
 
    	// Perform some operation or task for the device accessing the bus
    	// ...
 
    	// Update the current device using round-robin arbitration
    	currentDevice = busArbitrationRoundRobin(currentDevice);
 
    	// Print a newline for better readability
        printf("\n");
	}
 
    return 0;
}

