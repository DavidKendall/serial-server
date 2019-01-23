#include <mbed.h>
#include <stdbool.h>
#include <assert.h>

RawSerial server(D1, D0, 115200);
Serial pc(USBTX, USBRX, 115200);

char data[] = "ABCDEFGHIJKLMNOPQRST";

int main() {
  uint32_t i;

  pc.printf("Serial Server\n");
  while (true) {
    
    if (server.getc() == '\xA5') {
      if (server.getc() == '\x50') {
        for (i = 0; i < 20; i++) {
	  if (server.putc(data[i]) != data[i]) {
	    assert(false);
	  }
	}
	pc.printf("Got 0xA5 0x50 - Sent data\n");
      }
    }
  }
}
