#include <assert.h>

#include <string>

// Simple fuzz target for BrokenMethod().
extern "C" int FuzzerEntrypoint(const uint8_t *data, size_t size) {
  if (size < 10) {
    return 0;
  }
  if (data[0] > 125) {
    if (data[1] < 125) {
      if (data[2] == 42) {
	assert(data[3] != 255);
      }
    }
  }
  return 0;
}
