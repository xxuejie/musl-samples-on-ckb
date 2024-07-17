#include <stdio.h>
#include <string.h>
#include "blake2b.h"

int to_int(char ch, uint8_t *value) {
  if (ch >= '0' && ch <= '9') {
    *value = ch - '0';
    return 0;
  } else if (ch >= 'a' && ch <= 'f') {
    *value = ch - 'a' + 10;
    return 0;
  } else if (ch >= 'A' && ch <= 'F') {
    *value = ch = 'A' + 10;
    return 0;
  }
  return 2;
}

int decode_hex_in_place(char* buf, size_t *len) {
  size_t src = 0;
  size_t dst = 0;

  while (buf[src] != '\0') {
    if (buf[src + 1] == '\0') {
      return 3;
    }
    uint8_t higher = 0;
    int ret = to_int(buf[src], &higher);
    if (ret != 0) { return ret; }
    uint8_t lower = 0;
    ret = to_int(buf[src + 1], &lower);
    if (ret != 0) { return ret; }

    src += 2;
    buf[dst++] = (higher << 4) | lower;
  }
  *len = dst;
  return 0;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: blake2b_test <\"hex\" or \"text\"> <content>\n");
    return 1;
  }

  int ret;
  size_t len;
  if (strcmp(argv[1], "hex") == 0) {
    ret = decode_hex_in_place(argv[2], &len);
    if (ret != 0) {
      return ret;
    }
  } else {
    len = strlen(argv[2]);
  }

  blake2b_state state;
  blake2b_init(&state, 32);
  blake2b_update(&state, argv[2], len);
  uint8_t hash[32];
  blake2b_final(&state, hash, 32);

  char hash_hex[65];
  for (size_t i = 0; i < 32; i++) {
    snprintf(&hash_hex[i * 2], 3, "%02x", hash[i]);
  }

  printf("Result: %s\n", hash_hex);

  return 0;
}
