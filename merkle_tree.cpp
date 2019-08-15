#include "merkle_tree.h"
#include "crypto/md5c.h"

static void MDString (char *string)
{
  MD5_CTX context;
  unsigned char digest[16];
  unsigned int len = strlen (string);

  MD5Init (&context);
  MD5Update (&context, string, len);
  MD5Final (digest, &context);

  std::cout<<"md5 is  "<<string<<std::endl;
  // MDPrint (digest);
  printf ("\n");
}



int main()
{
    Node root = Node();

    Node left = Node("this is left");
    Node right = Node("this is right");

    root.child.push_back(&left);
    root.child.push_back(&right);

    char s[] = "hello@6969";
    MDString(s);
return 0;
}