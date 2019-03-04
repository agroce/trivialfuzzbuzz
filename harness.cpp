#include <assert.h>

#include <string>

// Simple fuzz target for BrokenMethod().
extern "C" int FuzzerEntrypoint(const uint8_t *data, size_t size) {
  if (size < 50) {
    return 0;
  }
  if (data[0] > 125) {
    if (data[1] < 125) {
      if (data[2] == 42) {
	if (data[3] == 41) {
	  assert(data[3] != 255);
	}
      }
      if (data[2] == 181) {
	assert(data[7] != 255);
      }      
    }
  }
  if ((data[9] == 12) && (data[15] == data[2])) {
    assert(data[28] != 32);
  }        
  return 0;
}
