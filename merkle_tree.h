#include <iostream>
#include <string>
#include<cstring>
#include <vector>
#include "crypto/md5c.h"

static std::string MDString(std::string sstring);
static void MDPrint(unsigned char digest[16]);

class Node {
 public:
  std::string hash;
  std::vector<class Node*> child;

  Node(std::string init = "") { this->hash = MDString(init); }
};

static void MDPrint(std::string sdigest) {
  unsigned char *digest=new unsigned char[sdigest.length()+1];
  strcpy((char *)digest,sdigest.c_str());
  
  unsigned int i;

  for (i = 0; i < 16; i++) printf("%02x", digest[i]);
}

static std::string MDString(std::string sstring) {
  unsigned char *ustring=new unsigned char[sstring.length()+1];
  strcpy((char *)ustring,sstring.c_str());

  MD5_CTX context;
  unsigned char digest[16];
  unsigned int len = strlen(reinterpret_cast<const char*>(ustring));

  MD5Init(&context);
  MD5Update(&context, ustring, len);
  MD5Final(digest, &context);
  
  std::string sdigest = reinterpret_cast<char*>(digest);
  return sdigest;
}
