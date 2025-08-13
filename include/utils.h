#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

/**
 * Retrieves the path to the %APPDATA% directory on Windows.
 * On non-Windows platforms, this can be adapted to return ~/.config or similar.
 *
 * @return Dynamically allocated string containing the path.
 *         Caller must free() the returned string.
 *         Returns NULL on error.
 */
char *get_appdata_path(void);

/**
 * Creates a folder (directory) at the specified path.
 * If intermediate directories do not exist, they are NOT created.
 *
 * @param path Full path to the folder to create.
 * @return 0 on success, -1 on failure.
 */
int create_folder(const char *path);

/**
 * Generates a random 16-character alphanumeric (A–Z, a–z, 0–9) string.
 * The string is case-sensitive and null-terminated.
 *
 * @param out Pointer to a char array with space for at least 17 bytes.
 */
void generate_profile_id(char *out);

/**
 * XOR encrypts or decrypts data in-place using the provided key.
 * Applying this function twice with the same key restores the original data.
 *
 * @param data Pointer to the data buffer to encrypt/decrypt (null-terminated string).
 * @param key  Null-terminated string used as the encryption key.
 */
void xor_encrypt_decrypt(char *data, const char *key);

#endif // UTILS_H
