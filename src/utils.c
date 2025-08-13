#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#include <ShlObj.h>
#include <direct.h>
#define mkdir(x, y) _mkdir(x)
#else
#include <sys/stat.h>
#include <unistd.h>
#endif

// Get %APPDATA% path
char *get_appdata_path()
{
#ifdef _WIN32
	char path[MAX_PATH];
	if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		char *res = malloc(strlen(path) + 1);
		if (res)
			strcpy(res, path);
		return res;
	}
	else
	{
		return NULL;
	}
#else
	const char *home = getenv("HOME");
	if (!home)
		return NULL;
	char *res = malloc(strlen(home) + 12);
	if (res)
		sprintf(res, "%s/.config", home);
	return res;
#endif
}

// Create folder (works recursively if needed)
int create_folder(const char *path)
{
#ifdef _WIN32
	return mkdir(path, 0755);
#else
	return mkdir(path, 0755);
#endif
}

// Generate 16-char alphanumeric profile ID
void generate_profile_id(char *out)
{
	static const char charset[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789";
	size_t charset_len = strlen(charset);

	srand((unsigned)time(NULL) + rand()); // basic randomness
	for (int i = 0; i < 16; i++)
	{
		out[i] = charset[rand() % charset_len];
	}
	out[16] = '\0';
}

// XOR encryption/decryption in-place
void xor_encrypt_decrypt(char *data, const char *key)
{
	if (!data || !key)
		return;
	size_t data_len = strlen(data);
	size_t key_len = strlen(key);
	for (size_t i = 0; i < data_len; i++)
	{
		data[i] ^= key[i % key_len];
	}
}
