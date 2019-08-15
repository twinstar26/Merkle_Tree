#include <iostream>
#include <string>
#include <vector>
#include "crypto/sha1.h"

class Node {
 public:
  std::string hash;
  std::vector<class Node*> child;

  Node(std::string init = "") { this->hash = init; }
};

static void MDPrint(unsigned char digest[16]) {
  unsigned int i;

  for (i = 0; i < 16; i++) printf("%02x", digest[i]);
}

static unsigned char* MDString(unsigned char* string) {
  MD5_CTX context;
  unsigned char digest[16];
  unsigned int len = strlen(reinterpret_cast<const char*>(string));

  MD5Init(&context);
  MD5Update(&context, string, len);
  MD5Final(digest, &context);
  return digest;
}
