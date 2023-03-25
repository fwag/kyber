#include <stddef.h>
#include <linux/types.h>
#include <uapi/linux/types.h>
//#include <stdlib.h>
#include "randombytes.h"
#include <linux/random.h>
#include<linux/string.h>

#ifdef _WIN32
#include <windows.h>
#include <wincrypt.h>
#else
#include <linux/fcntl.h>
#include <linux/errno.h>
#ifdef __linux__
#define _GNU_SOURCE
#include <linux/unistd.h>
//#include <sys/syscall.h>
#else
#include <unistd.h>
#endif
#endif

#ifdef _WIN32
void randombytes(uint8_t *out, size_t outlen) {
  HCRYPTPROV ctx;
  size_t len;

  if(!CryptAcquireContext(&ctx, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
    abort();

  while(outlen > 0) {
    len = (outlen > 1048576) ? 1048576 : outlen;
    if(!CryptGenRandom(ctx, len, (BYTE *)out))
      abort();

    out += len;
    outlen -= len;
  }

  if(!CryptReleaseContext(ctx, 0))
    abort();
}
#elif defined(__linux__) && defined(SYS_getrandom)
void randombytes(uint8_t *out, size_t outlen) {
  #if 0
  ssize_t ret;

  while(outlen > 0) {
    ret = syscall(SYS_getrandom, out, outlen, 0);
    if(ret == -1 && errno == EINTR)
      continue;
    else if(ret == -1)
      abort();

    out += ret;
    outlen -= ret;
  }
  #endif
  wait_for_random_bytes();
  get_random_bytes_wait(out, outlen);
  //memset(out, 0, outlen);
}
#else
void randombytes(uint8_t *out, size_t outlen) {
  #if 0
  static int fd = -1;
  ssize_t ret;

  while(fd == -1) {
    fd = open("/dev/urandom", O_RDONLY);
    if(fd == -1 && errno == EINTR)
      continue;
    else if(fd == -1)
      abort();
  }

  while(outlen > 0) {
    ret = read(fd, out, outlen);
    if(ret == -1 && errno == EINTR)
      continue;
    else if(ret == -1)
      abort();

    out += ret;
    outlen -= ret;
  }
  #endif
  wait_for_random_bytes();
  get_random_bytes_wait (out, outlen);
  //memset(out, 0, outlen);
}
#endif
