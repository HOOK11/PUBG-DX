
#include <vector>
#include <string>
using namespace  std;
#ifndef BASE64_H  
#define BASE64_H  

const char base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

/* Base64 ±àÂë */
char* base64_encode(const char* data, int data_len);

/* Base64 ½âÂë */
char *base64_decode(const char* data, int data_len);

std::vector<std::string> split(const std::string &s, const std::string &seperator);

#endif  