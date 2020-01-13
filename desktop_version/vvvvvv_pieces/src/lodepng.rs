use std::os::raw::{c_uint, c_uchar};
use libc::size_t;
use std::ffi::c_void;

use lodepng;

#[no_mangle]
pub unsafe extern fn vvvvvv_lodepng_decode24(
    out: &mut *mut c_uchar,
    w: &mut c_uint,
    h: &mut c_uint,
    in_ptr: *const c_uchar,
    in_size: size_t,
) -> c_uint {
    lodepng::ffi::lodepng_decode24(out, w, h, in_ptr, in_size).0
}

#[no_mangle]
pub unsafe extern fn vvvvvv_lodepng_decode32(
    out: &mut *mut c_uchar,
    w: &mut c_uint,
    h: &mut c_uint,
    in_ptr: *const c_uchar,
    in_size: size_t,
) -> c_uint {
    lodepng::ffi::lodepng_decode32(out, w, h, in_ptr, in_size).0
}

#[no_mangle]
pub unsafe extern fn vvvvvv_lodepng_free(
    ptr: *mut c_uchar,
) {
    lodepng::ffi::lodepng_free(ptr as *mut c_void);
}
