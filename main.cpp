// https://os.mbed.com/docs/mbed-os/v6.6/apis/serial-uart-apis.html

#include "mbed.h"
static DigitalOut led(LED1);
static BufferedSerial serial_port(PA_9, PA_10, 9600);

int main(void)
{ 
    char buf[32] = {0};
    char buf2[64];
    sprintf(buf2, "Mbed OS version %d.%d.%d\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);

    while (1) {
        if (uint32_t num = serial_port.read(buf, sizeof(buf))) {            // if RX
            led = !led; 
            serial_port.write(buf, num);  // Echo to terminal         
            serial_port.write(buf2, 24);  // buffer to terminal
        }
    }
}