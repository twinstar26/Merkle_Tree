#include "crypto/sha1.h"
#include<string>
#include<vector>
#include<iostream>

class Node
{
public:
    std::string hash;
    std::vector<class Node*> child;


    Node(std::string init = "")
    {
        this->hash = init;
    }
};

