#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <new>

extern "C" {

unsigned int vvvvvv_lodepng_decode24(unsigned char **out,
                                     unsigned int *w,
                                     unsigned int *h,
                                     const unsigned char *in_ptr,
                                     size_t in_size);

unsigned int vvvvvv_lodepng_decode32(unsigned char **out,
                                     unsigned int *w,
                                     unsigned int *h,
                                     const unsigned char *in_ptr,
                                     size_t in_size);

void vvvvvv_lodepng_free(unsigned char *ptr);

} // extern "C"
