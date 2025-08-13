#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

// Get %APPDATA% path. Returns a string you must free.
char *get_appdata_path();

// Create a folder, returns 0 on success, -1 on failure
int create_folder(const char *path);

// Generate a 16-character alphanumeric ID (case-sensitive)
void generate_profile_id(char *out);

// XOR encrypt/decrypt data using key (in-place)
void xor_encrypt_decrypt(char *data, const char *key);

#endif // UTILS_H
