/* GIMP RGB C-Source image dump (safe_zone.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[64 * 36 * 2 + 1];
} safe_zone_img = {
  64, 36, 2,
  "\033X\033X\000\000\000\000\000\000\000\000\000\000\033X\033X\000\000\000\000\000\000\000\000\033X\033X\033X\033X\033X"
  "\000\000\000\000\000\000\000\000\000\000\033X\033X\033X\000\000\000\000\000\000\033X\033X\033X\000\000\000\000\000\000\000\000"
  "\000\000\000\000\033X\033X\000\000\000\000\000\000\000\000\000\000\000\000\000\000\033X\033X\033X\000\000\000\000\000\000\000\000"
  "\000\000\000\000\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\033X\033X\000\000\000\000\000\000\000\000\000\000\033X"
  "\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\033X\033X\033X"
  "\000\000\000\000\000\000\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\000\000\033X\033X\033X\000\000\000\000\000\000"
  "\000\000\000\000\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X"
  "\033X\033X\000\000\000\000\000\000\000\000\000\000\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X"
  "\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\000\000\000\000"
  "\000\000\000\000\000\000\000\000\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\033X\033X\033X\033X\033X\033X"
  "\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X"
  "\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X"
  "\033X\033X\033X\033X\033X\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\000\000\033X\033X\033X\033X"
  "\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X"
  "\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\336\060\336\060\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336"
  "\060\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\336\060\336\060f\261f\261\336\060\336\060\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261f\261"
  "\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\336\060\336\060f\261\336\060\336\060f\261\336\060\336\060\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261\336\060\336"
  "\060f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\336\060\336\060f\261\336\060\336\060f\261\336\060\336\060\033X\033X\033"
  "X\033X\033X\033X\033X\033X\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261"
  "\336\060\336\060f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\336"
  "\060\336\060\033X\033X\033X\033X\033X\336\060\336\060f\261f\261\336\060\336\060\033X"
  "\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\336\060\336\060\033X\033X\033X\033X"
  "\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\336\060\336\060f\261f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\336\060\336\060\336\060\336\060\033X\033X\033X\033X\033X\336\060\336\060\336"
  "\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261f\261\336\060"
  "\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\336\060\336\060\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\336\060\336\060\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261f\261\336\060\336\060\033X\033"
  "X\033X\033X\033X\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060"
  "f\261\336\060\336\060f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\336\060"
  "\336\060f\261f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336"
  "\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261\336\060"
  "\336\060f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\336\060\336\060f\261\336\060\336\060f\261\336\060\336\060\033X\033X\033"
  "X\033X\033X\033X\336\060\336\060f\261\336\060\336\060f\261\336\060\336\060\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\336\060\336\060f\261\336\060\336\060f\261\336\060\336\060\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261f\261\336\060"
  "\336\060\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261\336\060\336\060f\261"
  "\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261f\261\336\060\336\060\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\336"
  "\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261f\261\336"
  "\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\336\060\336\060\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336"
  "\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\336\060\336"
  "\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\336\060\336\060\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060"
  "\336\060f\261f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\336\060\336\060\336\060\336\060\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261"
  "\336\060\336\060f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\336\060\336\060f\261f\261\336\060\336\060\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f"
  "\261\336\060\336\060f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\336\060\336\060f\261\336\060\336\060f\261\336\060\336\060"
  "\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\336\060\336\060\033X\033X\033X"
  "\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X"
  "\033X\033X\336\060\336\060f\261f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261\336\060\336\060f\261\336"
  "\060\336\060\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261f\261\336\060\336"
  "\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\336\060\336\060\336\060\336\060\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261f\261\336"
  "\060\336\060\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261\336\060\336\060f"
  "\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\033X\033X\033X\033X\033X\033"
  "X\033X\033X\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060"
  "\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261\336\060"
  "\336\060f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\336\060\336\060\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261"
  "f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\336\060\336\060f\261f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\336\060\336"
  "\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f"
  "\261\336\060\336\060f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261\336"
  "\060\336\060f\261\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\336\060\336\060f\261f\261\336\060"
  "\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\336\060\336\060\336\060\336\060\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\336\060\336\060\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\000\000\000\000\000\000\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\033X\033X\033"
  "X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\000\000\000\000\000\000\000\000\000\000\033X\033X\033X\033X\033X\033X\033X\033X\033X\033X\033"
  "X\033X\033X\000\000\000\000\000\000\000\000\000\000\033X\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\033X\033X\033X\033X\033X\033X\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\033X\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\033X"
  "\033X\033X\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\000\000\033X\000\000\000\000\000\000\000\000\000\000\033X"
  "\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\033X\033X\000\000\000\000\000\000\033X\033X"
  "\033X\033X\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\033X\033X\033X\000\000\000\000\000\000\000\000\000\000"
  "\033X\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\033X\000\000\000\000\000\000\033X",
};
